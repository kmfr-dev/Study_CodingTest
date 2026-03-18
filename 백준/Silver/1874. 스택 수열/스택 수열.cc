#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	stack<int> Stack;
	
	int Cur = 1;
	string Result = "";

	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;

		while (Cur <= Num)
		{
			Stack.push(Cur);
			++Cur;
			Result += "+\n";
		}

		if (!Stack.empty() && Stack.top() == Num)
		{
			Stack.pop();
			Result += "- \n";
		}

		else
		{
			cout << "NO";
			return 0;
		}
	}

	cout << Result;

	return 0;
}