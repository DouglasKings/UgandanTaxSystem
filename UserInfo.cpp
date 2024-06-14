#include <iostream>
#include <iomanip> // For setting precision of floating-point numbers
#include "UserInfo.h"// Presumably contains the UserInfo class definition
#include "Vehicle.h"// Presumably contains the base Vehicle class definition

// Method to display user information and vehicle details
void UserInfo::Display() {
    // Initialize local variables based on member variables
    int vehicleType = this->vehicleType;

    double Age = this->Age, grossWeight = this->grossWeight, engineCapacity = this->engineCapacity, seatingCapacity = this->seatingCapacity, 
            costInsuranceFreight = this->costInsuranceFreight, plateSystem = this->plateSystem, totalTaxes = 0,
            transportationMode = this->transportationMode, daysInBond = this->daysInBond;
    
    // Pointer to a Vehicle object, initially null
    Vehicle* vehicleInstance = nullptr;

    // Factory pattern to create different types of vehicles based on vehicleType
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
        throw std::runtime_error("Invalid vehicle type.");// Exception handling for invalid vehicle types
    }

    // Check if vehicleInstance is not null before accessing its methods
    if(vehicleInstance!= nullptr) {
        vehicleInstance->getDetails();
        delete vehicleInstance;
    }

    // Printing the results
    std::cout << "\n Type of vehicle is" << vehicleType <<'\n';
    std::cout << "The stamp duty is: " << stampDuty << '\n';
    std::cout << "The import duty is: " << std::fixed << std::setprecision(2) << importDutyFee << '\n';
    std::cout << "The value added tax is: " << std::fixed << std::setprecision(2) << valueAddedTaxFee << '\n';
    std::cout << "The withholding tax is: " << std::fixed << std::setprecision(2) << withholdingTaxFee << '\n';
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