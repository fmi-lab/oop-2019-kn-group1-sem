#pragma once
#include"String.h"
#include"MeteorologicalStation.h"

// Bad version
class Student {
    String name;
    MeteorologicalStation grades;

public:
    void add_grade(double _grade) {
        grades.add_measurement(_grade);
    }

    int get_number_of_grades() const {
        return grades.get_number_of_measurements();
    }
    
    double operator [] (int i) const {
        return grades[i];
    }

    double& operator [] (int i) {
        return grades[i];
    }
};
