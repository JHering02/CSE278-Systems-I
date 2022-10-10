#include <filesystem>
#include <iostream>

int main() {
    std::filesystem::path pa = "/home/james/CSE278/Lab8FileSystems/numTwo.cpp";
    std::filesystem::directory_entry d{pa};
    if (d.exists() && d.is_regular_file()) {
        std::cout << d.file_size() << " bytes " << std::endl;
    }
    return 0;
}