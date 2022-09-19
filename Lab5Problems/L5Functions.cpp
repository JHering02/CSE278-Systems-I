#include <iostream>
using namespace std;

// string RemoveNonAlpha(string in) {
//     string res = "";
//     for(char ch : in) {
//         if (isalpha(ch)) {
//             res += ch;
//         }
//     }
//     return res;
// }

void RemoveNonAlpha(string& in) {
    string temp = "";
    for (char ch : in) {
        if (isalpha(ch)) {
           temp += ch;
        }
    }
    in = temp;
}

int CheckOrder(int in1, int in2, int in3, int in4) {
    int nums [4] = {in1, in2, in3, in4};
    int count = 0;
    for(int i = 0; i < (sizeof(nums) / sizeof(int)) - 1; ++i) {
        if(nums[i] > nums[i + 1]) {
            count++;
        } else if(nums[i] == nums[i + 1]){
            count++;
        } else {
            count--;
        }
    }
    if (count == -3) {
        return -1;
    } else if (count == 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    //Q2
//    string input = "";
//    getline(cin, input);
// //    input = RemoveNonAlpha(input);
//     RemoveNonAlpha(input);
//    cout << input << endl;
    cout << CheckOrder(100, 200, 300, 400) + "\n" << CheckOrder(400, 300, 200, 100) + "\n" << CheckOrder(100, 500, 300, 400) + "\n";
   return 0;
}