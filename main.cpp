#include "Employee_C.h"
#include <fstream>
#include <limits>
//constructor
Employee_C* Fill_Array();
void Extract_ID(Employee_C*, string);
int Find_Employee(int, string);



Employee_C* Fill_Array()
{
	char name[51];
	int idNum;
	double sal;//salary
	char sex;
	int count = 0;
	Employee_C* employee = new Employee_C[100];
	char again = 'Y';
	while (again == 'Y')
	{
		cout << "\nEnter employee#" << count+1 << "'s name> ";
		cin.ignore();
		cin.get(name, 51);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		employee[count].Set_FullName(name);
		cout << "Enter employee's ID number> ";
		cin >> idNum;
		employee[count].Set_IdNumber(idNum);
		cout << "Enter employee's salary>$ ";
		cin >> sal;
		employee[count].Set_Salary(sal);
		totalSalary += sal;
		cout << "Enter employee's gender(M/F)> ";
		cin >> sex;
		employee[count].Set_Gender(sex);
		count++;
		cout << "Would you like to enter again?(Y/N)> ";
		cin >> again;
	}

	return employee;

}

void Extract_ID(Employee_C* em, string fileName)
{
	int idNum;
	fstream binFile;
	Employee_C employee;
	binFile.open(fileName, ios::out | ios::binary);

	if (!binFile)
	{
		cout << "\nCan't open the file";
		exit(0);
	}
	int count = 0;//count how many employ store in the array
	while(em[count].Get_IdNumber() != 0)
	{
		int id = em[count].Get_IdNumber();
		binFile.write(reinterpret_cast<char*>(&id), sizeof(id));
		count++;
	}


}


int Find_Employee(int idT, string fileNm)
{
	
	int position = -1;
	fstream idFile(fileNm.c_str(), ios::out | ios::binary | ios::in);
	bool found = false;

	int id;
	while (idFile.read((char*)&id, sizeof(id)))
	{
		
		position++;
		if (id == idT)
		{
			found = true;
			break;
		}
		
	}


	idFile.close();
	if (found == true)
	{
		return position;
	}
	else
	{
		return -1;
	}
}






int main()
{

	string fileName;
	cout << "Please enter file name> ";
	getline(cin, fileName);
	

	Employee_C* test = Fill_Array();
	
	Extract_ID(test, fileName);

	char c;//determine if continue to search
	do{
		int id;
		
		cout << "\nEnter the ID you want to search> ";
		cin >> id;
		int p = Find_Employee(id, fileName);

		
		if (p != -1)
		{
			cout << "\nEmployee found\n";
			cout << "Employee Info\n";
			test[p].Display_Info();
		} else if(p == -1)
		{
			cout << "\nError: id not found";
			
		}
		cout << "\nWould you like to continue?(Y/N)> ";
		cin >> c;

	} while (c == 'Y');
			

	system("pause");
	cout << endl << endl;
	return 0;
}