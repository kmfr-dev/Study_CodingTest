#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string Str;
	std::cin >> Str;
	
	int Arr[10]{ 0 };

	for (int i = 0; i < Str.length(); ++i)
	{
		int Number = Str[i] - '0';

		if (Number == 6 || Number == 9)
			Arr[6] > Arr[9] ? Arr[9]++ : Arr[6]++;
		else
			Arr[Number]++;
	}

	std::cout << *std::max_element(Arr, Arr + 10);

	return 0;
}