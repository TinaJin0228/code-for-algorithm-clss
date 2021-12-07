#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;

struct node{
    int id = 0;
    node* next = NULL;
    node(int id1 = 0,node* next1 = NULL):id(id1),next(next1){}
};

struct ndlist{
    node* head;
    ndlist* next = NULL;
    int num = 1;

};

void insert(node* &gh,int n1,int n2){
    node* head = &gh[n1];
    while(head->id!=0)head = head->next;
    head->id = n2;
    head->next = new node;
    return;
}



int main(){
    int n,m;
    int v1,a,v2,b;
    int i,j;
    int num1,num2;
    bool con = false;
    // queue <int> q;
    // queue <int> q2;
    node* head;

    node* gh = new node[2*n+1];

    cin>>n>>m;
    
    bool* visited = new bool[2*n+1];
    bool* scc = new bool[2*n+1];
    for(i=1;i<=2*n;i++){
        visited[i] = false;
        scc[i] = false;
    }

    for(i=0;i<m;i++){
        cin>>v1>>a>>v2>>b;
        insert(gh,v1+(!a)*n,v2+b*n);
        insert(gh,v2+(!b)*n,v1+a*n);
    }

    // dfs
    int s = 0;// 已经进入scc的点
    int numscc = 0;//scc的数量

    node* nodelist = new node[2*n+1];

    while(s<2*n){
    i=1;while(scc[i]==true)i++;
    num1 = i;
    for(i=1;i<=2*n;i++)visited[i] = false;

    visited[num1] = true;
    while(1){
        head = &gh[num1];
        while(head->id!=0 && visited[head->id] && scc[head->id])head = head->next;
        if(head->id!=0){
        num1 = head->id;
        visited[num1] = true;}
        else break;
    }

    insert(nodelist,numscc,num1);
    scc[num1] = true;s++;
    head = &gh[num1];
    if(head->id!=0){
    while(head->id!=num1){
        scc[head->id] = true;s++;
        insert(nodelist,numscc,head->id);
        head = &gh[head->id];
    }
    numscc++;
    }
    }

    int* res = new int[2*n+1];
    for(i=1;i<=2*n;i++)res[i]=-1;

    for(i=0;i<numscc;i++){
        int* tmpres = new int[2*n+1];
        for(j=1;j<=2*n;i++)tmpres[j]=-1;
        tmpres[i] = -1;
        head = &nodelist[i];
        while(head->id!=0 && !con){
        if(tmpres[head->id%(n+1)]!=-1){
            if(head->id/(n+1)!=tmpres[head->id%(n+1)]){
                con = true;break;}
            }
        else {
            tmpres[head->id%(n+1)]=head->id/(n+1);
        }
        head = head->next;
        }
        if(con){
            cout<<"No";break;
        }
        else {
            for(j=1;j<=2*n;j++)if(res[j]==-1)res[j] = tmpres[j];
        }
    }

    if(!con)for(i=1;i<=2*n;i++)cout<<res[i]<<" ";




}