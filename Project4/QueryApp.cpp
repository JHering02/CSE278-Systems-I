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
    std::cout << "Enter a menu number >>> \n";
}
void enterToContinue() {
    // Function to pause the menu until the user presses enter
    std::cout << "\nto continue, press enter...";
    std::cin.ignore();
    std::cin.ignore();
}

std::string listFilmByName(mysqlpp::Connection myDB) {
  std::cout << "Enter characters to search movies from >>> ";
  std::string bind;
  std::cin >> bind;
  mysqlpp::Query query = myDB.query();
  query << "SELECT title, description FROM film WHERE title LIKE %0q;";
  query.parse();
  mysqlpp::StoreQueryResult res = query.store(bind);

}

std::string listFilmByRating(mysqlpp::Connection myDB) {
  std::cout << "Enter Rating followed by a space & MaxLength >>> ";
  std::string bind;
  int bind2;
  std::cin >> bind;
  std::cin >> bind2;
  mysqlpp::Query query = myDB.query();
  query << "SELECT title, description, length FROM film WHERE"
        << "length < %1 AND rating = %0q ORDER BY length ASC;";
  query.parse();
  mysqlpp::StoreQueryResult res = query.store(bind, bind2);
}

std::string countRatingByPrice(mysqlpp::Connection myDB) {
  std::cout << "Enter The Maximum RentalPrice >>> ";
  int bind;
  std::cin >> bind;
  mysqlpp::Query query = myDB.query();
  query << "SELECT COUNT(*), rating FROM film "
        << "WHERE rental_rate < %0 GROUP BY rating;";
  query.parse();
  mysqlpp::StoreQueryResult res = query.store(bind);
}

std::string listActors(mysqlpp::Connection myDB) {
  std::cout << "Enter the Name of the Film >>> ";
  std::string bind;
  std::cin >> bind;
  mysqlpp::Query query = myDB.query();
  query << "SELECT actor.first_name, actor.last_name"
        << "FROM actor"
        << "INNER JOIN film_actor ON actor.actor_id = film_actor.actor_id"
        << "INNER JOIN film ON film_actor.film_id = film.film_id "
        << "WHERE film.title = %0q"
        << "ORDER BY actor.first_name ASC;";
  query.parse();
  mysqlpp::StoreQueryResult res = query.store(bind);
  Film act(bind, "temp", "temp", "temp");
  act.addActors(res);
  std::cout << "\nActors In Film " << bind << std::endl;
  for(std::string& name : act.getActorNames()) {

  }
}

void respond(int response, mysqlpp::Connection myDB) {
    switch (response) {
    case (1):
        std::cout << listFilmByName(myDB);
        break;
    case (2):
        std::cout << listFilmByRating(myDB);
        break;
    case (3):
        std::cout << countRatingByPrice(myDB);
        break;
    case (4):
        std::cout << listActors(myDB);
        break;
    case (5):
        std::cout << "Bye!" << std::endl;
        break;
    default:
        std::cout << "Wrong Choice, try again" << std::endl;
        response = 0;
        break;
    }
}

int main(int argc, char* argv[]) {
    mysqlpp::Connection myDB("cse278F2022", "localhost", 
    "cse278F2022","raspberrySeltzer");
    // Will prompt the user menu if myDB establishes a connection
    if (myDB.connected()) {
        int response = 0;
        do {
            printMenu();
            std::cin >> response;
            respond(response, myDB);
            if (response != 5) {
            enterToContinue();
            }
        }while(response != 5);
    } else {
        std::cout << "!!! Could not connect to the film database" << std::endl;
    }
  return 0;
}