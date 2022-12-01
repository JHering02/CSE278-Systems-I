// Copyright
// Purpose: A User Friendly Query Application, Using MYSQL++
// Date 11/30/2022
// Author James Hering

#define MYSQLPP_MYSQL_HEADERS_BURIED

#include "Film.h"
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>

void printMenu() {
     // Menu Components
    std::cout << std::setfill('~') << std::setw(35) << "" << std::endl;
    std::cout << "Film Data Query Application" << std::endl;
    std::cout << std::setfill('~') << std::setw(35) << "" << std::endl;
    std::cout << " 1 Find Films Matching a Name\n";
    std::cout << " 2 List Films For a Certain Rating "
              << "And Max Length Ordered by Length\n";
    std::cout << " 3 List Total Film Count For Each Rating Less Than a Cost\n";
    std::cout << " 4 List All Actor Names In a Film\n";
    std::cout << " 5 Exit\n";
    std::cout << std::setfill('~') << std::setw(35) << "" << std::endl;
    std::cout << "Enter a menu number >>> ";
}

void enterToContinue() {
    // Function to pause the menu until the user presses enter
    std::cout << "\nto continue, press enter...";
    std::cin.ignore();
    std::cin.ignore();
}

void listFilmByName(mysqlpp::Connection& myDB) {
  // Asking the user for a non-case sensitive movie name
  std::cout << "Enter characters to search movies from >>> ";
  std::string bind;
  std::cin >> bind;
  // Creating the Query, & SQL input language
  mysqlpp::Query query = myDB.query();
  query << "SELECT title, description FROM film WHERE title LIKE '%0%%';";
  query.parse();  // Check for correctness
  mysqlpp::StoreQueryResult res = query.store(bind);  // Bind variable
  // Display a table to the console with all the query results
  std::cout << std::setfill(' ') << "\n";
  std::cout << std::setw(30) << std::left << "Title";
  std::cout << std::left << " Description" << std::endl;
  for (const auto& row : res) {
    Film f(row[0].c_str(), row[1].c_str(), "temp", "0");
    f.printTitle();
    std::cout << " ";
    f.printDesc();
    std::cout << "\n";
  }
}

void listFilmByRating(mysqlpp::Connection& myDB) {
  // Asking the user for an included rating followed by a maximum movie length
  std::cout << "Enter Rating followed by a space & MaxLength >>> ";
  std::string bind;
  double bind2;
  // We have 2 bind variables for both query parts
  std::cin >> bind;
  std::cin >> bind2;
  mysqlpp::Query query = myDB.query();  // Making the query & adding SQL
  query << "SELECT title, description, length FROM film WHERE "
        << "length < %1 "
        << "AND rating = %0q ORDER BY length ASC;";
  query.parse();  // Check for correctness
  mysqlpp::StoreQueryResult res = query.store(bind, bind2);  // Store with Binds
  // Once the server work is done, we make a table with query output
  std::cout << std::setfill(' ') << "\n";
  std::cout << "All Films For Rating " << bind << " & MaxLength " << bind2;
  std::cout << "\n";
  std::cout << std::setw(30) << std::left << "\nTitle";
  std::cout << std::setw(115) << std::left << " Description";
  std::cout << "Length\n";
  for (const auto& row : res) {
    Film f(row[0].c_str(), row[1].c_str(), "temp", row[2].c_str());
    f.printTitle();
    std::cout << " ";
    f.printDesc();
    std::cout << std::setw(6) << std::right << f.getLength();
    std::cout << "\n";
  }
}

void countRatingByPrice(mysqlpp::Connection& myDB) {
  // Asking the user for an maximum movie rental price
  std::cout << "Enter The Maximum RentalPrice >>> ";
  double bind;
  std::cin >> bind;
  mysqlpp::Query query = myDB.query();  // Make query & put in SQL
  query << "SELECT COUNT(*), rating FROM film "
        << "WHERE rental_rate < %0 GROUP BY rating;";
  query.parse();
  mysqlpp::StoreQueryResult res = query.store(bind);  // Store it with bind
  // Making the table with query output
  std::cout << std::setfill(' ') << "\n";
  std::cout << std::setw(32) << std::left << "Film Amt";
  std::cout << std::setw(32) << std::left << "Rating" << std::endl;
  for (const auto& row : res) {
    std::cout << std::setw(32) << std::left << row[0].c_str();
    std::cout << std::setw(32) << std::left << row[1].c_str();
    std::cout << "\n";
  }
}

void listActors(mysqlpp::Connection& myDB) {
  // Asking the user for a film name
  std::cout << "Enter the Name of the Film >>> ";
  std::string bind;
  std::cin.ignore();  // We need to ignore other existing input
  std::getline(std::cin, bind);  // Take the whole title not 1/2
  mysqlpp::Query query = myDB.query();  // Make a query & add SQL
  query << "SELECT actor.first_name, actor.last_name "
        << "FROM actor "
        << "INNER JOIN film_actor ON actor.actor_id = film_actor.actor_id "
        << "INNER JOIN film ON film_actor.film_id = film.film_id "
        << "WHERE film.title = %0q "
        << "ORDER BY actor.first_name ASC;";
  query.parse();
  mysqlpp::StoreQueryResult res = query.store(bind);  // Store & Bind
  Film act(bind, "temp", "temp", "0");
  act.addActors(res);  // Here we're lazily loading the actor names with Film
  // Finishing with a readable table
  std::cout << std::setfill(' ') << "\n";
  std::cout << "\nActors In Film " << bind << std::endl;
  for (std::string& name : act.getActorNames()) {
    std::cout << name << std::endl;
  }
}

void respond(int response, mysqlpp::Connection& myDB) {
  // Each Option is handled by this switch case method
    switch (response) {
    case (1):
        listFilmByName(myDB);
        break;
    case (2):
        listFilmByRating(myDB);
        break;
    case (3):
        countRatingByPrice(myDB);
        break;
    case (4):
        listActors(myDB);
        break;
    case (5):
        std::cout << "Bye!" << std::endl;
        break;
    default:
        response = 0;
        break;
    }
}

int main(int argc, char* argv[]) {
    mysqlpp::Connection myDB("cse278F2022", "localhost",
    "cse278F2022", "raspberrySeltzer");
    // Will prompt the user menu if myDB establishes a connection
    if (myDB.connected()) {
        int response = 0;
        do {
           printMenu();
           if (std::cin >> response) {
              respond(response, myDB);
              if (response != 5) {
                 enterToContinue();  // If we're not exiting, promt to continue
              }
           } else {
                std::cout << "bad input: please enter an integer\n";
                std::cin.clear();  // Recover the stream if values are bad
                std::cin.ignore(1000, '\n');  // Remove bad input
           }
        } while (response != 5);
    } else {
        std::cout << "!!! Could not connect to the film database" << std::endl;
    }
  return 0;
}
