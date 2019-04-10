#pragma once

template<typename T>
class Array {
    T* arr;
    int number_of_elements;
    int capacity;

public:
    Array() {
        number_of_elements = 0;
        capacity = 16;
        arr = new T[capacity];
    }

    Array(const Array& other) {
        number_of_elements = other.number_of_elements;
        capacity = other.capacity;
        
        arr = new T[capacity];

        for (int i = 0; i < number_of_elements; i++) {
            arr[i] = other.arr[i];
        }
    }
    
    Array& operator=(const Array& other) {
        if(this != &other) {
            delete[] arr;
            
            number_of_elements = other.number_of_elements;
            capacity = other.capacity;
            
            arr = new T[capacity];
    
            for (int i = 0; i < number_of_elements; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] arr;
    }
    
    int get_number_of_elements() const {
        return number_of_elements;
    }

    void resize() {
        capacity *= 2;
        T* helper = new T[capacity];
        
        for(int i = 0; i < number_of_elements; i++) {
            helper[i] = arr[i];
        }
        
        delete[] arr;
        arr = helper;
    }

    void add_element(T element) {
        if (number_of_elements == capacity) {
            resize();
        }
        arr[number_of_elements] = element;
        number_of_elements++;
    }

    T operator [] (int i) const {
        return arr[i];
    }

    T& operator [] (int i) {
        return arr[i];
    }
};
