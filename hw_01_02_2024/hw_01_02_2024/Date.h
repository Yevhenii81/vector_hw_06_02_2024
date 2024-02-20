#pragma once

class Date {
    unsigned short day;
    unsigned short month;
    long long year;
    unsigned short oneDay = 1;
public:
    Date();
    Date(unsigned short day, unsigned short month, long long year);
    Date(unsigned short day, unsigned short month);

    void PrintDate() const;

    void SetDay(unsigned short day);
    void SetMonth(unsigned short month);
    void SetYear(long long year);

    unsigned short GetDay() const;
    unsigned short GetMonth() const;
    long long GetYear() const;

    //������ ���������� ++ ���������� �����
    Date operator ++ ()
    {
        this->day += this->oneDay;
        return*this;
    }

    //������ ���������� ++ ����������� �����
    Date operator ++ (int x)
    {
        Date copy = *this;
        this->day = this->oneDay;
        return copy;
    }

    //������ ���������� -- ���������� �����
    Date operator -- ()
    {
        this->day += this->oneDay;
        return*this;
    }

    //������ ���������� -- ����������� �����
    Date operator -- (int x)
    {
        Date copy = *this;
        this->day = this->oneDay;
        return copy;
    }

    //������ ���������� +=
    Date operator += (int x)
    {
        Date copy = *this;
        this->day += x;
        return copy;
    }
};

