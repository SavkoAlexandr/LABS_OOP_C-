#include "pch.h"
#include <iostream>
#include "Deque.hpp"

using namespace std;

void menu() {
    cout << "\nDeque Menu:\n";
    cout << "1. Push Back\n";
    cout << "2. Pop Back\n";
    cout << "3. Access Element\n";
    cout << "4. Show Size\n";
    cout << "5. Iterate Positive Elements\n";
    cout << "6. Iterate Negative Elements\n";
    cout << "7. Exit\n";
}

int main() {
    Deque<int> deque;
    int choice, value, index;

    while (true) {
        menu();
        cout << "Choose an option: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                deque.push_back(value);
                break;
            case 2:
                deque.pop_back();
                cout << "Last element removed.\n";
                break;
            case 3:
                cout << "Enter index: ";
                cin >> index;
                cout << "Element: " << deque[index] << "\n";
                break;
            case 4:
                cout << "Size: " << deque.size() << "\n";
                break;
            case 5:
                cout << "Positive elements: ";
                for (auto it = deque.positive_begin(); it != deque.positive_end(); ++it) {
                    cout << *it << " ";
                }
                cout << "\n";
                break;
            case 6:
                cout << "Negative elements: ";
                for (auto it = deque.negative_begin(); it != deque.negative_end(); ++it) {
                    cout << *it << " ";
                }
                cout << "\n";
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice.\n";
            }
        }
        catch (const DequeException& ex) {
            cerr << "Deque error: " << ex.what() << "\n";
        }
        catch (const std::exception& ex) {
            cerr << "General error: " << ex.what() << "\n";
        }
    }
}
