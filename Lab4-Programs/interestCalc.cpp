#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double amt;
    double payment;
    double interest;
    std::cin >> fixed >> setprecision(2)
             >> amt >> payment >> interest;
    int count = 1;
    while(payment <= amt) {
      amt += (amt * interest);
      amt -= payment;
      ++count;
    }
    string plur = " payment";
    if(count > 1) {plur = " payments";}
    cout << count << plur << endl;
   return 0;
}