#include <iostream>
using namespace std;
int main()
{   int a[] = {31, 14, 4, 84, 6,17,95,2};
	int n = 8;
	cout << "Array before sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
    /*
	 int t;
	 cin>>t;
	while(t--)
    { int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      int k;
      cin>>k;
      while(k--)
      { int pos,min;
        for(i=0;i<n;i++)
        { pos=i;
          max=a[i];
        }
      }
	
	*/
	cout << "\nArray after sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << "\n";
	system("pause");
	return 0;
}
