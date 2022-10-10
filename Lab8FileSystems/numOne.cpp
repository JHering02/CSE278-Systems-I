#include <filesystem>
#include <iostream>

int main() {
    std::filesystem::path pa = "/home/james/CSE278/";
    pa.append("Lab8FileSystems/");
    std::cout << pa << std::endl;
    for(auto item : pa) {
        std::cout << item << std::endl;
    }
    if(std::filesystem::exists(pa)) {
        std::cout << pa << "exists" << std::endl;
    } else {
        std::cout << pa << "doesn't exist" << std::endl;
    }
    pa.append("test.txt");
    std::cout << "Filename: " << pa.filename() << std::endl;
    std::cout << "Extension of " << pa.extension() << std::endl;
    std::cout << "The parent Path: " << pa.parent_path() << std::endl;
    std::cout << "Is this absolute path ? " << pa.is_absolute() << std::endl;

    return 0;
}
