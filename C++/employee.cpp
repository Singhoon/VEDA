#include "employee.h"

FullTimeEmp::FullTimeEmp(string name, int empNumber, int salary)
	: Employee(name, empNumber, 1), salary(salary) {
	std::cout << "정규직인 " << this->name << "이(가) 생성되었습니다." << std::endl;
}

int FullTimeEmp::getPay() const {
	return this->salary;
}

void FullTimeEmp::showSalary() const {
	std::cout << "[정규직] " << this->name << " (" << this->empNumber << ") : " << this->getPay() << " 만원" << std::endl;
}

PartTimeEmp::PartTimeEmp(string name, int empNumber, int workday, int wage)
	: Employee(name, empNumber, 2), workday(workday), wage(wage) {
	std::cout << "비정규직인 " << this->name << "이(가) 생성되었습니다." << std::endl;
}

int PartTimeEmp::getPay() const {
	return (this->wage) * (this->workday);
}

void PartTimeEmp::showSalary() const {
	std::cout << "[비정규직] " << this->name << " (" << this->empNumber << ") : " << this->getPay() << " 만원" << std::endl;
}

SalesEmp::SalesEmp(string name, int empNumber, int basePay, int sales)
	: Employee(name, empNumber, 3), basePay(basePay), sales(sales) {
	std::cout << "영업직인 " << this->name << "이(가) 생성되었습니다." << std::endl;
}

int SalesEmp::getPay() const {
	return (this->basePay) + (this->sales / 10);
}

void SalesEmp::showSalary() const {
	std::cout << "[영업직] " << this->name << " (" << this->empNumber << ") : " << this->getPay() << " 만원" << std::endl;
}

Manager::Manager() {
	totalCount = 0;
	cout << "=== 사원 관리 프로그램 ===" << endl;
}

Manager::~Manager() {
	cout << "\n관리 프로그램을 종료합니다. (직원 정보 삭제)" << endl;
	for (int i = 0; i < totalCount; i++) {
		delete myVec[i];
		myVec[i] = nullptr;
	}
}

void Manager::run() {
	while (true) {
		int choice;
		cout << "\n--- 메뉴 ---" << endl;
		cout << "1. 정규직 추가" << endl;
		cout << "2. 비정규직 추가" << endl;
		cout << "3. 영업직 추가" << endl;
		cout << "4. 모든 직원 급여 보기 (및 총합)" << endl;
		cout << "0. 종료" << endl;
		cout << "선택 >> ";

		cin >> choice;

		if (choice >= 1 && choice <= 3) {

			string name;
			int empNumber;
			cout << "이름 입력 >> ";
			cin >> name;
			cout << "사번 입력 >> ";
			cin >> empNumber;

			switch (choice) {
			case 1: {
				int salary;
				cout << "기본급 입력 (만원) >> ";
				cin >> salary;
				myVec.push_back(new FullTimeEmp(name, empNumber, salary));
				break;
			}
			case 2: {
				int workday, wage;
				cout << "근무일수 입력 >> ";
				cin >> workday;
				cout << "일당 입력 (만원) >> ";
				cin >> wage;
				myVec.push_back(new PartTimeEmp(name, empNumber, workday, wage));
				break;
			}
			case 3: {
				int basePay, sales;
				cout << "기본급 입력 (만원) >> ";
				cin >> basePay;
				cout << "판매실적 (만원) >> ";
				cin >> sales;
				myVec.push_back(new SalesEmp(name, empNumber, basePay, sales));
				break;
			}
			}
			totalCount++;
		}
		else if (choice == 4) {
			printEmps();
		}
		else if (choice == 0) {
			cout << "\n프로그램을 종료합니다." << endl;
			return;
		}
		else {
			cout << "\n[에러] 0~4 중에서 다시 입력해주세요." << endl;
		}
	}
}

void Manager::printEmps() {
	if (totalCount == 0) {
		cout << "\n[정보] 등록된 직원이 없습니다." << endl;
		return;
	}

	cout << "\n--- [전체 직원 급여 정보] ---" << endl;
	int totalSalary = 0;
	int fullTimeTotal = 0;
	int partTimeTotal = 0;
	int salesTotal = 0;

	for (int i = 0; i < totalCount; i++) {
		myVec[i]->showSalary();

		int pay = myVec[i]->getPay();
		totalSalary += pay;

		int type = myVec[i]->getType();

		if (type == 1) {
			fullTimeTotal += pay;
		}
		else if (type == 2) {
			partTimeTotal += pay;
		}
		else if (type == 3) {
			salesTotal += pay;
		}
	}

	cout << "---------------------------" << endl;
	cout << "정규직 총 급여: " << fullTimeTotal << " 만원" << endl;
	cout << "비정규직 총 급여: " << partTimeTotal << " 만원" << endl;
	cout << "영업직 총 급여: " << salesTotal << " 만원" << endl;
	cout << "=== 총 급여 합계: " << totalSalary << " 만원 ===" << endl;
}