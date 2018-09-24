#include <iostream>
#include<fstream>
#include<string>

using namespace std;
#define SIZE 20

struct student {
	int number;
	string name;
	int usualgrade;
	int expergrade;
	int finalgrade;
	double rank;
}student[SIZE],temp;


void main(void) {
	int n = 0;

	ifstream read("data.txt",ios::in);
	if (!read.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(1);
	}
	while(!read.eof() && n<SIZE){
		read >> student[n].number >> student[n].name >> student[n].usualgrade >> student[n].expergrade >> student[n].finalgrade;
		student[n].rank = (0.2 * student[n].usualgrade + 0.2 * student[n].expergrade + 0.6 * student[n].finalgrade) ;
		n++;
	}
	int record = n ;
	//չʾ���������ϵ��£�
	/*for (int i = 0; i < record; ++i)
		cout << "number:" << student[i].number << " name: " << student[i].name << " ƽʱ�ɼ�: " << student[i].usualgrade << " ʵ��ɼ���" << student[i].expergrade << " ��ĩ�ɼ�: " << student[i].finalgrade << endl;
	*/
	int maxIndex;
	for (int i = 0; i < record; i++) {
		maxIndex = i;
		for (int j = i + 1; j < record; j++) {
			if (student[j].rank > student[maxIndex].rank) {     // Ѱ����С����
				maxIndex = j;                 // ����С������������
			}
			temp = student[maxIndex];
			student[maxIndex] = student[i];
			student[i] = temp;
		}
	}
	cout << "�ɼ�����Ϊ��" << endl;
	for (int i = 0; i < record; ++i)
		cout<< "��" <<i+1<<": "<< "number:" << student[i].number << " name: " << student[i].name << " ƽʱ�ɼ�: " << student[i].usualgrade << " ʵ��ɼ���" << student[i].expergrade << " ��ĩ�ɼ�: " << student[i].finalgrade << " ���ճɼ�: " << student[i].rank << endl;
	/*�����ֵ*/
	double sum1 = 0;
	for (int i = 0; i < record; i++) {
		sum1 += student[i].rank;
	}
	double ave = sum1 / record;
	cout << "�⼸�˳ɼ��ľ�ֵΪ" << ave << endl;
	double sum2 = 0;
	for (int i = 0; i < record; i++) {
		sum2 += (student[i].rank - ave) * (student[i].rank - ave);
	}
	double variance = sum2 / record;
	cout << "�⼸�˳ɼ��ķ���Ϊ" << variance << endl;
	//����
	cout << "�Ƿ�ͨ��ѧ�Ų�ѯѧ����Ϣ��y/n��" << endl;
	char flag;
	int numbs;
	cin >> flag;
	if (flag == 'y') {
		cout << "������ѧ��" << endl;
		cin >> numbs;
		//˳�����
		int l = 0;
		for (int i = 0; i < record; i++) {
			if (student[i].number == numbs) {
				cout << "number:" << student[i].number << " name: " << student[i].name << " ƽʱ�ɼ�: " << student[i].usualgrade << " ʵ��ɼ���" << student[i].expergrade << " ��ĩ�ɼ�: " << student[i].finalgrade << " �ܳɼ�: " << student[i].rank << endl;
				l++;
			}
		}
		if(l == 0)
		cout << "���ǲ�������ˣ�" << endl;
	}
	if(flag == 'n') {
		exit(1);
	}
	read.close();
	
}
