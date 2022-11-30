#ifndef FILM_H
#define FILM_H
#define MYSQLPP_MYSQL_HEADERS_BURIED

#include <mysql++/mysql++.h>
#include <string>
#include <iostream>

class Film {
  public :
    Film(std::string ti, std::string desc, std::string rate, std::string len);
    void addActors(mysqlpp::StoreQueryResult& myRes);
  private : 
    std::string title;
    std::string description;
    std::string rating;
    int length;
    std::vector<std::string> actorNames;
};

#endif