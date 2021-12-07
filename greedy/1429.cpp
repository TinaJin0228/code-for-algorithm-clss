#include <iostream>
using namespace std;

bool sche[366];
struct pt{
    pt* next=NULL;
    int id=0;

    pt(int id1=0,pt* next1=NULL):id(id1),next(next1){}
};

pt* gh;

void insert(int p1,int p2){
    pt* head = &gh[p1];
    bool flagnew = true;
    while(head->id!=0){
        if(head->id!=p2)
        head = head->next;
        else return;//同一段时间人只能打一份工
    }

    head->id = p2;
    head->next = new pt;
    return;
}

int salary(int day){
    if(day==0)return 0;
    else {
        pt* pt1 = &gh[day];
        int j;
        bool flag;
        while(pt1->id!=0){
            flag = true;
            for(j=pt1->id;flag && j<=day;j++)if(sche[j])flag = false;
            if(flag){
                for(j=pt1->id;j<=day;j++)sche[j] = true;
                return salary(day-1)+1;
            }
            pt1 = pt1->next;
        }
        return salary(day-1);
    }
}

int main(){
    int n,m,x;
    int i;
    int s,t,a;
    int sal = 0;
    int day;
    pt* pt1;

    cin>>n>>m>>x;

    gh = new pt[n+1];

    for(i=1;i<=365;i++)sche[i] = false;

    for(i=1;i<=m;i++){
        cin>>s>>t>>a;
        insert(t,s);//图中存储以结束日为索引的所有工作
    }

    // cout<<salary(n);


    for(day=1;day<=n;day++){
        pt1 = &gh[day];
        bool flag;
        while(pt1->id!=0){
            flag = true;
            for(i=pt1->id;flag && i<=day;i++)if(sche[i])flag = false;
            if(flag){
                for(i=pt1->id;i<=day;i++)sche[i] = true;
                sal++;
            }
            pt1 = pt1->next;
        }
    }
    cout<<sal;
    return 0;
}