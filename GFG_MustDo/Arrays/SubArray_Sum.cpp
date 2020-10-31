#include <iostream>
using namespace std;

void func(int a[], int *N, int *S)
{
   int start = 0;
   int end = 0;
   int sum = a[0];
   
   while (end < *N)
   {
      if (sum == *S)
      {
           cout <<start+1 << " " << end+1 << "\n";
           break;
      }
      if (sum < *S && end < *N)
      {
         sum = sum + a[++end];
      }

      else if (sum > *S && start < end)
      {
         sum = sum - a[start++];
      }
   }
    
}
int main()
{
   int T;
   cin >> T;
   int N, S;
   while (T--)
   {
      cin >> N;
      cin >> S;
      int a[N];
      for (int i = 0; i < N; i++)
      {
         cin >> a[i];
      }
     func(a,&N, &S);
    
   }

}
