#pragma once
#include <iostream>
#include <ostream>
#include <string>

class CRational
{
public:
    CRational();
    CRational(int value);
    CRational(int numerator, int denominator);
    int GetNumerator() const;
    int GetDenominator() const;
    double ToDouble() const;
    //Унарный + и -
    void ChangeSign();   
    //Бинарный +
    CRational operator+(const CRational& other) const;
    CRational operator+(int num) const;
    friend CRational operator+(int num, const CRational& rational);
    //Бинарный -
    CRational operator-(const CRational& other) const;
    CRational operator-(int num) const;
    friend CRational operator-(int num, const CRational& rational);
    //+=
    CRational& operator+=(const CRational& other);
    CRational& operator+=(int num);
    //-=
    CRational& operator-=(const CRational& other);
    CRational& operator-=(int num);
    //*
    CRational operator*(const CRational& other) const;
    CRational operator*(int num) const;
    friend CRational operator*(int num, const CRational& rational);
    //деление рациональных чисел
    CRational operator/(const CRational& other) const;
    CRational operator/(int num) const;
    friend CRational operator/(int num, const CRational& rational);
    //*=
    CRational& operator*=(const CRational& other);
    CRational& operator*=(int num);
    // /=
    CRational& operator/=(const CRational& other);
    CRational& operator/=(int num);
    // == и !=
    bool operator==(const CRational& other) const;
    bool operator==(int num) const;
    friend bool operator==(int num, const CRational& rational);
    bool operator!=(const CRational& other) const;
    bool operator!=(int num) const;
    friend bool operator!=(int num, const CRational& rational);
    // <, <=, >, >=
    bool operator<(const CRational& other) const;
    bool operator<(int num) const;
    friend bool operator<(int num, const CRational& rational);
    bool operator>(const CRational& other) const;
    bool operator>(int num) const;
    friend bool operator>(int num, const CRational& rational);
    bool operator<=(const CRational& other) const;
    bool operator<=(int num) const;
    friend bool operator<=(int num, const CRational& rational);
    bool operator>=(const CRational& other) const;
    bool operator>=(int num) const;
    friend bool operator>=(int num, const CRational& rational);
    // <<
    friend std::ostream& operator<<(std::ostream& os, const CRational& rational);
    // >>
    friend std::istream& operator>>(std::istream& is, CRational& rational);
private:
    int m_numerator, m_denominator;
    int FindGCD(int a, int b);
};