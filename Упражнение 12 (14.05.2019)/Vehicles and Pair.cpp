#include<iostream>
using namespace std;

class Vehicle {
public:
    virtual double get_speed() = 0;
};

class Bicycle : public Vehicle {
public:
    double get_speed() {
        return 20;
    }
    double distance_for_time(int t) {
        return t * get_speed();
    }
};

class Car : public Vehicle {
    double speed;
public:
    void set_speed(double _speed) {
        speed = _speed;
    }

    double get_speed() {
        return speed;
    }
};

template<typename T>
class Pair {
    T first;
    T second;

public:
    void set_first(const T& _first) {
        first = _first;
    }
    void set_second(const T& _second) {
        second = _second;
    }

    T get_first() const {
        return first;
    }
    T get_second() const {
        return second;
    }
};

template<typename T>
void reverse_pairs(Pair<T>* pairs, int n) {
    for (int i = 0; i < n; i++) {
        T old_first = pairs[i].get_first();
        T old_second = pairs[i].get_second();
        pairs[i].set_first(old_second);
        pairs[i].set_second(old_first);
    }
}

int main() {
    Bicycle bike;

    Car car;
    car.set_speed(70);

    Vehicle* arr[10];
    arr[0] = &bike;
    arr[1] = &car;

    cout << arr[0]->get_speed() << endl;    // 20
    cout << arr[1]->get_speed() << endl;    // 70

    ////////////////////////////////////

    Pair<int> pairs[10];
    
    pairs[0].set_first(11);
    pairs[0].set_second(12);

    pairs[1].set_first(13);
    pairs[1].set_second(14);

    reverse_pairs(pairs, 2);

    cout << pairs[0].get_first() << endl;       // 12
    cout << pairs[0].get_second() << endl;      // 11

    cout << pairs[1].get_first() << endl;       // 14
    cout << pairs[1].get_second() << endl;      // 13
}
