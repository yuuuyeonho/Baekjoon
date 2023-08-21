#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string str;
	cin >> str;


	int num[26] = { 0 };

	// 대문자로 변환하고 각 문자의 빈도수 저장
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]); //통째로 변환 안됨
		num[str[i] - 65]++; // 
	}

	// 가장 많이 등장한 문자
	int max = 0; // 가장 높은 빈도수
	int index = -1; // max값의 인덱스
	for (int i = 0; i < 26; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (i == index)
			continue;
		if (num[i] == max)
		{
			cout << '?';
			return 0;
		}
	}

	cout << (char)(index + 65);
	return 0;
}