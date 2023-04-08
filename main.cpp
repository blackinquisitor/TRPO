#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>



void PrintMenu() {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << " 1. Sort elements          " << std::endl;
    std::cout << " 2. console clear          " << std::endl;
    std::cout << " 3. Exit                   " << std::endl;
    std::cout << "+--------------------------+" << std::endl;
}

int GetVariant(int number) {
    int variant;
    std::cout << "\nSelect operations - ";

    std::cin >> variant;
    while (variant < 1 || variant > number || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');

        printf("Incorrect input. Try again: ");
        std::cin >> variant;
    }
    return variant;
}

int GetNumber() {
    int number;
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

int MiddleArray(int sizeArray) {
    double doubleSizeArray = sizeArray;
    if (sizeArray % 2 ==0)
        return  sizeArray / 2 + 1;
    else if (sizeArray % 2 != 0) {
        return round(doubleSizeArray / 2);
    }
}

void SortingFiveElementsArray(int array[], int sizeArray) {
    if  (array[0] > array[1])
        std::swap(array[0], array[1]);
    if  (array[2] > array[3])
        std::swap(array[2], array[3]);

    int firstMax = std::max(array[0], array[1]);
    int secondMax = std::max(array[2], array[3]);

    if (firstMax > secondMax) {
        if (array[4] < firstMax)
            std::swap(array[4], firstMax);
    }
    else if (secondMax > firstMax) {
        if (array[4] < secondMax)
            std::swap(array[4], secondMax);
    }
        for (int idx_i = 0; idx_i < sizeArray; ++idx_i) {
            for (int idx_j = 0; idx_j < sizeArray - 1; ++idx_j) {
                if (array[idx_j] > array[idx_j + 1])
                    std::swap(array[idx_j], array[idx_j + 1]);
            }
        }
}

int SortingArray(int array[], int sizeArray) {
    switch (sizeArray) {
        case 3: {
            for (int idx_i = 0; idx_i < sizeArray; ++idx_i) {
                for (int idx_j = 0; idx_j < sizeArray - 1 - idx_i; ++idx_j) {
                    if (array[idx_j + 1] < array[idx_j])
                        std::swap(array[idx_j], array[idx_j + 1]);
                }
            }
            break;
        }

        case 4: {
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
            break;
        }
        case 5: {
        SortingFiveElementsArray(array, sizeArray);
        break;
    }
        default: {
            for (int i = 0; i < sizeArray / 5; ++i) {
                SortingFiveElementsArray(array + i * 5, 5);
            }
            SortingFiveElementsArray(array + sizeArray / 5 * 5, sizeArray % 5);
            }
            break;
    }
    PrintArray(array, sizeArray);
}




int main() {
    using namespace std;

    int *min = new int;
    int *max = new int;


    int variant;
    do {
        PrintMenu();

        variant = GetVariant(2);
        switch (variant) {
            case 1: {
                cout << "\nInput size array value - ";
                int sizeArray = GetNumber();
                while (sizeArray <= 0) {
                    cout << "\nInput fail, input value again ";
                    sizeArray = GetNumber();
                }
                int array[sizeArray];
                cout << "\nInput min value - ";
                *min = GetNumber();
                cout << "\nInput max value - ";
                *max = GetNumber();
                CheckNumber(min, max);

                srand(static_cast<int> (time(NULL)));
                for (int i = 0; i < sizeArray; ++i) {
                    array[i] = GetRandomNumber(*min, *max);
                }
                cout << "Unsorted array:" << endl;
                PrintArray(array, sizeArray);
                cout << endl;

                cout << "Sorted array:" << endl;
                SortingArray(array, sizeArray);
                break;
            }
            case 2: {
                for (int i = 0; i < 10; ++i) {
                    cout << "\n\n\n\n\n\n\n\n\n\n";
                }
                break;
            }
        }
        if (variant == 3)
            system("pause");
    } while (variant != 3);

    return 0;
}
