#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <limits>

#include "Ambulance.h"
#include "Estate.h"
#include "Sedan.h"
#include "SUV.h"
#include "Trailer.h"
#include "UserInfo.h"

int main() {
    int vehicleType = 0; // Initialize variable to avoid undefined behavior
    double Age = 0, grossWeight = 0, engineCapacity = 0, seatingCapacity = 0, costInsuranceFreight = 0, plateSystem, totalTaxes = 0, transportationMode = 0, daysInBond = 0;
    double stampDuty = 35000, formFees = 20000, exciseDuty = 200000, infrastructureLevyFee = 150000, importDuty = 0.25, valueAddedTax = 0.18, withholdingTax = 0.06, currentYear = 2024, carAgeFee = 0, parkingFeePerDay = 15000;

    double importDutyFee, valueAddedTaxFee, withholdingTaxFee, grossWeightFee, engineCapacityFee, transportationFee, parkingFee, seatingCapacityFee;

    do {
        std::cout << "Enter the Vehicle Type (e.g 1 for Ambulance, 2 for Estate, 3 for Sedan, 4 for Sports Utility Vehicle(SUV) & 5 for Trailer): ";
        std::cin >> vehicleType;
        std::cout << "Vehicle type is: " << vehicleType << "\n";
        if (vehicleType!= 1 && vehicleType!= 2 && vehicleType!= 3 && vehicleType!= 4 && vehicleType!= 5) {
            std::cout << "Invalid vehicle type.\n";
            continue;
        }

        if (vehicleType == 2 || vehicleType == 3 || vehicleType == 5) {
            std::cout << "Enter engine capacity: ";
            std::cin >> engineCapacity;
            std::cout << "Engine capacity is: " << std::fixed << std::setprecision(2) << engineCapacity << "\n";
        } else if (vehicleType == 2 || vehicleType == 4) {
            std::cout << "Enter seating capacity: ";
            std::cin >> seatingCapacity;
            std::cout << "Seating capacity is: " << std::fixed << std::setprecision(2) << seatingCapacity << "\n";
        }

    } while (vehicleType <= 0 || vehicleType > 5);

    std::cout << "Enter the Cost Insurance Freight: ";
    std::cin >> costInsuranceFreight;
    std::cout << "Cost Insurance Freight: " << std::fixed << std::setprecision(2) << costInsuranceFreight << "\n";

    std::cout << "Enter the vehicle age in years: ";
    std::cin >> Age;
    std::cout << "Age is: " << std::fixed << std::setprecision(2) << Age << "\n";

    double plateSystem = 0; // Initialize variable to avoid undefined behavior

    do {
        std::cout << "Enter plate system (Analog Plate System (300000) or Digital Plate System (700000), Ambulance & Sedan is DPS, SUV is APS): ";
        std::cin >> plateSystem;
        if (plateSystem!= 300000 && plateSystem!= 700000) {
            std::cout << "Invalid input. Please enter 300000 or 700000. \n";
        } else {
            if (plateSystem == 300000) {
                std::cout << "The plate system is Analog Plate System. \n";
            } else {
                std::cout << "The plate system is Digital Plate System. \n";
            }
            break;
        }
    } while (true); // Changed condition to true to exit the loop properly

    std::cout << "Enter the transportation mode (e.g., 1 for Carrier bed or 2 for Driven): ";
    std::cin >> transportationMode;
    if (transportationMode == 1) {
        std::cout << "The mode of transportation was on a carrier bed. \n";
    } else if (transportationMode == 2) {
        std::cout << "The vehicle was driven into the country. \n";
    } else {
        std::cout << "Invalid transportation mode. Please enter 1 for Carrier bed or 2 for Driven. \n";
    }

    std::cout << "Enter number of days the vehicle spends in the bond: ";
    std::cin >> daysInBond;
    std::cout << "Days in bond is " << std::fixed << std::setprecision(2) << daysInBond << "\n";

    // Instantiate userInfo object
    userInfo userInfo;

    // Display vehicle details
    try {
        UserInfo.Display();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}