#include <iostream>

using namespace std;

long long int MAXWT = 1000000000;

struct pt{
    pt* next=NULL;
    int id=0;
    long long int wt = 0;
    pt(int id1=0,long long int wt1 = 0,pt* next1=NULL):id(id1),wt(wt1),next(next1){}
};

void insert(pt* &gh,long long int wt,int p1,int p2){
    pt* head = &gh[p1];
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

int pre[2501];
long long int dist[2501];
bool visited[2501];
int negcycle[2501];


int main(){
    int n,m;
    int i,j;
    int p1,p2;
    long long int wt;
    int sig;
    int num1,num2;
    int k=0;
    bool negativecycle = false;
    pt* pt1;

    // freopen("1344.in","r",stdin);

    cin>>n>>m;

    pt* gh = new pt[n+1];

    for(i=1;i<=m;i++){
        cin>>p1>>p2>>wt;
        insert(gh,wt,p1,p2);
    }
    // for(i=1;i<=m;i++){
    //     cin>>p1>>p2>>wt;
    //     if(wt<0)
    //     insert(gh,wt,p1,p2);
    //     else {
    //         insert(gh,wt,p1,p2);
    //         insert(gh,wt,p2,p1);
    //     }
    // }

    for(i=1;i<=n;i++){
        dist[i] = 0;
        visited[i] = false;
    }


    for(i=1;i<=n-1;i++){
        for(j=1;j<=n;j++){
        pt1 = &gh[j];
        while(pt1->id!=0){
            if(dist[pt1->id]>dist[j]+pt1->wt){
                dist[pt1->id] = dist[j]+pt1->wt;
                pre[pt1->id] = j;
            }
            pt1 = pt1->next;
            }
        }
    }

    
    for(j=1;j<=n;j++){
    pt1 = &gh[j];
    while(pt1->id!=0){
        if(dist[pt1->id]>dist[j]+pt1->wt){
                dist[pt1->id] = dist[j]+pt1->wt;
                pre[pt1->id] = j;
                negativecycle = true;
                sig = pt1->id;
        }
        pt1 = pt1->next;
        }
    } 

    if(!negativecycle)cout<<"No";
    else {
        num1 = sig;
        while(!visited[num1]){
            visited[num1] = true;
            num1 = pre[num1];
        }
        k=1;
        num2 = pre[num1];
        negcycle[1] = num1;
        while(num2!=num1){
            k++;
            negcycle[k] = num2;
            num2 = pre[num2];
        }
        cout<<"Yes"<<endl<<k<<endl;
        while(k--)cout<<negcycle[k+1]<<" ";
    }


    return 0;
}