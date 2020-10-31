
#include <iostream>
using namespace std;
bool
Check (int A[], long long int n)
{
  long long int i;
  for (i = 0; i < n - 1; ++i)
    if (A[i] > A[i + 1])
      {
	cout << "\n" << A[i] << " " << A[i + 1];
	return false;
      }

  return true;
}

void
BubbleSort (int A[], long long int n)
{
  long long int i, j;
  int t;
  for (i = 0; i < n - 2; ++i)
    for (j = 0; j < n - 1 - i; ++j)
      if (A[j] > A[j + 1])
	{
	  t = A[j];
	  A[j] = A[j + 1];
	  A[j + 1] = t;
	}
}

void
SelectionSort (int A[], long long int n)
{
  long long int i, j, max;
  int t;
  for (i = 0; i < n - 1; ++i)
    {
      max = 0;
      for (j = 1; j < n - i; ++j)
	if (A[j] > A[max])
	  max = j;

      if (max < n - 1 - i)
	{
	  t = A[max];
	  A[max] = A[n - 1 - i];
	  A[n - 1 - i] = t;
	}
    }
}

void
InsertionSort (int A[], long long int n)
{
  long long int i, j, max;
  int t;
  for (i = 1; i < n; ++i)
    {
      j = i - 1;
      t = A[i];
      while (j > -1 && A[j] > t)
	A[j + 1] = A[j--];

      A[j + 1] = t;
    }
}

void
Merge (int A[], long long int l, long long int r)
{

  long long int mid, i, j, B[r - l + 1], p = 0;
  mid = (l + r) / 2;
  i = l;
  j = mid + 1;

  while (i < mid + 1 && j < r + 1)
    {
      if (A[i] <= A[j])
	B[p++] = A[i++];
      else
	B[p++] = A[j++];
    }

  while (i < mid + 1)
    B[p++] = A[i++];

  while (j < r + 1)
    B[p++] = A[j++];

  i = l;
  p = 0;
  while (i < r + 1)
    A[i++] = B[p++];

}

void
MergeSort (int A[], long long int l, long long int r)
{
  if (l < r)
    {
      long long int mid;
      mid = (l + r) / 2;
      MergeSort (A, l, mid);
      MergeSort (A, mid + 1, r);
      Merge (A, l, r);
    }
}

long long int
Partition (int A[], long long int l, long long int r)
{

  long long int i, j, pivot, t;
  pivot = A[l];
  i = l + 1;
  j = r;
  while (i <= j)
    {
      while (i <= j && A[i] <= pivot)
	i++;
      while (i <= j && A[j] > pivot)
	j--;
      if (i < j)
	{
	  t = A[i];
	  A[i] = A[j];
	  A[j] = t;
	  i++;
	  j--;
	}
    }
  i--;
  A[l] = A[i];
  A[i] = pivot;
  return i;
}


void
RQSort (int A[], long long int l, long long int r)
{
  if (l < r)
    {
      long long int k, p, t;
      p = rand () % (r - l + 1) + l;
      t = A[l];
      A[l] = A[p];
      A[p] = t;
      k = Partition (A, l, r);

      RQSort (A, l, k - 1);
      RQSort (A, k + 1, r);

    }
}

bool
BinarySearch (int A[], long long int l, long long int r, long long int X)
{
  long long int mid;
  while (l <= r)
    {
      mid = (l + r) / 2;
      if (A[mid] == X)
	return true;
      else if (A[mid] > X)
	r = mid - 1;
      else
	l = mid + 1;
    }
  return false;
}

int
main ()
{
  long long int n = 1000000, i, j, k;
  int A[1000000];
//cin>>n;
  for (i = 0; i < n; ++i)
    {
      A[i] = rand () % 10000;
      //cout<<A[i]<<" ";
    }
//BubbleSort(A,n);
//SelectionSort(A,n);
//InsertionSort(A,n);
//MergeSort(A,0,n-1);
  RQSort (A, 0, n - 1);
/*
for(i=0;i<n;++i){
     cout<<A[i]<<" ";
}*/

  if (Check (A, n))
    cout << "cool";
  if (BinarySearch (A, 0, n - 1, 324))
    cout << "out";
  if (BinarySearch (A, 0, n - 1, A[n / 4]))
    cout << "in";
  return 0;
}
