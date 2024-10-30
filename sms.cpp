#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string courseName;
    int courseCredits;

    Course() {
        courseName = "";
        courseCredits = 0;
    }

    void setCourseInfo(string name, int credits) {
        courseName = name;
        courseCredits = credits;
    }

    void displayCourseInfo() const {
        cout << "Course Name: " << courseName << ", Credits: " << courseCredits << endl;
    }
};

class Grade {
public:
    string courseName;
    float score;

    Grade() {
        courseName = "";
        score = 0.0;
    }

    void setGradeInfo(string cName, float s) {
        courseName = cName;
        score = s;
    }

    void displayGradeInfo() const {
        cout << "Course: " << courseName << ", Score: " << score << endl;
    }
};

class Student {
public:
    int id;
    string name;
    float percentage;
    char grade;
    Course courses[2];  
    Grade grades[2];  

    Student() {
        id = 0;
        name = "";
        percentage = 0.0;
        grade = 'F';
    }

    Student(int i, string n, float p, char g) {
        id = i;
        name = n;
        percentage = p;
        grade = g;
    }

    void addCourseAndGrade(string courseName, int credits, string gradeName, float score, int index) {
        if (index < 2) { 
            courses[index].setCourseInfo(courseName, credits);
            grades[index].setGradeInfo(gradeName, score);
        }
    }

    void displayStudentInfo() const {
        cout << "ID: " << id << ", Name: " << name << ", Percentage: " << percentage << ", Grade: " << grade << endl;
        cout << "Courses:\n";
        for (int i = 0; i < 2; i++) {
            courses[i].displayCourseInfo();
        }
        cout << "Grades:\n";
        for (int i = 0; i < 2; i++) {
            grades[i].displayGradeInfo();
        }
    }
};

void displayMenu() {
    cout << "\nMenu Options:\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Display All Students\n";
    cout << "6. Exit\n";
}

int main() {
    const int maxStudents = 10; 
    Student students[maxStudents];
    int studentCount = 3; 

    students[0] = Student(101, "Ananya", 85.5, 'B');
    students[0].addCourseAndGrade("oops", 3, "oops", 88.0, 0);
    students[0].addCourseAndGrade("dbms", 4, "dbms", 95.5, 1);

    students[1] = Student(102, "Saumya", 92.0, 'A');
    students[1].addCourseAndGrade("oops", 3, "oops", 90.0, 0);
    students[1].addCourseAndGrade("dbms", 4, "dbms", 98.0, 1);

    students[2] = Student(103, "Manju", 78.0, 'C');
    students[2].addCourseAndGrade("math", 3, "math", 75.0, 0);
    students[2].addCourseAndGrade("phy", 4, "phy", 80.0, 1);

    int choice; 

    while (true) {
        displayMenu(); 
        cout << "Enter your choice: ";
        cin >> choice; 

        switch (choice) {
            case 1: { 
                if (studentCount < maxStudents) {
                    int id;
                    string name;
                    float percentage;
                    char grade;

                    cout << "Enter student ID: ";
                    cin >> id;
                    cout << "Enter student name: ";
                    cin >> name;
                    cout << "Enter percentage: ";
                    cin >> percentage;
                    cout << "Enter grade: ";
                    cin >> grade;
                    students[studentCount] = Student(id, name, percentage, grade);
                    for (int i = 0; i < 2; i++) {
                        string courseName;
                        int credits;
                        float score;

                        cout << "Enter course name for course " << (i + 1) << ": ";
                        cin >> courseName;
                        cout << "Enter credits for course " << (i + 1) << ": ";
                        cin >> credits;
                        cout << "Enter score for course " << (i + 1) << ": ";
                        cin >> score;

                        students[studentCount].addCourseAndGrade(courseName, credits, courseName, score, i);
                    }

                    studentCount++; 
                } else {
                    cout << "Student limit reached. Cannot add more students.\n";
                }
                break;
            }

            case 2: { 
                int id;
                cout << "Enter student ID to remove: ";
                cin >> id;
                bool found = false;

                for (int i = 0; i < studentCount; i++) {
                    if (students[i].id == id) {
                        found = true;
                        for (int j = i; j < studentCount - 1; j++) {
                            students[j] = students[j + 1]; 
                        }
                        studentCount--; 
                        cout << "Student with ID " << id << " removed.\n";
                        break;
                    }
                }
                if (!found) {
                    cout << "Student with ID " << id << " not found.\n";
                }
                break;
            }

            case 3: { 
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                bool found = false;

                for (int i = 0; i < studentCount; i++) {
                    if (students[i].id == id) {
                        students[i].displayStudentInfo(); 
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student with ID " << id << " not found.\n";
                }
                break;
            }

            case 4: {
                int id;
                cout << "Enter student ID to update: ";
                cin >> id;
                bool found = false;

                for (int i = 0; i < studentCount; i++) {
                    if (students[i].id == id) {
                        found = true;

                        cout << "Updating details for student ID: " << id << endl;
                        cout << "Enter new name: ";
                        cin >> students[i].name;
                        cout << "Enter new percentage: ";
                        cin >> students[i].percentage;
                        cout << "Enter new grade: ";
                        cin >> students[i].grade;

                        for (int j = 0; j < 2; j++) {
                            string courseName;
                            int credits;
                            float score;

                            cout << "Enter course name for course " << (j + 1) << ": ";
                            cin >> courseName;
                            cout << "Enter credits for course " << (j + 1) << ": ";
                            cin >> credits;
                            cout << "Enter score for course " << (j + 1) << ": ";
                            cin >> score;

                            students[i].addCourseAndGrade(courseName, credits, courseName, score, j);
                        }
                        break;
                    }
                }
                if (!found) {
                    cout << "Student with ID " << id << " not found.\n";
                }
                break;
            }

            case 5: { 
                if (studentCount == 0) {
                    cout << "No students to display.\n";
                } else {
                    for (int i = 0; i < studentCount; i++) {
                        students[i].displayStudentInfo(); 
                        cout << endl;
                    }
                }
                break;
            }

            case 6: 
                cout << "Exiting program. Goodbye!" << endl;
               
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
