#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T, res;
	cin >> T;
	while (T--)
	{
		int val = 0;
		int n, fail = -1;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());

		for (int i = n - 1; i > 1; i--)
		{
			int j = 0;
			int k = i - 1;
			while (j < k)
			{
				if ((v.at(j) + v.at(k)) == v.at(i))
				{
					val++;
					j++;
					k--;
				}

				else if ((v.at(j) + v.at(k)) < v.at(i))
				{
					j++;
				}

				else
				{
					k--;
				}
			}
		}

		if (val != 0)
		{
			cout << "\n"
				 << val;
		}
		else
		{
			cout << "\n"
				 << fail;
		}
	}
	system("pause");
	return 0;
}