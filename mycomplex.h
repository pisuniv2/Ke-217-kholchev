#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_

#include <iostream>
using namespace std;

/**
 * @class Complex
 * @brief Класс для представления комплексных чисел.
 * 
 * Этот класс предоставляет операции для работы с комплексными числами, такие как
 * сложение, вычитание, умножение, деление, а также вычисление модуля числа.
 */
class Complex
{
private:
    double Re; ///< Вещественная часть комплексного числа
    double Im; ///< Мнимая часть комплексного числа
    
public:
    /**
     * @brief Конструктор комплексного числа.
     * @param aRe Вещественная часть (по умолчанию 0)
     * @param aIm Мнимая часть (по умолчанию 0)
     */
    Complex(double aRe=0, double aIm=0);

    /**
     * @brief Конструктор копирования.
     * @param other Объект комплексного числа для копирования.
     */
    Complex(const Complex& other);

    /**
     * @brief Деструктор для класса Complex.
     */
    ~Complex();

    /**
     * @brief Устанавливает значения для вещественной и мнимой части.
     * @param aRe Вещественная часть
     * @param aIm Мнимая часть (по умолчанию 0)
     */
    void Set(double aRe, double aIm=0);

    /**
     * @brief Преобразует объект Complex в тип double (модуль комплексного числа).
     * @return Модуль комплексного числа.
     */
    operator double();

    /**
     * @brief Вычисляет модуль комплексного числа.
     * @return Модуль комплексного числа.
     */
    double abs();

    /**
     * @brief Перегрузка оператора ввода для комплексного числа.
     * @param in Поток ввода.
     * @param c Объект комплексного числа.
     * @return Поток ввода.
     */
    friend istream& operator>>(istream& in, Complex& c);

    /**
     * @brief Перегрузка оператора вывода для комплексного числа.
     * @param out Поток вывода.
     * @param c Объект комплексного числа.
     * @return Поток вывода.
     */
    friend ostream& operator<<(ostream& out, Complex& c);

    /**
     * @brief Операция сложения комплексных чисел.
     * @param other Комплексное число для сложения.
     * @return Результат сложения.
     */
    Complex operator+(const Complex& other);

    /**
     * @brief Операция вычитания комплексных чисел.
     * @param other Комплексное число для вычитания.
     * @return Результат вычитания.
     */
    Complex operator-(const Complex& other);

    /**
     * @brief Операция сложения комплексного числа и вещественного числа.
     * @param value Вещественное число для сложения.
     * @return Результат сложения.
     */
    Complex operator+(const double& value);

    /**
     * @brief Операция сложения вещественного числа и комплексного числа.
     * @param value Вещественное число для сложения.
     * @param complex Комплексное число для сложения.
     * @return Результат сложения.
     */
    friend Complex operator+(const double& value, const Complex& complex);

    /**
     * @brief Операция вычитания вещественного числа из комплексного.
     * @param value Вещественное число для вычитания.
     * @return Результат вычитания.
     */
    Complex operator-(const double& value);

    /**
     * @brief Операция вычитания комплексного числа из вещественного.
     * @param value Вещественное число для вычитания.
     * @param complex Комплексное число для вычитания.
     * @return Результат вычитания.
     */
    friend Complex operator-(const double& value, const Complex& complex);

    /**
     * @brief Операция умножения двух комплексных чисел.
     * @param other Комплексное число для умножения.
     * @return Результат умножения.
     */
    Complex operator*(const Complex& other);

    /**
     * @brief Операция умножения комплексного числа на вещественное.
     * @param value Вещественное число для умножения.
     * @return Результат умножения.
     */
    Complex operator*(const double& value);

    /**
     * @brief Операция умножения вещественного числа на комплексное.
     * @param value Вещественное число для умножения.
     * @param complex Комплексное число для умножения.
     * @return Результат умножения.
     */
    friend Complex operator*(const double& value, const Complex& complex);

    /**
     * @brief Операция деления комплексного числа на вещественное.
     * @param value Вещественное число для деления.
     * @return Результат деления.
     */
    Complex operator/(const double& value);

    /**
     * @brief Операция присваивания для двух комплексных чисел.
     * @param other Комплексное число для присваивания.
     * @return Ссылка на текущий объект.
     */
    Complex& operator=(const Complex& other);

    /**
     * @brief Операция присваивания для комплексного числа и вещественного числа.
     * @param value Вещественное число для присваивания.
     * @return Ссылка на текущий объект.
     */
    Complex& operator=(const double& value);

    // Операторы для присваивания с операциями
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator+=(const double& value);
    Complex& operator-=(const double& value);
    Complex& operator*=(const double& value);
    Complex& operator/=(const double& value);
};

#endif
