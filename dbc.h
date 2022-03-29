  #include <iostream>  
#include <iomanip>  
#include "sqlite3/sqlite3.h"
using namespace std;

sqlite3                 *db;
const char* db_name =   "database.db";
char                    *zErrMsg;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    cout << endl;
    cout << setw(10) << azColName[0] << setw(15) << azColName[1] << setw(10) << azColName[2] << setw(10) << azColName[3] << setw(15) << azColName[4] << setw(10) << endl;
    cout << setw(10) << argv[0] << setw(15) << argv[1] << setw(10) << argv[2] << setw(10) << argv[3] << setw(15) << argv[4] << setw(10) << endl;
    cout << endl;
    return 0;
}

int displayColumns() {
    int rc = sqlite3_open(db_name, &db);
    if(rc) {
        cout << " Status: Access Denied. \n Check if correct database has been selected." << endl;
        sqlite3_close(db);
        exit(1);
    }
    const char select_sql[] = "SELECT * FROM students";
    rc = sqlite3_exec(db, select_sql, callback, 0, &zErrMsg);
    sqlite3_close(db);
    return 0;
}

int insert_student(string name, int age, int gpa, string classroom) {
    // sqlite operations
    int rc = sqlite3_open(db_name, &db);
    if(rc) {
        cout << " Status: Access Denied. \n Check if correct database has been selected." << endl;
        sqlite3_close(db);
        exit(1);
    }
    //INSERT SQL process
    // prepare with parameters
    const char insert_sql[] = "INSERT INTO students(name, age, gpa, classroom) VALUES(?,?,?,?)";
    sqlite3_stmt *insert_stmt = NULL;
    rc = sqlite3_prepare_v2(db, insert_sql, -1, &insert_stmt, NULL);
    if(SQLITE_OK != rc) {
        cout << " Status: Prepared statement failed!" << endl;
        sqlite3_close(db);
        exit(1);
    }

    // bind parameters
    rc = sqlite3_bind_text(insert_stmt, 1, name.c_str(), name.length(), SQLITE_TRANSIENT);
    rc = sqlite3_bind_int(insert_stmt, 2, age);
    rc = sqlite3_bind_double(insert_stmt, 3, gpa);
    rc = sqlite3_bind_text(insert_stmt, 4, classroom.c_str(), classroom.length(), SQLITE_TRANSIENT);

    // execute sql
    rc = sqlite3_step(insert_stmt);
    if(SQLITE_DONE != rc) {
        cout << " Status: Failed to INSERT" << endl;
    } else {
        cout << " Status: INSERT done"  << endl;
    }
    // close database and statements
    sqlite3_finalize(insert_stmt);
    sqlite3_close(db); 
    return 0;
}

int delete_student(int studentID) {
    int rc = sqlite3_open(db_name, &db);
    if(rc) {
        cout << " Status: Access Denied. \n Check if correct database has been selected." << endl;
        sqlite3_close(db);
        exit(1);
    }
    const char delete_sql[] = "DELETE FROM students WHERE studentID = ?";
    sqlite3_stmt *delete_stmt = NULL;
    rc = sqlite3_prepare_v2(db, delete_sql, -1, &delete_stmt, NULL);
    if(SQLITE_OK != rc) {
        cout << " Status: Prepared statement failed!" << endl;
        sqlite3_close(db);
        exit(1);
    }
    rc = sqlite3_bind_int(delete_stmt, 1, studentID);
    rc = sqlite3_step(delete_stmt);
    if(SQLITE_DONE != rc) {
        cout << " Status: Failed to DELETE" << endl;
    } else {
        cout << " Status: DELETE done"  << endl;
    }
    // close database and statements
    sqlite3_finalize(delete_stmt);
    sqlite3_close(db);
    return 0;
}

