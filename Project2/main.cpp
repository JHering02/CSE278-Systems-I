#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <limits>

void printMenu() {
    // Menu Components
    std::cout << std::setfill('-') << std::setw(35) << std::endl;
    std::cout << "Airline Crew Scheduling Application" << std::endl;
    std::cout << std::setfill('-') << std::setw(35) << std::endl;
    std::cout << " 1 List assigned flights of a crew\n";
    std::cout << " 2 List crews for a flight\n";
    std::cout << " 3 List names of the crews\n";
    std::cout << " 4 [Your Option]\n";
    std::cout << "-1 Exit\n";
    std::cout << std::setfill('-') << std::setw(35) << std::endl;
}
void enterToContinue() {
    // Function to pause the menu until the user presses enter.
    std::cout << "\nto continue, press enter...";
    std::cin.ignore();
}
int main() {
    std::ifstream flights, schedule;
    flights.open("Flights.txt");
    schedule.open("CrewSchedule.txt");
    if((flights.is_open()) && (schedule.is_open())) {
        int response;
        flights.close();
        schedule.close();
        do {
            printMenu();
            std::cin >> response;
            respond(response);
            if(response != -1) {
            enterToContinue();
            }
        }while(response != -1);
    } else {
        std::cout << "!!! Could not open the input file(s)" << std::endl;
    }
   return 0;
}