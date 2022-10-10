#include <iostream>
#include <vector>

using namespace std;

bool IsVectorMult10(vector<int> myVec) {
   for(int i = 0; i < myVec.size(); ++i) {
      if(!((myVec.at(i) % 10) == 0)) {
         return false;
      }
   }
   return true;
}

bool IsVectorNoMult10(vector<int> myVec) {
   for(int i = 0; i < myVec.size(); ++i) {
      if((myVec.at(i) % 10) == 0) {
         return false;
      }
   }
   return true;
}

int main() {
   int nums = 0;
   cin >> nums;
   vector<int> vecNums;
   for(int i = 0; i < nums; ++i) {
      int input = 0;
      cin >> input;
      vecNums.push_back(input);
   }
   if(IsVectorMult10(vecNums)) {
      cout << "all multiples of 10" << endl;
   } else if (IsVectorNoMult10(vecNums)) {
      cout << "no multiples of 10" << endl;
   } else {
      cout << "mixed values" << endl;
   }
   return 0;
}