int edit_student_name(string name, int studentID) {
    int rc = sqlite3_open(db_name, &db);
    if(rc) {
        cout << " Status: Access Denied. \n Check if correct database has been selected." << endl;
        sqlite3_close(db);
        exit(1);
    }
    const char update_name_sql[] = "UPDATE students SET name = ? WHERE studentID = ?";
    sqlite3_stmt *update_name_stmt = NULL;
    rc = sqlite3_prepare_v2(db, update_name_sql, -1, &update_name_stmt, NULL);
    if(SQLITE_OK != rc) {
        cout << " Status: Prepared statement failed!" << endl;
        sqlite3_close(db);
        exit(1);
    }
    rc = sqlite3_bind_text(update_name_stmt, 1, name.c_str(), name.length(), SQLITE_TRANSIENT);
    rc = sqlite3_bind_int(update_name_stmt, 2, studentID);
    rc = sqlite3_step(update_name_stmt);
    if(SQLITE_DONE != rc) {
        cout << " Status: Failed to UPDATE" << endl;
    } else {
        cout << " Status: UPDATE done"  << endl;
    }
    // close database and statements
    sqlite3_finalize(update_name_stmt);
    sqlite3_close(db); 
    return 0;
}

int edit_student_age(int age, int studentID) {
    int rc = sqlite3_open(db_name, &db);
    if(rc) {
        cout << " Status: Access Denied. \n Check if correct database has been selected." << endl;
        sqlite3_close(db);
        exit(1);
    }
    const char update_name_sql[] = "UPDATE students SET age = ? WHERE studentID = ?";
    sqlite3_stmt *update_age_stmt = NULL;
    rc = sqlite3_prepare_v2(db, update_name_sql, -1, &update_age_stmt, NULL);
    if(SQLITE_OK != rc) {
        cout << " Status: Prepared statement failed!" << endl;
        sqlite3_close(db);
        exit(1);
    }
    rc = sqlite3_bind_int(update_age_stmt, 1, age);
    rc = sqlite3_bind_int(update_age_stmt, 2, studentID);
    rc = sqlite3_step(update_age_stmt);
    if(SQLITE_DONE != rc) {
        cout << " Status: Failed to UPDATE" << endl;
    } else {
        cout << " Status: UPDATE done"  << endl;
    }
    // close database and statements
    sqlite3_finalize(update_age_stmt);
    sqlite3_close(db); 
    return 0;
}

int edit_student_gpa(int gpa, int studentID) {
    int rc = sqlite3_open(db_name, &db);
    if(rc) {
        cout << " Status: Access Denied. \n Check if correct database has been selected." << endl;
        sqlite3_close(db);
        exit(1);
    }
    const char update_gpa_sql[] = "UPDATE students SET gpa = ? WHERE studentID = ?";
    sqlite3_stmt *update_gpa_stmt = NULL;
    rc = sqlite3_prepare_v2(db, update_gpa_sql, -1, &update_gpa_stmt, NULL);
    if(SQLITE_OK != rc) {
        cout << " Status: Prepared statement failed!" << endl;
        sqlite3_close(db);
        exit(1);
    }
    rc = sqlite3_bind_int(update_gpa_stmt, 1, gpa);
    rc = sqlite3_bind_int(update_gpa_stmt, 2, studentID);
    rc = sqlite3_step(update_gpa_stmt);
    if(SQLITE_DONE != rc) {
        cout << " Status: Failed to UPDATE" << endl;
    } else {
        cout << " Status: UPDATE done"  << endl;
    }
    // close database and statements
    sqlite3_finalize(update_gpa_stmt);
    sqlite3_close(db); 
    return 0;
}

int edit_student_classroom(string classroom, int studentID) {
    int rc = sqlite3_open(db_name, &db);
    if(rc) {
        cout << " Status: Access Denied. \n Check if correct database has been selected." << endl;
        sqlite3_close(db);
        exit(1);
    }
    const char update_classroom_sql[] = "UPDATE students SET classroom = ? WHERE studentID = ?";
    sqlite3_stmt *update_classroom_stmt = NULL;
    rc = sqlite3_prepare_v2(db, update_classroom_sql, -1, &update_classroom_stmt, NULL);
    if(SQLITE_OK != rc) {
        cout << " Status: Prepared statement failed!" << endl;
        sqlite3_close(db);
        exit(1);
    }
    rc = sqlite3_bind_text(update_classroom_stmt, 1, classroom.c_str(), classroom.length(), SQLITE_TRANSIENT);
    rc = sqlite3_bind_int(update_classroom_stmt, 2, studentID);
    rc = sqlite3_step(update_classroom_stmt);
    if(SQLITE_DONE != rc) {
        cout << " Status: Failed to UPDATE" << endl;
    } else {
        cout << " Status: UPDATE done"  << endl;
    }
    // close database and statements
    sqlite3_finalize(update_classroom_stmt);
    sqlite3_close(db); 
    return 0;
}