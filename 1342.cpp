#include <iostream>
using namespace std;

struct vertex{
    int id = -1;
    int wt = -1;
    vertex* next = NULL;
    vertex():id(-1),wt(-1){}
    vertex(int id1,int wt1=-1):id(id1),wt(wt1){}
};

long long D[2501];

int main(){
    int n,m,s,t;
    int u,v,w;
    int i;

    cin>>n>>m>>s>>t;

    vertex* graph = new vertex[n+1];

    for(i=0;i<m;i++){
        cin>>u>>v>>w;
        vertex* head1 = &graph[u];
        if(head1->id==-1){
            head1->id = v;head1->wt = w;
        }
        else {
        while(head1->next!=NULL)
        {
            if(head1->id == v){
                head1->wt = head1->wt<w?head1->wt:w;
                break;
            }
            head1 = head1->next;
        }

        if(head1->next==NULL)
            {
                if(head1->id!=v)head1->next = new vertex(v,w);
                else head1->wt = head1->wt<w?head1->wt:w;
            }
        }
        head1 = &graph[v];
        if(head1->id==-1){
            head1->id = u;head1->wt = w;
        }
        else {
        while(head1->next!=NULL)
        {
            if(head1->id == u){
                head1->wt = head1->wt<w?head1->wt:w;
                break;
            }
            head1 = head1->next;
        }
        if(head1->next==NULL)            
            {
                if(head1->id!=u)head1->next = new vertex(u,w);
                else head1->wt = head1->wt<w?head1->wt:w;
            }
        }
    }

    for(i=1;i<=n;i++)D[i] = -1;//-1:undefined(positive infinite)
    D[s] = 0;

    int* T = new int[n+1];
    for(i=0;i<=n;i++)T[i] = 0;
    T[0] = 1;T[s] = 1;

    int* pre = new int[n+1];


    vertex* head = &graph[s];
    while(head!=NULL){
        D[head->id] = head->wt;
        pre[head->id] = s;
        head = head->next;
    }    
    
    int min_v;long long min_d = -1;
    while(T[0]<n){
        min_d = -1;
        for(i=1;i<=n;i++){
            if(T[i]==0 && D[i]!=-1){
                if(min_d==-1){
                    min_d = D[i];min_v = i;
                }
                else if(D[i]<min_d){
                    min_d = D[i];min_v = i;
                }
            }
        }
        if(min_v==t)break;
        T[0]++;T[min_v] = 1;
        
        head = &graph[min_v];
        while(head!=NULL){
            if(D[head->id]==-1){
                D[head->id] = min_d+head->wt;
                pre[head->id] = min_v;
            }
            else if(D[head->id]>min_d+head->wt){
                D[head->id] = min_d+head->wt;
                pre[head->id] = min_v;
            }
            head = head->next;
        }

    }

    cout<<D[t];
    

    return 0;
}