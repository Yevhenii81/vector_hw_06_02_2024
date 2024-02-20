#pragma once
#include "Student.h"

class Group
{
    unsigned short countStudent = 0;
public:
    vector<Student> classmates;
private:
    unsigned short numberOfCoure;
    string groupName;
    string specialization;
public:
    Group();

    void PrintGroup();

    void AddStudent(const Student& newStudent);

    void WeanStudent(unsigned short index);

    void Expel();

    void SetCountOfStudent(int countStudent);
    void SetGroupName(string groupName);
    void SetSpecialization(string specialization);
    void SetNumberOfCourse(int numberOfCoure);

    int GetCountOfStudent() const;
    string GetGroupName() const;
    string GetSpecialization() const;
    int GetNumberOfCourse() const;

    Group& operator += (const Student& s)
    {
        AddStudent(s);
        return *this;
    }

    operator string ()
    {
        return groupName + "\n" + specialization + "\n" + to_string(numberOfCoure) + "\n" + to_string(countStudent);
    }
};