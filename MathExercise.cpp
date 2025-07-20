/*1. ����ͷ�ļ�*/
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000;
using namespace std;

/*2. ��������*/
/*������ϰ*/
void MathExercise();
/*��������*/
int MathTest();
/*��������*/
void TestSettings();
/*����ɼ���ʾ*/
void ShowScore();

/*3. ȫ�ֱ�������*/
// ʵ��ԭ����Ҫ�ڲ�ͬ����֮�乲��������
long testRightNumber;				  // ��������ȷ������
long randomDigits = 10;				  // �����λ����Ĭ��ֵΪ10��Ҳ����10���ڵ���������
long questionNumber = 5;			  // ��Ŀ������Ĭ��5��
long int totalScore = 100;			  // �ܷ֣�Ĭ��Ϊ100��
long int newScore;					  // ����ģʽ�µķ���
long int tFirstNumber, tSecondNumber; // ����ģʽ�µ����������
char mathProblems[1000][1000];		  // ����ģʽ�µĲο���

/*4. ����ʵ��*/
/*������ϰ*/
void MathExercise()
{
	int exerciseRightNumber = 0; // ��ϰ����ȷ������
	int firstNumber, secondNumber;
	int operatorSelect;
	int correctResult;
	int calculationResult;	// ������
	double correctnessRate; // ��ȷ��
	srand((unsigned)time(NULL));
	// ����ѭ��
	for (int i = 0; i < questionNumber; ++i)
	{
		// �������������
		// ����ģ�����ǲ��������ڵ������
		firstNumber = (rand() % randomDigits);
		secondNumber = (rand() % randomDigits);
		// ������ֵڶ�����������Ļ����Ǿ�����ȡһ�Σ���Ϊ0������������
		if (secondNumber == 0)
			secondNumber = (rand() % randomDigits);
		// ���ѡ�������
		operatorSelect = rand() % 4;
		// ѡ��0��1��2��3�ֱ����Ӽ��˳�����
		switch (operatorSelect)
		{
		case 0:
			cout << firstNumber << " + " << secondNumber << " = ";
			cin >> calculationResult;
			correctResult = firstNumber + secondNumber;
			if (firstNumber + secondNumber == calculationResult)
			{
				cout << "�ش���ȷ" << endl;
				++exerciseRightNumber;
			}
			else
			{
				cout << "�ش����" << endl;
			}
			cout << "��ȷ�����" << correctResult << endl;
			break;
		case 1:
			cout << firstNumber << " - " << secondNumber << " = ";
			cin >> calculationResult;
			correctResult = firstNumber - secondNumber;
			if (firstNumber - secondNumber == calculationResult)
			{
				cout << "�ش���ȷ" << endl;
				++exerciseRightNumber;
			}
			else
			{
				cout << "�ش����" << endl;
			}
			cout << "��ȷ�����" << correctResult << endl;
			break;
		case 2:
			cout << firstNumber << " * " << secondNumber << " = ";
			cin >> calculationResult;
			correctResult = firstNumber * secondNumber;
			if (firstNumber * secondNumber == calculationResult)
			{
				cout << "�ش���ȷ" << endl;
				++exerciseRightNumber;
			}
			else
			{
				cout << "�ش����" << endl;
			}
			cout << "��ȷ�����" << correctResult << endl;
			break;
		case 3:
			cout << firstNumber << " / " << secondNumber << " = ";
			cin >> calculationResult;
			correctResult = firstNumber / secondNumber;
			if (firstNumber / secondNumber == calculationResult)
			{
				cout << "�ش���ȷ" << endl;
				++exerciseRightNumber;
			}
			else
			{
				cout << "�ش����" << endl;
			}
			cout << "��ȷ�����" << correctResult << endl;
			break;
		default:
			break;
		}
	}
	cout << "==============================================" << endl;
	cout << "��ȷ������" << exerciseRightNumber << endl;
	cout << "�ܴ�������" << questionNumber << endl;
	// ������ȷ�ʣ�����ѵ�һ������ת��double����Ȼ�����������ǲ���ȷ��
	correctnessRate = (double)exerciseRightNumber / questionNumber;
	// ����Ϊ����ʾ2λС������printf
	printf("��ȷ�ʣ�%.2f\n", correctnessRate);
	cout << "==============================================" << endl;
	system("pause");
}

