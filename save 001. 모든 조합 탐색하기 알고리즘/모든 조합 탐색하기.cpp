#include <iostream>
#include <string>
#include <vector>

using namespace std;

void mix_func(string mix, int pos, string numbers)
{
	//��������� ��� ����
	//cout << "mix: " << mix << endl;

	//����� ä���� �� ����
	if (pos == mix.size())
	{
		cout << "mix: " << mix << endl;
		return;
	}

	for (size_t i = 0; i < numbers.size(); i++)
	{
		string a = numbers;
		string m = mix;
		int p = pos;
		m[p] = a[i];
		a.erase(a.begin() + i);

		mix_func(m, ++p, a);
	}
}

int main()
{
	//string numbers;
	//numbers.resize(findings.size());

	//for (int i = 0; i < findings.size(); i++)
	//{
	//	numbers[i] = i + '0';
	//}

	string numbers = "01234";

	string mix;
	mix.resize(numbers.size());
	mix_func(mix, 0, numbers);
}