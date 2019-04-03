void add_element(double*& arr, int size, double element) {
    double* new_arr = new double[size + 1];

    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    new_arr[size] = element;
    delete[] arr;
    arr = new_arr;
}

void fast_add_element(double*& arr, int size, double element) {

    if (size % 10 == 0) {          // No memory, we need new memory

        double* new_arr = new double[size + 10];

        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        new_arr[size] = element;
        delete[] arr;
        arr = new_arr;
    }
    else {                              // There is memory
        arr[size] = element;
    }
}

void quick_add_element(double*& arr, int size, double element) {

    if (is_power_of_2(size)) {          // No memory, we need new memory

        double* new_arr = new double[size * 2];

        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        new_arr[size] = element;
        delete[] arr;
        arr = new_arr;
    }
    else {                              // There is memory
        arr[size] = element;
    }
}
