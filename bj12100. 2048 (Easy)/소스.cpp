#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
int g_N;
int max_num = 0;

void left_move()
{
	//�������� �ѹ� �̵�
	for (int i = 0; i < g_N; i++)
	{
		vector<int> tmp(g_N, 0);
		for (int j = 0, tmp_index = 0; j < g_N; j++)
		{
			//0���� üũ
			if (!board[i][j]) continue;

			//tmp�� ���� ���ٸ� �ֱ�
			if (!tmp[tmp_index])
			{
				tmp[tmp_index] = board[i][j];
				continue;
			}

			//tmp�� ���� �ִٸ� ���� �� üũ
			if (board[i][j] == tmp[tmp_index])
			{
				tmp[tmp_index] += board[i][j];
				++tmp_index;
			}
			else
			{
				++tmp_index;
				tmp[tmp_index] = board[i][j];
			}
		}
		board[i] = tmp;
	}
}

void right_move()
{
	for (int i = 0; i < g_N; i++)
	{
		vector<int> tmp(g_N, 0);
		for (int j = g_N - 1, tmp_index = g_N - 1; j > -1; --j)
		{
			//0���� üũ
			if (!board[i][j]) continue;

			//tmp�� ���� ���ٸ� �ֱ�
			if (!tmp[tmp_index])
			{
				tmp[tmp_index] = board[i][j];
				continue;
			}

			//tmp�� ���� �ִٸ� ���� �� üũ
			if (board[i][j] == tmp[tmp_index])
			{
				tmp[tmp_index] += board[i][j];
				--tmp_index;
			}
			else
			{
				--tmp_index;
				tmp[tmp_index] = board[i][j];
			}
		}
		board[i] = tmp;
	}
}

void up_move()
{
	vector<int> tmp_row(g_N);
	vector<vector<int>> tmp(g_N, tmp_row);
	for (int i = 0; i < g_N; i++)
	{
		for (int j = 0, tmp_index = 0; j < g_N; j++)
		{
			//0���� üũ
			if (!board[j][i]) continue;

			//tmp�� ���� ���ٸ� �ֱ�
			if (!tmp[tmp_index][i])
			{
				tmp[tmp_index][i] = board[j][i];
				continue;
			}

			//tmp�� ���� �ִٸ� ���� �� üũ
			if (board[j][i] == tmp[tmp_index][i])
			{
				tmp[tmp_index][i] += board[j][i];
				++tmp_index;
			}
			else
			{
				++tmp_index;
				tmp[tmp_index][i] = board[j][i];
			}
		}
	}

	board = tmp;
}

void down_move()
{
	vector<int> tmp_row(g_N);
	vector<vector<int>> tmp(g_N, tmp_row);
	for (int i = 0; i < g_N; i++)
	{
		for (int j = g_N - 1, tmp_index = g_N - 1; j > -1; --j)
		{
			//0���� üũ
			if (!board[j][i]) continue;

			//tmp�� ���� ���ٸ� �ֱ�
			if (!tmp[tmp_index][i])
			{
				tmp[tmp_index][i] = board[j][i];
				continue;
			}

			//tmp�� ���� �ִٸ� ���� �� üũ
			if (board[j][i] == tmp[tmp_index][i])
			{
				tmp[tmp_index][i] += board[j][i];
				--tmp_index;
			}
			else
			{
				--tmp_index;
				tmp[tmp_index][i] = board[j][i];
			}
		}
	}

	board = tmp;
}

void move(int dir)
{
	switch (dir)
	{
	case 0:
	{
		up_move();
		break;
	}
	case 1:
	{
		down_move();
		break;
	}
	case 2:
	{
		left_move();
		break;
	}
	case 3:
		right_move();
	}
}

void find_max(int lev) {	
	if (lev == 5) {
		for (auto& v : board)
		{
			int a = *max_element(v.begin(), v.end());
			max_num = max(max_num, a);
		}

		//���
		static int check = 0;
		if (!check && max_num == 64)
			check = 1;
		if (check == 1)
		{
			check = 2;
			cout << lev << "��" << endl;
			for (auto& v : board)
			{
				for (auto& d : v)
				{
					cout << d << ' ';
				}
				cout << endl;
			}
		}
		return;
	}

	auto tmp = board;

	for (int i = 0; i <= 3; i++) {
		move(i);
		find_max(lev + 1);
		//�Ѹ� ��忡�� board ���󺹱�
		board = tmp;
	}
}

int main()
{
	while (true)
	{
		g_N = 0;
		max_num = 0;
		board.clear();

		int N;
		cin >> N;
		board.resize(N);
		g_N = N;

		int in;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> in;
				board[i].push_back(in);
			}

		find_max(0);
		cout << max_num << endl;
	}

	//auto tmp = board;
	//left_move();
	////���
	//for (auto& v : board)
	//{
	//	for (auto& d : v)
	//	{
	//		cout << d << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	//board = tmp;
	//right_move();
	////���
	//for (auto& v : board)
	//{
	//	for (auto& d : v)
	//	{
	//		cout << d << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	//board = tmp;
	//up_move();
	////���
	//for (auto& v : board)
	//{
	//	for (auto& d : v)
	//	{
	//		cout << d << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	//board = tmp;
	//down_move();
	////���
	//for (auto& v : board)
	//{
	//	for (auto& d : v)
	//	{
	//		cout << d << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;
}