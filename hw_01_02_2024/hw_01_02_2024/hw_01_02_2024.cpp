﻿//#include <iostream>
//#include <ctime>
//#include <string.h>
using namespace std;

#include <vector>
#include "Student.h"
#include "Date.h"
#include "Group.h"
#include "Fraction.h"

Group operator + (const Group& one, const Group two)
{

    Group result;
    result.SetGroupName(one.GetGroupName() + two.GetGroupName());
    result.SetNumberOfCourse(one.GetNumberOfCourse());
    result.SetSpecialization(one.GetSpecialization());

    for (int i = 0; i < one.GetCountOfStudent(); i++)
    {
        result.AddStudent(one.classmates[i]);
    }
    for (int i = 0; i < two.GetCountOfStudent(); i++)
    {
        result.AddStudent(two.classmates[i]);
    }

    return result;
}

int operator - (const Date& dateNow, const Date& otherDate)
{
    int thisDays = dateNow.GetDay() + 31 * (dateNow.GetMonth() - 1);
    int otherDays = otherDate.GetDay() + 31 * (otherDate.GetMonth() - 1);

    thisDays += (dateNow.GetYear() % 4 == 0 && dateNow.GetMonth() > 2);
    otherDays += (otherDate.GetYear() % 4 == 0 && otherDate.GetMonth() > 2);

    thisDays += (dateNow.GetMonth() > 1);
    otherDays += (otherDate.GetMonth() > 1);

    thisDays += dateNow.GetMonth() / 2 + ((dateNow.GetMonth() % 2 == 0 && dateNow.GetMonth() > 7));
    otherDays += otherDate.GetMonth() / 2 + ((otherDate.GetMonth() % 2 == 0 && otherDate.GetMonth() > 7));

    thisDays += 365 * (dateNow.GetYear() - 1);
    otherDays += 365 * (otherDate.GetYear() - 1);

    return thisDays - otherDays;
}

//Student
bool operator > (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator < (const Student& a, const Student& b)
{
    return a.GetAverageGrade() < b.GetAverageGrade();
}

bool operator >= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator <= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() <= b.GetAverageGrade();
}

bool operator == (const Student& a, const Student& b)
{
    return a.GetAverageGrade() == b.GetAverageGrade();
}

bool operator != (const Student& a, const Student& b)
{
    return a.GetAverageGrade() != b.GetAverageGrade();
}

//Group
bool operator > (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() > b.GetCountOfStudent();
}

bool operator < (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() < b.GetCountOfStudent();
}

bool operator >= (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() >= b.GetCountOfStudent();
}

bool operator <= (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() <= b.GetCountOfStudent();
}

bool operator == (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() == b.GetCountOfStudent();
}

bool operator != (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() != b.GetCountOfStudent();
}

Group& operator += (Group& group, const Student& student)
{
    group.AddStudent(student);
    return group;
}

istream& operator >> (const istream& i, Student& d)
{

    cout << "surname: ";
    string answear;
    cin >> answear;
    d.SetSurname(answear);

    cout << "name: ";
    cin >> answear;
    d.SetName(answear);

    cout << "middle name: ";
    cin >> answear;
    d.SetPatronymic(answear);

    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);

    cout << "phonnumber: ";
    cin >> answear;
    d.SetPhoneNumber(answear);

    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);

    return cin;

}

ostream& operator << (const ostream& i, Student& d)
{
    d.PrintStudent();
    d.PrintExam();
    d.PrintPractic();
    d.PrintHW();
    return cout;
}

istream& operator >> (const istream& i, Group& g)
{

    cout << "Group Name: ";
    string answear;
    cin >> answear;
    g.SetGroupName(answear);

    cout << "Group Specification: ";
    cin >> answear;
    g.SetSpecialization(answear);

    cout << "Course: ";
    unsigned short amswear2;
    cin >> amswear2;
    g.SetNumberOfCourse(amswear2);

    return cin;

}

ostream& operator << (const ostream& i, Group& d)
{
    d.PrintGroup();
    return cout;
}

