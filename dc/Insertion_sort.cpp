#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void insertionSort(Student students[], int n) {
    for (int i = 1; i < n; ++i) {
        Student key = students[i]; 
        int j = i - 1;
        while (j >= 0 && students[j].rollNo > key.rollNo) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key; 
    }
}

void displayStudents(Student students[], int n) {
    cout << "\nRoll Call List:\n";
    cout << "Roll No\tName\t\tSGPA\n";
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << students[i].rollNo << "\t" << students[i].name << "\t\t" << students[i].sgpa << "\n";
    }
}

int main() {
    int n;
    int i;
    cout << "Enter the number of students: ";
    cin >> n;
    Student students[n];

    for (i = 0; i < n; ++i) {
        cout << "\nEnter details for student :\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }

    insertionSort(students, n);
    displayStudents(students, n);

    return 0;
}
