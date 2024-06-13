#include <iostream>
#include <iomanip>

#include "UserInfo.h"
#include "Vehicle.h"


// Implementation of the Display method for userInfo class
void UserInfo::Display() {
    int vehicleType = 0; // Initialize variable to avoid undefined behavior
    double Age = 0, grossWeight = 0, engineCapacity = 0, seatingCapacity = 0, costInsuranceFreight = 0, plateSystem, totalTaxes = 0,
    transportationMode = 0, daysInBond = 0;
    double stampDuty = 35000, formFees = 20000, exciseDuty = 200000, importDutyFee, valueAddedTaxFee, witholdingTaxFee, 
    infrastructureLevyFee, seatingCapacityFee, grossWeightFee, engineCapacityFee, transportationModeFee, parkingFee;

    Vehicle* vehicleInstance = nullptr;

    // Checking the type of vehicle and call the corresponding constructor
       if(vehicleType == 1) { 
        vehicleInstance = new Ambulance(vehicleType, Age, costInsuranceFreight, transportationMode, daysInBond, plateSystem);
    } 
    else if(vehicleType == 2) { 
        vehicleInstance = new Estate(vehicleType, Age, costInsuranceFreight, transportationMode, daysInBond, seatingCapacity, engineCapacity, grossWeight, plateSystem);
    } 
    else if(vehicleType == 3) { 
        vehicleInstance = new Sedan(vehicleType, Age, costInsuranceFreight, transportationMode, daysInBond, plateSystem, engineCapacity, grossWeight);
    }
    else if(vehicleType == 4) { 
        vehicleInstance = new SUV(vehicleType, Age, costInsuranceFreight, transportationMode, daysInBond, seatingCapacity, engineCapacity, grossWeight, plateSystem);
    }
    else if(vehicleType == 5) { 
        vehicleInstance = new Trailer(vehicleType, Age, costInsuranceFreight, transportationMode, daysInBond, seatingCapacity, engineCapacity, grossWeight, plateSystem);
    }
    else {
        throw std::runtime_error("Invalid vehicle type."); // Throwing exception for invalid vehicle types
    }

    if(vehicleInstance != nullptr) {
        vehicleInstance->getDetails(); // Getting details of the vehicle instance
        delete vehicleInstance; // Clean up memory to avoid leaks
    }


    // Display various vehicle details
    std::cout << "\n Type of vehicle is" << vehicleType <<'\n';
    std::cout << "The stamp duty is: " << stampDuty << '\n'; // Assuming these variables are defined somewhere
    std::cout << "The import duty is: " << std::fixed << std::setprecision(2) << importDutyFee << '\n';
    std::cout << "The value added tax is: " << std::fixed << std::setprecision(2) << valueAddedTaxFee << '\n';
    std::cout << "The withholding tax is: " << std::fixed << std::setprecision(2) << witholdingTaxFee << '\n';
    std::cout << "The form fees are: " << formFees << '\n';
    std::cout << "The excise duty is: " << exciseDuty << '\n';
    std::cout << "The Plate System Registration is: " << plateSystem << '\n';
    std::cout << "The Infrastructure Levy Fee: " << std::fixed << std::setprecision(2) << infrastructureLevyFee << '\n';
    std::cout << "The seating capacity is: " << std::fixed << std::setprecision(2) << seatingCapacityFee << '\n';
    std::cout << "The gross weight fee is: " << std::fixed << std::setprecision(2) << grossWeightFee << '\n';
    std::cout << "The engine capacity fee is: " << std::fixed << std::setprecision(2) << engineCapacityFee << '\n';
    std::cout << "The transportation mode is: " << std::fixed << std::setprecision(2) << transportationModeFee << '\n';
    std::cout << "The parking fee is: " << std::fixed << std::setprecision(2) << parkingFee << '\n';
    std::cout << "Total Taxes: " << std::fixed << std::setprecision(2) << totalTaxes << '\n';
}