#include <iostream>
#include <cstring>
#include "Console.h"
using namespace std;

int main() {
  cout<<"Which mode would you prefer?";
  cout<<endl;
  cout<<"1. Generate all results\n";
  cout<<"2. Generate the results one by one \nEnter 1 or 2 to continue:";

  int choice;
  cin>>choice;

    switch (choice) {
        case 1: {
            cout << "You are in the first mode, enter your file: ";
            char fileName[1024];
            cin.ignore();
            cin.getline(fileName, 1024);
            cout<<fileName;
            //Console app(fileName);
            break;
        }
            // Add other cases as needed
        default: {
            cout << "Invalid choice. Exiting." << endl;
            break;
        }
    }


}








