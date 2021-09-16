#include "student.h"

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram)
{
	Student::setStudentID(studentID);
	Student::setFirstName(firstName);
	Student::setLastName(lastName);
	Student::setEmailAddress(emailAddress);
	Student::setAge(age);
	Student::setDaysToCompleteCourse(daysToCompleteCourse);
	Student::setDegreeProgram(degreeProgram);
}

void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysToCompleteCourse(int* daysToCompleteCourse)
{
	for (int i = 0; i < 3; i++) {
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

void Student::Print()
{
	int* pDaysToCompleteCourse = getDaysToCompleteCourse();
	string degree;
	switch (getDegreeProgram())
	{
	case DegreeProgram::SECURITY: degree = "SECURITY"; break;
	case DegreeProgram::NETWORK: degree = "NETWORK"; break;
	case DegreeProgram::SOFTWARE: degree = "SOFTWARE"; break;
	}

	printf("%-2s \t First Name: %-9s \t Last Name: %-8s \t Age: %-2d \t Days In Course: {%2d, %2d, %2d} \t Degree Program: %s", getStudentID().c_str(), getFirstName().c_str(), getLastName().c_str(), getAge(), pDaysToCompleteCourse[0], pDaysToCompleteCourse[1], pDaysToCompleteCourse[2], degree.c_str());
	std::cout << std::endl;
}