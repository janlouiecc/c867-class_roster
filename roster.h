#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <iostream>
#include <sstream>
#include <string>
using std::string;

class Roster 
{
private:
	Student* classRosterArray[5]{};
	int lastArrayIndex = -1;
	int numberOfStudents = 0;

public:
	void parseAndAdd(string studentData);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram); 

	void printAll();

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);

	void remove(string studentID);

	void printAverageDaysInCourse(string studentID);

	~Roster();
};

#endif