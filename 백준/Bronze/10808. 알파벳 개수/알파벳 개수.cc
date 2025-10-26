#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string String;
	std::cin >> String;
		
	std::vector<int> Vector(26, 0);

	int Index = 0;
	
	for (int i = 0; i < String.length(); ++i)
	{
		for (char j = 'a'; j <= 'z'; ++j)
		{
			if (String[i] == j)
				++Vector[j - 'a'];
		}
	}

	for (int i = 0; i < Vector.size(); ++i)
		std::cout << Vector[i] << " ";

	return 0;
}