#include <iostream>
#include <string>
using namespace std;
template <typename T>
class IPtrArr {
private:
    T* ptr;          
    size_t* refCount; 

public:
    IPtrArr() : ptr(nullptr), refCount(new size_t(1)) {}
    IPtrArr(T* p) : ptr(p), refCount(new size_t(1)) {}
    IPtrArr(const IPtrArr& other) : ptr(other.ptr), refCount(other.refCount) {
        (*refCount)++;
    }

    IPtrArr& operator=(const IPtrArr& other) {
        if (this != &other) {
            if (--(*refCount) == 0) {
                delete[] ptr;
                delete refCount;
            }
            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    ~IPtrArr() {
        if (--(*refCount) == 0) {
            delete[] ptr;
            delete refCount;
        }
    }

    void reset() {
        if (--(*refCount) == 0) {
            delete[] ptr;
            delete refCount;
        }
        ptr = nullptr;
        refCount = new size_t(1);
    }

    T* get() const {
        return ptr;
    }

    T& operator[](size_t index) {
        return ptr[index];
    }

    
    size_t size() const {
        return sizeof(ptr) / sizeof(T); 
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    do {
        cout << "Выберите тип данных:\n";
        cout << "1. int\n";
        cout << "2. double\n";
        cout << "3. string\n";
        cout << "4. Выход\n";
        cin >> choice;

        if (choice == 4) break;

        int size;
        cout << "Введите размер массива: ";
        cin >> size;

        switch (choice) {
        case 1: {
            IPtrArr<int> arr(new int[size]);
            for (int i = 0; i < size; ++i) {
                arr[i] = i + 1;
            }
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        case 2: {
            IPtrArr<double> arr(new double[size]);
            for (int i = 0; i < size; ++i) {
                arr[i] = (i + 1) * 0.5;
            }
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        case 3: {
            IPtrArr<string> arr(new string[size]);
            for (int i = 0; i < size; ++i) {
                arr[i] = "Строка " + to_string(i + 1);
            }
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (true);

    return 0;
}
