// Copyright
// Purpose: Includes necessary functions to read an Airline Schedule Properly
// Date 10/10/2022
// Author James Hering

#include "functions.h"
#include <iostream>
#include <fstream> 

void listNames(std::string fileName){
    std::ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) {
      std::cout << "!!! Could not open the input file(s)" << std::endl;
      return;
   } 
   std::cout << "--- Names of The Crews ---" << std::endl;
    while(!(inFile.eof())) {
        std::string name, temp;
        inFile >> name;
        std::cout << name << std::endl;
        std::getline(inFile, temp);
    }
}

void respond(int& response) {
    switch(response) {
        case(1) :
            std::cout << "List assigned flights of a crew\n";
            break;
        case(2) :
            std::cout << "List crews for a flight\n";
            break;
        case(3) :
            listNames("CrewSchedule.txt");
            break;
        case(4) :
            std::cout << "Your option\n";
            break;
        case(-1) :
            std::cout << "Bye!" << std::endl;
            break;
        default :
            std::cout << "The wrong choice!!!" << std::endl;
            response = 0;
            break;
    }
}

 