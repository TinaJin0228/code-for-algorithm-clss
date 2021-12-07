# include <iostream>
using namespace std;


struct pt{
    pt* next=NULL;
    int id=0;
    int wt = 0;
    pt(int id1=0,int wt1 = 0,pt* next1=NULL):id(id1),wt(wt1),next(next1){}
};

void insert(pt* &gh,int wt,int p1,int p2){
    pt* head = &gh[p1];
    if(p1==p2)return;// 自环边在最小生成树中没有意义
    bool flagnew = true;
    while(head->id!=0){
        if(head->id!=p2)
        head = head->next;
        else{
            head->wt = head->wt<wt?head->wt:wt;
            flagnew = false;
            break;
        }
    }
    if(flagnew){
    head->id = p2;
    head->wt = wt;
    head->next = new pt;
    }
    return;
}

void swap(int* &list,int i,int j){
    int tmp = list[i];
    list[i] = list[j];
    list[j] = tmp;
}

// 更新n个元素的最小堆
// 鉴于本问题中最小堆中的元素的值改变时只可能是变小，仅需向上过滤
void update(int* &heap,int i){
    while(i>1){
        if(heap[i]/10000>=heap[i/2]/10000)return;
        swap(heap,i,i/2);
        i = i/2;
    }
    return;
}

//将标号为1的元素向下过滤
void filterdown(int* &heap,int n){
    int i = 1;
    while(2*i+1<=n){
        if((heap[i]/10000)<=(heap[2*i]/10000) && (heap[i]/10000)<=(heap[2*i+1]/10000))return;
        else {
            i = (heap[2*i]/10000)<(heap[2*i+1]/10000)?2*i:2*i+1;
            swap(heap,i,i/2);
        }
    }
    if(2*i>n)return;
    else// i.e. n==2i 
    {
        if((heap[i]/10000)<=(heap[2*i]/10000))return;
        else {
            swap(heap,i,2*i);
            return;
        }
    }

}


int main(){
    int n,m;
    int i;
    int wt,p1,p2;
    int s,v;
    int cost = 0;
    pt* pt1;

    cin>>n>>m;
    
    pt* gh = new pt[n+1];
    int* dist = new int[n+1];//(distance to the current P-MST)*10000+number,最小堆
    bool* visited = new bool[n+1];// is the pt visited

    // initialization
    // gh
    for(i=1;i<=m;i++){
        cin>>p1>>p2>>wt;
        insert(gh,wt,p1,p2);
        insert(gh,wt,p2,p1);
    }

    // dist,visited
    for(i=1;i<=n;i++){
        dist[i] = 10000*10001 + i;// as wt<=10000
        visited[i] = false;
    }
    

    s = 1;//起点
    visited[s] = true;
    swap(dist,s,n);
    n--;

    v = s;//v: newly added vertex

    // n:最小堆中仍未加入P-MST的点
    while(n){
        // update dist of v's neighbors
        pt1 = &gh[v];
        while(pt1->id!=0){
            if(!visited[pt1->id]){
                i=1;
                while(dist[i]%10000!=pt1->id)i++;
                if((pt1->id+pt1->wt*10000) < dist[i])
                {
                dist[i] = pt1->id+pt1->wt*10000;
                // 向上过滤
                update(dist,i);
                }
            }
            pt1 = pt1->next;
        }

        cost += dist[1]/10000;
        visited[dist[1]%10000] = true;
        v = dist[1]%10000;
        swap(dist,1,n);
        n--;
        filterdown(dist,n);
    }
    cout<<cost;
    return 0;
}