#include <iostream>
using namespace std;

int main() {
    int totalChange;
    cin >> totalChange;
    string res;
    if(totalChange <= 0) {
        cout << "No change" << endl;
    } else {
        while(totalChange > 0) {
            if (totalChange >= 100) {
                res = "Dollar ";
                if (totalChange / 100 > 1) {
                    res = "Dollars ";
                }
                cout << res << (totalChange / 100) << endl;
                totalChange = totalChange % 100;
            } else if (totalChange >= 25) {
                res = "Quarter ";
                if (totalChange / 25 > 1) {
                    res = "Quarters  ";
                }
                cout << res << (totalChange / 25) << endl;
                totalChange = totalChange % 25;
            } else if (totalChange >= 10) {
                res = "Dime ";
                if (totalChange / 10 > 1) {
                    res = "Dimes ";
                }
                cout << res << (totalChange / 10) << endl;
                totalChange = totalChange % 10;
            } else if (totalChange >= 5) {
                res = "Nickel ";
                if (totalChange / 5 > 1) {
                    res = "Nickels ";
                }
                cout << res << (totalChange / 5) << endl;
                totalChange = totalChange % 5;
            } else {
                res = "Penny ";
                if (totalChange > 1) {
                    res = "Pennies ";
                }
                cout << res << totalChange << endl;
                totalChange = 0;
            }
        }
    }
   return 0;
}