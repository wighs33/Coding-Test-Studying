#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include <iostream>

using namespace std;

static set<int> primenumbers;

bool isPrimeNumber(int num) {
	if (num == 0 || num == 1) return false;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void mix_func(string mix, int pos, string numbers)
{
	//cout << "mix: " << mix << endl;

	if (isdigit(mix[0]) && isPrimeNumber(stoi(mix)))
		primenumbers.insert(stoi(mix));

	if (pos == mix.size()) return;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		string a = numbers;
		auto m = mix;
		auto p = pos;
		m[p] = a[i];
		a.erase(a.begin() + i);
		
		mix_func(m, ++p, a);
	}
}

int solution(string numbers) {
	primenumbers.clear();

	string mix;
	mix.resize(numbers.size());
	mix_func(mix, 0, numbers);

	return primenumbers.size();
}

int main()
{
	cout << solution({ "178" }) << endl;
	cout << solution({ "011" }) << endl;
}