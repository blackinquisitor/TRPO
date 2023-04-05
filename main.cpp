#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>



void PrintMenu() {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|1. Sort  3 random elements|" << std::endl;
    std::cout << "|2. Sort  4 random elements|" << std::endl;
    std::cout << "|3. Sort  5 random elements|" << std::endl;
    std::cout << "|4. Sort your elements     |" << std::endl;
    std::cout << "|5. Exit                   |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
}

int GetVariant(int number) {
    int variant;

    std::cin >> variant;
    while (variant < 1 || variant > 5) {
        printf("Incorrect input. Try again: ");
        std::cin >> variant;
    }
    return variant;
}

int GetNumber() {
    int number;
    std::cout << "Input value" << std::endl;
    std::cin >> number;

    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');


        std::cout << "Input failed. Input value again" << std::endl;
        std::cin >> number;
    }
    return number;
}

int CheckNumber(int* firstNumber, int* secondNumber) {
    if (*firstNumber > *secondNumber)
        std::swap(*firstNumber, *secondNumber);
    return *firstNumber, *secondNumber;
}



int GetRandomNumber(int min, int  max) {
    return min + rand() % (max - min + 1);
}

void PrintArray(int array[], int size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int FirstSortingArray(int array[], int sizeArray) {
    for (int idx_i = 0; idx_i < sizeArray; ++idx_i) {
        for (int idx_j = 0; idx_j < sizeArray - 1 - idx_i; ++idx_j) {
            if (array[idx_j + 1] < array[idx_j])
                std::swap(array[idx_j], array[idx_j + 1]);
        }
    }
    PrintArray(array, sizeArray);
}

int MiddleArray(int sizeArray) {
    double doubleSizeArray = sizeArray;
    if (sizeArray % 2 ==0)
        return  sizeArray / 2 + 1;
    else if (sizeArray % 2 != 0) {
        return round(doubleSizeArray / 2);
    }
}

int SecondSortingArray(int array[], int sizeArray) {
    for (int idx_i = 0; idx_i < sizeArray; ++idx_i) {
        for (int idx_j = 0; idx_j < MiddleArray(sizeArray); ++idx_j) {
            if (array[idx_j + 1] < array[idx_j])
                std::swap(array[idx_j], array[idx_j + 1]);
            if (idx_i == 1) {
                if (array[1] > array[idx_j])
                    std::swap(array[idx_j], array[idx_j + 1]);
            }
        }
    }
    PrintArray(array, sizeArray);
}

int main() {
        using namespace std;
        //system("color 5");

        int *min = new int;
        int *max = new int;

        int variant;
        do {
            PrintMenu();

            variant = GetVariant(5);
            switch (variant) {
                case 1: {
                    *min = GetNumber();
                    *max = GetNumber();

                    int const sizeArray = 3;
                    int array[sizeArray];

                    srand(static_cast<int> (time(NULL)));
                    for (int i = 0; i < sizeArray; ++i) {
                        array[i] = GetRandomNumber(*min, *max);
                    }
                    cout << "Unsorted array:" << endl;
                    PrintArray(array, sizeArray);
                    cout << endl;

                    cout << "Sorted array:" << endl;
                    FirstSortingArray(array, sizeArray);
                    break;
                }
                case 2: {
                    *min = GetNumber();
                    *max = GetNumber();

                    int const sizeArray = 4;
                    int array[sizeArray] ;

                    srand(static_cast<int> (time(NULL)));
                    for (int i = 0; i < sizeArray; ++i) {
                        array[i] = GetRandomNumber(*min, *max);
                    }
                    cout << "Unsorted array:" << endl;
                    PrintArray(array, sizeArray);
                    cout << endl;

                    cout << "Sorted array:" << endl;
                    SecondSortingArray(array, sizeArray);
                    break;
                }
                case 3: {
                    *min = GetNumber();
                    *max = GetNumber();

                    int const sizeArray = 5;
                    int array[sizeArray];

                    srand(static_cast<int> (time(NULL)));
                    for (int i = 0; i < sizeArray; ++i) {
                        array[i] = GetRandomNumber(*min, *max);
                    }
                    cout << "Unsorted array:" << endl;
                    PrintArray(array, sizeArray);
                    cout << endl;

                    cout << "Sorted array:" << endl;
//                SortArray(array, sizeArray);
                    break;
                }
            }
//        if (variant == 5)
//            system("pause");
        } while (variant != 5);

        return 0;
}