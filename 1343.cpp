#include <iostream>
#include <stack>
using namespace std;

// 变动的下标参数的边界条件

struct pt{
    pt* next=NULL;
    int id=0;
    pt(int id1=0,pt* next1=NULL):id(id1),next(next1){}
};

void insert(pt* &gh,int p1,int p2){
    pt* head = &gh[p1];
    while(head->id!=0)head = head->next;
    head->id = p2;
    head->next = new pt;
    return;
}

// int pre[1000001];
int BFStree[1000001];
bool visited[1000001];

int main(){
    int n,m,s,t;
    int i;
    int p1,p2,wt;
    int num1;
    int st,ed;
    int dist = 0;
    int dtdist = 0;
    pt* pt1;
    
    // freopen("1343.in","r",stdin);

    cin>>n>>m>>s>>t;


    pt* gh0 = new pt[n+1];
    pt* gh1 = new pt[n+1];

    for(i=0;i<m;i++){
        cin>>p1>>p2>>wt;
        if(wt==1){
            insert(gh1,p1,p2);
            insert(gh1,p2,p1);}
        else {
            insert(gh0,p1,p2);
            insert(gh0,p2,p1);
        }
    }

    for(i=1;i<=n;i++){
        // pre[i] = 0;
        visited[i] = false;
    }

    BFStree[0] = 1;
    BFStree[1] = s;
    if(t!=s)visited[s] = true;

    stack<int> sk;
    sk.push(s);

    st = 1;ed = 0;
    while(1)//v not added in tree
    {   
        // BFS 0
        dtdist = 0;
        // st = BFStree[0];
        while(!sk.empty()){
            num1 = sk.top();
            sk.pop();
            pt1 = &gh0[num1];
            while(pt1->id!=0){
                if(!visited[pt1->id]){
                    visited[pt1->id] = true;
                    BFStree[0]++;
                    BFStree[BFStree[0]] = pt1->id;
                    sk.push(pt1->id);
                }
                pt1 = pt1->next;
            }
        }
        if(visited[t])break; 
        // BFS 1
        if(st!=1)st = ed+1;
        ed = BFStree[0];
        // 此时tree[st-ed]是需要搜索wt==1的路径的点
        for(i=st;i<=ed;i++){
            num1 = BFStree[i];
            pt1 = &gh1[num1];
            while(pt1->id!=0){
                if(!visited[pt1->id]){
                    visited[pt1->id] = true;
                    BFStree[0]++;
                    BFStree[BFStree[0]] = pt1->id;
                    dtdist = 1; 
                }
                pt1 = pt1->next;
            }
        }
        st = BFStree[0];
        dist += dtdist;
        if(visited[t])break;
        // 此时tree[ed+1,st]是需要搜索wt==0的点
        for(i=ed+1;i<=st;i++)sk.push(BFStree[i]);        
    }

    cout<<dist;

    return 0;
}