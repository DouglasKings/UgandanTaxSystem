#include <iostream>
#include "Ambulance.h"

// Sets the vehicle type within valid options
void Ambulance::setvehicleType(int option) {
    if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5) {
        vehicleType = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose between 1 to 5.");
    }        
}

// Sets the plate system within valid options
void Ambulance::setplateSystem(double option) {
    if (option == 1) {
        plateSystem = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
    }
}

// Sets the transportation mode within valid options
void Ambulance::settransportationMode(double option) {
    if (option == 1 || option == 2) {
        transportationMode = option;
    } else {
        throw std::invalid_argument("Invalid option. Please choose 1 or 2.");
    }
}

// Calculates the infrastructure levy fee based on age and insurance freight cost
double Ambulance::calculateInfrastructureLevyFee(int Age, double costInsuranceFreight) {
    if (Age >= 10) {
        return 0.15 * costInsuranceFreight; 
    } else {
        return 150000; 
    }
}

// Calculates the transportation mode fee based on mode and insurance freight cost
double Ambulance::calculateTransportationModeFee(int transportationMode, double costInsuranceFreight) {
    if (transportationMode == 1) {
        return 0.005 * costInsuranceFreight;
    } else if (transportationMode == 2) {
        return 0.015 * costInsuranceFreight;
    } else {
        return 0;
    }
}

// Calculates the parking fee based on days in bond and daily parking fee
double Ambulance::calculateParkingFee(double daysinBond, double parkingFeePerDay) {
    return daysinBond * parkingFeePerDay;
}

// Calculates the final price including all applicable taxes and fees
double Ambulance::getFinalPrice() {
    double infrastructureLevyFee, transportationModeFee, daysinBond, parkingFeePerDay, totalTaxes;

    infrastructureLevyFee = calculateInfrastructureLevyFee(Age, costInsuranceFreight);
    transportationModeFee = calculateTransportationModeFee(transportationMode, costInsuranceFreight);
    parkingFee = calculateParkingFee(daysinBond, parkingFeePerDay);
    totalTaxes = stampDuty + formFees + exciseDuty + plateSystem + infrastructureLevyFee + transportationModeFee + parkingFee;
    return totalTaxes;
}

// Displays detailed information about the ambulance
void Ambulance::getDetails() {
    double infrastructureLevyFee, transportationModeFee, totalTaxes;

    printf("Ambulance\n");
    printf("The stamp duty fee is %.2lf\n", stampDuty);
    printf("The form fees are %.2lf\n", formFees);
    printf("The excise duty fee is %.2lf\n", exciseDuty);
    printf("The plate system fee is %.2lf\n", plateSystem);
    printf("The infrastructure levy fee is %.2lf\n", infrastructureLevyFee); 
    printf("The transportation fee is %.2lf\n", transportationModeFee); 
    printf("The parking fee is %.2lf\n", parkingFee);   
    printf("Total Taxes: %.2lf\n", totalTaxes);
}