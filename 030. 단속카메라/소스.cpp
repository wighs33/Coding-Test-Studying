#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
		if (a[0] == b[0])
			return a[1] < b[1];
		return  a[0] < b[0];
		});

	int camera_cnt = 0;
	int overlap_cnt = 0;
	bool has_cam = false;
	for (size_t i = 0; i < routes.size(); i++)
	{
		i += overlap_cnt;
		overlap_cnt = 0;
		//cout << "i : " << i << endl;

		if (i == routes.size() - 1)
			return ++camera_cnt;

		int tmp = routes[i][1];
		for (size_t j = i + 1; ; j++)
		{
			//cout << routes[i][0] << ' ' << tmp << endl;
			//cout << routes[j][0] << ' ' << routes[j][1] << endl;
			if (tmp >= routes[j][0])
			{
				if (tmp > routes[j][1])
				{
					++camera_cnt;
					++overlap_cnt;
					has_cam = true;
					tmp = routes[j][1];
				}
				else
				{
					++overlap_cnt;
				}
			}
			else
			{
				//cout << "camera_cnt : " << camera_cnt << endl;
				//cout << "overlap_cnt : " << overlap_cnt << endl;
				if(!has_cam) ++camera_cnt;
				has_cam = false;
				break;
			}

			if (j == routes.size() - 1)
			{
				if (!has_cam) ++camera_cnt;
				return camera_cnt;
			}

			//cout << "camera_cnt : " << camera_cnt << endl;
			//cout << "overlap_cnt : " << overlap_cnt << endl;
		}
	}
}

int main()
{
	cout << solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} }) << endl; //2
	cout << solution({ {-2, -1}, {1, 2}, {-3, 0} }) << endl; //2
	cout << solution({ {0, 0}, }) << endl; //1
	cout << solution({ {0, 1}, {0, 1}, {1, 2} }) << endl; //1
	cout << solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} }) << endl; //4
	cout << solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} }) << endl; //2
	cout << solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }) << endl; //2
	cout << solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} }) << endl; //2
	cout << solution({{-100, 100}, {50, 170}, {150, 200}, {-50, -10}, {10, 20}, {30, 40}} ) << endl; //4
	cout << solution({{0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12}} ) << endl; //2
	cout << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} }) << endl; //4
	cout << solution({ {0, 1}, {1, 2} }) << endl; //1
	cout << solution({ {0, 10} }) << endl; //1
	cout << solution({ {0, 2}, {1, 3}, {2, 4} }) << endl; //1
	cout << solution({ {0, 2}, {2, 3}, {3, 4}, {4, 6} }) << endl; //2
	cout << solution({ {2, 2}, {0, 1}, {-10, 9} }) << endl; //2
	cout << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} }) << endl; //4
	cout << solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} }) << endl; //8
	cout << solution({ {0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12} }) << endl; //2
	cout << solution({{0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12}} ) << endl; //2
	cout << solution({ {0,2},{2,3},{3,4},{4,6} }) << endl; //2
	cout << endl << endl;
	cout << solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }); //2
	cout << endl;
	cout << solution({ {-2, -1}, {1, 2}, {-3, 0} });//2
	cout << endl;
	cout << solution({ {0, 0}, });//1
	cout << endl;
	cout << solution({ {0, 1}, {0, 1}, {1, 2} });//1
	cout << endl;
	cout << solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} });//4
	cout << endl;
	cout << solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
	cout << endl;
	cout << solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
	cout << endl;
	cout << solution({ {2,2},{0,1},{-10,9} });//2
	cout << endl;
	cout << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} });//4
	cout << endl;
	cout << solution({ {-5, -3}, {-4, 0}, {-4, -2}, {-1, 2}, {0, 3}, {1, 5}, {2, 4} });//2
	cout << endl;
	cout << solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} });//8
	cout << endl;
	cout << solution({ {0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12} });//2
	cout << endl;
	cout << solution({ {-191, -107}, { -184,-151 }, { -150,-102 }, { -171,-124 }, { -120,-114 } }); // 2
	cout << endl;
}