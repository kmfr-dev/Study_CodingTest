#include <iostream>

void Print(int _Hour, int _Min)
{
	// 45를 빼준다.
	_Min -= 45;

	// 만약 0보다 작다면
	if (_Min < 0)
	{
		// 기존 값에 60을 더한다.
		_Min = 60 + _Min;

		// 만약 시간이 0이라면
		if (_Hour == 0)
		{
			// 24에서 1을 빼준시간을 적용
			_Hour = 24 - 1;
		}

		// 아니라면 기존 시간에서 1시간을 빼준다.
		else
		{
			_Hour -= 1;
		}
	}

	// 최종 알람시간 출력
	std::cout << _Hour << " " << _Min << std::endl;
}


int main()
{
	// 정수 시간, 분
	int Hour, Min;
	// 입력을 받는다.
	std::cin >> Hour >> Min;
	// 알람 시간을 출력하는 함수 호출
	Print(Hour, Min);

	return 0;
}