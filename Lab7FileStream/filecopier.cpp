#include <iostream>
#include <fstream> 
using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 3) {
        cout << "Not enough arguments passed.";
    }
    ifstream inFile;
    string input = argv[1];
    int numLines = atoi(argv[2]);
    inFile.open(input);
    if (!inFile.is_open()) {
      cout << "Could not open file numFile.txt." << endl;
      return 1; // Error 
   }
    string output;
    ofstream outFile;
    outFile.open("copy_" + input);
    for(int i = 0; i < numLines; ++i) {
        getline(inFile, output);
        outFile << output << "\n";
    }
    inFile.close();
    outFile.close();
}

