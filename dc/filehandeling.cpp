#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
    int rollNumber;
    string name, division, address;

public:
    void getData() {
        cout << "Enter Roll Number: ";#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to store student data
struct Student {
    int rollNo;
    string name;
    string division;
    string address;
};

// Function to add a student record to the file
void addStudent(fstream &file) {
    Student student;

    // Ask for student details
    cout << "Enter Roll Number: ";
    cin >> student.rollNo;
    cin.ignore();  // To ignore the newline character after entering roll number

    cout << "Enter Name: ";
    getline(cin, student.name);

    cout << "Enter Division: ";
    getline(cin, student.division);

    cout << "Enter Address: ";
    getline(cin, student.address);

    // Move the file pointer to the end to append new data
    file.seekp(0, ios::end);
    
    // Write the student record to the file
    file.write(reinterpret_cast<char*>(&student), sizeof(student));
    cout << "Student record added successfully.\n";
}

// Function to delete a student record from the file
void deleteStudent(fstream &file) {
    int rollNo;
    cout << "Enter Roll Number of the student to delete: ";
    cin >> rollNo;

    file.clear();
    file.seekg(0, ios::beg);

    // Create a temporary file for storing updated records
    fstream tempFile("temp.dat", ios::out | ios::binary);

    bool found = false;
    Student student;
    
    // Read and copy all records except the one to be deleted
    while (file.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNo != rollNo) {
            tempFile.write(reinterpret_cast<char*>(&student), sizeof(student));
        } else {
            found = true;
        }
    }

    if (found) {
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record with Roll Number " << rollNo << " not found.\n";
    }

    // Close the files
    file.close();
    tempFile.close();

    // Remove the original file and rename the temporary file
    remove("students.dat");
    rename("temp.dat", "students.dat");

    // Reopen the original file for future operations
    file.open("students.dat", ios::in | ios::out | ios::binary);
}

// Function to display student details by roll number
void displayStudent(fstream &file) {
    int rollNo;
    cout << "Enter Roll Number to display details: ";
    cin >> rollNo;

    file.clear();
    file.seekg(0, ios::beg);

    bool found = false;
    Student student;

    // Search for the student with the given roll number
    while (file.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNo == rollNo) {
            found = true;
            cout << "\nStudent Details:\n";
            cout << "Roll Number: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << rollNo << " not found.\n";
    }
}

// Main function
int main() {
    fstream file;

    // Open the file for reading and writing in binary mode
    file.open("students.dat", ios::in | ios::out | ios::binary);

    if (!file) {
        // If the file does not exist, create it
        file.open("students.dat", ios::out | ios::binary);
        file.close();
        file.open("students.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    while (true) {
        // Menu options
        cout << "\nStudent Database Management\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(file);
                break;
            case 2:
                deleteStudent(file);
                break;
            case 3:
                displayStudent(file);
                break;
            case 4:
                cout << "Exiting program...\n";
                file.close();
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Division: ";
        getline(cin, division);
        cout << "Enter Address: ";
        getline(cin, address);
    }

    void showData() const {
        cout << "Roll No: " << rollNumber 
             << ", Name: " << name 
             << ", Division: " << division 
             << ", Address: " << address << endl;
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

// Function to add a student record
void addRecord() {
    ofstream outFile("student_database.dat", ios::app | ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    Student s;
    s.getData();
    outFile.write(reinterpret_cast<char*>(&s), sizeof(Student));
    outFile.close();
    cout << "Record added successfully.\n";
}

// Function to display all student records
void displayRecords() {
    ifstream inFile("student_database.dat", ios::in | ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return;
    }
    Student s;
    bool isEmpty = true;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        s.showData();
        isEmpty = false;
    }
    if (isEmpty)
        cout << "No records found.\n";
    inFile.close();
}

// Function to search for a student record by roll number
void searchRecord(int rollNo) {
    ifstream inFile("student_database.dat", ios::in | ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return;
    }
    Student s;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.getRollNumber() == rollNo) {
            s.showData();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Record not found.\n";
    inFile.close();
}

// Main function
int main() {
    int choice, rollNo;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                cout << "Enter Roll Number to search: ";
                cin >> rollNo;
                searchRecord(rollNo);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
