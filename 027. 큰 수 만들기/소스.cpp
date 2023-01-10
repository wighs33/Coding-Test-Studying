#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	for (size_t i = 0; i < number.size(); i++)
	{
		if (k == 0)
			return number;

		if (number[i] < number[i + 1])
		{
			cout << number[i] << endl;
			number.erase(number.begin() + i);
			cout << number << endl;
			--k;
			if (i == 0)
				i = -1;
			else
				i -= 2;
		}
	}
	return number.substr(0, number.size() - k);
}

int main()
{
	//cout << solution("1924", 2) << endl;
	//cout << solution("1231234", 3) << endl;
	//cout << solution("4177252841", 4) << endl;
	cout << solution("4321", 1) << endl;
}