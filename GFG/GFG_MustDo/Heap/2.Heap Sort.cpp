/* Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.


Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.
Example 2:

Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output:
1 2 3 4 5 6 7 8 9 10
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1, 2,3,4,5,6,7,8,9,10.

Your Task :
You don't have to read input or print anything. Your task is to complete the functions heapify(), buildheap() and heapSort() where heapSort() and buildheap() takes the array and it's size as input and heapify() takes the array, it's size and an index i as input. Complete and use these functions to sort the array using heap sort algorithm.


Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).


Constraints:
1 <= N <= 106
1 <= arr[i] <= 106 */

class Solution
{
public:
    //Heapify function to maintain heap property.
    void heapify(int a[], int n, int i)
    {
        int largest = i;   //laregst is root
        int l = 2 * i + 1; //2i+1 is left
        int r = 2 * i + 2; // 2i+2 is right
        if (l < n and a[l] > a[i])
        {
            largest = l;
        }
        if (r < n and a[r] > a[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

public:
    //Function to build a Heap from array.
    void buildHeap(int a[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(a, n, i);
    }

public:
    //Function to sort an array using Heap Sort.
    void heapSort(int a[], int n)
    {
        buildHeap(a, n);
        for (int i = n - 1; i > 0; i--)
        {
            swap(a[0], a[i]);
            heapify(a, i, 0);
        }
    }
};
