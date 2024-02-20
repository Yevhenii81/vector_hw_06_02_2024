#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
    string surname;
    string name;
    string patronymic;
    string adress;
    string phoneNumber;
    int averGradeExam = 0;
    /*unsigned int countPractic = 0;
    unsigned int countHW = 0;
    unsigned int countExam = 0;*/
    vector<int> gradeOfPractic;
    vector<int> gradeOfHW;
    vector<int> gradeOfExam;

public:
    //Student(const Student& original);
    /// <summary>
    ///  ����������� �� ���������. �������������� ������ Student ��� ����������
    /// </summary>
    Student();

    /// <summary>
    /// ����������� � �����������. �������������� ������ Student � ��������� ���������� �����
    /// </summary>
    /// <param name="surname">������� ��������</param>
    /// <param name="name">��� ��������</param>
    /// <param name="patronymic">�������� ��������</param>
    /// <param name="adress">����� ��������</param>
    /// <param name="phoneNumber">����� �������� ��������</param>
    Student(string surname, string name, string patronymic, string adress, string phoneNumber);

    /// <summary>
    /// ����������� � �����������. �������������� ������ Student � ��������� ���������� �����,
    /// ������������ �������� �� ��������� ��� ������ ��������
    /// </summary>
    /// <param name="surname">������� ��������</param>
    /// <param name="name">��� ��������</param>
    /// <param name="patronymic">�������� ��������</param>
    /// <param name="adress">����� ��������</param>
    Student(string surname, string name, string patronymic, string adress);

    /// <summary>
   /// ����������. ����������� ���������� ������������ ������
   /// </summary>
    ~Student();

    /// <summary>
    /// ������� ���������� � ��������
    /// </summary>
    void PrintStudent() const;

    /// <summary>
    /// ������������� ������� ��������
    /// </summary>
    /// <param name="surname">������� ��������</param>
    void SetSurname(string surname);

    /// <summary>
    /// ������������� ��� ��������
    /// </summary>
    /// <param name="name">��� ��������</param>
    void SetName(string name);

    /// <summary>
    /// ������������� �������� ��������
    /// </summary>
    /// <param name="patronymic">�������� ��������</param>
    void SetPatronymic(string patronymic);

    /// <summary>
    /// ������������� ����� ��������
    /// </summary>
    /// <param name="adress">����� ��������</param>
    void SetAdress(string adress);

    /// <summary>
   /// ������������� ����� �������� ��������
   /// </summary>
   /// <param name="phoneNumber">����� �������� ��������</param>
    void SetPhoneNumber(string phoneNumber);

    /// <summary>
    /// �������� ������� ��������
    /// </summary>
    /// <returns>������� ��������</returns>
    string GetSurname() const;

    /// <summary>
    /// �������� ��� ��������
    /// </summary>
    /// <returns>��� ��������</returns>
    string GetName() const;

    /// <summary>
    /// �������� �������� ��������
    /// </summary>
    /// <returns>�������� ��������</returns>
    string GetPatronymic() const;

    /// <summary>
    /// �������� ����� ��������
    /// </summary>
    /// <returns>����� ��������</returns>
    string GetAdress() const;

    /// <summary>
    /// �������� ����� �������� ��������
    /// </summary>
    /// <returns>����� �������� ��������</returns>
    string GetPhoneNumber() const;

    /// <summary>
    /// ��������� ������ �� ��������
    /// </summary>
    /// <param name="grade">������ �� ��������</param>
    void AddPractic(int grade);

    /// <summary>
    /// ������� ������ �� ��������
    /// </summary>
    void PrintPractic() const;

    /// <summary>
    /// �������� ������ �� �������� �� ���������� �������
    /// </summary>
    /// <param name="index">������ ������ �� ��������</param>
    /// <returns>������ �� ��������</returns>
    int GetPracticRates(unsigned int index) const;

    /// <summary>
    /// ��������� ������ �� �������� �������
    /// </summary>
    /// <param name="grade">������ �� �������� �������</param>
    void AddHW(int grade);

    /// <summary>
    /// ������� ������ �� �������� �������
    /// </summary>
    void PrintHW() const;

    /// <summary>
    /// �������� ������ �� �������� ������� �� ���������� �������
    /// </summary>
    /// <param name="index">������ ������ �� �������� �������</param>
    /// <returns>������ �� �������� �������</returns>
    int GetHWRates(unsigned int index) const;

    /// <summary>
    /// ��������� ������ �� �������
    /// </summary>
    /// <param name="grade">������ �� �������</param>
    void AddExam(int grade);

    /// <summary>
    /// ������� ������ �� ��������
    /// </summary>
    void PrintExam() const;

    /// <summary>
    /// �������� ������ �� ������� �� ���������� �������
    /// </summary>
    /// <param name="index">������ ������ �� �������</param>
    /// <returns>������ �� �������</returns>
    int GetExamRates(unsigned int index) const;

    void AverageGrade();

    void SetAverageGrade(int averGradeExam);
    int GetAverageGrade() const;

    operator string()
    {
        return surname + "\n" + name + "\n" + patronymic + "\n" + to_string(averGradeExam) + "\n" + phoneNumber;
    }
};