#pragma execution_character_set("utf-8")
#include <iostream>
#include <cmath>
#include "mycomplex.h"
#include <windows.h> // ��� Windows � ������ � UTF-8

using namespace std;

/**
 * @brief ����������� ��� �������� ������������ �����.
 * @param aRe - �������������� ����� �����.
 * @param aIm - ������ ����� �����.
 */
Complex::Complex(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief ����������� ����������� ��� ������������ �����.
 * @param aRval - �������� ����������� �����.
 */
Complex::Complex(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
 * @brief ���������� ��� ������������ �����.
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief ������������� ����� �������� ��� ������������ �����.
 * @param aRe - ����� �������������� �����.
 * @param aIm - ����� ������ �����.
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief ����������� ����������� ����� � ��� double, ��������� ��� ���������� ��������.
 * @return ���������� �������� ������������ �����.
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief ��������� ���������� �������� ������������ �����.
 * @return ���������� �������� ������������ �����.
 */
double Complex::abs() {
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief �������� �������� ��� ���� ����������� �����.
 * @param aRval - ������ ����������� ����� ��� ��������.
 * @return ��������� �������� ���� ����������� �����.
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief �������� ��������� ��� ���� ����������� �����.
 * @param aRval - ������ ����������� ����� ��� ���������.
 * @return ��������� ��������� ���� ����������� �����.
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief �������� �������� ������������ ����� � ����� ���� double.
 * @param aRval - ����� ���� double ��� ��������.
 * @return ��������� �������� ������������ ����� � ����� ���� double.
 */
Complex Complex::operator+(const double& aRval) {
    Complex result;
    result.Re = Re + aRval;
    result.Im = Im;
    return result;
}

/**
 * @brief �������� ��������� ����� ���� double �� ������������ �����.
 * @param aRval - ����� ���� double ��� ���������.
 * @return ��������� ��������� ����� �� ������������ �����.
 */
Complex Complex::operator-(const double& aRval) {
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

/**
 * @brief �������� ��������� ���� ����������� �����.
 * @param aRval - ������ ����������� ����� ��� ���������.
 * @return ��������� ��������� ���� ����������� �����.
 */
Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
 * @brief �������� ��������� ������������ ����� �� ����� ���� double.
 * @param aRval - ����� ���� double ��� ���������.
 * @return ��������� ��������� ������������ ����� �� ����� ���� double.
 */
Complex Complex::operator*(const double& aRval) {
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/**
 * @brief �������� ������� ������������ ����� �� ����� ���� double.
 * @param aRval - ����� ���� double ��� �������.
 * @return ��������� ������� ������������ ����� �� ����� ���� double.
 */
Complex Complex::operator/(const double& aRval) {
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/**
 * @brief �������� ���������� ��� ����������� ����� (� �������������).
 * @param aRval - ������ ����������� ����� ��� ����������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
 * @brief �������� ��������� ��� ����������� ����� (� �������������).
 * @param aRval - ������ ����������� ����� ��� ���������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
 * @brief �������� ��������� ��� ����������� ����� (� �������������).
 * @param aRval - ������ ����������� ����� ��� ���������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
 * @brief �������� ���������� ��� ������������ ����� � ����� ���� double (� �������������).
 * @param aRval - ����� ���� double ��� ����������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator+=(const double& aRval) {
    Re += aRval;
    return *this;
}

/**
 * @brief �������� ��������� ��� ������������ ����� � ����� ���� double (� �������������).
 * @param aRval - ����� ���� double ��� ���������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator-=(const double& aRval) {
    Re -= aRval;
    return *this;
}

/**
 * @brief �������� ��������� ��� ������������ ����� � ����� ���� double (� �������������).
 * @param aRval - ����� ���� double ��� ���������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator*=(const double& aRval) {
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/**
 * @brief �������� ������� ��� ������������ ����� � ����� ���� double (� �������������).
 * @param aRval - ����� ���� double ��� �������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator/=(const double& aRval) {
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/**
 * @brief �������� ������������ ��� ����������� �����.
 * @param aRval - ����������� �����, ������� ����� ���������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
 * @brief �������� ������������ ��� ������������ ����� � ����� ���� double.
 * @param aRval - ����� ���� double, ������� ����� ���������.
 * @return ������ �� ������� ������.
 */
Complex& Complex::operator=(const double& aRval) {
    Re = aRval;
    Im = 0.0;
    return *this;
}

/**
 * @brief �������� ����� ��� ������������ �����.
 * @param stream - ����� �����.
 * @param a - ����������� �����, ������� ����� �������.
 * @return ����� �����.
