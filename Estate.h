// Header file for the Estate class, which inherits from the Vehicle class.
#ifndef Estate_H
#define Estate_H

#include "Vehicle.h" // Include the base Vehicle class header file.

class Estate : public Vehicle { // Define the Estate class that extends Vehicle.
protected:
    double stampDuty = 35000; // Stamp Duty amount.
    double formFees = 20000; // Form Fees amount.
    double exciseDuty = 200000; // Excise Duty amount.
    double infrastructureLevy = 150000; // Infrastructure Levy amount.
    double importDuty = 0.25; // Import Duty rate.
    double valueAddedTax = 0.18; // Value Added Tax rate.
    double withholdingTax = 0.06; // Withholding Tax rate.

public:
    // Constructor for the Estate class, initializing member variables.
    Estate(int Type, int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double seatingCapacity,
           double engineCapacity, double grossWeight, double plateSystem)
        : Vehicle(Type, Age, costInsuranceFreight, plateSystem, transportationMode, parkingFee), stampDuty(stampDuty),
          formFees(formFees), exciseDuty(exciseDuty), importDuty(importDuty), valueAddedTax(valueAddedTax), withholdingTax(withholdingTax), infrastructureLevy(infrastructureLevy) 
    {}

    // Destructor for the Estate class.
    ~Estate() override = default;

    // Method to override the getDetails method from the Vehicle class.
    void getDetails() override;

    // Methods to set various properties of the Estate vehicle.
    void setvehicleType(int option);
    void setplateSystem(double option);
    void settransportationMode(double option);

    // Methods to calculate various taxes and fees based on the Estate vehicle's specifications.
    double calculateImportDutyFee(double importDuty, double costInsuranceFreight);
    double calculateValueAddedTaxFee(double valueAddedTax, double costInsuranceFreight);
    double calculateWitholdingTaxFee(double witholdingTax, double costInsuranceFreight);
    double calculateInfrastructureLevyFee(int age, double costInsuranceFreight);
    double calculateSeatingCapacityFee(double seatingCapacity);
    double calculateGrossWeightFee(double grossWeight, double costInsuranceFreight);
    double calculateEngineCapacityFee(double costInsuranceFreight, double engineCapacity);
    double calculateParkingFee(double daysinBond, double parkingFeePerDay);

    // Method to calculate the final price of the Estate vehicle after applying all taxes and fees.
    double getFinalPrice();

    // Additional method for demonstration purposes.
    void someMethod();
};

#endif // Estate_H