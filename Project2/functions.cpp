// Copyright
// Purpose: Includes necessary functions to read an Airline Schedule Properly
// Date 10/15/2022
// Author James Hering

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include "./Project2/functions.h"

std::ifstream openFile(std::string fileName) {
    // This function is utilized in almost every other function here
    std::ifstream inFile;
    inFile.open(fileName);
    // This checks to see if the file is able to be opened
    if (!inFile.is_open()) {
      std::cout << "!!! Could not open the input file(s)" << std::endl;
      inFile.close();
      return inFile;
    } else {
        return inFile;
    }
}

std::string readFlight(std::string str) {
    int count = 0;
    bool feasible = true;
    std::ifstream inFile = openFile("Flights.txt");
    std::string res, temp;
    // In this loop we check the 1/0 Sequence
    while (!(inFile.eof())) {
        std::getline(inFile, temp);
        temp[3] = '-';
        while (temp.find(' ') != std::string::npos) {
            temp.erase(temp.find(' '), 1);
        }
        // We subtract 48 because the character '1' or '0' is ASCII
        if (static_cast<int>(str[count]) - 48) {
            // Check the flights to see if it will be feasible after adding
            if ((res.size() > 9) && feasible) {
                std::string str1 = res.substr(res.find_last_of('-') + 1, 3);
                std::string str2 = temp.substr(res.find(' ') + 1, 3);
                feasible = (str1.compare(str2) == 0);
            }
            res += (temp + "\n");
        }
        count++;
    }
    // Finish the string by adding feasibility
    if (feasible) {
        res += "The flight sequence is feasible\n";
    } else {
        res += "The flight sequence is not feasible!!\n";
    }
    inFile.close();
    return res;
}

void listCrewFlights() {
    bool contained = false;
    std::string crew, schedule;
    do {
        std::ifstream inFile = openFile("CrewSchedule.txt");
        std::cout << ">> Enter the name of the crew :\n";
        std::cin >> crew;
        // This for loop is making the crew name non-case sensitive
        for (char &ch : crew) {
            ch = toupper(ch);
        }
        // This while loop will check every crew for their flights
        while (!(inFile.eof())) {
            std::string name, temp;
            inFile >> name;
            if (crew.compare(name) == 0) {
                contained = true;
                inFile >> temp;
                schedule = readFlight(temp);
            }
            inFile >> temp;
        }
        // Printing out the crews flights
        if ((contained) && (schedule.size() > 0)) {
            std::cout << "---- Assigned Flights ----\n"
                      << schedule;
        } else if (contained && !(schedule.size() > 0)) {
            std::cout << "No flight was assigned to " << crew << " !!!\n";
        } else {
            std::cout << "!!! No record for " << crew << std::endl;
        }
        inFile.close();
    } while (!contained);
}

bool flightExists(std::string flight) {
    // Checks if the flight is in the list and returns false otherwise
    std::ifstream inFile = openFile("Flights.txt");
    std::string str;
    while (!inFile.eof()) {
        std::getline(inFile, str);
        while (str.find_last_of(' ') > 3) {
            str.erase(str.find_last_of(' '), 1);
        }
        if (flight.compare(str) == 0) {
            return true;
        }
    }
    inFile.close();
    return false;
}

void listCrewsWithFlight(std::string flight) {
    std::ifstream crews = openFile("CrewSchedule.txt");
    std::string crewsInFlight;
    int count = 0;
    // Iterates through CrewSchedule.txt to add every crew with flight
    while (!crews.eof()) {
        std::string crew, index, flights;
        crews >> crew;
        crews >> index;
        flights = readFlight(index);
        if (flights.find(flight) != std::string::npos) {
            crewsInFlight += (crew + "\n");
            count++;
        }
    }
    // Printing the crews with this flight
    std::cout << "---- Crew List ----\n"
              << crewsInFlight;
    std::cout << count << " crew(s) work(s) on the flight " << flight;
    std::cout << "\n";
    crews.close();
}

void promptForFlight() {
    std::string curr, temp, flight;
    std::vector<std::string> points;
    std::ifstream flights = openFile("Flights.txt");
    // Adds every flight point to a vector
    while (!(flights.eof())) {
        flights >> curr;
        if (std::find(points.begin(), points.end(), curr) == points.end()) {
            points.push_back(curr);
        }
        flights >> temp;
    }
    // Prompting the user to insert an existing flight until a flight exists
    do {
        std::string input;
        flight = "";
        std::cout << "Here is the flight points: ";
        for (int i = 0; i < static_cast<int>(points.size()); ++i) {
            if (i < static_cast<int>(points.size()) - 1) {
                std::cout << points.at(i) << ", ";
            } else {
                std::cout << points.at(i);
            }
        }
        std::cout << "\n"
                  << ">> FROM :\n";
        std::cin >> input;
        flight += input;
        std::cout << ">> TO :\n";
        std::cin >> input;
        flight += (" " + input);
        for (char &ch : flight) {
            ch = toupper(ch);
        }
        if (flightExists(flight)) {
            std::replace(flight.begin(), flight.end(), ' ', '-');
            listCrewsWithFlight(flight);
        } else {
            std::cout << "No flight was found!!Please enter again...\n";
        }
    } while (flight.find('-') == std::string::npos);
    flights.close();
}

void listNames() {
    std::ifstream inFile = openFile("CrewSchedule.txt");
    std::cout << "--- Names of The Crews ---" << std::endl;
    // Lists every existing crew in CrewSchedule.txt
    while (!(inFile.eof())) {
        std::string name, temp;
        inFile >> name;
        std::cout << name << std::endl;
        std::getline(inFile, temp);
    }
    inFile.close();
}

void respond(int response) {
    switch (response) {
    case (1):
        listCrewFlights();
        break;
    case (2):
        promptForFlight();
        break;
    case (3):
        listNames();
        break;
    case (4):
        std::cout << "Your option\n";
        break;
    case (-1):
        std::cout << "Bye!" << std::endl;
        break;
    default:
        std::cout << "The wrong choice!!!" << std::endl;
        response = 0;
        break;
    }
}
