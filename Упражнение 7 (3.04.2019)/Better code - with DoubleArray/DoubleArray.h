#pragma once

class DoubleArray {
    double* arr;
    int number_of_elements;
    int capacity;

public:
    DoubleArray() {
        number_of_elements = 0;
        capacity = 16;
        arr = new double[capacity];
    }

    DoubleArray(const DoubleArray& other) {
        number_of_elements = other.number_of_elements;
        capacity = other.capacity;
        
        arr = new double[capacity];

        for (int i = 0; i < number_of_elements; i++) {
            arr[i] = other.arr[i];
        }
    }
    
    DoubleArray& operator=(const DoubleArray& other) {
        if(this != &other) {
            delete[] arr;
            
            number_of_elements = other.number_of_elements;
            capacity = other.capacity;
            
            arr = new double[capacity];
    
            for (int i = 0; i < number_of_elements; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    ~DoubleArray() {
        delete[] arr;
    }
    
    int get_number_of_elements() const {
        return number_of_elements;
    }

    void resize() {
        capacity *= 2;
        double* helper = new double[capacity];
        
        for(int i = 0; i < number_of_elements; i++) {
            helper[i] = arr[i];
        }
        
        delete[] arr;
        arr = helper;
    }

    void add_element(double element) {
        if (number_of_elements == capacity) {
            resize();
        }
        arr[number_of_elements] = element;
        number_of_elements++;
    }

    double operator [] (int i) const {
        return arr[i];
    }

    double& operator [] (int i) {
        return arr[i];
    }
};
