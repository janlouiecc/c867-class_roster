#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>

using namespace std;

int main()
{
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jan Louie,Castro,jcas413@wgu.edu,27,30,34,45,SOFTWARE"
	};

	cout << "C867: Scripting & Programming - Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 003952787" << endl;
	cout << "Name: Jan Louie Castro\n" << endl;

	Roster classRoster;
	
	for (int i = 0; i < 5; i++)
	{
		classRoster.parseAndAdd(studentData[i]);
	}

	classRoster.printAll();
	
	classRoster.printInvalidEmails();

	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");
	
	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	// classRoster.remove("A3");
	
	classRoster.printAll();
	
	// classRoster.remove("A3");*/

	return 0;
}