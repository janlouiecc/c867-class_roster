#include "roster.h"

void Roster::parseAndAdd(string studentData)
{
	DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
	size_t rightSide = studentData.find(',');
	string studentID = studentData.substr(0, rightSide);

	size_t leftSide = rightSide + 1;
	rightSide = studentData.find(',', leftSide);
	string firstName = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1;
	rightSide = studentData.find(',', leftSide);
	string lastName = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1;
	rightSide = studentData.find(',', leftSide);
	string emailAddress = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1;
	rightSide = studentData.find(',', leftSide);
	int age = stoi(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(',', leftSide);
	int daysToCompleteCourse1 = stoi(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(',', leftSide);
	int daysToCompleteCourse2 = stoi(studentData.substr(leftSide, rightSide - leftSide)); 
	
	leftSide = rightSide + 1;
	rightSide = studentData.find(',', leftSide);
	int daysToCompleteCourse3 = stoi(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(',', leftSide);

	if (studentData.substr(leftSide, rightSide - leftSide) == "SECURITY")
	{
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (studentData.substr(leftSide, rightSide - leftSide) == "NETWORK")
	{
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (studentData.substr(leftSide, rightSide - leftSide) == "SOFTWARE")
	{
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram)
{
	int daysToCompleteCourse[] = { daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3 };
	lastArrayIndex++;
	classRosterArray[lastArrayIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourse, degreeProgram);
	numberOfStudents++;
}

void Roster::printAll()
{
	std::cout << "Displaying all students:" << std::endl;
	for (int i = 0; i < numberOfStudents; i++)
	{
		classRosterArray[i]->Print();
	}
	std::cout << std::endl;
}

void Roster::printInvalidEmails()
{
	std::cout << "Displaying Invalid E-mails:" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find('@') == string::npos || email.find(' ') != string::npos || email.find(".") == string::npos)
		{
			std::cout << classRosterArray[i]->getEmailAddress() << " is INVALID.";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	switch (degreeProgram)
	{
	case DegreeProgram::NETWORK: std::cout << "Displaying students in the NETWORK degree program:" << std::endl; break;
	case DegreeProgram::SOFTWARE: std::cout << "Displaying students in the SOFTWARE degree program:" << std::endl; break;
	case DegreeProgram::SECURITY: std::cout << "Displaying students in the SECURITY degree program:" << std::endl; break;
	}


	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->Print();
		}
	}
	std::cout << std::endl;
}

void Roster::remove(string studentID)
{
	bool idFound = false;
	std::cout << "Removing " << studentID << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			idFound = true;
			for (int j = i; j < (numberOfStudents - 1); j++)
			{
				classRosterArray[j] = classRosterArray[j + 1];
			}
			lastArrayIndex--;
			numberOfStudents--;
			break;
		}
		else
		{
			continue;
		}
	}

	if (idFound)
	{
		std::cout << "The student with the ID: " << studentID << " has been removed." << std::endl;
	}
	else
	{
		std::cout << "The student with the ID: " << studentID << " is not found." << std::endl;
	}

	std::cout << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	int a, b, c;
	for (int i = 0; i < 5; i++)
	{
		if (studentID == classRosterArray[i]->getStudentID())
		{
			a = *(classRosterArray[i]->getDaysToCompleteCourse());
			b = *(classRosterArray[i]->getDaysToCompleteCourse() + 1);
			c = *(classRosterArray[i]->getDaysToCompleteCourse() + 2);
		}
	}
	std::cout << "Student ID: " << studentID << ", average days left in a course - " << (a + b + c) / 3 << " days." << std::endl;
}

Roster::~Roster() = default;