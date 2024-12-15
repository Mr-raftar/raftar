#include <iostream>
#include <string.h>
#include <cmath> // for fabs()
using namespace std;

typedef struct student {
    int roll_num;
    char name[20];
    float marks;
} stud;

void create(stud s[20], int n);
void display(stud s[20], int n);
void bubble_sort(stud s[20], int n); // Arrange list of students by roll number
void insertionSort(stud s[20], int n); // Arrange list of students alphabetically
void quick_sort(stud s[20], int, int); // Arrange list of students by marks
int partition(stud s[20], int, int);
void search(stud s[20], int n, float key); // Search students by marks
int bsearch(stud s[20], char x[20], int low, int high); // Search students by name

int main() {
    stud s[20];
    int ch, n = 0, result;
    char x[20];
    float key;

    do {
        cout << "\n 1) Create Student Database ";
        cout << "\n 2) Display Student Records ";
        cout << "\n 3) Bubble Sort ";
        cout << "\n 4) Insertion Sort ";
        cout << "\n 5) Quick Sort ";
        cout << "\n 6) Linear Search ";
        cout << "\n 7) Binary Search ";
        cout << "\n 8) Exit ";
        cout << "\n Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\n Enter the number of records: ";
            cin >> n;
            create(s, n);
            break;

        case 2:
            display(s, n);
            break;

        case 3:
            bubble_sort(s, n);
            break;

        case 4:
            insertionSort(s, n);
            break;

        case 5:
            quick_sort(s, 0, n - 1);
            cout << "\n\tRoll No\tName\tMarks";
            for (int i = n - 1; i >= max(0, n - 10); i--) {
                cout << "\n\t" << s[i].roll_num << "\t" << s[i].name << "\t" << s[i].marks;
            }
            break;

        case 6:
            cout << "\n Enter the marks you want to search for: ";
            cin >> key;
            search(s, n, key);
            break;

        case 7:
            cout << "\n Enter the name of the student you want to search for: ";
            cin >> x;
            insertionSort(s, n); // Binary search requires a sorted array
            result = bsearch(s, x, 0, n - 1);
            if (result == -1) {
                cout << " \n Student name you searched for is not present! \n";
            } else {
                cout << " \n The student is present: \t" << s[result].name;
            }
            break;

        case 8:
            return 0;

        default:
            cout << "\n Invalid choice! Please enter your choice again." << endl;
        }
    } while (ch != 8);

    return 0;
}

void create(stud s[20], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n Enter the roll number: ";
        cin >> s[i].roll_num;
        cout << "\n Enter the name: ";
        cin >> s[i].name;
        cout << "\n Enter the marks: ";
        cin >> s[i].marks;
    }
}

void display(stud s[20], int n) {
    cout << "\n\tRoll No\tName\tMarks";
    for (int i = 0; i < n; i++) {
        cout << "\n\t" << s[i].roll_num << "\t" << s[i].name << "\t" << s[i].marks;
    }
}

void bubble_sort(stud s[20], int n) {
    stud temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (s[j].roll_num > s[j + 1].roll_num) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void insertionSort(stud s[20], int n) {
    for (int i = 1; i < n; i++) {
        stud key = s[i];
        int j = i - 1;

        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

void quick_sort(stud s[20], int l, int u) {
    if (l < u) {
        int j = partition(s, l, u);
        quick_sort(s, l, j - 1);
        quick_sort(s, j + 1, u);
    }
}

int partition(stud s[20], int l, int u) {
    stud v = s[l];
    int i = l, j = u + 1;

    do {
        do i++; while (i <= u && s[i].marks < v.marks);
        do j--; while (s[j].marks > v.marks);

        if (i < j) {
            stud temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    } while (i < j);

    s[l] = s[j];
    s[j] = v;

    return j;
}

void search(stud s[20], int n, float key) {
    cout << "\n\tRoll No\tName\tMarks";
    for (int i = 0; i < n; i++) {
        if (fabs(key - s[i].marks) < 0.0001) { // Compare floating-point values
            cout << "\n\t" << s[i].roll_num << "\t" << s[i].name << "\t" << s[i].marks;
        }
    }
}

int bsearch(stud s[20], char x[20], int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(x, s[mid].name);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
