#include <iostream>
#include <cstring>
#define MAX_SIZE 20

using namespace std;

class PersonAdditionalInfo {
    char address[MAX_SIZE], license[MAX_SIZE], insurance[MAX_SIZE];
    long int contact;

public:
    PersonAdditionalInfo() {
        strcpy(address, "XYZ");
        strcpy(license, "XY-0000000000");
        strcpy(insurance, "XY00000000X");
        contact = 0;
    }

    ~PersonAdditionalInfo() {
        cout << "I am in Destructor";
    }

    friend class Person; // Declare friend class
};

class Person {
    char name[MAX_SIZE], dob[MAX_SIZE], blood[MAX_SIZE];
    float ht, wt;
    static int count; // Static variable
    PersonAdditionalInfo* pai;

public:
    Person() {
        strcpy(name, "XYZ");
        strcpy(dob, "dd/mm/yy");
        strcpy(blood, "A +");
        ht = 0;
        wt = 0;
        pai = new PersonAdditionalInfo;
        count++;
    }

    Person(Person* p1) {
        strcpy(name, p1->name);
        strcpy(dob, p1->dob);
        strcpy(blood, p1->blood);
        ht = p1->ht;
        wt = p1->wt;
        pai = new PersonAdditionalInfo;
        strcpy(pai->address, p1->pai->address);
        strcpy(pai->license, p1->pai->license);
        strcpy(pai->insurance, p1->pai->insurance);
        pai->contact = p1->pai->contact;
        count++;
    }

    static void ShowCount() {
        cout << "\nNo of records count=" << count << "\n";
    }

    ~Person() {
        cout << "\nI am in Destructor\n";
    }

    void GetData(char name[MAX_SIZE]);
    inline void Display();
};

int Person::count = 0;

void Person::GetData(char name[MAX_SIZE]) {
    strcpy(this->name, name);
    cout << "\nEnter date of birth: ";
    cin >> dob;
    cout << "\nEnter blood group: ";
    cin >> blood;
    cout << "\nEnter height: ";
    cin >> ht;
    cout << "\nEnter weight: ";
    cin >> wt;
    cout << "\nEnter address: ";
    cin >> pai->address;
    cout << "\nEnter License number: ";
    cin >> pai->license;
    cout << "\nEnter Insurance policy number: ";
    cin >> pai->insurance;
    cout << "\nEnter Contact number: ";
    cin >> pai->contact;
}

inline void Person::Display() {
    cout << "\t" << name;
    cout << "\t" << dob;
    cout << "\t" << blood;
    cout << "\t" << ht;
    cout << "\t" << wt;
    cout << "\t" << pai->address;
    cout << "\t" << pai->license;
    cout << "\t" << pai->insurance;
    cout << "\t" << pai->contact;
}

int main() {
    Person* p1, * p2;
    int ch;
    p1 = new Person; // Call default constructor & dynamic memory allocation
    p2 = new Person(p1); // Call copy constructor

    cout << "\tName";
    cout << "\tDob";
    cout << "\tBlood";
    cout << "\tHt";
    cout << "\tWt";
    cout << "\tAddress";
    cout << "\tLicense";
    cout << "\tInsurance";
    cout << "\tContact";
    cout << endl;

    cout << "Default Constructor Value \n";
    p1->Display();
    cout << "\n";
    cout << "Copy Constructor Value \n";
    p2->Display();

    int n;
    cout << "\nEnter how many records you want: ";
    cin >> n;

    Person p3[n]; // Array of objects
    char name[MAX_SIZE];
    int x = 0;

    do {
        cout << "\nWelcome to Personal database system";
        cout << "\n1. Enter the record";
        cout << "\n2. Display the record";
        cout << "\n3. Exit";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "\nEnter the Name: ";
                cin >> name;
                p3[x].GetData(name);
                Person::ShowCount(); // Calls static function
                x++;
                break;
            }
            case 2: {
                cout << "\tName";
                cout << "\tDob";
                cout << "\tBlood";
                cout << "\tHt";
                cout << "\tWt";
                cout << "\tAddress";
                cout << "\tLicense";
                cout << "\tInsurance";
                cout << "\tContact";

                for (int i = 0; i < n; i++) {
                    cout << "\n";
                    p3[i].Display(); // Calls inline function
                }
                break;
            }
        }
    } while (ch != 3);

    delete p1; // Dynamic memory de-allocation
    delete p2;

    return 0;
}

