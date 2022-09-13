#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double db1;
    double db2;
    double epsilon;
    cin >> db1;
    cin >> db2;
    cin >> epsilon;
    if (abs(db1 - db2) <= .001 && abs(db2 - db1) <= .001) {
        cout << "equal" << endl;
    } else if (abs(db1 - db2) <= epsilon && abs(db2 - db1) <= epsilon) {
        cout << "close enough" << endl;
    } else {
        cout << "not close" << endl;
    }
   return 0;
}