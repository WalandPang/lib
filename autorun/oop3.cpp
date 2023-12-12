#include <iostream>
using namespace std;

class Books {
private:
    string title;
    int price;

public:
    void getB() {
        try {
            cout << "Enter book title: ";
            cin >> title;
            cout << "Enter book price: ";
            cin >> price;

            if (price > 500 && price < 1000) {
                displayB();
            } else {
                throw 1;
            }
        } catch (int i) {
            cout << "Caught exception in getB()" << endl;
            cout << "Invalid data entered" << endl;
            title = "";
            price = 0;
            displayB();
            throw;
        }
    }

    void displayB() {
        cout << "The details of the book you entered are:" << '\n';
        cout << "Title: " << title << '\n';
        cout << "Price: " << price << '\n';
    }
};

class Tape {
private:
    string title;
    float price;
    int min;

public:
    void getT() {
        try {
            cout << "Enter tape title: ";
            cin >> title;
            cout << "Enter tape price: ";
            cin >> price;
            cout << "Enter play time (in minutes): ";
            cin >> min;

            if (price > 500 && price < 1000) {
                displayT();
            } else {
                throw 0.0f;
            }
        } catch (float f) {
            cout << "Caught exception in getT()" << endl;
            cout << "Invalid data entered" << endl;
            title = "";
            price = 0.0;
            min = 0;
            displayT();
            throw;
        }
    }

    void displayT() {
        cout << "The details of the tape you entered are:" << '\n';
        cout << "Title: " << title << '\n';
        cout << "Price: " << price << '\n';
        cout << "Play time: " << min << " minutes" << '\n';
    }
};

int main() {
    Books b;
    Tape t;
    int choice;

    cout << "Do you want to buy a book (Press 1) or a tape (Press 2): ";
    cin >> choice;

    switch (choice) {
    case 1:
        try {
            b.getB();
        } catch (...) {
            cout << "Caught exception in main()" << endl;
        }
        break;

    case 2:
        try {
            t.getT();
        } catch (...) {
            cout << "Caught exception in main()" << endl;
        }
        break;

    default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }

    return 0;
}

