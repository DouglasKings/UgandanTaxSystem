#include "Vehicle.h" // Include the header file for the Vehicle class

// Function to display details of a vehicle
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