# ifndef _MANAGEMENT_H
# define _MANAGEMENT_H

# include <iostream>
using namespace std;

#ifndef _STRUCT_STUDENT
#define _STRUCT_STUDENT
// struct student
// num[13] 代表学号，name[51]代表姓名，g1, g2, g3代表成绩，student *next用于组成单链表
struct student{
    char num[13];
    char name[51];
    int g1 =0;
    int g2 =0;
    int g3 =0;
    student *next;
};

#endif

// Function AddStudent()
void AddStudent(student *head);

// Function ModifyByNumber()
void ModifyBynumber(student *head);

// Function ShowAllStudents();
void ShowAllStudents(student *head);

// Function SearchByNumber();
void SearchByNumber(student *head);

// Function SearchByName();
void SearchByName(student *head);

// Function RangeByNumber();
void RangeByNumber(student *head);

// Function RangeByGrade();
void RangeByGrade(student *head);

#endif