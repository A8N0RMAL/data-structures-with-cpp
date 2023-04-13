#include<iostream>
#include<stack>
#include<string>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool ArePair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '[' && close == ']')
		return true;
	return false;
}
bool AreBalanced(string exp)
{
	stack<char>  S;
	int length = exp.length();
	for (int i = 0; i < length; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

int main()
{

	string expr;
	cout << "Enter an expression:";
	cin >> expr;
	if (AreBalanced(expr))
		cout << "Balanced\n";
	else
		cout << "Not Balanced\n";

	return 0;
}
