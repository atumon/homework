#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int* pa = new int[20];
	int record = 0;
	int a = 0, b = 0;
	while (cin >> pa[record])
		record++;

	for (int y = 0; y < record; y++) {
		if (pa[y] > 0)
			a++;
		if (pa[y] < 0)
			b++;
	}
	
	/*����*/
	cout << "������" << a << endl;
	cout << "������" << b << endl;
	int temp;
	int maxIndex;
	for (int i = 0; i < record; i++) {
		
		for (int j = i + 1; j < record; j++) {
			maxIndex = i;
			if (pa[j] <= pa[maxIndex]) {     // Ѱ����С����
				maxIndex = j;                 // ����С������������
			}
			temp = pa[maxIndex];
			pa[maxIndex] = pa[i];
			pa[i] = temp;
		}
	}

	/*���*/
	cout << "����С����˳������:" ;
	for (int y = 0; y < record; y++) {
		cout << pa[y] << "   ";
	}
	cout << endl;
	/*��ֵ�ͷ���*/
	double sum1 = 0;
	for (int i = 0; i < record; i++) {
		sum1 += pa[i];
	}
	double ave = sum1 / record;
	cout << "�⼸�����ľ�ֵΪ" << ave << endl;

	double sum2 = 0;
	for (int i = 0; i < record; i++) {
		sum2 += (pa[i] - ave) * (pa[i] - ave);
	}
	double variance = sum2 / record;
	cout << "�⼸�����ķ���Ϊ" << variance << endl;

	/*�ͷ��ڴ�*/
	delete[]pa;
	return 0;
}