// Copyright heringja, 13 September 2022, James Hering
// Uses Christian Zellers algorithm to calculate the correct day of the week
// meets cpplint style
#include <iostream>

int main() {
  std::cout << "Enter a date between 1900 01 01 and 2050 12 31" << std::endl;
  int year = 0, month = 0, day = 0;
  std::cin >> year >> month >> day;
  bool isCentury = (year % 100 == 0);
  bool isLeapYear = ((!isCentury && (year % 4 == 0)) ||
                    (isCentury && (year % 400 == 0)));
  bool isThirty = (month == 4 || month == 6 ||
                   month == 9 || month == 11);
  std::string incorrectDay = "The day is not correct!!!\n";
  incorrectDay = incorrectDay + "The program will be ended...\n";
  if (year < 1900 || year > 2050) {
    std::cout << "The year is not correct!!!\nThe program will be ended...\n";
  } else if (month < 1 || month > 12) {
    std::cout << "The month is not correct!!!\nThe program will be ended...\n";
  } else if (isLeapYear && month == 2 && day > 29) {
      std::cout << incorrectDay;
  } else if (isThirty && day > 30) {
      std::cout << incorrectDay;
  } else if ((day > 31 || day < 1) ||
  (!isLeapYear && (month == 2 && day > 28))) {
      std::cout << incorrectDay;
  } else {
      if (month == 2 || month == 1) {
        month += 12;
        year = year - 1;
      }
      int date = (day + ((26 * (month + 1)) / 10) + (year % 100)
      + ((year % 100) / 4) + ((year / 100) / 4) + (5 * (year / 100))) % 7;
      switch (date) {
        case (0):
          std::cout << "Saturday\n";
          break;
        case(1):
          std::cout << "Sunday\n";
          break;
        case(2):
          std::cout << "Monday\n";
          break;
        case(3):
          std::cout << "Tuesday\n";
          break;
        case(4):
          std::cout << "Wednesday\n";
          break;
        case(5):
          std::cout << "Thursday\n";
          break;
        case(6):
          std::cout << "Friday\n";
          break;
      }
  }
}
