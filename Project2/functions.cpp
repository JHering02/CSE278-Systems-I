// Copyright
// Purpose: Includes necessary functions to read an Airline Schedule Properly
// Date 10/10/2022
// Author James Hering

#include "functions.h"
#include <iostream>
#include <fstream> 

std::ifstream openFile(std::string fileName) {
    std::ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) {
      std::cout << "!!! Could not open the input file(s)" << std::endl;
      return;
   } else {
        return inFile;
   }
}

void listCrewFlights(std::string fileName) {
    bool contained = false;
    std::ifstream inFile = openFile(fileName);
    std::string crew, schedule;
    std::cout << ">> Enter the name of the crew :";
    std::cin >> crew;
    for(char ch : crew) { toupper(ch); }
    while(!(inFile.eof())) {
        std::string name, temp;
        inFile >> name;
        for(char ch : name) { toupper(ch); }
        if(crew.compare(name) == 0) {
            contained = true;
            inFile >> temp;
            // Do binary stuff to read the flights
        }
        std::getline(inFile, temp);
    }
    if ((contained) && (schedule.size() > 0)) {
        std::cout << "---- Assigned Flights ----\n" << schedule;
    } else if (contained && !(schedule.size() > 0)) {
        std::cout << "No flight was assigned to " << crew << " !!!\n";
    } else {
        std::cout << "!!! No record for " << crew << std::endl;
    }
    inFile.close();
}
void listNames(std::string fileName){
   std::ifstream inFile = openFile(fileName);
   std::cout << "--- Names of The Crews ---" << std::endl;
    while(!(inFile.eof())) {
        std::string name, temp;
        inFile >> name;
        std::cout << name << std::endl;
        std::getline(inFile, temp);
    }
    inFile.close();
}

void respond(int& response) {
    switch(response) {
        case(1) :
            listCrewFlights("CrewSchedule.txt");
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

 