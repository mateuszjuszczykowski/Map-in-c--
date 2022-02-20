#include "Map.h"														// Defines template Map<Key, Value>
#include "Employee.h"													// Defines class Employee
#include "BookInfo.h"
#include <string>
#include <iostream>

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees
typedef Map<string, Book> Bookshelf;

using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);

int main() {
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database (copy constructor called)
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database (assignment operator called)

	cout << "Database after the assignment:" << endl << database << endl;

	//book tests

	Bookshelf bk;
	bk.add("Harry Potter", 	Book("JK Rowling", "Fantasy", 153, true));
	cout<<bk<<endl;
	Book bk1 = Book("JK Rowling", "Fantasy", 153, true);
	bk1.borrow();
	bk.add("Harry potter 2", bk1);
	cout<<bk<<endl;
	

}

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* pE;

	pE = database.find(510212881);										// Find employee using its ID
	pE->position = "salesman";											// Modify the position of employee
	
	pE = database.find(761028073);										// Find employee using its ID
	pE->age = 29;														// Modify the age of employee
}