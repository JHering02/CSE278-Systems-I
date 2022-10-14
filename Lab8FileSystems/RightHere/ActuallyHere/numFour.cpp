#include <iostream>
#include <filesystem>
#include <string>

void printFileSystem(const std::filesystem::path &p)
{
    std::string fileType;
    std::filesystem::directory_entry d{p};
    if (std::filesystem::is_regular_file(d))
    {
        fileType = "file";
        std::cout << std::setw(18) << std::left << p.filename().string();
        std::cout << std::setw(4) << std::left << fileType << "\t";
        std::cout << std::setw(96) << std::left << p.string();
        std::cout << std::left << "   " << d.file_size() << " bytes";
        std::cout << "\n";
    }
    else if (std::filesystem::is_directory(d))
    {
        fileType = "dir";
        std::cout << std::setw(18) << std::left << p.filename().string();
        std::cout << std::setw(4) << std::left << fileType << "\t";
        std::cout << std::setw(96) << std::left << p.string();
        std::cout << std::left << "   "
                  << "---" << std::endl;
    }
}

int handleFiles(const std::filesystem::path &pa, const std::filesystem::path &p)
{
    // Recursive way of handling the file path
    if (std::filesystem::is_directory(pa))
    {
        printFileSystem(pa);
        for (auto item : std::filesystem::directory_iterator(pa))
        {
            int temp = handleFiles(item, p);
            if (p.compare(item) == 0 || temp == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    else if (std::filesystem::is_regular_file(pa))
    {
        printFileSystem(pa);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Not enough arguments passed." << std::endl;
        return 0;
    }
    else
    {
        std::filesystem::path pa = argv[1];
        std::filesystem::path p = argv[2];
        if (!(std::filesystem::exists(pa)) || !(std::filesystem::exists(p)))
        {
            std::cout << "A directory or file you passed doesn't exist." << std::endl;
            return 0;
        }
        handleFiles(pa, p);
    }
}