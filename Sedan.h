#ifndef Sedan_H
#define Sedan_H

#include "Vehicle.h"

// Sedan class derived from Vehicle base class
class Sedan : public Vehicle {
protected:
    // Protected member variables representing various taxes and fees applicable to sedans
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double infrastructureLevy = 150000;
    double importDuty = 0.25; 
    double valueAddedTax = 0.18; 
    double withholdingTax = 0.06;

public:
    // Constructor for Sedan objects, initializing base Vehicle properties and Sedan-specific properties
    Sedan(int Type, int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double plateSystem,
          double engineCapacity, double grossWeight)
        : Vehicle(Type, Age, costInsuranceFreight, plateSystem, transportationMode, parkingFee), stampDuty (stampDuty),
          formFees(formFees), exciseDuty(exciseDuty) {}

    // Destructor
    ~Sedan() override = default;

    // Method to override the getDetails method from the Vehicle base class
    void getDetails() override;

    // Methods to set various properties of the Sedan object
    void setvehicleType(int option);
    void setplateSystem(double option);
    void settransportationMode(double option);

    // Methods to calculate various fees based on input parameters
    double calculateImportDutyFee(double importDuty, double costInsuranceFreight);
    double calculateValueAddedTaxFee(double valueAddedTax, double costInsuranceFreight);
    double calculateWitholdingTaxFee(double witholdingTax, double costInsuranceFreight);
    double calculateInfrastructureLevyFee(int age, double costInsuranceFreight);
    double calculateGrossWeightFee(double grossWeight, double costInsuranceFreight);
    double calculateEngineCapacityFee(double costInsuranceFreight, double engineCapacity);
    double calculateParkingFee(double daysinBond, double parkingFeePerDay);

    // Method to calculate the final price after applying all taxes and fees
    double getFinalPrice(double importDuty, double costInsuranceFreight, int Age, double grossWeight, double engineCapacity, 
                            double daysinBond, double parkingFeePerDay, double stampDuty, double formFees, 
                            double exciseDuty, double transportationModeFee);

    // Placeholder method for future functionality
    void someMethod();
};

#endif