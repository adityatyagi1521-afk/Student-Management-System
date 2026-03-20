#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    char name[50];
    int age;

    void input() {
        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter Age: ";
        cin >> age;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age << endl;
    }
};

// Add Student
void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    s.input();
    file.write((char*)&s, sizeof(s));

    file.close();
    cout << "Student Added Successfully!\n";
}

// Display Students
void displayStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);

    if (!file) {
        cout << "No records found!\n";
        return;
    }

    while (file.read((char*)&s, sizeof(s))) {
        s.display();
    }

    file.close();
}

// Search Student
void searchStudent() {
    Student s;
    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    ifstream file("students.dat", ios::binary);
    bool found = false;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == searchId) {
            cout << "\nStudent Found:";
            s.display();
            found = true;
        }
    }

    if (!found) {
        cout << "Student Not Found!\n";
    }

    file.close();
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}