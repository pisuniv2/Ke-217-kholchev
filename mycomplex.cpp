#pragma execution_character_set("utf-8")
#include <iostream>
#include <cmath>
#include "mycomplex.h"
#include <windows.h> // Для Windows и вывода в UTF-8

using namespace std;

/**
 * @brief Конструктор для создания комплексного числа.
 * @param aRe - действительная часть числа.
 * @param aIm - мнимая часть числа.
 */
Complex::Complex(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Конструктор копирования для комплексного числа.
 * @param aRval - исходное комплексное число.
 */
Complex::Complex(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
 * @brief Деструктор для комплексного числа.
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief Устанавливает новое значение для комплексного числа.
 * @param aRe - новая действительная часть.
 * @param aIm - новая мнимая часть.
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Преобразует комплексное число в тип double, возвращая его абсолютную величину.
 * @return Абсолютная величина комплексного числа.
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief Вычисляет абсолютное значение комплексного числа.
 * @return Абсолютная величина комплексного числа.
 */
double Complex::abs() {
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief Оператор сложения для двух комплексных чисел.
 * @param aRval - второе комплексное число для сложения.
 * @return Результат сложения двух комплексных чисел.
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief Оператор вычитания для двух комплексных чисел.
 * @param aRval - второе комплексное число для вычитания.
 * @return Результат вычитания двух комплексных чисел.
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief Оператор сложения комплексного числа и числа типа double.
 * @param aRval - число типа double для сложения.
 * @return Результат сложения комплексного числа и числа типа double.
 */
Complex Complex::operator+(const double& aRval) {
    Complex result;
    result.Re = Re + aRval;
    result.Im = Im;
    return result;
}

/**
 * @brief Оператор вычитания числа типа double из комплексного числа.
 * @param aRval - число типа double для вычитания.
 * @return Результат вычитания числа из комплексного числа.
 */
Complex Complex::operator-(const double& aRval) {
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

/**
 * @brief Оператор умножения двух комплексных чисел.
 * @param aRval - второе комплексное число для умножения.
 * @return Результат умножения двух комплексных чисел.
 */
Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
 * @brief Оператор умножения комплексного числа на число типа double.
 * @param aRval - число типа double для умножения.
 * @return Результат умножения комплексного числа на число типа double.
 */
Complex Complex::operator*(const double& aRval) {
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/**
 * @brief Оператор деления комплексного числа на число типа double.
 * @param aRval - число типа double для деления.
 * @return Результат деления комплексного числа на число типа double.
 */
Complex Complex::operator/(const double& aRval) {
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/**
 * @brief Оператор добавления для комплексных чисел (с присваиванием).
 * @param aRval - второе комплексное число для добавления.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
 * @brief Оператор вычитания для комплексных чисел (с присваиванием).
 * @param aRval - второе комплексное число для вычитания.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
 * @brief Оператор умножения для комплексных чисел (с присваиванием).
 * @param aRval - второе комплексное число для умножения.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
 * @brief Оператор добавления для комплексного числа и числа типа double (с присваиванием).
 * @param aRval - число типа double для добавления.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator+=(const double& aRval) {
    Re += aRval;
    return *this;
}

/**
 * @brief Оператор вычитания для комплексного числа и числа типа double (с присваиванием).
 * @param aRval - число типа double для вычитания.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator-=(const double& aRval) {
    Re -= aRval;
    return *this;
}

/**
 * @brief Оператор умножения для комплексного числа и числа типа double (с присваиванием).
 * @param aRval - число типа double для умножения.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator*=(const double& aRval) {
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/**
 * @brief Оператор деления для комплексного числа и числа типа double (с присваиванием).
 * @param aRval - число типа double для деления.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator/=(const double& aRval) {
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/**
 * @brief Оператор присваивания для комплексных чисел.
 * @param aRval - комплексное число, которое будет присвоено.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
 * @brief Оператор присваивания для комплексного числа и числа типа double.
 * @param aRval - число типа double, которое будет присвоено.
 * @return Ссылка на текущий объект.
 */
Complex& Complex::operator=(const double& aRval) {
    Re = aRval;
    Im = 0.0;
    return *this;
}

/**
 * @brief Оператор ввода для комплексного числа.
 * @param stream - поток ввода.
 * @param a - комплексное число, которое нужно считать.
 * @return Поток ввода.
