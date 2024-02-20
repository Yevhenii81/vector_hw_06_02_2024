#include "Group.h"

Group::Group()
{
    SetGroupName("P26");
    SetNumberOfCourse(2);
    SetSpecialization("Software Delelopmer");
}

void Group::PrintGroup() 
{
    cout << groupName << "\n";
    for (int i = 0; i < countStudent; i++)
    {
        classmates[i].PrintStudent();
        classmates[i].PrintHW();
        classmates[i].PrintExam();
        classmates[i].PrintPractic();
        cout << "\naver grade: ";
        classmates[i].AverageGrade();
        cout << "\n";
    }
}

void Group::AddStudent(const Student& newStudent)
{
    countStudent++;
    classmates.push_back(newStudent);
}

void Group::WeanStudent(unsigned short index)
{
    if (index < classmates.size()) {
        classmates.erase(classmates.begin() + index);
        countStudent--;
    }
}

void Group::Expel()
{
    if (countStudent == 0)
    {
        cout << "Group is empty\n\n";
        return;
    }
    int minGradeIndex = 0;
    for (int i = 1; i < countStudent; i++)
    {
        if (classmates[i].GetAverageGrade() < classmates[minGradeIndex].GetAverageGrade())
        {
            minGradeIndex = i;
        }
    }

    classmates.erase(classmates.begin() + minGradeIndex);
    countStudent--;
    cout << "The student with the lowest grade point average is dropped from the group\n\n";
}

void Group::SetCountOfStudent(int countStudent)
{
    this->countStudent = countStudent;
}

void Group::SetGroupName(string groupName)
{
    this->groupName = groupName;
}

void Group::SetSpecialization(string specialization)
{
    this->specialization = specialization;
}

void Group::SetNumberOfCourse(int numberOfCoure)
{
    this->numberOfCoure = numberOfCoure;
}

int Group::GetCountOfStudent() const
{
    return countStudent;
}

string Group::GetGroupName() const
{
    return groupName;
}

string Group::GetSpecialization() const
{
    return specialization;
}

int Group::GetNumberOfCourse() const
{
    return numberOfCoure;
}