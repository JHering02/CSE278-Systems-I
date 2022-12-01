// Copyright
// Purpose: The header file for a film object, made for the query application
// Date 11/30/2022
// Author James Hering

#ifndef _HOME_HERINGJA_CSE278_PROJECT4_FILM_H_
#define _HOME_HERINGJA_CSE278_PROJECT4_FILM_H_
#define MYSQLPP_MYSQL_HEADERS_BURIED

#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include <vector>

class Film {
 public :
    Film(std::string ti, std::string de, std::string rate, std::string len);
    void addActors(const mysqlpp::StoreQueryResult& myRes);
    std::string getTitle() {return title;}
    std::string getDescription() {return description;}
    std::string getRating() {return rating;}
    int getLength() {return length;}
    std::vector<std::string> getActorNames() {return actorNames;}
    void printTitle();
    void printDesc();
    void printRating();
 private :
    std::string title;
    std::string description;
    std::string rating;
    int length;
    std::vector<std::string> actorNames;
};

#endif  // _HOME_HERINGJA_CSE278_PROJECT4_FILM_H_
