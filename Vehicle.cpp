#include "Vehicle.h" // Includes the header file for the Vehicle class. This file contains the declaration of the Vehicle class and its member variables and methods.

// Function to display details of a vehicle.
// This function takes a constant reference to a Vehicle object as its parameter.
// It outputs the type of vehicle, age, cost of insurance and freight, plate system registration,
// mode of transportation, and parking fee to the console.
void Display(const Vehicle& vehicle){
    std::cout << "Type of vehicle is: " << vehicle.vehicleType << ", Age of the car is: " << vehicle.Age << ", The Cost Insurance Freight is: " << vehicle.costInsuranceFreight
    << ", The Plate System Registration is: " << vehicle.plateSystem << ", The mode of transportation is: " << vehicle.transportationMode 
    << ", The parking fee is: " << vehicle.parkingFee << '\n';
}


/*// Function to display vehicle details 
void Display(const Vehicle& vehicle) {
    std::cout << std::fixed << std::setprecision(2);  // Set output formatting for decimals
    std::cout << "Type of vehicle is: " << vehicle.vehicleType << std::endl;
    std::cout << "Age of the car is: " << vehicle.Age << std::endl;
    std::cout << "The Cost Insurance Freight is: $" << vehicle.costInsuranceFreight << std::endl;
    std::cout << "The Plate System Registration is: " << vehicle.plateSystem << std::endl;
    std::cout << "The mode of transportation is: " << vehicle.transportationMode << std::endl;
    std::cout << "The parking fee is: $" << vehicle.parkingFee << std::endl;
}*/