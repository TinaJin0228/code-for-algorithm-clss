# include <iostream>
# include "management.h"
using namespace std;

// struct student{
//     char num[13];
//     char name[51];
//     int g1 =0;
//     int g2 =0;
//     int g3 =0;
//     student *next;
// };

int main(){
    int n;
    student *head = nullptr;// head代表学生单链表的头指针
    bool flag = true;

    cout<<"欢迎使用成绩管理系统"<<endl;
    cout<<"1--添加学生成绩"<<endl;
    cout<<"2--修改学生成绩"<<endl;
    cout<<"3--显示全部学生成绩"<<endl;
    cout<<"4--按学号查询学生成绩"<<endl;
    cout<<"5--按姓名查询学生成绩"<<endl;
    cout<<"6--按学号升序排序"<<endl;
    cout<<"7--按总分降序排序"<<endl;
    cout<<"0--退出";

    while(flag){
    cin>>n;

    switch(n){
        case 0:flag = false;break;
        case 1:AddStudent(head);break;
        case 2:ModifyBynumber(head);break;
        case 3:ShowAllStudents(head);break;
        case 4:SearchByNumber(head);break;
        case 5:SearchByName(head);break;
        case 6:RangeByNumber(head);break;
        case 7:RangeByGrade(head);break;
    }
    }

    return 0;
}