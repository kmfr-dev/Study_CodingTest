#include <iostream>
#include <string>
#include <vector>

int main()
{
	int Case = { 0 };
	std::cin >> Case;

	std::vector<std::string> StrVec;
	StrVec.resize(Case);

	for (int i = 0; i < Case; ++i)
		std::cin >> StrVec[i];

	for (int i = 0; i < StrVec.size(); ++i)
	{
		int Best = i;
		for (int j = i + 1; j < StrVec.size(); ++j)
		{
			if (StrVec[Best].length() > StrVec[j].length())
			{
				Best = j;
		
			}
			
			else if (StrVec[Best].length() == StrVec[j].length())
			{
				int Result = StrVec[Best].compare(StrVec[j]);
				if (Result > 0)
					Best = j;
			}
		}
		
		std::string Temp = StrVec[i];
		StrVec[i] = StrVec[Best];
		StrVec[Best] = Temp;
	}

	for (int i = 0; i < StrVec.size(); ++i)
	{
		if(i == 0 || StrVec[i] != StrVec[i - 1])
			std::cout << StrVec[i] << std::endl;
	}

	return 0;
}