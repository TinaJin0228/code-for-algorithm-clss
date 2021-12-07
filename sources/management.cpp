# include <iostream>
# include "management.h"
using namespace std;

void AddStudent(student *head){
    char order[100];
    cin.getline(order,100);

    if(head == nullptr){
    int i=0;int j=0;
    student *ns = new student;
    for(;i<12;i++)ns->num[i] = order[i+2];
    ns->num[12] = '\0';
    i=15;
    while(order[i]!=' '){
        ns->g1 = ns->g1*10+(order[i])-48;i++;
    }
    i++;
    while(order[i]!=' '){
        ns->g2 = ns->g2*10+(order[i])-48;i++;
    }
    i++;
    while(order[i]!=' '){
        ns->g3 = ns->g3*10+(order[i])-48;i++;
    }
    i++;
    for(;order[i]!='\0';i++){
        ns->name[j] = order[i];
        j++;
    }
    ns->name[j] = '\0';
    
    head->next = ns;
}
else {
    bool flag = true;
    student *tp = head->next;
    while(tp && flag){
    int p=0;bool flag2 = true;
    while(p<=11){
        if(tp->num[p]!=order[p+2])flag2 = false;
        p++;
    }
    if(!flag2)tp = tp->next;
    else flag = false;
    }

    if(flag){
    int i=0;int j=0;
    student *ns = new student;
    for(;i<12;i++)ns->num[i] = order[i+2];
    ns->num[12] = '\0';
    i=15;
    while(order[i]!=' '){
        ns->g1 = ns->g1*10+(order[i])-48;i++;
    }
    i++;
    while(order[i]!=' '){
        ns->g2 = ns->g2*10+(order[i])-48;i++;
    }
    i++;
    while(order[i]!=' '){
        ns->g3 = ns->g3*10+(order[i])-48;i++;
    }
    i++;
    for(;order[i]!='\0';i++){
        ns->name[j] = order[i];
        j++;
    }
    ns->name[j] = '\0';

    ns->next = head->next;
    head->next = ns;
    }
    else {
    int i=0;int j=0;
    i=15;
    while(order[i]!=' '){
        tp->g1 = tp->g1*10+(order[i])-48;i++;
    }
    i++;
    while(order[i]!=' '){
        tp->g2 = tp->g2*10+(order[i])-48;i++;
    }
    i++;
    while(order[i]!=' '){
        tp->g3 = tp->g3*10+(order[i])-48;i++;
    }
    i++;
    for(;order[i]!='\0';i++){
        tp->name[j] = order[i];
        j++;
    }
    tp->name[j] = '\0';
    }
}
}

// Function ModifyByNumber()
void ModifyBynumber(student *head){

    char order[100];
    cin.getline(order,100);

    bool flag = true;
    student *tp = head->next;
    while(tp && flag){
    int p=0;bool flag2 = true;
    while(p<=11){
        if(tp->num[p]!=order[p+2])flag2 = false;
        p++;
    }
    if(!flag2)tp = tp->next;
    else flag = false;
    }
    if(!flag){
        int i=0;int j=0;
    i=15;
    while(order[i]!=' '){
        tp->g1 = tp->g1*10+(order[i])-48;i++;
    }
    i++;
    while(order[i]!=' '){
        tp->g2 = tp->g2*10+(order[i])-48;i++;
    }
    i++;
    while(order[i]!=' '){
        tp->g3 = tp->g3*10+(order[i])-48;i++;
    }
    i++;
    for(;order[i]!='\0';i++){
        tp->name[j] = order[i];
        j++;
    }
    tp->name[j] = '\0';
    }
}

// Function ShowAllStudents();
void ShowAllStudents(student *head){
    student *tp = head->next;
    while(tp)cout<<tp->num<<" "<<tp->name<<" "<<tp->g1<<" "<<tp->g2<<" "<<tp->g3<<endl;
}

// Function SearchByNumber();
void SearchByNumber(student *head){

    char order[100];
    cin.getline(order,100);

    bool flag = true;
    student *tp = head->next;
    while(tp && flag){
    int p=0;bool flag2 = true;
    while(p<=11){
        if(tp->num[p]!=order[p+2])flag2 = false;
        p++;
    }
    if(!flag2)tp = tp->next;
    else flag = false;
    }
    if(!flag)cout<<tp->num<<" "<<tp->name<<" "<<tp->g1<<" "<<tp->g2<<" "<<tp->g3<<endl;
}

// Function SearchByName();
void SearchByName(student *head){
    char order[100];
    cin.getline(order,100);

    bool flag = true;
    student *tp = head->next;
    while(tp && flag){
    int p=0;bool flag2 = true;
    while(p<=11){
        if(tp->num[p]!=order[p+2])flag2 = false;
        p++;
    }
    if(!flag2)tp = tp->next;
    else flag = false;
    }
    if(!flag)cout<<tp->num<<" "<<tp->name<<" "<<tp->g1<<" "<<tp->g2<<" "<<tp->g3<<endl;




}

// Function RangeByNumber();
void RangeByNumber(student *head){
    char order[100];
    cin.getline(order,100);

    bool flag = true;
    student *tp = head->next;
    while(tp && flag){
    int p=0;bool flag2 = true;
    while(p<=11){
        if(tp->num[p]!=order[p+2])flag2 = false;
        p++;
    }
    if(!flag2)tp = tp->next;
    else flag = false;
    }
    if(!flag)cout<<tp->num<<" "<<tp->name<<" "<<tp->g1<<" "<<tp->g2<<" "<<tp->g3<<endl;











}

// Function RangeByGrade();
void RangeByGrade(student *head){
    char order[100];
    cin.getline(order,100);

    bool flag = true;
    student *tp = head->next;
    while(tp && flag){
    int p=0;bool flag2 = true;
    while(p<=11){
        if(tp->num[p]!=order[p+2])flag2 = false;
        p++;
    }
    if(!flag2)tp = tp->next;
    else flag = false;
    }
    if(!flag)cout<<tp->num<<" "<<tp->name<<" "<<tp->g1<<" "<<tp->g2<<" "<<tp->g3<<endl;








    
}