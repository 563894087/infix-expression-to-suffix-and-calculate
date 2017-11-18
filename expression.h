#include<stack>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;
struct InExpression
{
	string inExpression;
	

	InExpression() {}

	void inputInExpression()
	{
		cin >> inExpression;
		
		int i = 0;  
		//给初始的中缀表达式加入‘_’符号以区别不同数字
		while(i<inExpression.length())
		{
		if (inExpression[i] == '+' || inExpression[i] == '-' || inExpression[i] == '*' || inExpression[i] == '/')
		{
		inExpression.insert(i, "_");
		i = i + 2;
		}
		else
		i++;
		}
		inExpression.insert(0, "_");
		
	}
	vector<char> inToPost(string inExpression)
	{
		vector<char> postExpression;
		stack<char> operand;
		for (int i = 0; i < inExpression.length(); i++)
		{
			if (operand.empty() && (inExpression[i] == '+' || inExpression[i] == '-' || inExpression[i] == '*' || inExpression[i] == '/'))
				operand.push(inExpression[i]);
			else if (inExpression[i] == '+' || inExpression[i] == '-')
			{

				if (operand.top() == '+' || operand.top() == '-' || operand.top() == '*' || operand.top() == '/')
				{
					bool flag = false;
					while ((!operand.empty()) && flag == false)
					{
						if (operand.top() == '+' || operand.top() == '-')
						{
							postExpression.push_back(operand.top());
							operand.pop();

						}
						else if (operand.top() == '*' || operand.top() == '/')
						{
							postExpression.push_back(operand.top());
							operand.pop();

						}
						if (!operand.empty() && operand.top() == '(')
						{
							flag = true;
						}


					}
					operand.push(inExpression[i]);
				}


				if (operand.top() == '(')
				{
					operand.push(inExpression[i]);
				}



			}

		
			else if (inExpression[i] == '*' || inExpression[i] == '/')
			{
				if (operand.top() == '*' || operand.top() == '/')
				{
					postExpression.push_back(operand.top());
					operand.pop();
					operand.push(inExpression[i]);
				}
				else if (operand.top() == '+' || operand.top() == '-')
				{
					operand.push(inExpression[i]);
				}
				else if(operand.top() == '(')
				{
					operand.push(inExpression[i]);
				}
			}
				
			else if (inExpression[i] == '(')
			{
				operand.push(inExpression[i]);
			}
			else if (inExpression[i] == ')')
			{
				while (operand.top() != '(')
				{
					postExpression.push_back(operand.top());
					operand.pop();
				}
				operand.pop();
			}
			else
			{
				postExpression.push_back(inExpression[i]);
			}
		}
		while (!operand.empty())
		{
			postExpression.push_back(operand.top());
			operand.pop();
		}

		return postExpression;
	}
};

	struct PostExpression
	{
		vector<char> postExpression;
		stack<double> numStack;
		PostExpression() {}
		double calPostExpression()
		{
			int i = 1;
			while (i<postExpression.size())
			{

				string strNum ="";
				double num;
				if ((postExpression[i - 1] == '_' || postExpression[i - 1] == '+' ||
					postExpression[i - 1] == '-' || postExpression[i - 1] == '*' ||
					postExpression[i - 1] == '/') &&
					(postExpression[i] != '_' && postExpression[i] != '+' &&
						postExpression[i] != '-' && postExpression[i] != '*' &&
						postExpression[i] != '/'))	
				{
					while (postExpression[i] != '_' && postExpression[i] != '+' &&
						postExpression[i] != '-' && postExpression[i] != '*' &&
						postExpression[i] != '/')
					{
						strNum += postExpression[i];
						i++;
					}
					//string转换为double类型
					if (strNum[0] != '#')
					{
						num = stringToDouble(strNum);
					}
					//带有#的转换为相对应的相反数
					else if (strNum[0] == '#')
					{
						strNum.erase(0, 1);
						num = -(stringToDouble(strNum));
					}
					numStack.push(num);
					
				}
				else if (postExpression[i] == '+' || postExpression[i] == '-' ||
					postExpression[i] == '*' || postExpression[i] == '/')
				{
					double numToCal2 = numStack.top();
					numStack.pop();
					double numToCal1 = numStack.top();
					numStack.pop();
					double newNum;

					if (postExpression[i] == '+')
						newNum = numToCal1 + numToCal2;
					else if (postExpression[i] == '-')
						newNum = numToCal1 - numToCal2;
					else if (postExpression[i] == '*')
						newNum = numToCal1 * numToCal2;
					else if (postExpression[i] == '/')
						newNum = numToCal1 / numToCal2;

					numStack.push(newNum);
					i++;
				}
				else if (postExpression[i] == '_')
					i++;
			}
			double result = numStack.top();
			numStack.pop();
		

			return result;

		}

		double stringToDouble(string strNum)//string 转换成double类型的数据
		{
			double num;
			istringstream iss(strNum);
			iss >> num;
			return num;
		}
		

	};
