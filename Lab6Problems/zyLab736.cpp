#include <iostream>
#include <vector>

using namespace std;

int main() {
   int nums = 0;
   cin >> nums;
   vector<int> vecNums;
   for(int i = 0; i < nums; ++i) {
      int input = 0;
      cin >> input;
      vecNums.push_back(input);
   }
   int least = __INT_MAX__;
   int index = 0;
   for(int i = 0; i < vecNums.size(); ++i) {
      if(vecNums.at(i) < least) {
         least = vecNums.at(i);
         index = i;
      }
   }
   vecNums.erase(vecNums.begin() + index);
   cout << least << " and ";
   least = __INT_MAX__;
   for(int i = 0; i < vecNums.size(); ++i) {
      if(vecNums.at(i) < least) {
         least = vecNums.at(i);
      }
   }
   cout << least << endl;
   return 0;
}
