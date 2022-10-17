// Copyright
// Purpose: Declares necessary functions to read an Airline Schedule Properly
// Date 10/15/2022
// Author James Hering

#ifndef PROJECT2_FUNCTIONS_H_
#define PROJECT2_FUNCTIONS_H_
#include <iostream>
#include <string>
  std::ifstream openFile(std::string fileName);
  std::string readFlight(std::string str);
  void listCrewFlights();
  bool flightExists(std::string flight);
  void listCrewsWithFlight(std::string flight);
  void promptForFlight();
  void listNames();
  void respond(int response);

#endif  // PROJECT2_FUNCTIONS_H_
