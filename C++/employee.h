#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
protected:
	string name;
	int empNumber;
	int empType;

public:
	Employee(string name, int empNumber, int type)
		: name(name), empNumber(empNumber), empType(type) {
	}

	virtual int getPay() const = 0; //순수가상함수
	virtual void showSalary() const = 0;
	virtual ~Employee() {}

	int getType() const { return empType; }
};

class FullTimeEmp : public Employee {
private:
	int salary;
public:
	FullTimeEmp(string name, int empNumber, int salary);

	virtual int getPay() const override;
	virtual void showSalary() const override;
};

class PartTimeEmp : public Employee {
private:
	int workday;
	int wage;
public:
	PartTimeEmp(string name, int empNumber, int workDay, int wage);
	virtual int getPay() const override;
	virtual void showSalary() const override;
};

class SalesEmp : public Employee {
private:
	int sales;
	int extraPay;
	int basePay;
public:
	SalesEmp(string name, int empNumber, int basePay, int sales);
	virtual int getPay() const override;
	virtual void showSalary() const override;
};

class Manager {
private:
	vector<Employee*> myVec;
	//Employee* ePtr[10];
	int totalCount;
public:
	Manager();
	~Manager();
	void run();
	void printEmps();
};

#endif