#ifndef Ambulance_H
#define Ambulance_H

#include "Vehicle.h"

// Defining the Ambulance class that inherits from the Vehicle class
class Ambulance : public Vehicle {
protected:
    // Declaring protected member variables specific to Ambulance
    double stampDuty = 35000; // Stamp duty amount
    double formFees = 20000; // Form fees amount
    double exciseDuty = 200000; // Excise duty amount
    double infrastructureLevy = 150000; // Infrastructure levy amount

public:
    // Constructor for the Ambulance class
    // Initializes base Vehicle properties and Ambulance-specific properties
    Ambulance(int Type, int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem)
        : Vehicle(Type, Age, costInsuranceFreight, plateSystem, transportationMode, parkingFee), // Initialize base Vehicle properties
          stampDuty(stampDuty), // Initialize stamp duty
          formFees(formFees), // Initialize form fees
          exciseDuty(exciseDuty) {} // Initialize excise duty

    // Destructor for the Ambulance class
    // Default destructor since we don't need to perform any special cleanup
    ~Ambulance() override = default;

    // Method to display details of the ambulance
    // Override method from the Vehicle class to display ambulance-specific details
    void getDetails() override;

    // Setter methods for vehicle type, plate system, and transportation mode
    // These methods allow setting the values of these properties after object creation
    void setvehicleType(int option);
    void setplateSystem(double option);
    void settransportationMode(double option);

    // Calculation methods for various fees
    // These methods calculate specific fees based on given parameters
    double calculateInfrastructureLevyFee(int age, double costInsuranceFreight);
    double calculateTransportationModeFee(int transportationMode, double costInsuranceFreight);
    double calculateParkingFee(double daysinBond, double parkingFeePerDay);

    // Method to calculate the final price after applying all taxes and fees
    // This method calculates the total cost including all applicable fees and taxes
    double getFinalPrice();
};

#endif
