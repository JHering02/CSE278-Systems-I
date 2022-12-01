// Copyright
// Purpose: The functions for a film object, made for the query application
// Date 11/30/2022
// Author James Hering

#define MYSQLPP_MYSQL_HEADERS_BURIED

#include "Film.h"
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>

Film::Film(std::string ti, std::string de, std::string rate, std::string len) {
  // Basic parameter constructor here
  title = ti;
  description = de;
  rating = rate;
  length = stoi(len);
}

void Film::addActors(const mysqlpp::StoreQueryResult& myRes) {
// By taking the stored result, we can add the strings to a vector
  for (const auto& row : myRes) {
     std::string fName = row[0].c_str();
     std::string lName = row[1].c_str();
     actorNames.push_back(fName + " " + lName);
  }
}

void Film::printTitle() {
std::cout << std::setw(30) << std::left << title;
}

void Film::printDesc() {
std::cout << std::setw(115) << std::left << description;
}

void Film::printRating() {
std::cout << std::setw(5) << std::left << rating;
}







