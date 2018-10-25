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
	Stu* pa = new Stu[20];
	cout << "please input the info of stu" << endl;
	int i = 0;
	string name;
	int age;
	int grade;
	int record = 0;
	while (cin >> pa[i].name >> pa[i].age >> pa[i].grade) {
		record++;
		i++;
	}
	for (int y = 0; y < record; y++) {
		cout << "��" << y+1 << "��ѧ�� :" << endl;
		try {
			checkAgeScore(pa[y].age, pa[y].grade);
			cout << "���� :" << pa[y].name << endl;
			cout << "���� :" << pa[y].age << endl;
			cout << "�ٷ��Ƴɼ� :" << checkAgeScore(pa[y].age, pa[y].grade) << endl;
		}
		catch (int a) {
			if (a % 2 == 0)
				cout << "error���ɼ����ڷ�Χ��0-5����!" << endl;
			if (a % 3 == 0)
				cout << "error�����䲻�ڷ�Χ��16-20���ڣ�" << endl;
		}
	}
	return 0;
}
