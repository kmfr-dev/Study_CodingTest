#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int N;
	std::cin >> N;

	int Arr[26];
	std::string Str1, Str2;

	bool IsPossible = false;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> Str1 >> Str2;
		IsPossible = true;
		std::fill(Arr, Arr + 26, 0);

		for (int j = 0; j < Str1.length(); ++j)
		{
			Arr[Str1[j] - 'a']++;
			Arr[Str2[j] - 'a']--;
		}

		for (int k = 0; k < 26; ++k)
		{
			if (Arr[k] != 0)
			{
				IsPossible = false;
				break;
			}
		}

		if (IsPossible)
			std::cout << "Possible" << "\n";
		else 
			std::cout << "Impossible" << "\n";
	}

	
	return 0;
}