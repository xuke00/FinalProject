#ifndef Employee_C_H
#define Employee_C_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

static double totalSalary = 0;

class Employee_C
{
private:
	
	char fullName[51];
	int idNumber;
	double salary;
	char gender;
	

public:
	Employee_C();
	Employee_C(char*, int, double, char);

	void Set_FullName(char*);
	char* Get_FullName();

	void Set_IdNumber(int);
	int Get_IdNumber() const;

	void Set_Salary(double);
	double Get_Salary() const;

	void Set_Gender(char);
	char Get_Gender() const;

	void Display_Info();

};






#endif // !Employee_C_H

