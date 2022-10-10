#include <iostream>
#include <filesystem>
#include <string>

void printFiles(const std::filesystem::path& pa, std::filesystem::path p) {
        // recursive case
           if (std::filesystem::is_directory(pa)) {
            for(auto item : std::filesystem::directory_iterator(pa)) {
                
                printFiles(item, p);
            }
           } else if (std::filesystem::is_regular_file(pa)) {
                
           }
}

int main() {
    std::filesystem::path pa = "/home/james/CSE278/Lab8FileSystems/";
    printFiles();
}