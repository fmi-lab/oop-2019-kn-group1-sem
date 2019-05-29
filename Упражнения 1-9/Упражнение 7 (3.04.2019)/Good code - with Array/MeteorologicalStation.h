#pragma once
#include"Array.h"
#include"Measurement.h"

// Good version
class MeteorologicalStation {
    Array<Measurement> measurements;

public:
    void add_measurement(double _measurement) {
        measurements.add_element(_measurement);
    }

    int get_number_of_measurements() const {
        return measurements.get_number_of_elements();
    }

    double operator [] (int i) const {
        return measurements[i];
    }

    double& operator [] (int i) {
        return measurements[i];
    }
};
