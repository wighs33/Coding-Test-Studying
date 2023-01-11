#include <iostream>
#include <vector>
#include <string>

using namespace std;

int make_number(const int& N, const int& count) {
	string num = "";
	for (int i = 0; i < count; ++i)
		num += to_string(N);
	return stoi(num);
}
int solution(int N, int number) {
	//N마다 
	vector<int>dp[9];

	// N 1개
	dp[1].push_back(make_number(N, 1));
	if (number == N)
		return 1;

	// N 2개~8개
	for (int x = 2; x <= 8; ++x) {
		//원래 자리 수 넣기
		dp[x].push_back(make_number(N, x));
		for (int i = 1; i < x; ++i)
			for (auto& j : dp[i]) {
				if (j == 0)			continue;
				for (auto& k : dp[x - i])
				{
					if (k == 0)		continue;

					//(j 연산 k) 계산하고 넣기 -> 계산에서 N의 개수는 x개
					dp[x].push_back(j * k);
					dp[x].push_back(j / k);
					dp[x].push_back(j + k);
					dp[x].push_back(j - k);
				}
			}

		for (int i = 0; i < dp[x].size(); ++i)
			if (number == dp[x][i])
				return x;
	}

	// N 9개
	return -1;
}

int main()
{
    cout << solution(5,	12) << endl;
   // cout << solution(2,	11) << endl;
}