/*��������*/
int MathTest()
{
	char temp[10];
	int testRightNumber = 0;
	int operatorSelect;
	int correctResult;
	int calculationResult;								  // ������
	double perProblemScore = totalScore / questionNumber; // ÿ����ĵ÷�
	newScore = totalScore;
	srand((unsigned)time(NULL));
	// ����ѭ��
	for (int i = 0; i < questionNumber; ++i)
	{
		// �������������
		tFirstNumber = (rand() % randomDigits);
		itoa(tFirstNumber, temp, 10);
		strcat(mathProblems[i], temp);
		// printf("%s", mathProblems[i]);
		tSecondNumber = (rand() % randomDigits);
		// ������ֵڶ�����������Ļ����Ǿ�����ȡһ�Σ���Ϊ0������������
		if (tSecondNumber == 0)
			tSecondNumber = (rand() % randomDigits);
		// ���ѡ�������
		operatorSelect = rand() % 4;
		// ѡ��0��1��2��3�ֱ����Ӽ��˳�����
		switch (operatorSelect)
		{
		case 0:
			cout << tFirstNumber << " + " << tSecondNumber << " = ";
			cin >> calculationResult;
			correctResult = tFirstNumber + tSecondNumber;
			if (tFirstNumber + tSecondNumber == calculationResult)
			{
				++testRightNumber;
			}
			else
			{
				newScore -= perProblemScore;
			}
			strcat(mathProblems[i], " + ");
			itoa(tSecondNumber, temp, 10);
			strcat(mathProblems[i], temp);
			break;
		case 1:
			cout << tFirstNumber << " - " << tSecondNumber << " = ";
			cin >> calculationResult;
			correctResult = tFirstNumber - tSecondNumber;
			if (tFirstNumber - tSecondNumber == calculationResult)
			{
				++testRightNumber;
			}
			else
			{
				newScore -= perProblemScore;
			}
			strcat(mathProblems[i], " - ");
			itoa(tSecondNumber, temp, 10);
			strcat(mathProblems[i], temp);
			break;
		case 2:
			cout << tFirstNumber << " * " << tSecondNumber << " = ";
			cin >> calculationResult;
			correctResult = tFirstNumber * tSecondNumber;
			if (tFirstNumber * tSecondNumber == calculationResult)
			{
				++testRightNumber;
			}
			else
			{
				newScore -= perProblemScore;
			}
			strcat(mathProblems[i], " * ");
			itoa(tSecondNumber, temp, 10);
			strcat(mathProblems[i], temp);
			break;
		case 3:
			cout << tFirstNumber << " / " << tSecondNumber << " = ";
			cin >> calculationResult;
			correctResult = tFirstNumber / tSecondNumber;
			if (tFirstNumber / tSecondNumber == calculationResult)
			{
				++testRightNumber;
			}
			else
			{
				newScore -= perProblemScore;
			}
			strcat(mathProblems[i], " / ");
			itoa(tSecondNumber, temp, 10);
			strcat(mathProblems[i], temp);
			break;
		default:
			break;
		}
		strcat(mathProblems[i], " = ");
		itoa(correctResult, temp, 10);
		strcat(mathProblems[i], temp);
	}
	cout << "==============================================" << endl;
	cout << "�ο��𰸣�" << endl;
	for (int j = 0; j < questionNumber; ++j)
		cout << mathProblems[j] << endl;
	cout << "��������" << questionNumber << endl;
	cout << "���������" << testRightNumber << endl;
	cout << "���������" << questionNumber - testRightNumber << endl;
	cout << "���β���ĳɼ���" << newScore << endl;
	cout << "==============================================" << endl;
	system("pause");
}

/*��������*/
void TestSettings()
{
again:
	cout << "��Ҫ���м�λ���ڵ����㣺";
	cin >> randomDigits;
	// 1λ����10���ڣ�2λ����100���ڣ�3λ����1000���ڣ����������±����ˣ���ֱ�����¸�ֵ
	if (randomDigits == 1)
		randomDigits = 10;
	if (randomDigits == 2)
		randomDigits = 100;
	if (randomDigits == 3)
		randomDigits = 100;
	else
	{
		cout << "����������" << endl;
		goto again;
	}
	cout << "��������Ŀ������";
	cin >> questionNumber;
	cout << "�������ܷ֣�";
	cin >> totalScore;
}

/*д��ɼ�*/
void ShowScore()
{
	char userName[100];
	FILE *fp;
	fp = fopen("Score.txt", "w");
	cout << "�������������֣�";
	getchar(); // �Ե�ǰ������4��ʱ��Ļس�����Ȼ�س���ֵ��userName�Ͳ�����
	gets(userName);
	fprintf(fp, "������%s\n", userName);
	fprintf(fp, "�ο��𰸣�\n");
	for (int i = 0; i < questionNumber; ++i)
		fprintf(fp, "%s\n", mathProblems[i]);
	fprintf(fp, "��ȷ������%d\n", testRightNumber);
	fprintf(fp, "����������%d\n", questionNumber - testRightNumber);
	fprintf(fp, "��ȷ������%d\n", testRightNumber);
	fprintf(fp, "�ɼ���%d\n", newScore);
	fclose(fp);
}

/*5. ������*/
int main()
{
	int a;
	bool flag = true;
	while (flag)
	{
		a = 0;
		cout << "������ϰ" << endl;
		cout << "1. ��ϰ" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. �鿴����ɼ�" << endl;
		cout << "0. �˳�" << endl;
		cout << "����������ѡ��";
		cin >> a;
		switch (a)
		{
		case 1:
			system("cls");
			MathExercise();
			system("cls");
			break;
		case 2:
			system("cls");
			MathTest();
			system("cls");
			break;
		case 3:
			system("cls");
			TestSettings();
			system("cls");
			break;
		case 4:
			system("cls");
			ShowScore();
			system("cls");
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "�����������������!" << endl;
			cout << endl;
		}
	}
	system("pause");
}
