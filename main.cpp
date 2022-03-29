#include <iostream> 
#include <climits> 
#include "sqlite3/sqlite3.h"
#include "dbc.h"
using namespace std;

int main() {  
    //declared variables
    double  gpa;
    int     age;
    int     change;
    int     selection;
    int     studentID;
    string  classroom;
    string  name;

    //screen print menu
    cout << " Student Management System v1.0" << endl;
    cout << " =================================================   " << endl;
    cout << " Select an option (type the number and hit enter): \n" << endl;
    cout << " 1. Add              student information             " << endl;
    cout << " 2. Remove           student information             " << endl;
    cout << " 3. Edit             student information             " << endl;
    cout << " 4. Display all      student information             " << endl;
    cout << " 5. Exit Program                                     " << endl;
    cout << " =================================================   " << endl;
    cout << " >> "; cin >> selection; 
    //catches the user attempting to input characters instead of numbers
    while(cin.fail()) 
    { 
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << " You can only enter numbers. \n";
        cout << " >> "; cin >> selection;
    }
    //selection switch
    switch (selection) 
    {
    case 1: //Add student from database
        cout << " Enter Student information\n" << endl;  
        cout << " Name      : "; cin >> name;
        cout << " Age       : "; cin >> age;
        cout << " GPA       : "; cin >> gpa;
        cout << " Classroom : "; cin >> classroom;
        insert_student(name, age, gpa, classroom);
        system("PAUSE");
        system("CLS");
        main();
        break;
    case 2: //Remove student to database 
        cout << endl; 
        cout << " Enter the Student ID to remove from database: "; cin >> studentID;
        delete_student(studentID);
        system("PAUSE");
        system("CLS");
        main();
        cout << endl; 
        
        break;
    case 3: //Edit student information
        cout << " What value you wish to change? \n"; 
        cout << " 1. name \n 2. age \n 3. gpa \n 4. classroom" << endl;
        cout << " >> "; cin >> change;
        // new switch for edit options(switchception)
        switch (change)
        {
        case 1:
            cout << " Enter student ID to make changes: "; cin >> studentID;
            cout << " Enter new name: "; cin >> name;
            edit_student_name(name, studentID);
            system("PAUSE");
            system("CLS");
            main();
            break;
        case 2:
            cout << " Enter student ID to make changes: "; cin >> studentID;
            cout << " Enter new age: "; cin >> age;
            edit_student_age(age, studentID);
            system("PAUSE");
            system("CLS");
            main();
        case 3:
            cout << " Enter student ID to make changes: "; cin >> studentID;
            cout << " Enter new gpa: "; cin >> gpa;
            edit_student_gpa(gpa, studentID);
            system("PAUSE");
            system("CLS");
            main();
        case 4:
            cout << " Enter student ID to make changes: "; cin >> studentID;
            cout << " Enter new classroom: "; cin >> classroom;
            edit_student_classroom(classroom, studentID);
            system("PAUSE");
            system("CLS");
            main();
        default:
        cout << "Invalid or unavailable";
            system("PAUSE");
            system("CLS");
            main();
            break;
        }     
    case 4: //Display Information
        displayColumns();
        system("PAUSE");
        system("CLS");
        main();
        break;
    case 5: //exit
        cout << " Goodbye! Have a good day!" << endl;
        system("PAUSE");
        system("CLS");
        exit(0);
        break;
    default:
        cout << "Invalid option or unavailable! Try again." << endl;
        main();
        break;
    }
    return 0;
}