#include <random>
#include <iostream>


void printArray(int a[], size_t Len)
{
    for (int i = 0; i < Len; ++i)
    {
        std::cout << a[i] << std::endl;
    }
}

void fillArrayRandomly(int prev[], size_t size, int max)
{
    // Creating the random number distribution provided
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, max);
    // Assigning values
    for (int i = 0; i < size; ++i)
    {
        prev[i] = distrib(gen);
    }
}

void printHistogram(const int arr[], size_t size, int max)
{
    // Declaring an array for each possible int value
    int temp[max] = {0};
    
    for (int i = 0; i < max; ++i) {
        temp[i] = i + 1;
    }

    // Going through and checking frequency of each value
    for (int i = 0; i < max; ++i) 
    {
        int count = 0;
        for (int j = 0; j < size; ++j)
        {
            if (temp[i] == arr[j])
            {
                count++;
            }
        }
        // Printing the results
        std::cout << "Number " << temp[i] << " repeats " << count << " times." << std::endl;
    }
}

int main()
{
    // Random 1000 array
    int test[1000] = {0};
    fillArrayRandomly(test, 1000, 10);
    std::cout << "1st List" << std::endl;
    printHistogram(test, 1000, 10);
    // Random 10000 array
    std::cout << "2nd List" << std::endl;
    int test2[10000] = {0};
    fillArrayRandomly(test2, 10000, 10);
    printHistogram(test2, 10000, 10);
    return 0;
}
