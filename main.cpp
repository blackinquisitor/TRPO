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
    std::cout << " Select operations" << std::endl;
    std::cout << "+--------------------------+" << std::endl;

    std::cin >> variant;
    while (variant < 1 || variant > 5) {
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

int NeedMaxNumber(int firstMax, int secondMax, int array[], int sizeArray) {
    for (int i = sizeArray - 1; i < sizeArray; ++i) {
        if (firstMax > array[i])
            return 1;
        else
            return 2;
        /*else
            return 3;*/
    }
}

int SortFiveNumverArray(int array[], int sizeArray) {
    int firstMax = INT32_MIN;
    int secondMax = INT32_MIN;

    for (int idx_j = 0; idx_j < 1; ++idx_j) {
        if (array[idx_j + 1] < array[idx_j])
            std::swap(array[idx_j], array[idx_j + 1]);
    }
    for (int i = 0; i < 2; ++i) {
        if (array[i] > firstMax) {
            firstMax = array[i];
        }
    }
    for (int idx_j = 2; idx_j < 3; ++idx_j) {
        if (array[idx_j + 1] < array[idx_j])
            std::swap(array[idx_j], array[idx_j + 1]);
    }
    for (int j = 2; j < 4; ++j) {
        if (array[j] > secondMax)
            secondMax = array[j];
    }

    int sorting = NeedMaxNumber(firstMax, secondMax, array, sizeArray);
    switch (sorting) {
        case 1: {
            for (int idx_i = 0; idx_i < sizeArray; ++idx_i) {
                std::swap(firstMax, array[4]);
                for (int idx_j = 0; idx_j < 2; ++idx_j) {
                    if (array[idx_j] > array[idx_j + 1])
                        std::swap(array[idx_j], array[idx_j + 1]);
                }
            }
            break;
        }
        case 2: {
            for (int idx_i = 0; idx_i < sizeArray; ++idx_i) {
                std::swap(secondMax, array[4]);
                for (int idx_j = 1; idx_j < sizeArray - 1; ++idx_j) {
                    if (array[idx_j] > array[idx_j + 1])
                        std::swap(array[idx_j], array[idx_j + 1]);
                }
            }
            break;
        }
        /*case 3: {
            for (int idx_i = 0; idx_i < sizeArray; ++idx_i) {
                for (int idx_j = 1; idx_j < sizeArray - idx_i; ++idx_j) {
                    if (array[idx_j] > array[idx_j + 1])
                        std::swap(array[idx_j], array[idx_j + 1]);
                }
            }
            break;
        }*/
    }
    std::cout << "FirstMax = " << firstMax << " SecondMax = " << secondMax << std::endl;
    return array, sizeArray;
}

int SortingArray(int array[], int sizeArray) {
    switch (sizeArray) {
        case 2: {
            for (int idx_i = 0; idx_i < sizeArray; ++idx_i) {
                if (array[idx_i + 1] < array[idx_i])
                    std::swap(array[idx_i], array[idx_i + 1]);
            }
            break;
        }
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
            array[sizeArray] = SortFiveNumverArray(array, sizeArray);
            break;
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

        variant = GetVariant(2);
        switch (variant) {
            case 1: {
                cout << " Input size array value - ";
                cout << "\n+--------------------------+" << std::endl;
                int sizeArray = GetNumber();
                while (sizeArray <= 0) {
                    cout << " Input fail, input value again ";
                    cout << "\n+--------------------------+" << std::endl;
                    sizeArray = GetNumber();
                }
                int array[sizeArray];
                cout << " Input min value";
                cout << "\n+--------------------------+" << std::endl;
                *min = GetNumber();
                cout << " Input max value - ";
                cout << "\n+--------------------------+" << std::endl;
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
