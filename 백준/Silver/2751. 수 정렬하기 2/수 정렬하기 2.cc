#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int Compare(const void* _Dest, const void* _Src)
{
	int A = *static_cast<const int*>(_Dest);
	int B = *static_cast<const int*>(_Src);

	if (A < B)
		return -1;
	if (A > B)
		return 1;

	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Case;
	std::cin >> Case;

	std::vector<int> NumberVec(Case);
	for (int i = 0; i < Case; ++i)
		std::cin >> NumberVec[i];

	std::qsort(NumberVec.data(), NumberVec.size(), sizeof(int), Compare);

	for (int i = 0; i < NumberVec.size(); ++i)
		std::cout << NumberVec[i] << "\n";

	return 0;
}