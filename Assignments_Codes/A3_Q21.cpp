#include <bits/stdc++.h> 
using namespace std; 

int mostFrequent(int arr[], int n,int i,int j) 
{ 	int max_count = 1, res = arr[i], curr_count = 1; 
	for (int r = i+1; r < j; r++) { 
		if (arr[r] == arr[r - 1]) 
			curr_count++; 
		else { 
			if (curr_count > max_count) { 
				max_count = curr_count; 
				res = arr[r - 1]; 
			} 
			curr_count = 1; 
		} 
	} 
	if (curr_count > max_count) 
	{ 
		max_count = curr_count; 
		res = arr[j - 1]; 
	} 

	return res; 
} 
int main() 
{   int i,j,qur;
	int arr[] = { -2,-2,-2,-1,1, 2, 2, 3, 3, 3, 4,5,5,5,8,9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout<<"Enter the number of quries to want to ask:";
    cin>>qur;
    while(qur--)
    { cout<<"Enter value of i and j(0-"<<n<<") [given i<j] : ";
      cin>>i>>j;
	  cout <<"Most Frequent value between i="<<i<<"and j="<<j<<" is: "<<mostFrequent(arr, n, i, j)<<"\n"; 
    }
    system("pause");
	return 0; 
} 