istream& operator >> (const istream& i, Fraction& f)
{

    cout << "numerator: ";
    int answear;
    cin >> answear;
    f.SetNumerator(answear);

    cout << "denominator: ";
    cin >> answear;
    f.SetDenominator(answear);

    return cin;

}

ostream& operator << (const ostream& i, Fraction& f)
{
    f.Print();
    return cout;
}

int main()
{
    Student first;
    first.AddExam(12);
    first.AddExam(9);
    first.AddExam(12);

    Student second;
    second.AddExam(3);
    second.AddExam(12);
    second.AddExam(10);

    Group g;
    g.AddStudent(first);
    g.AddStudent(second);

    g.PrintGroup();
    g.Expel();
    g.PrintGroup();

    /*-----------------------*/
    //#1
    /*Student s;
    s.AddExam(2);
    s.AddExam(12);
    s.AverageGrade();

    string a = (string)s;
    cout << a;*/

    //#2
    /*Student s;
    Student d;

    Group g;
    g += s;
    g += d;

    string str = (string)g;
    cout << str;*/

    //#3
    Date toDay(1, 2, 2024);
    toDay++; // 2 2 2024
    toDay.PrintDate();
    ++toDay; // 3 2 2024
    toDay.PrintDate();
    --toDay; // 2 2 2024
    toDay.PrintDate();
    toDay--; // 1 2 2024
    toDay.PrintDate();
    toDay += 5; // 6 2 2024
    toDay.PrintDate();

    //Date d(29, 2, 2024);
    //d++; // 1 3 2024
    //d.PrintDate();


    ////////////////////
    ////тест класса Fraction:
    //Fraction a(1, 2);
    //Fraction b(3, 4);

    ////Fraction + int
    //Fraction res = a + 5;
    //res.Print();
    ////int + Fraction
    //Fraction result1 = 10 + b;
    //result1.Print();
    ////double + Fraction
    //Fraction result2 = 9.99 + a;
    //result2.Print();
    ////Fraction + double 
    //Fraction re = b + 4;
    //re.Print();

    //тест для класса Date:
    /*Date now;
    Date start(3, 2, 2024);
    int days = now - start;
    cout << "Before the exam: " << days;*/

    //тест для класса Group:
    //Student studentA;
    //studentA.AddExam(7);
    //studentA.AddExam(12);
    //studentA.AddExam(9);

    //Student studentB;
    //studentB.AddExam(5);
    //studentB.AddExam(9);
    //studentB.AddExam(12);

    //Student studentС;
    //studentС.AddExam(2);
    //studentС.AddExam(9);
    //studentС.AddExam(7);

    //Group group;

    //// Добавление студентов в группу
    //group.AddStudent(studentA);
    //group.AddStudent(studentB);
    //group.AddStudent(studentС);

    //// Вывод информации о группе
    //cout << "Original Group:\n";
    //group.PrintGroup();

    //// Исключение студента из группы
    //cout << "\nExpelling a student:\n";
    //group.Expel();
    //group.PrintGroup();

    //Student copya;
    //copya = studentA;

    //Student copyb;
    //copyb = studentB;
    //Student copyс;
    //copyс = studentС;

    //Group copy;
    //copy = group;

    //cout << "\nCopied Group:\n";
    //copy.PrintGroup();



    /*Student a;
    a.AddExam(12);
    a.AddExam(12);
    Student b;
    b.AddExam(1);
    b.AddExam(10);

    a.AverageGrade();
    b.AverageGrade();

    Group one;
    one.AddStudent(a);
    Group two;
    two.AddStudent(b);

    if (a > b)
    {
        cout << "a>b\n";
    }

    if (one == two)
    {
        cout << "==\n";
    }*/


    /*Student a;
    Group g;
    g += a;
    g.PrintGroup();*/


    /*Student s;
    cin >> s;
    cout << s;

    Group g;
    cin >> g;
    g.PrintGroup();

    Fraction f;
    cin >> f;
    cout << f;*/
}
