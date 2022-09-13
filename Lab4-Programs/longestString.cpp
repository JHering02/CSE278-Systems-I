#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	string str2;
    string temp;
    cin >> str1;
    cin >> temp;
    cin >> str2;
    if(str1.length() == str2.length() || str2.length() > str1.length()) {
        cout << str2;
    } else {
        cout << str1;
    }

   return 0;
}