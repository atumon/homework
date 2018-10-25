#include<iostream>
#include<string>
using namespace std;

class Stu {
public:
	string name;
	int age;
	int grade;
};

float checkAgeScore(int age, float grade)
{
	if ((age <= 15 || age>25) && (grade < 0 || grade > 5))
		throw 6;
	else if (age <= 15 || age > 25)
		throw 3;
	else if (grade < 0 || grade > 5)
		throw 2;

	return float(20 * grade);
}

int main() {
	Stu pa;
	cout << "please input the info of stu" << endl;
	cin >> pa.name >> pa.age >> pa.grade;
	try {
		cout << endl;
		checkAgeScore(pa.age, pa.grade);
		cout << "���� " << pa.name << endl;
		cout << "���� " << pa.age << endl;
		cout << "�ٷ��Ƴɼ� " << checkAgeScore(pa.age, pa.grade) << endl;
	}
	catch (int a) {
		if (a % 2 == 0)
			cout << "error���ɼ����ڷ�Χ��0-5����!" << endl;
		if (a % 3 == 0)
			cout << "error�����䲻�ڷ�Χ��15-20���ڣ�" << endl;
	}
	return 0;
}
