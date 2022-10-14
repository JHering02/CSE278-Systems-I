#include <iostream>
#include <fstream> 
#include <limits>

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
              std::cout << "\nto continue, press enter...";
            }
        }while(response != -1);
    } else {
        std::cout << "!!! Could not open the input file(s)" << std::endl;
    }
   return 0;
}