#include <iostream>

using namespace std;

class Complex
{
    // Поля класса (должны быть private)
    double re, im;
public:
    // Конструкторы. Называются так же, как и класс. Не имеют типа возвращаемого результата
    Complex(double x, double y);
    Complex();
    // Методы для получения полей класса извне. Для примера реализованы прямо здесь же.
    double get_re() { return re; }
    double get_im() { return im; }
    // Методы для изменения полей класса извне
    void set_re(double x) { re = x; }
    void set_im(double y) { im = y; }
    // Операторы сложения и умножения двух комплексных чисел, умножения на double
    Complex operator+(Complex);
    Complex operator*(Complex);
    Complex operator*(double);
    // Простейший метод для вывода на экран
    void print() { cout << re << " + " << im << "i"; }
    // Метод для более удобного вывода на экран, через оператор <<
    friend ostream& operator<<(ostream&, const Complex&);
};

// Начало реализации методов класса.
// Ко всем именам функций добавляется указание на то, что эта функция - из класса Complex.
Complex::Complex(double x, double y)
{
    re = x;
    im = y;
}

Complex::Complex()
{
    re = 0;
    im = 0;
}

Complex Complex::operator+(Complex a)
{
    return Complex(re + a.re, im + a.im);
}

Complex Complex::operator*(Complex a)
{
    return Complex(re * a.re - im * a.im, re * a.im + im * a.re);
}

Complex Complex::operator*(double a)
{
    return Complex(re * a, im * a);
}

ostream& operator<<(ostream& out, const Complex& a)
{
    return out << a.re << " + " << a.im << "i";
}

int main()
{
    double re, im;
    cout << "Input real and imagine parts of a complex number: ";
    cin >> re >> im;
    Complex a(re, im);
    cout << "Input real and imagine parts of another one complex number: ";
    cin >> re >> im;
    Complex b(re, im);
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;
    cout << "Sum of numbers: " << a + b << endl;
    cout << "Product of numbers: " << a * b << endl;
    // Вывод без использования оператора <<
    cout << "First number multiplied by 10: ";
    (a * 10).print();
}