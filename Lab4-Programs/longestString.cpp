#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	string str2;
    cin >> str1;
    cin >> str2;
    if(str1.length() == str2.length() || str2.length() > str1.length()) {
        cout << str2 << endl;
    } else {
        cout << str1 << endl;
    }

   return 0;
}