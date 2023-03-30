#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include  <regex>




void PrintMenu() {

    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|1. Sort  3 random elements|" << std::endl;
    std::cout << "|2. Sort  4 random elements|" << std::endl;
    std::cout << "|3. Sort  5 random elements|" << std::endl;
    std::cout << "|4. Sort your elements     |" << std::endl;
    std::cout << "|5. Exit                   |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
}

int GetVariant(int count) {
    int variant;
    char VariantLine[100];
    scanf("%s", VariantLine);

    while (scanf(VariantLine, "%d", &variant) != 1 || variant < 1 || variant > 5) {
        printf("Incorrect input. Try again: ");
        scanf("%s", VariantLine);
    }
    return variant;
}

bool IsNumeric(std::string const &number) {
    return std::regex_match(number, std::regex("[(-|+)|][0-9]+"));
}

double GetMin() {
    double min;
    std::string minStr;

        std::cout << "Input min value (through.)" << std::endl;
        std::cin >> minStr;
        while (IsNumeric(minStr) == false) {
            std::cout << "Input min value again" << std::endl;
                std::cin >> minStr;
            if (IsNumeric(minStr) == true) {
                break;
            };
        };
        std::string::size_type sz;
        min = std::stod(minStr, &sz);
    return min;
}
double GetMax() {
    double max;

    std::cin >> max;

    return max;

}

int main() {
    system("cls");
    system("color 5");

    using namespace std;

    double min;
    min = GetMin();


    cout << "Min = " << min;
    int variant;
    do {
        PrintMenu();

        variant = GetVariant(5);
        switch (variant) {
            case 1:
                cout << "| 1, 2, 3                  |" << std::endl;
                break;
            case 2:
                cout << "| 1, 2, 3, 4               |" << std::endl;
                break;
            case 3:
                cout << "| 1, 2, 3, 4, 5            |" << std::endl;
                break;

        }
        if (variant == 5)
            system("pause");
    } while (variant != 5);

    return 0;
}

