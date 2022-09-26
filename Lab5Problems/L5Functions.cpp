#include <iostream>

// string RemoveNonAlpha(string in) {
//     string res = "";
//     for(char ch : in) {
//         if (isalpha(ch)) {
//             res += ch;
//         }
//     }
//     return res;
// }

// void RemoveNonAlpha(string& in) {
//     string temp = "";
//     for (char ch : in) {
//         if (isalpha(ch)) {
//            temp += ch;
//         }
//     }
//     in = temp;
// }

int CheckOrder(int in1, int in2, int in3, int in4) {
    int nums [4] = {in1, in2, in3, in4};
    bool isAscending = false;
    bool isDescending = false;
    for(int i = 0; i < 3; ++i) {
        if(nums[i] > nums[i + 1]) {
            isAscending = true;
        } else {
            isDescending = true;
        }
    }
    if (isDescending && !isAscending) {
        return -1;
    } else if (isAscending && !isDescending) {
        return 1;
    } else {
        return 0;
    }
}

int CheckOrder(std::string in1, std::string in2, std::string in3, std::string in4) {
    std::string strings [4] = {in1, in2, in3, in4};
    bool isAscending = false;
    bool isDescending = false;
    for(int i = 0; i < 3; ++i) {
        if(strings[i].compare(strings[i + 1]) < 0) {
            isDescending = true;
        } else {
            isAscending = true;
        }
    }
    if (isDescending && !isAscending) {
        return -1;
    } else if (isAscending && !isDescending) {
        return 1;
    } else {
        return 0;
    }
}

int CheckOrder(double in1, double in2, double in3, double in4) {
    double doubles [4] = {in1, in2, in3, in4};
    bool isAscending = false;
    bool isDescending = false;
    for(int i = 0; i < 3; ++i) {
        if(doubles[i] > doubles[i + 1]) {
            isAscending = true;
        } else {
            isDescending = true;
        }
    }
    if (isDescending && !isAscending) {
        return -1;
    } else if (isAscending && !isDescending) {
        return 1;
    } else {
        return 0;
    }
}

int CheckOrder(char in1, char in2, char in3, char in4) {
    char chars [4] = {in1, in2, in3, in4};
    bool isAscending = false;
    bool isDescending = false;
    for(int i = 0; i < 3; ++i) {
        if(chars[i] > chars[i + 1]) {
            isAscending = true;
        } else {
            isDescending = true;
        }
    }
    if (isDescending && !isAscending) {
        return -1;
    } else if (isAscending && !isDescending) {
        return 1;
    } else {
        return 0;
    }
}

// int main() {
//     //Q2
// //    string input = "";
// //    getline(cin, input);
// // //    input = RemoveNonAlpha(input);
// //     RemoveNonAlpha(input);
// //    cout << input << endl;
//     char outputChar = CheckOrder('a', 'b', 'z', 'c');
//     cout << "Order: " << outputChar << endl;
//     string outputStr = CheckOrder("bat", "hat", "mat", "sat");
//     cout << "Order: " << outputStr << endl;
//     double outputDbl = CheckOrder( 12.8, 6.94, 3.01, 0.67);
//     cout << "Order: " << outputDbl << endl;
//    return 0;
// }
int main() {
   
    // Test 1
    std::cout << "400.4 300.4 200.5 100.44" << std::endl;
    std::cout << "Order: " << CheckOrder(400.4, 300.4, 200.5, 100.44) << std::endl;
    // Test 2
    std::cout << "100 200 300 400" << std::endl;
    std::cout <<"Order: " << CheckOrder(100, 200, 300, 400) << std::endl;
    // Test 3
    std::cout << "100 300 300 400" << std::endl;
    std::cout <<"Order: " << CheckOrder(100, 300, 300, 400) << std::endl;
    // Test 4
    std::cout << "100 500 300 400" << std::endl;
    std::cout << "Order: " <<CheckOrder(100, 500, 300, 400) << std::endl;
    // Test 5
    std::cout << " a B s Z" << std::endl;
    std::cout <<"Order: " << CheckOrder('a', 'B', 's', 'Z') << std::endl;
    // Test 6
    std::cout << " a b s z" << std::endl;
    std::cout <<"Order: " << CheckOrder('a', 'b', 's', 'z') << std::endl;
    // Test 7
    std::cout << " sat sat mat hat" << std::endl;
    std::cout <<"Order: " << CheckOrder("sat", "sat", "mat", "hat") << std::endl;
    // Test 8
    std::cout << " live long and prosper" << std::endl;
    std::cout <<"Order: " << CheckOrder("live", "long", "and", "prosper") << std::endl;
   
   return 0;
}