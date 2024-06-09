#ifndef Trailer_H
#define Trailer_H

#include "Vehicle.h"

class Trailer : public Vehicle {
protected:
    double stampDuty = 35000; 
    double formFees = 20000;
    double exciseDuty = 200000;
    double infrastructureLevy = 150000;
    double importDuty = 0.25; 
    double valueAddedTax = 0.18; 
    double withholdingTax = 0.06;

public:
    Trailer(int Type, int Age, double costInsuranceFreight, double transportationMode, double daysInBond, double seatingCapacity,
                            double engineCapacity, double grossWeight, double plateSystem)
        : Vehicle(Type, Age, costInsuranceFreight, plateSystem, transportationMode, parkingFee), stampDuty (stampDuty ),
          formFees(formFees), exciseDuty(exciseDuty), importDuty(importDuty), valueAddedTax(valueAddedTax), withholdingTax(withholdingTax), infrastructureLevy(infrastructureLevy) 
 {}

    ~Trailer() override = default;

    void getDetails() override;

    void setvehicleType(int option);

    void setplateSystem(double option);

    void settransportationMode(double option);

    double calculateImportDutyFee(double importDuty, double costInsuranceFreight);

    double calculateValueAddedTaxFee(double valueAddedTax, double costInsuranceFreight);

    double calculateWitholdingTaxFee(double witholdingTax, double costInsuranceFreight);

    double calculateInfrastructureLevyFee(int age, double costInsuranceFreight);

    double calculateGrossWeightFee(double grossWeight, double costInsuranceFreight);

    double calculateEngineCapacityFee(double costInsuranceFreight, double engineCapacity);

    double calculateParkingFee(double daysinBond, double parkingFeePerDay);

    double getFinalPrice();

    void someMethod();
};

#endif

 
