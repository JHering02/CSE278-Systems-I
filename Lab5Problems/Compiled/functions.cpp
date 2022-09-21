#include "functions.h"

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