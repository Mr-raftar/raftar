#include <iostream>
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
