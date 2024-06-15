// Includes necessary libraries for I/O operations, formatting, and standard containers
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <limits>

// Includes custom header files for classes used in the program
#include "Vehicle.h"
#include "UserInfo.h"
#include "UserInfo.cpp"
#include "Ambulance.h"
#include "Estate.h"
#include "Sedan.h"
#include "SUV.h"
#include "Trailer.h"


int main() {
    char choice; // Variable to store user choice
     // Main loop to continuously process vehicle details until user decides to exit
     while(1){
    // Initializing variables to avoid undefined behavior due to uninitialized usage
    int vehicleType = 0;
    double Age = 0, grossWeight = 0, engineCapacity = 0, seatingCapacity = 0, costInsuranceFreight = 0, 
           plateSystem, totalTaxes = 0, transportationMode = 0, daysInBond = 0, 
           stampDuty = 35000, formFees = 20000, exciseDuty = 200000, infrastructureLevyFee = 150000,
           importDuty = 0.25, valueAddedTax = 0.18, withholdingTax = 0.06, currentYear = 2024, 
           carAgeFee = 0, parkingFeePerDay = 15000;

    // Declaring variables that will be calculated based on user input
    double importDutyFee, valueAddedTaxFee, withholdingTaxFee, grossWeightFee, engineCapacityFee, transportationFee, parkingFee, seatingCapacityFee;

    // Looping until valid vehicle type is entered
    do {
        std::cout << "Enter the Vehicle Type (e.g 1 for Ambulance, 2 for Estate, 3 for Sedan, 4 for Sports Utility Vehicle(SUV) & 5 for Trailer): ";
        std::cin >> vehicleType;
        std::cout << "Vehicle type is: " << vehicleType << "\n";
        if (vehicleType!= 1 && vehicleType!= 2 && vehicleType!= 3 && vehicleType!= 4 && vehicleType!= 5) {
            std::cout << "Invalid vehicle type.\n";
            continue;
        }

        // Depending on the vehicle type, ask for different parameters
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

    // Continuing to ask for other parameters
    std::cout << "Enter the Cost Insurance Freight: ";
    std::cin >> costInsuranceFreight;
    std::cout << "Cost Insurance Freight: " << std::fixed << std::setprecision(2) << costInsuranceFreight << "\n";

    std::cout << "Enter the vehicle age in years: ";
    std::cin >> Age;
    std::cout << "Age is: " << std::fixed << std::setprecision(2) << Age << "\n";

    // Initializing variable to avoid undefined behavior
    plateSystem = 0;

    // Looping until valid plate system is entered
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
    } while (true); // Ensuring proper exit from the loop

    // Asking for transportation mode
    std::cout << "Enter the transportation mode (e.g., 1 for Carrier bed or 2 for Driven): ";
    std::cin >> transportationMode;
    if (transportationMode == 1) {
        std::cout << "The mode of transportation was on a carrier bed. \n";
    } else if (transportationMode == 2) {
        std::cout << "The vehicle was driven into the country. \n";
    } else {
        std::cout << "Invalid transportation mode. Please enter 1 for Carrier bed or 2 for Driven. \n";
    }

    // Asking for days in bond
    std::cout << "Enter number of days the vehicle spends in the bond: ";
    std::cin >> daysInBond;
    std::cout << "Days in bond is " << std::fixed << std::setprecision(2) << daysInBond << "\n";

    // Instantiating userInfo object with collected data
    UserInfo userInfo(vehicleType, Age, grossWeight, engineCapacity, seatingCapacity, costInsuranceFreight, plateSystem, transportationMode, daysInBond);

    // Attempting to display vehicle details
    try {
        userInfo.Display();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    // Ask the user if they want to choose another car
    printf("\nDo you want to choose another car? (Y/N): ");
    scanf(" %c", &choice); // Note the space before %c to skip any whitespace characters
    getchar(); // To consume the newline character left by scanf

    // Check if the user wants to stop
    if (choice == 'n' || choice == 'N') {
        break; // Exit the loop if the user chooses 'N' or 'n'
    }
}

    return 0;
}