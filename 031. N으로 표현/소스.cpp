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
	//N���� 
	vector<int>dp[9];

	// N 1��
	dp[1].push_back(make_number(N, 1));
	if (number == N)
		return 1;

	// N 2��~8��
	for (int x = 2; x <= 8; ++x) {
		//���� �ڸ� �� �ֱ�
		dp[x].push_back(make_number(N, x));
		for (int i = 1; i < x; ++i)
			for (auto& j : dp[i]) {
				if (j == 0)			continue;
				for (auto& k : dp[x - i])
				{
					if (k == 0)		continue;

					//(j ���� k) ����ϰ� �ֱ� -> ��꿡�� N�� ������ x��
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

	// N 9��
	return -1;
}

int main()
{
    cout << solution(5,	12) << endl;
   // cout << solution(2,	11) << endl;
}