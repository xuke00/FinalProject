#include "Employee_C.h"

Employee_C::Employee_C()
{
	strcpy(fullName, " ");
	idNumber = 0;
	salary = 0.0;
	gender = 'n';//n means not filled

}

Employee_C::Employee_C(char* name, int id, double sal, char sex)
{
	strcpy(fullName, name);
	idNumber = id;
	salary = sal;
	gender = sex;
	
}

//Setter
void Employee_C::Set_FullName(char* name)
{
	strcpy(fullName, name);

}
void Employee_C::Set_IdNumber(int id)
{
	idNumber = id;
}
void Employee_C::Set_Salary(double money)
{
	salary = money;
}
void Employee_C::Set_Gender(char sex)
{
	gender = sex;
}
//Getter
char* Employee_C::Get_FullName()
{
	return fullName;
}
int Employee_C::Get_IdNumber() const
{
	return idNumber;
}
double Employee_C::Get_Salary() const
{
	return salary;
}

char Employee_C::Get_Gender() const
{
	return gender;
}

void Employee_C::Display_Info()
{
	cout << "\nFull name: " << Get_FullName();
	cout << "\nEmployee ID number: " << Get_IdNumber();
	cout << "\nEmployee salary: " << Get_Salary();
	cout << "\nEmployee gender: " << Get_Gender();
}
