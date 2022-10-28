#include <map>
#include <string>
#include <iostream>

// complete fillMap function
void fillMap(std::map<std::string, double>* student) {
  student->insert(std::pair<std::string, double>("Harry Rawlins", 84.3));
  student->insert(std::pair<std::string, double>("Stephanie Kong", 91.0));
  student->insert(std::pair<std::string, double>("Shailen Tennyson", 78.6));
  student->insert(std::pair<std::string, double>("Quincy Wraight", 65.4));
  student->insert(std::pair<std::string, double>("Janine Antinori", 98.2));
}
// complte updateMap function
bool updateMap(std::map<std::string, double>* students) {
  std::string nameCheck;
  double newGrade;
  std::cout << "Enter a name for the grade update" << std::endl;
  std::cin >> nameCheck >> newGrade;
  if((*students->find(nameCheck)) != *students->end()) {
    (*students->find(nameCheck)).second = newGrade;
    std::cout << "***Update completed***" << std::endl;
    return true;
  } else {
    std::cout << "!!!The student is not registered!!!" << std::endl;
  }
  return false;
}
// complete printMap function
void printMap(std::map<std::string, double>& students) {
  for(std::map<std::string, double>::const_iterator itr = students.begin(); 
  itr != students.end(); ++itr) {
    std::cout << itr->first << ":" << itr->second << std::endl;
  }
  std::cout << "\n";
}

int main () {
    std::map<std::string, double> studentGrades;
    fillMap(&studentGrades);
    printMap(studentGrades);
    if (updateMap(&studentGrades))
        printMap(studentGrades);
    return 0;
  
}