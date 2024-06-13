#include <iostream>
#include "Trailer.h"

void Trailer::setvehicleType(int option) {
    if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5) {
        vehicleType = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose between 1 to 5.");
    }        
}

void Trailer::setplateSystem(double option) {
    if (option == 1 || option == 2) {
        plateSystem = option;
    } else {
            throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
    }
}

void Trailer::settransportationMode(double option) {
    if (option == 1 || option == 2) {
        transportationMode = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
    }
}

double Trailer::calculateImportDutyFee(double importDuty, double costInsuranceFreight) {
        return importDuty * costInsuranceFreight;                        
}

double Trailer::calculateValueAddedTaxFee(double valueAddedTax, double costInsuranceFreight) {
        return valueAddedTax * costInsuranceFreight;               
}

double Trailer::calculateWitholdingTaxFee(double witholdingTax, double costInsuranceFreight) {
        return witholdingTax * costInsuranceFreight;             
}

double Trailer::calculateInfrastructureLevyFee(int age, double costInsuranceFreight){
    if (age >= 15) {
        std::cout << "Trailers older than 15 years cannot to be imported into the country\n";
        return 0;
    } else if (age >= 10) {
        return costInsuranceFreight * 0.10;
    } else if (age >= 5) {
            return costInsuranceFreight * 0.05;
    } else if (age < 5) {
            return costInsuranceFreight * 0.015; 
    }else{
        return 0;
    }
}

double Trailer::calculateGrossWeightFee(double grossWeight, double costInsuranceFreight){
    if(grossWeight >= 15000 && grossWeight <= 20000){
        return 0.15 * costInsuranceFreight;
    }else if(grossWeight > 20000){
        return 0.25 * costInsuranceFreight;
    }else{
        return costInsuranceFreight * 0.05;
    }
}

double Trailer::calculateEngineCapacityFee(double engineCapacity, double costInsuranceFreight){
        if(engineCapacity > 20000){
            return 0.10 * costInsuranceFreight;
        }else if(engineCapacity >= 20000 && engineCapacity <= 15000){
            return 0.05 * costInsuranceFreight;
        }else{
            return 0.025 * costInsuranceFreight;
        }
}

double Trailer::calculateParkingFee(double daysinBond, double parkingFeePerDay) {
    return daysinBond * parkingFeePerDay;
}

double Trailer::getFinalPrice() {
    double infrastructureLevyFee, transportationModeFee, daysinBond, parkingFeePerDay, totalTaxes, importDutyFee, valueAddedTaxFee,
           witholdingTaxFee, seatingCapacityFee,  grossWeightFee, engineCapacityFee;
    double importDuty, valueAddedTax, witholdingTax, seatingCapacity, grossWeight, engineCapacity;

        importDutyFee = calculateImportDutyFee(importDuty, costInsuranceFreight);
        valueAddedTaxFee = calculateValueAddedTaxFee(valueAddedTax, costInsuranceFreight);
        witholdingTaxFee = calculateWitholdingTaxFee(witholdingTax, costInsuranceFreight);
        infrastructureLevyFee = calculateInfrastructureLevyFee(Age, costInsuranceFreight);
        grossWeightFee = calculateGrossWeightFee(grossWeight, costInsuranceFreight);
        engineCapacityFee = calculateEngineCapacityFee(costInsuranceFreight, engineCapacity);
        parkingFee = calculateParkingFee(daysinBond, parkingFeePerDay);

        totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + seatingCapacityFee + grossWeightFee + engineCapacityFee +
                     stampDuty + formFees + exciseDuty + plateSystem + infrastructureLevyFee + transportationModeFee + parkingFee;

            return totalTaxes;
}

void Trailer::getDetails() {
    double infrastructureLevyFee, transportationModeFee, importDutyFee, valueAddedTaxFee, witholdingTaxFee, seatingCapacityFee,
           grossWeightFee, engineCapacityFee, totalTaxes;

    printf("Trailer\n");
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

