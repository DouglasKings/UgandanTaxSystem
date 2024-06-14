// Header guard to prevent multiple inclusions
#ifndef UserInfo_H
#define UserInfo_H

// Include necessary headers
#include "Vehicle.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <limits>

// Include headers for specific vehicle types (assuming these exist)
#include "Ambulance.h"
#include "Estate.h"
#include "Sedan.h"
#include "SUV.h"
#include "Trailer.h"

// UserInfo class inherits from Vehicle
class UserInfo : public Vehicle {
private:
  // Declaring various variables
  int vehicleType, Age;
  double costInsuranceFreight, plateSystem, transportationMode, parkingFee, engineCapacity, grossWeight, seatingCapacity, daysInBond;

  // Various tax variables (assuming these are relevant)
  double stampDuty;
  double importDutyFee;
  double valueAddedTaxFee;
  double withholdingTaxFee;
  double formFees;
  double exciseDuty;
  double infrastructureLevyFee;
  double seatingCapacityFee;
  double grossWeightFee;
  double engineCapacityFee;
  double transportationModeFee;

  // Total taxes calculated for the vehicle
  double totalTaxes;

public:
  // Constructor to initialize UserInfo object
  UserInfo(int Type, int Age, double grossWeight, double engineCapacity, double seatingCapacity, double costInsuranceFreight, double plateSystem,
           int transportationMode, double daysInBond)
      : Vehicle(Type, Age, costInsuranceFreight, plateSystem, transportationMode, parkingFee),
        engineCapacity(engineCapacity), grossWeight(grossWeight), seatingCapacity(seatingCapacity),
        vehicleType(Type), Age(Age), costInsuranceFreight(costInsuranceFreight), plateSystem(plateSystem), transportationMode(transportationMode),
        parkingFee(parkingFee), daysInBond(daysInBond) {}

  // Function to display user information (likely details about the vehicle)
  void Display();

  // Override getDetails function from Vehicle class (implementation likely similar to Vehicle's getDetails)
  void getDetails() override {
    std::cout << "Displaying UserInfo details..." << std::endl;
  }
};

// End of header guard
#endif // UserInfo_H