#define MYSQLPP_MYSQL_HEADERS_BURIED

#include "Film.h"
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>

Film::Film(std::string ti, std::string desc, std::string rate, std::string len) {
   title = ti;
   description = desc;
   rating = rate;
   length = stoi(len);
}

void Film::addActors(mysqlpp::StoreQueryResult& myRes) {
  for (const auto& row : myRes) {
     std::string fName = row[0].c_str();
     std::string lName = row[1].c_str();
     actorNames.push_back(fName + " " + lName);
  }
}

std::string Film::printTitle() {
   std::cout << std::setw(128) << std::left << title;
}

std::string Film::printDesc() {
   std::cout << std::left << description;
}

std::string Film::printRating() {
   std::cout << std::setw(5) << std::left << rating;
}







