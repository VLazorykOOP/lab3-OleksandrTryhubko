#include <cmath>
#include <iostream>
#include <string>
using namespace std;
/*
Створити клас типу – ромб ( поля : сторона, діагональ, колір). У класі визначити
o конструктори ( не менше двох);
o функції-члени обчислення площі, периметру;
o функції-члени встановлення значення сторони, діагоналі та кольору, функції
встановлення полів класу повинні перевіряти коректність параметрів, що
задаються; o функції-члени що повертають значення полів; o функцію друку.
Написати програму тестування всіх можливостей цього класу.
*/

class Romb {
private:
    double side;
    double diagonal;
    std::string color;

public:
    Romb() {
        this->side = 0;
        this->diagonal = 0;
        this->color = "No color";
    }
    Romb(double side) {
        set_side(side);
        this->diagonal = 0;
        this->color = "No color";
    }
    Romb(double side, double diagonal) {
        set_side(side);
        set_diagonal(diagonal);
        this->color = "No color";
    }
    Romb(double side, double diagonal, std::string color) {
        set_side(side);
        set_diagonal(diagonal);
        set_color(color);
    }
    void set_side(double side) {
        if (side <= 0) {
            cout << "Side must be positive number";
        }
        this->side = side;
    }

    void set_diagonal(double diagonal) {
        if (diagonal <= 0) {
            cout << "Diagonal must be positive number";
        }
        this->diagonal = diagonal;
    }
    void set_color(std::string color) { this->color = color; }
    double get_side() { return side; }
    double get_diagonal() { return diagonal; }
    std::string get_color() { return color; }
    double area() const {
        return 0.5 * diagonal * sqrt(pow(diagonal / 2, 2) - pow(side / 2, 2));
    }
    int perimeter() const { return 4 * side; }
    void print() {
        std::cout << "Side: " << side << std::endl;
        std::cout << "Diagonal: " << diagonal << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
    }
};

void exercise1() {
    Romb r1(2, 3, "red");
    r1.print();
    std::cout << std::endl;

    Romb r2;
    r2.set_side(5);
    r2.set_diagonal(7);
    r2.set_color("blue");
    r2.print();
    std::cout << std::endl;
}

/*
Створити тип даних - клас вектор, який має поля x, y та z типу float і змінну
стану. У класі визначити

o конструктор без параметрів(інінціалізує поля в нуль);
o конструктор з одним параметром типу float (інінціалізує поля x, y та z
значенням параметру);
o конструктор з одним параметром вказівник на тип (інінціалізує поля x, y та z
значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити
код помилки);
o деструктор із виведенням інформації про стан вектора;
o визначити функцію, яка присвоює полю x, y або z деяке значення (параметр за
замовчуванням);
o функцію яка одержує деякий елемент з полів x, y та z;
o конструктор копій та операцію присвоєння; // !!!
o визначити функції друку, додавання, віднімання, векторний добуток які
здійснюють ці арифметичні операції з даними цього класу;
o функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не
виконувати);
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.*/

enum STATE { OK, BAD_INIT, BAD_DIV };

class Vector {
    double x, y, z;
    int state = OK;

public:
    Vector() {
        x = 0;
        y = 0;
        z = 0;
    }
    Vector(int value) {
        x = value;
        y = value;
        z = value;
    }

    Vector(Vector& v) {
        if (&v == nullptr) {
            state = BAD_INIT;
        }
        x = v.x;
        y = v.y;
        z = v.z;
        state = v.state;
    }

    ~Vector() {}

    void setValue(int value) {
        x = value;
        y = value;
        z = value;
    }

    double returnX() { return x; }
    double returnY() { return y; }
    double returnZ() { return z; }

    void print() { cout << "X = " << x << " Y = " << y << " Z = " << z << endl; };

    Vector(const Vector& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        state = other.state;
    }
    Vector& operator=(const Vector& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        state = other.state;
        return *this;
    }

    Vector operator+(const Vector& other) const {
        Vector result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        return result;
    }

    Vector operator-(const Vector& other) const {
        Vector result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        return result;
    }

    Vector operator*(const Vector& other) {
        Vector result;
        result.x = y * other.z - z * other.y;
        result.y = z * other.x - x * other.z;
        result.z = x * other.y - y * other.x;
        return result;
    }

    void division(short value) {
        if (value == 0) {
            state = BAD_DIV;
        }
        else {
            x = x / value;
            y = y / value;
            z = z / value;
        }
    }

    Vector operator==(const Vector& other) {
        if (x != other.x || y != other.y || z != other.z) {
            return false;
        }
        return true;
    }

    Vector operator<(const Vector& other) {
        if (x > other.x || y > other.y || z > other.z) {
            return false;
        }
        return true;
    }

    Vector operator>(const Vector& other) {
        if (x < other.x || y < other.y || z < other.z) {
            return false;
        }
        return true;
    }
};

void exercise2() {
    Vector v1;
    Vector v2(3), v3;
    cout << "Vector v1 set value 2 ";
    v1.setValue(2);
    cout << "Vector v1 ";
    v1.print();
    cout << "Vector v2 ";
    v2.print();
    cout << "Vector v3 = v1+v2 ";
    v3 = v2 + v1;
    v3.print();
    cout << "Vector v3 = v1-v2 ";
    v3 = v2 - v1;
    v3.print();
}

void ShowTaskMenu() {
    cout << "Exersices" << endl;
    cout << "1. Task 1" << endl;
    cout << "2. Task 2" << endl;
}

int main() {
    bool isSelected = false;
    while (!isSelected) {
        system("cls");
        ShowTaskMenu();
        int ch;
        cin >> ch;
        switch (ch) {
        case 1:
            exercise1();
            isSelected = true;
            break;
        case 2:
            exercise2();
            isSelected = true;
            break;
        default:
            break;
        }
    }
    return 0;
}