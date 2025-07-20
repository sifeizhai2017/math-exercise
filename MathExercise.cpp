/*1. 包含头文件*/
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000;
using namespace std;

/*2. 函数声明*/
/*算数练习*/
void MathExercise();
/*算术测验*/
int MathTest();
/*测验设置*/
void TestSettings();
/*测验成绩显示*/
void ShowScore();

/*3. 全局变量定义*/
// 实际原因是要在不同函数之间共享多个数据
long testRightNumber;				  // 测验中正确的题数
long randomDigits = 10;				  // 随机数位数，默认值为10，也就是10以内的算术运算
long questionNumber = 5;			  // 题目数量，默认5题
long int totalScore = 100;			  // 总分，默认为100分
long int newScore;					  // 测试模式下的分数
long int tFirstNumber, tSecondNumber; // 测验模式下的两个随机数
char mathProblems[1000][1000];		  // 测验模式下的参考答案

/*4. 函数实现*/
/*算数练习*/
void MathExercise()
{
	int exerciseRightNumber = 0; // 练习中正确的题数
	int firstNumber, secondNumber;
	int operatorSelect;
	int correctResult;
	int calculationResult;	// 运算结果
	double correctnessRate; // 正确率
	srand((unsigned)time(NULL));
	// 做题循环
	for (int i = 0; i < questionNumber; ++i)
	{
		// 产生两个随机数
		// 这里模几就是产生几以内的随机数
		firstNumber = (rand() % randomDigits);
		secondNumber = (rand() % randomDigits);
		// 如果出现第二个数等于零的话，那就重新取一次，因为0不能做除数。
		if (secondNumber == 0)
			secondNumber = (rand() % randomDigits);
		// 随机选择运算符
		operatorSelect = rand() % 4;
		// 选到0、1、2、3分别代表加减乘除操作
		switch (operatorSelect)
		{
		case 0:
			cout << firstNumber << " + " << secondNumber << " = ";
			cin >> calculationResult;
			correctResult = firstNumber + secondNumber;
			if (firstNumber + secondNumber == calculationResult)
			{
				cout << "回答正确" << endl;
				++exerciseRightNumber;
			}
			else
			{
				cout << "回答错误" << endl;
			}
			cout << "正确结果：" << correctResult << endl;
			break;
		case 1:
			cout << firstNumber << " - " << secondNumber << " = ";
			cin >> calculationResult;
			correctResult = firstNumber - secondNumber;
			if (firstNumber - secondNumber == calculationResult)
			{
				cout << "回答正确" << endl;
				++exerciseRightNumber;
			}
			else
			{
				cout << "回答错误" << endl;
			}
			cout << "正确结果：" << correctResult << endl;
			break;
		case 2:
			cout << firstNumber << " * " << secondNumber << " = ";
			cin >> calculationResult;
			correctResult = firstNumber * secondNumber;
			if (firstNumber * secondNumber == calculationResult)
			{
				cout << "回答正确" << endl;
				++exerciseRightNumber;
			}
			else
			{
				cout << "回答错误" << endl;
			}
			cout << "正确结果：" << correctResult << endl;
			break;
		case 3:
			cout << firstNumber << " / " << secondNumber << " = ";
			cin >> calculationResult;
			correctResult = firstNumber / secondNumber;
			if (firstNumber / secondNumber == calculationResult)
			{
				cout << "回答正确" << endl;
				++exerciseRightNumber;
			}
			else
			{
				cout << "回答错误" << endl;
			}
			cout << "正确结果：" << correctResult << endl;
			break;
		default:
			break;
		}
	}
	cout << "==============================================" << endl;
	cout << "正确题数：" << exerciseRightNumber << endl;
	cout << "总答题数：" << questionNumber << endl;
	// 计算正确率，必须把第一个数字转成double，不然出来的数字是不精确的
	correctnessRate = (double)exerciseRightNumber / questionNumber;
	// 这里为了显示2位小数用了printf
	printf("正确率：%.2f\n", correctnessRate);
	cout << "==============================================" << endl;
	system("pause");
}

/*算数测验*/
int MathTest()
{
	char temp[10];
	int testRightNumber = 0;
	int operatorSelect;
	int correctResult;
	int calculationResult;								  // 运算结果
	double perProblemScore = totalScore / questionNumber; // 每道题的得分
	newScore = totalScore;
	srand((unsigned)time(NULL));
	// 做题循环
	for (int i = 0; i < questionNumber; ++i)
	{
		// 产生两个随机数
		tFirstNumber = (rand() % randomDigits);
		itoa(tFirstNumber, temp, 10);
		strcat(mathProblems[i], temp);
		// printf("%s", mathProblems[i]);
		tSecondNumber = (rand() % randomDigits);
		// 如果出现第二个数等于零的话，那就重新取一次，因为0不能做除数。
		if (tSecondNumber == 0)
			tSecondNumber = (rand() % randomDigits);
		// 随机选择运算符
		operatorSelect = rand() % 4;
		// 选到0、1、2、3分别代表加减乘除操作
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
	cout << "参考答案：" << endl;
	for (int j = 0; j < questionNumber; ++j)
		cout << mathProblems[j] << endl;
	cout << "总题数：" << questionNumber << endl;
	cout << "答对题数：" << testRightNumber << endl;
	cout << "答错题数：" << questionNumber - testRightNumber << endl;
	cout << "本次测验的成绩：" << newScore << endl;
	cout << "==============================================" << endl;
	system("pause");
}

/*测验设置*/
void TestSettings()
{
again:
	cout << "你要进行几位以内的运算：";
	cin >> randomDigits;
	// 1位就是10以内，2位就是100以内，3位就是1000以内，懒得再用新变量了，就直接重新赋值
	if (randomDigits == 1)
		randomDigits = 10;
	if (randomDigits == 2)
		randomDigits = 100;
	if (randomDigits == 3)
		randomDigits = 100;
	else
	{
		cout << "请重新输入" << endl;
		goto again;
	}
	cout << "请输入题目数量：";
	cin >> questionNumber;
	cout << "请输入总分：";
	cin >> totalScore;
}

/*写入成绩*/
void ShowScore()
{
	char userName[100];
	FILE *fp;
	fp = fopen("Score.txt", "w");
	cout << "请输入您的名字：";
	getchar(); // 吃掉前面输入4的时候的回车，不然回车赋值给userName就不对了
	gets(userName);
	fprintf(fp, "姓名：%s\n", userName);
	fprintf(fp, "参考答案：\n");
	for (int i = 0; i < questionNumber; ++i)
		fprintf(fp, "%s\n", mathProblems[i]);
	fprintf(fp, "正确题数：%d\n", testRightNumber);
	fprintf(fp, "错误题数：%d\n", questionNumber - testRightNumber);
	fprintf(fp, "正确题数：%d\n", testRightNumber);
	fprintf(fp, "成绩：%d\n", newScore);
	fclose(fp);
}

/*5. 主函数*/
int main()
{
	int a;
	bool flag = true;
	while (flag)
	{
		a = 0;
		cout << "算数练习" << endl;
		cout << "1. 练习" << endl;
		cout << "2. 测验" << endl;
		cout << "3. 设置" << endl;
		cout << "4. 查看测验成绩" << endl;
		cout << "0. 退出" << endl;
		cout << "请输入数字选择：";
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
			cout << "输入错误，请重新输入!" << endl;
			cout << endl;
		}
	}
	system("pause");
}
