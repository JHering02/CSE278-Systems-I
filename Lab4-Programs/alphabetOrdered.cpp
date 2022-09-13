#include <iostream>
using namespace std;

int main() {
   char a;
   char b;
   char c;
   std::cin >> a >> b >> c;
   while(a > b || b > c || a > c) {
    if(b < a) {
        char temp = a;
        a = b;
        b = temp;
    } else if(c < b) {
        char temp = b;
        b = c;
        c = temp;
    }
   }
    cout << a << " " << b << " " << c << endl;
   return 0;
}