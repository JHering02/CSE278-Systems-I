#include <iostream>
#include <fstream> 
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

// Uses conditions to return the correct letter grade character given a double
char isLetterGrade(double& studentAvg) {
    if(studentAvg >= 90) {
            return 'A';
        } else if(studentAvg >= 80) {
            return 'B';
        } else if(studentAvg >= 70) {
            return 'C';
        } else if(studentAvg >= 60) {
            return 'D';
        } else {
            return 'F';
        }
}

// Takes two file streams to properly make the described report
void makeReport(ifstream& inFile, ofstream& outFile) {
    string fname, lname;
    int mid1 = 0, mid2 = 0, mid3 = 0;
    double avg1 = 0, avg2 = 0, avg3 = 0;
    int count = 0;
    while(!(inFile.eof())) {
        string currStudent;
        getline(inFile, currStudent);
        if(currStudent.empty()) {
            continue;
        }
        istringstream currLine(currStudent);
        currLine >> fname >> lname >> mid1 >> mid2 >> mid3;
        avg1 += mid1;
        avg2 += mid2;
        avg3 += mid3;
        double studentAvg = ((mid1 + mid2 + mid3) / 3.0);
        char letterGrade = isLetterGrade(studentAvg);
        count++;
        outFile << fname + "\t" << lname + "\t" << mid1 << "\t" 
        << mid2 << "\t" << mid3 << "\t" << letterGrade << endl;
    }
    avg1 /= count;
    avg2 /= count;
    avg3 /= count;
    outFile << fixed << setprecision(2);
    outFile << "\nAverages: " 
            << "midterm1 " << avg1
            << ", midterm2 " << avg2
            << ", final " << avg3 << endl;
}

// Main function
int main() {
    ifstream inFile;
    ofstream outFile;
    string input;
    cin >> input;
    inFile.open(input);
    if (!inFile.is_open()) {
      cout << "Could not open file numFile.txt." << endl;
      return 1; // Error 
   }
    outFile.open("report.txt");
    makeReport(inFile, outFile);
    inFile.close();
    outFile.close();
}
