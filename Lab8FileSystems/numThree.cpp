#include <iostream>
#include <filesystem>
#include <string>

void printFilesAsFolders(const std::filesystem::path& p, size_t level) {
    // base case
    std::string dash(level*2,'-');
    if(std::filesystem::is_regular_file(p)) {
        std::cout << dash << "file: " << p.filename() << std::endl;
    } else if (!(std::filesystem::exists(p))) {
        return;
    } else if (std::filesystem::is_directory(p)) {
        // recursive case
        std::cout << dash << "dir: " << p << std::endl;
        for(auto item : std::filesystem::directory_iterator(p)) {
            printFilesAsFolders(item, level+1);
        }
    }
}

int main() {
    std::filesystem::path pa = "/home/james/CSE278/Lab8FileSystems/";
    printFilesAsFolders(pa, 0);
}