#include<iostream>
using namespace std;

class Shape {
public:
    virtual double get_area() const {
        return -1;
    }
};

class Square : public Shape {
    double a;

public:
    Square(double _a) {
        a = _a;
    }
    double get_area() const {
        return a*a;
    }
};

class Rectangle : public Shape {
    double a;
    double b;
    
public:
    Rectangle(double _a, double _b) {
        a = _a;
        b = _b;
    }
    double get_area() const {
        return a*b;
    }
};

class Circle : public Shape {
    double r;

public:
    Circle(double _r) {
        r = _r;
    }
    double get_area() const {
        return 3.14*r*r;
    }
};

int main() {
    Square square(11);
    Rectangle rectangle(20, 4);
    Circle circle(10);
    
    Shape* shapes[3] = { &square, &rectangle, &circle };

    for (int i = 0; i < 3; i++) {
        cout << shapes[i]->get_area() << ' ';
    }
    expect("121 80 314");
}
