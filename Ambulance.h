#ifndef Ambulance_H
#define Ambulance_H

#include "Vehicle.h"

// Ambulance class inherits from Vehicle class
class Ambulance : public Vehicle {
protected:
    // Protected member variables specific to Ambulance
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double infrastructureLevy = 150000;

public:
    // Constructor for Ambulance class
    Ambulance(int Type, int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem)
        : Vehicle(Type, Age, costInsuranceFreight, plateSystem, transportationMode, parkingFee), stampDuty(stampDuty),
          formFees(formFees), exciseDuty(exciseDuty) {}

    // Destructor
    ~Ambulance() override = default;

    // Method to display details of the ambulance
    void getDetails() override;

    // Setter methods for vehicle type, plate system, and transportation mode
    void setvehicleType(int option);
    void setplateSystem(double option);
    void settransportationMode(double option);

    // Calculation methods for various fees
    double calculateInfrastructureLevyFee(int age, double costInsuranceFreight);
    double calculateTransportationModeFee(int transportationMode, double costInsuranceFreight);
    double calculateParkingFee(double daysinBond, double parkingFeePerDay);

    // Method to calculate the final price after applying all taxes and fees
    double getFinalPrice();

    // Additional method that could be overridden or implemented based on requirements
    void someMethod();
};

#endif