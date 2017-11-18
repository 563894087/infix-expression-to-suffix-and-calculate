// StackPractice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "expression.h"


int main()
{
	InExpression inExample;
	PostExpression postExample;

	int flag = true;

	while (flag) 
	{
		cout << "请输入你想要求值的中缀表达式：";
		inExample.inputInExpression();
		postExample.postExpression = inExample.inToPost(inExample.inExpression);
		cout << "输出的后缀表达式为：";
		for (int i = 0; i < postExample.postExpression.size(); i++)
		{
			if (postExample.postExpression[i] == '+' || postExample.postExpression[i] == '-' ||
				postExample.postExpression[i] == '*' || postExample.postExpression[i] == '/')
			{
				if ((i != 0) && (postExample.postExpression[i - 1] != '_'))
				{
					cout << " ";
					cout << postExample.postExpression[i];
				}
				else if ((i != postExample.postExpression.size() - 1) && (postExample.postExpression[i + 1] != '_'))
				{
					cout << postExample.postExpression[i];
					cout << " ";

				}
				else
				{
					cout << postExample.postExpression[i];
				}
			}
			else if (postExample.postExpression[i] != '_')
				cout << postExample.postExpression[i];
			else if (postExample.postExpression[i] == '_')
				cout << " ";
		}

		cout << "" << endl;

		double result = postExample.calPostExpression();
		if (result != INFINITY && result != -INFINITY)
		{
			cout << "中缀表达式的最终求值为：";
			cout << result;
			cout << "" << endl;
		}
		else
		{
			cout << "你输入的表达式存在问题，程序无法运算，请检查表达式，防止出现‘x/0’的情况。";
			cout << "" << endl;
		}
		cout << "你是否还想继续进行计算，是请输入Y，否请输入N：";
		char ch;
		cin >> ch;
		if (ch == 'N')
			flag = false;
		cout << "" << endl;
	} 

	cout << "谢谢你的使用！再见！";
	getchar();
	getchar();

    return 0;
}

