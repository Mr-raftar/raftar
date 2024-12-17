#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int binarySearch(Student students[], int n, int targetRollNo) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        
        if (students[mid].rollNo == targetRollNo) {
            return mid; 
        } else if (students[mid].rollNo < targetRollNo) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void displayStudents(Student students[], int n) {
    cout << "\nStudent list:\n";
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

    bubbleSort(students, n);
    displayStudents(students, n);

int targetRollNo;
    cout << "\nEnter the Roll No to search: ";
    cin >> targetRollNo;

    int index = binarySearch(students, n, targetRollNo);

   if (index != -1) {
        cout << "Student Found:\nRoll No: " << students[index].rollNo
             << "\nName: " << students[index].name
             << "\nSGPA: " << students[index].sgpa << "\n";
    } else {
        cout << "Student with Roll No " << targetRollNo << " not found.\n";
    }

    return 0;
}