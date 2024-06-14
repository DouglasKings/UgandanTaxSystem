#ifndef Vehicle_H
#define Vehicle_H

// Includes necessary libraries for I/O operations, string manipulation, and container types
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>

// Defines the Vehicle class
class Vehicle{
protected:
    // Protected member variables representing different attributes of a vehicle
    int vehicleType, Age; // Type of vehicle and its age
    double costInsuranceFreight, plateSystem, transportationMode, parkingFee; // Various costs and modes associated with vehicles

public:
    // Constructor for the Vehicle class, initializing member variables
    Vehicle(int Type, int Age, double costInsuranceFreight, double plateSystem, double transportationMode, double parkingFee)
        : vehicleType(Type), Age(Age), costInsuranceFreight(costInsuranceFreight), plateSystem(plateSystem), transportationMode(transportationMode), parkingFee(parkingFee){}

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Vehicle() = default;

    // Pure virtual method for getting details about the vehicle
    virtual void getDetails() = 0;

    // Method to set the type of vehicle, throwing an exception if an invalid option is chosen
    void setvehicleType(int option) {
        if (option >= 1 && option <= 5) { // Ensuring valid range
           vehicleType = option;
        } else {
            throw std::invalid_argument("Invalid option. Please choose between 1 to 5.");
        }
    }

    // Methods to set other attributes of the vehicle, similar to setvehicleType but with specific options
    void setplateSystem(double option) {
        if (option == 1 || option == 2) {
            plateSystem = option;
        } else {
            throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
        }
    }

    void settransportationMode(double option) {
        if (option == 1 || option == 2) {
           transportationMode = option;
        } else {
            throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
        }
    }

    // Friend function to display details of a vehicle object
    friend void Display(const Vehicle& vehicle);
};

#endif