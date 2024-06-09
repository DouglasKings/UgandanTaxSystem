// Implementation of the Display method for userInfo class
void UserInfo::Display() {
    // Checking the type of vehicle and call the corresponding constructor
    if(vehicleType == 1) { 
        Ambulance(Type, Age, costInsuranceFreight, transportationMode, daysInBond, plateSystem); // Assuming Ambulance is another class
        vehicleInstance.getDetails(); // Getting details of the ambulance instance
    } 
    else if(vehicleType == 2) { 
        Estate(Type, Age, costInsuranceFreight, transportationMode, daysInBond, seatingCapacity, engineCapacity, grossWeight, plateSystem);
        vehicleInstance.getDetails(); // Getting details of the estate instance
    } 
    else if(vehicleType == 3) { 
        Sedan(Type, Age, costInsuranceFreight, transportationMode, daysInBond, plateSystem, engineCapacity, grossWeight);
        vehicleInstance.getDetails(); // Getting details of the sedan instance
    }
    else if(vehicleType == 4) { 
        SUV(Type, Age, costInsuranceFreight, transportationMode, daysInBond, seatingCapacity, engineCapacity, grossWeight, plateSystem);
        vehicleInstance.getDetails(); // Getting details of the SUV instance
    }
    else if(vehicleType == 5) { 
        Trailer(Type, Age, costInsuranceFreight, transportationMode, daysInBond, seatingCapacity, engineCapacity, grossWeight, plateSystem);
        vehicleInstance.getDetails(); // Getting details of the trailer instance
    }
    else {
        throw std::runtime_error("Invalid vehicle type."); // Throwing exception for invalid vehicle types
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