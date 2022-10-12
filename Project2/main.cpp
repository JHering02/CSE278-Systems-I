#include "functions.h"
#include <iostream>
#include <fstream> 
#include <limits>


// Menu Components
const std::string menu = "-----------------------------------\n"
                        "Airline Crew Scheduling Application\n"
                        "-----------------------------------\n"
                        " 1 List assigned flights of a crew\n"
                        " 2 List crews for a flight\n"
                        " 3 List names of the crews\n"
                        " 4 [Your Option]\n"
                        "-1 Exit\n"
                        "-----------------------------------\n";
void enterToContinue() {
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
            std::cout << menu << ">> Enter your choice:" << std::endl;
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