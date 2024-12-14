
#include <iostream>
#include <algorithm> 
using namespace std;

template <typename T>
class MSet {
private:
    T* elements;       
    size_t size;     
    size_t capacity;  

    void resize() {                                                     
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newElements = new T[capacity];                                          
        for (size_t i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

    void sort() {
        std::sort(elements, elements + size);
    }

public:
    MSet() : elements(nullptr), size(0), capacity(0) {}
    MSet(const MSet& other) :elements(nullptr), size(other.size), capacity(other.capacity) {
        if (other.size > 0) {
            elements = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
    }
         ~MSet() {
             delete[] elements;
         }
    void insert(const T& value) {
        if (size == capacity) {
            resize(); 
        }
        elements[size++] = value;
        sort(); 
    }

    
    bool remove(const T& value) {                               
        for (size_t i = 0; i < size; ++i) {
            if (elements[i] == value) {
                for (size_t j = i; j < size - 1; ++j) {
                    elements[j] = elements[j + 1];
                }
                --size;
                return true;
            }
        }
        return false; 
    }

    
    bool contains(const T& value) const {
        for (size_t i = 0; i < size; ++i) {
            if (elements[i] == value) {
                return true;
            }
        }
        return false;
    }

    
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MSet<int> mySet;
    int choice;

    cout << "Menu:\n";
    cout << "1. Add number\n";
    cout << "2. Remove number\n";
    cout << "3. Check if number exists\n";
    cout << "4. Print set\n";
    cout << "5. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int num;
            cout << "Enter number to add: ";
            cin >> num;
            mySet.insert(num);
            break;
        }
        case 2: {
            int num;
            cout << "Enter number to remove: ";
            cin >> num;
            if (mySet.remove(num)) {
                cout << "Number removed successfully.\n";
            }
            else {
                cout << "Number not found.\n";
            }
            break;
        }
        case 3: {
            int num;
            cout << "Enter number to check: ";
            cin >> num;
            if (mySet.contains(num)) {
                cout << "Number exists in the set.\n";
            }
            else {
                cout << "Number does not exist in the set.\n";
            }
            break;
        }
        case 4:
            cout << "Set elements: ";
            mySet.print();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}






























