#include <iostream>
#include "Sedan.h"

// Sets the vehicle type within valid options
void Sedan::setvehicleType(int option) {
    if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5) {
        vehicleType = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose between 1 to 5.");
    }        
}

// Sets the plate system within valid options
void Sedan::setplateSystem(double option) {
    if (option == 1 || option == 2) {
        plateSystem = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
    }
}

// Sets the transportation mode within valid options
void Sedan::settransportationMode(double option) {
    if (option == 1 || option == 2) {
        transportationMode = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
    }
}

// Calculates the import duty fee based on the given parameters
double Sedan::calculateImportDutyFee(double importDuty, double costInsuranceFreight) {
    return importDuty * costInsuranceFreight;                        
}

// Calculates the value-added tax fee based on the given parameters
double Sedan::calculateValueAddedTaxFee(double valueAddedTax, double costInsuranceFreight) {
    return valueAddedTax * costInsuranceFreight;               
}

// Calculates the withholding tax fee based on the given parameters
double Sedan::calculateWitholdingTaxFee(double witholdingTax, double costInsuranceFreight) {
    return witholdingTax * costInsuranceFreight;             
}

// Calculates the infrastructure levy fee based on the vehicle's age
double Sedan::calculateInfrastructureLevyFee(int age, double costInsuranceFreight){
    if (age > 15) {
        std::cout << "Sedans older than 15 years cannot be imported into the country.\n";
        return 0; // Early return if the sedan is too old
    } else if (age > 1 && age <= 5){
        return 150000 + costInsuranceFreight * 0.01;
    } else if(age > 5 && age <= 10){
        return 150000 + costInsuranceFreight * 0.05;
    } else if(age > 10){
        return 0.15 * costInsuranceFreight;
    } else {
        return 0;
    }
}

// Calculates the gross weight fee based on the vehicle's gross weight
double Sedan::calculateGrossWeightFee(double grossWeight, double costInsuranceFreight){
    if(grossWeight >= 1500 && grossWeight <= 2000){
        return 0.10 * costInsuranceFreight;
    }else if(grossWeight > 2000){
        return 0.15 * costInsuranceFreight;
    }else{
        return costInsuranceFreight * 0.02;
    }
}

// Calculates the engine capacity fee based on the vehicle's engine capacity
double Sedan::calculateEngineCapacityFee(double engineCapacity, double costInsuranceFreight){
    if(engineCapacity > 2000){
        return 0.10 * costInsuranceFreight;
    }else if(engineCapacity >= 1500 && engineCapacity <= 2000){
        return 0.05 * costInsuranceFreight;
    }else{
        return 0.025 * costInsuranceFreight;
    }
}

// Calculates the parking fee based on the number of days in bond and daily parking fee per day
double Sedan::calculateParkingFee(double daysinBond, double parkingFeePerDay) {
    return daysinBond * parkingFeePerDay;
}

// Calculates the final price after applying all taxes and fees
double Sedan::getFinalPrice(double importDuty, double costInsuranceFreight, int Age, double grossWeight, double engineCapacity, 
                            double daysinBond, double parkingFeePerDay, double stampDuty, double formFees, 
                            double exciseDuty, double transportationModeFee) {
    double importDutyFee = calculateImportDutyFee(importDuty, costInsuranceFreight);
    double valueAddedTaxFee = calculateValueAddedTaxFee(valueAddedTax, costInsuranceFreight); // Assuming valueAddedTax is defined elsewhere
    double witholdingTaxFee = calculateWitholdingTaxFee(withholdingTax, costInsuranceFreight); // Assuming witholdingTax is defined elsewhere
    double infrastructureLevyFee = calculateInfrastructureLevyFee(Age, costInsuranceFreight);
    double grossWeightFee = calculateGrossWeightFee(grossWeight, costInsuranceFreight);
    double engineCapacityFee = calculateEngineCapacityFee(engineCapacity, costInsuranceFreight);
    double parkingFee = calculateParkingFee(daysinBond, parkingFeePerDay);

    double totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + grossWeightFee + engineCapacityFee +
                        stampDuty + formFees + exciseDuty + plateSystem + infrastructureLevyFee + transportationModeFee + parkingFee;

    return totalTaxes;
}

// Method to display detailed information about the sedan
void Sedan::getDetails() {
    double infrastructureLevyFee, transportationModeFee, importDutyFee, valueAddedTaxFee, witholdingTaxFee, grossWeightFee,
           engineCapacityFee, totalTaxes;

    printf("Estate\n");
    printf("The import duty fee is %.2lf\n", importDutyFee);
    printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);
    printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);
    printf("The stamp duty fee is %.2lf\n", stampDuty);
    printf("The form fees are %.2lf\n", formFees);
    printf("The excise duty fee is %.2lf\n", exciseDuty);
    printf("The plate system fee is %.2lf\n", plateSystem);
    printf("The infrastructure levy fee is %.2lf\n", infrastructureLevyFee);
    printf("The gross weight fee is %.2lf\n", grossWeightFee);
    printf("The engine capacity fee is %.2lf\n", engineCapacityFee); 
    printf("The transportation fee is %.2lf\n", transportationModeFee);
    printf("The parking fee is %.2lf\n", parkingFee);
    printf("Total Taxes: %.2lf\n", totalTaxes);
}

