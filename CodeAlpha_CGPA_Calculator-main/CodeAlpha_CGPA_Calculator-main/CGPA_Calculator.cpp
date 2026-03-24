#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

/* ---------- Structure Definitions ---------- */

struct Course {
    string name;
    string grade;
    double gradePoint;
    int creditHours;
};

struct Semester {
    vector<Course> courses;
    int totalCredits = 0;
    double totalGradePoints = 0.0;
    double gpa = 0.0;
};

/* ---------- Function Prototypes ---------- */

double convertGradeToPoint (string grade);
void inputSemesterData (Semester &sem, int semesterNumber);
void calculateSemesterResult (Semester &sem);
void displaySemesterResult (const Semester &sem, int semesterNumber);

/* ---------- Grade Conversion ---------- */

double convertGradeToPoint(string grade) {
    for (char &c : grade)
        c = toupper(c);

    if (grade == "A") return 4.0;
    if (grade == "A-") return 3.7;
    if (grade == "B+") return 3.3;
    if (grade == "B") return 3.0;
    if (grade == "C") return 2.0;
    if (grade == "D") return 1.0;
    if (grade == "F") return 0.0;

    return -1.0; // Invalid grade
}

/* ---------- Input Semester Data ---------- */

void inputSemesterData(Semester &sem, int semesterNumber) {
    int courseCount;

    cout << "\nEnter number of courses for Semester " << semesterNumber << ": ";
    cin >> courseCount;

    while (courseCount <= 0) {
        cout << "Invalid number. Enter again: ";
        cin >> courseCount;
    }

    sem.courses.resize(courseCount);

    for (int i = 0; i < courseCount; i++) {
        Course &c = sem.courses[i];

        cout << "\nCourse " << i + 1 << " Name: ";
        cin.ignore();
        getline(cin, c.name);

        do {
            cout << "Grade (A, A-, B+, B, C, D, F): ";
            cin >> c.grade;
            c.gradePoint = convertGradeToPoint(c.grade);

            if (c.gradePoint < 0)
                cout << "Invalid grade. Try again.\n";

        } while (c.gradePoint < 0);

        cout << "Credit Hours: ";
        cin >> c.creditHours;

        while (c.creditHours <= 0) {
            cout << "Invalid credit hours. Enter again: ";
            cin >> c.creditHours;
        }
    }
}

/* ---------- Semester Calculation ---------- */

void calculateSemesterResult(Semester &sem) {
    sem.totalCredits = 0;
    sem.totalGradePoints = 0.0;

    for (const Course &c : sem.courses) {
        sem.totalCredits += c.creditHours;
        sem.totalGradePoints += c.gradePoint * c.creditHours;
    }

    sem.gpa = sem.totalGradePoints / sem.totalCredits;
}

/* ---------- Display Semester Result ---------- */

void displaySemesterResult(const Semester &sem, int semesterNumber) {
    cout << "\n--- Semester " << semesterNumber << " Result ---\n";

    cout << left << setw(20) << "Course"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours"
         << setw(15) << "Grade Points" << '\n';

    for (const Course &c : sem.courses) {

        // Trim leading and trailing spaces from course name
        string name = c.name;
        size_t start = name.find_first_not_of(" \t");
        size_t end   = name.find_last_not_of(" \t");

        if (start != string::npos)
            name = name.substr(start, end - start + 1);
        else
            name.clear();

        cout << left << setw(20) << name
             << setw(10) << c.grade
             << setw(15) << c.creditHours
             << setw(15) << fixed << setprecision(2)
             << (c.gradePoint * c.creditHours)
             << '\n';
    }

    cout << "\nTotal Credits: " << sem.totalCredits << '\n';
    cout << "Semester GPA: " << fixed << setprecision(2) << sem.gpa << '\n';
}

/* ---------- Main Program ---------- */

int main() {
    int totalSemesters;

    cout << "Enter total number of semesters: ";
    cin >> totalSemesters;

    while (totalSemesters <= 0) {
        cout << "Invalid input. Enter again: ";
        cin >> totalSemesters;
    }

    vector<Semester> semesters(totalSemesters);

    double overallGradePoints = 0.0;
    int overallCredits = 0;

    for (int i = 0; i < totalSemesters; i++) {
        inputSemesterData(semesters[i], i + 1);
        calculateSemesterResult(semesters[i]);
        displaySemesterResult(semesters[i], i + 1);

        overallGradePoints += semesters[i].totalGradePoints;
        overallCredits += semesters[i].totalCredits;
    }

    double cgpa = overallGradePoints / overallCredits;

    cout << "\n==============================\n";
    cout << "Final CGPA: " << fixed << setprecision(2) << cgpa << endl;
    cout << "==============================\n";

    return 0;
}