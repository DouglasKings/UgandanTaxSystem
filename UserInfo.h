// Header guard to prevent multiple inclusions of the same header file
#ifndef UserInfo_H
#define UserInfo_H

// Including necessary libraries and other header files
#include "Vehicle.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <limits>

// Forward declaration of classes that will be used later
#include "Ambulance.h"
#include "Estate.h"
#include "Sedan.h"
#include "SUV.h"
#include "Trailer.h"

// userInfo class definition inheriting from Vehicle class
class UserInfo : public Vehicle {
private:
    // Private member variables
    int vehicleType, Age; // Type of vehicle and age
    double costInsuranceFreight, plateSystem, transportationMode, parkingFee, engineCapacity, grossWeight; // Various costs and specifications

public:
    // Constructor for userInfo class
    UserInfo(int Type, int Age, double grossWeight, double engineCapacity, double seatingCapacity, double costInsuranceFreight, double plateSystem,
             int transportationMode, double daysInBond)
        : Vehicle(vehicleType, Age, costInsuranceFreight, plateSystem, transportationMode, parkingFee), // Initialize base class members
          engineCapacity(engineCapacity), grossWeight(grossWeight), // Initialize derived class members
          vehicleType(Type), Age(Age), costInsuranceFreight(costInsuranceFreight), plateSystem(plateSystem), transportationMode(transportationMode), parkingFee(parkingFee) {}

    // Method to display detailed information about the vehicle
    void Display(); 

      // Override the pure virtual function getDetails()
    void getDetails() override {
        std::cout << "Displaying UserInfo details..." << std::endl;
    }

}; // End of userInfo class definition

#endif // UserInfo_H