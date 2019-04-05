#pragma once

// Bad version
class MeteorologicalStation {
    double* measurements;
    int number_of_measurements;
    int capacity_of_measurements;

public:
    MeteorologicalStation() {
        number_of_measurements = 0;
        capacity_of_measurements = 16;
        measurements = new double[capacity_of_measurements];
    }

    MeteorologicalStation(const MeteorologicalStation& other) {
        number_of_measurements = other.number_of_measurements;
        capacity_of_measurements = other.capacity_of_measurements;
        
        measurements = new double[capacity_of_measurements];

        for (int i = 0; i < number_of_measurements; i++) {
            measurements[i] = other.measurements[i];
        }
    }
    
    MeteorologicalStation& operator=(const MeteorologicalStation& other) {
        if(this != &other) {
            delete[] measurements;
            
            number_of_measurements = other.number_of_measurements;
            capacity_of_measurements = other.capacity_of_measurements;
            
            measurements = new double[capacity_of_measurements];
    
            for (int i = 0; i < number_of_measurements; i++) {
                measurements[i] = other.measurements[i];
            }
        }
        return *this;
    }

    ~MeteorologicalStation() {
        delete[] measurements;
    }
    
    int get_number_of_measurements() const {
        return number_of_measurements;
    }

    void resize() {
        capacity_of_measurements *= 2;
        double* helper = new double[capacity_of_measurements];
        
        for(int i = 0; i < number_of_measurements; i++) {
            helper[i] = measurements[i];
        }
        
        delete[] measurements;
        measurements = helper;
    }

    void add_measurement(double _measurement) {
        if (number_of_measurements == capacity_of_measurements) {
            resize();
        }
        measurements[number_of_measurements] = _measurement;
        number_of_measurements++;
    }

    double operator [] (int i) const {
        return measurements[i];
    }

    double& operator [] (int i) {
        return measurements[i];
    }
};
