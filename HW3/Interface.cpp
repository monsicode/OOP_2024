#include "Interface.h"

void Interface::run() const {
    std::cout << "Which mode would you prefer?";
    std::cout << std::endl;
    std::cout << "1. Generate all results\n";
    std::cout << "2. Generate the results one by one \nEnter 1 or 2 to continue:\n";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "You are in the first mode, enter your file: ";
            char fileName[1024];
            std::cin.ignore();
            std::cin.getline(fileName, 1024);
            Console app(fileName);

            std::cout << "Enter the range you want: ";
            int a, b;
            std::cin >> a >> b;
            std::cout << "Your range is: [ " << a << " " << b << " ] \n";
            app.rangeAll(a, b);
            break;
        }

        case 2: {
            std::cout << "You are in the second mode, enter your file: ";
            char fileName[1024];
            std::cin.ignore();
            std::cin.getline(fileName, 1024);
            Console app(fileName);

            std::cout << "Enter the range you want: ";
            int a, b;
            std::cin >> a >> b;
            std::cout << "Your range is: [ " << a << " " << b << " ] \n";

            int curNumber = a;

            std::cout << "Would you like to generate next function? (y/n):\n";
            char ans;
            std::cin >> ans;
            app.rangeGenerate(curNumber, b);
            curNumber++;

            while ((ans == 'y' || ans == 'Y') && curNumber <= b) {
                std::cout << "Would you like to generate next function? (y/n):\n";
                std::cin >> ans;
                app.rangeGenerate(curNumber, b);
                curNumber++;

                if (curNumber == b + 1) {
                    std::cout << "Exceeded limit!";
                    break;
                }
            }
            break;
        }

        default: {
            std::cout << "Invalid choice. Exiting." << std::endl;
            break;
        }
    }

}