// StackPractice.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "����������Ҫ��ֵ����׺���ʽ��";
		inExample.inputInExpression();
		postExample.postExpression = inExample.inToPost(inExample.inExpression);
		cout << "����ĺ�׺���ʽΪ��";
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
			cout << "��׺���ʽ��������ֵΪ��";
			cout << result;
			cout << "" << endl;
		}
		else
		{
			cout << "������ı��ʽ�������⣬�����޷����㣬������ʽ����ֹ���֡�x/0���������";
			cout << "" << endl;
		}
		cout << "���Ƿ���������м��㣬��������Y����������N��";
		char ch;
		cin >> ch;
		if (ch == 'N')
			flag = false;
		cout << "" << endl;
	} 

	cout << "лл���ʹ�ã��ټ���";
	getchar();
	getchar();

    return 0;
}

