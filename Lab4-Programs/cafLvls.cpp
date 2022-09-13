#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   cin >> caffeineMg;
   int tf = 6;
   for(int i = 0; i < 3; ++i) {
        double res = caffeineMg * (pow((.5), (tf / (6))));
        cout << fixed << setprecision(2);
        cout << "After " << tf << " hours: " << res << " mg" << endl;
        tf = tf * 2;
   }
   return 0;
}
