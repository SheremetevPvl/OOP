#include "../Rational/CRational.h"
#include <iostream>
#include <stdexcept>

CRational::CRational() 
	: m_numerator(0)
	, m_denominator(1) 
{};

CRational::CRational(int value)
	: m_numerator(value)
	, m_denominator(1)
{};

int CRational::FindGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }  
    return FindGCD(b, a % b);
}

CRational::CRational(int numerator, int denominator) {
    if (denominator == 0) 
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    int gcd = FindGCD(numerator, denominator);
    m_numerator = numerator / gcd;
    m_denominator = denominator / gcd;
    if (m_denominator < 0) 
    {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
}

int CRational::GetNumerator() const
{
    return m_numerator;
}

int CRational::GetDenominator() const
{
    return m_denominator;
}

double CRational::ToDouble() const 
{
    return static_cast<double>(m_numerator) / m_denominator;
}

void CRational::ChangeSign()
{
    m_numerator = m_numerator * (-1);
}

//Бинарный плюс
CRational CRational::operator+(const CRational& other) const       //использовать gcd для нахождения НОД
{
    int numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
    int denominator = m_denominator * other.m_denominator;
    return CRational(numerator, denominator);
}

CRational CRational::operator+(int num) const 
{
    return *this + CRational(num, 1);
}

CRational operator+(int num, const CRational& rational) 
{
    return rational + num;
}

//Бинарный минус
CRational CRational::operator-(const CRational& other) const    //также как и бинарном плюсе
{
    int numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
    int denominator = m_denominator * other.m_denominator;
    return CRational(numerator, denominator);
}

CRational CRational::operator-(int num) const 
{
    return *this - CRational(num, 1);
}

CRational operator-(int num, const CRational& rational) 
{
    return CRational(num, 1) - rational;
}

// +=
CRational& CRational::operator+=(const CRational& other)
{
    m_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
    m_denominator = m_denominator * other.m_denominator;
    int gcd = FindGCD(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
    return *this;
}

CRational& CRational::operator+=(int num) {
    *this += CRational(num, 1);
    return *this;
}

// -=
CRational& CRational::operator-=(const CRational& other)
{
    m_numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
    m_denominator = m_denominator * other.m_denominator;
    int gcd = FindGCD(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
    return *this;
}

CRational& CRational::operator-=(int num) 
{
    *this -= CRational(num, 1);
    return *this;
}

//*
CRational CRational::operator*(const CRational& other) const 
{
    int numerator = m_numerator * other.m_numerator;
    int denominator = m_denominator * other.m_denominator;
    return CRational(numerator, denominator);
}

CRational CRational::operator*(int num) const 
{
    return *this * CRational(num, 1);
}

CRational operator*(int num, const CRational& rational) 
{
    return rational * num;
}

//частное двух чисел
CRational CRational::operator/(const CRational& other) const 
{
    int numerator = m_numerator * other.m_denominator;
    int denominator = m_denominator * other.m_numerator;
    return CRational(numerator, denominator);
}

CRational CRational::operator/(int num) const 
{
    return *this / CRational(num, 1);
}

CRational operator/(int num, const CRational& rational) 
{
    return CRational(num, 1) / rational;
}

// *=
CRational& CRational::operator*=(const CRational& other)
{
    m_numerator = m_numerator * other.m_numerator;
    m_denominator = m_denominator * other.m_denominator;
    int gcd = FindGCD(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
    return *this;
}

CRational& CRational::operator*=(int num)
{
    *this *= CRational(num, 1);
    return *this;
}

// /=
CRational& CRational::operator/=(const CRational& other)
{
    if (m_denominator * other.m_numerator == 0)
    {
        throw std::invalid_argument("Div on zero");
    }
    m_numerator = m_numerator * other.m_denominator;
    m_denominator = m_denominator * other.m_numerator;
    int gcd = FindGCD(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
    return *this;
}

CRational& CRational::operator/=(int num)
{
    *this /= CRational(num, 1);
    return *this;
}

//== и !=
bool CRational::operator==(const CRational& other) const
{
    return (m_numerator == other.m_numerator && m_denominator == other.m_denominator);
}

bool CRational::operator==(int num) const
{
    return *this == CRational(num, 1);
}

bool operator==(int num, const CRational& rational)
{
    return rational == num;
}

bool CRational::operator!=(const CRational& other) const
{
    bool res = *this == other;
    return !res;
}

bool CRational::operator!=(int num) const
{
    return *this != CRational(num, 1);
}

bool operator!=(int num, const CRational& rational)
{
    return rational != num;
}

//<, <=, >, >=
bool CRational::operator<(const CRational& other) const
{
    int fisrtNumNumerator = m_numerator * other.m_denominator;
    int secNumNumerator = other.m_numerator * m_denominator;
    return (fisrtNumNumerator < secNumNumerator);
}

bool CRational::operator<(int num) const
{
    return *this < CRational(num, 1);
}

bool operator<(int num, const CRational& rational)
{
    return CRational(num, 1) < rational;
}

bool CRational::operator>(const CRational& other) const
{
    int fisrtNumNumerator = m_numerator * other.m_denominator;
    int secNumNumerator = other.m_numerator * m_denominator;
    return (fisrtNumNumerator > secNumNumerator);
}

bool CRational::operator>(int num) const
{
    return *this > CRational(num, 1);
}

bool operator>(int num, const CRational& rational)
{
    return CRational(num, 1) > rational;
}

bool CRational::operator>=(const CRational& other) const
{
    bool res = *this > other || *this == other;
    return (res);
}

bool CRational::operator>=(int num) const
{
    return *this >= CRational(num, 1);
}

bool operator>=(int num, const CRational& rational)
{
    return CRational(num, 1) >= rational;
}

bool CRational::operator<=(const CRational& other) const
{
    bool res = *this < other || *this == other;
    return (res);
}

bool CRational::operator<=(int num) const
{
    return *this <= CRational(num, 1);
}

bool operator<=(int num, const CRational& rational)
{
    return CRational(num, 1) >= rational;
}

//<<
std::ostream& operator<<(std::ostream& os, const CRational& rational) 
{
    os << rational.m_numerator << "/" << rational.m_denominator;
    return os;
}

// >>
std::istream& operator>>(std::istream& is, CRational& rational) {
    char slash;
    int numerator, denominator;
    is >> numerator >> slash >> denominator;
    int gcd = rational.FindGCD(numerator, denominator);
    rational.m_numerator = numerator / gcd;
    rational.m_denominator = denominator / gcd;
    return is;
}
