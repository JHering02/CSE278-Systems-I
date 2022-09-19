#include <iostream>
#include <string>
using namespace std;

int main() {
   bool isForm = true;
   string userString;
   cin >> userString;
   for(int i = 0 ; i < userString.size(); ++i) {
      if(!isdigit(userString[i])) {
         isForm = false;
      }
   }
   if(isForm) {
      cout << "Yes" << endl;
   } else {
      cout << "No" << endl;
   }
   return 0;
}
