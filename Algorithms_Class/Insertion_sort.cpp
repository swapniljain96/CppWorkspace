#include <iostream>
using namespace std;

int main()
{
	int a[] = {31, 14, 4, 84, 6};
	int n = 5;
	cout << "Array before sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	int i, j, t;
	for (i = 1; i < n; i++)
	{ 	j = i - 1;
		t = a[i];
		while (j > -1 && a[j] > t)
		 {	a[j+1] = a[j];
		 	j--;
		 }
		
		a[j + 1] = t;
	}

	cout << "\nArray after sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << "\n";
	system("pause");
	return 0;
}