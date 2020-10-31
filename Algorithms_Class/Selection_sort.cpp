#include <iostream>
using namespace std;

int main()
{
	int a[] = {31, 14, 4, 84, 6, 17};
	int n = 6, t;
	cout << "Array before sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	int max, pos;

	for (int i = 0; i < n; i++)
	{ max=a[i];
	  pos=i;
		for (int j = i; j < n; j++)
		{ if (a[j] < max)
			{   max=a[j];
				pos = j;
			}
		}
		t = a[i];
		a[i] = a[pos];
		a[pos] = t;
	}

    cout << "\nArray after sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << "\n";
	system("pause");
	return 0;
}