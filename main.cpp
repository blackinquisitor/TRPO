#include <iostream>
#include <stdio.h>


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
    char line[100];
    scanf("%s", line);

    while (sscanf(line, "%d", &variant) != 1 || variant < 1 || variant > 5) {
        printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
       //scanf("%s", line);
    }
    return variant;
}

int main() {
    system("cls");
    system("color 5");

    using namespace std;

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