#include <iostream>
#include "Estate.h" // Include the Estate class header file.

// Set the vehicle type based on the given option.
void Estate::setvehicleType(int option) {
    if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5) {
        vehicleType = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose between 1 to 5.");
    }        
}

// Set the plate system based on the given option.
void Estate::setplateSystem(double option) {
    if (option == 1 || option == 2) {
        plateSystem = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
    }
}

// Set the transportation mode based on the given option.
void Estate::settransportationMode(double option) {
    if (option == 1 || option == 2) {
        transportationMode = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
    }
}

// Calculate the import duty fee based on the given parameters.
double Estate::calculateImportDutyFee(double importDuty, double costInsuranceFreight) {
    return importDuty * costInsuranceFreight;                        
}

// Calculate the value added tax fee based on the given parameters.
double Estate::calculateValueAddedTaxFee(double valueAddedTax, double costInsuranceFreight) {
    return valueAddedTax * costInsuranceFreight;               
}

// Calculate the withholding tax fee based on the given parameters.
double Estate::calculateWitholdingTaxFee(double witholdingTax, double costInsuranceFreight) {
    return witholdingTax * costInsuranceFreight;             
}

// Calculate the infrastructure levy fee based on the vehicle's age and insurance freight cost.
double Estate::calculateInfrastructureLevyFee(int age, double costInsuranceFreight){
    if (age > 1 && age <= 5){
        return 150000 + costInsuranceFreight * 0.01;
    } else if(age > 5 && age <= 10){
            return 150000 + costInsuranceFreight * 0.05;
    }else if(age > 10){
            return 0.15 * costInsuranceFreight;
    }else{
        return 0;
    }
}

// Calculate the seating capacity fee based on the seating capacity.
double Estate::calculateSeatingCapacityFee(double seatingCapacity){
    return (seatingCapacity > 5)? 250000 * seatingCapacity: 0;
}

// Calculate the gross weight fee based on the gross weight and insurance freight cost.
double Estate::calculateGrossWeightFee(double grossWeight, double costInsuranceFreight){
    if(grossWeight >= 1500 && grossWeight <= 2000){
        return 0.05 * costInsuranceFreight;
    }else if(grossWeight > 2000){
        return 0.10 * costInsuranceFreight;
    }else{
        return costInsuranceFreight * 0.02;
    }
}

// Calculate the engine capacity fee based on the engine capacity and insurance freight cost.
double Estate::calculateEngineCapacityFee(double costInsuranceFreight, double engineCapacity){
    return (engineCapacity > 1800)? costInsuranceFreight * 0.05: costInsuranceFreight * 0.025;
}

// Calculate the parking fee based on the number of days in bond and daily parking fee per day.
double Estate::calculateParkingFee(double daysinBond, double parkingFeePerDay) {
    return daysinBond * parkingFeePerDay;
}

// Calculate the final price of the Estate vehicle after applying all taxes and fees.
double Estate::getFinalPrice() {
    double infrastructureLevyFee, transportationModeFee, daysinBond, parkingFeePerDay, totalTaxes, importDutyFee, valueAddedTaxFee,
           witholdingTaxFee, infrastructureLevyFee, seatingCapacityFee,  grossWeightFee, engineCapacityFee;
    double importDuty, valueAddedTax, witholdingTax, seatingCapacity, grossWeight, engineCapacity;

    importDutyFee = calculateImportDutyFee(importDuty, costInsuranceFreight);
    valueAddedTaxFee = calculateValueAddedTaxFee(valueAddedTax, costInsuranceFreight);
    witholdingTaxFee = calculateWitholdingTaxFee(witholdingTax, costInsuranceFreight);
    infrastructureLevyFee = calculateInfrastructureLevyFee(Age, costInsuranceFreight);
    seatingCapacityFee = calculateSeatingCapacityFee(seatingCapacity);
    grossWeightFee = calculateGrossWeightFee(grossWeight, costInsuranceFreight);
    engineCapacityFee = calculateEngineCapacityFee(costInsuranceFreight, engineCapacity);
    parkingFee = calculateParkingFee(daysinBond, parkingFeePerDay);

    totalTaxes = importDutyFee + valueAddedTaxFee + witholdingTaxFee + seatingCapacityFee + grossWeightFee + engineCapacityFee +
                 stampDuty + formFees + exciseDuty + plateSystem + infrastructureLevyFee + transportationModeFee + parkingFee;

    return totalTaxes;
}

// Display detailed information about the Estate vehicle, including calculated taxes and fees.
void Estate::getDetails() {
    double infrastructureLevyFee, transportationModeFee, importDutyFee, valueAddedTaxFee, witholdingTaxFee, seatingCapacityFee,
           grossWeightFee, engineCapacityFee, totalTaxes;

    printf("Estate\n");
    printf("The import duty fee is %.2lf\n", importDutyFee);
    printf("The value added tax fee is %.2lf\n", valueAddedTaxFee);
    printf("The withholding tax fee is %.2lf\n", witholdingTaxFee);
    printf("The stamp duty fee is %.2lf\n", stampDuty);
    printf("The form fees are %.2lf\n", formFees);
    printf("The excise duty fee is %.2lf\n", exciseDuty);
    printf("The plate system fee is %.2lf\n", plateSystem);
    printf("The infrastructure levy fee is %.2lf\n", infrastructureLevyFee);
    printf("The seating capacity fee is %.2lf\n", seatingCapacityFee);  
    printf("The gross weight fee is %.2lf\n", grossWeightFee);
    printf("The engine capacity fee is %.2lf\n", engineCapacityFee); 
    printf("The transportation fee is %.2lf\n", transportationModeFee);
    printf("The parking fee is %.2lf\n", parkingFee);
    printf("Total Taxes: %.2lf\n", totalTaxes);
}