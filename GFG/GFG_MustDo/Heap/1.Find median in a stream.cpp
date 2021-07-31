/* Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 
 

Example 2:

Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 
Your Task:
You are required to complete the class Solution. 
It should have 2 data members to represent 2 heaps. 
It should have the following member functions:
insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
getMedian() does not take any arguments. It should return the current median of the stream.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
 
Constraints:
1 <= N <= 106
1 <= x <= 106 */

class Solution
{
public:
    priority_queue<int> maxheap;                            //1st half (left half)
    priority_queue<int, vector<int>, greater<int>> minheap; //2nd half (Right half)

    void insertHeap(int &num)
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if (lsize == 0) //num is the 1st element in stream
            maxheap.push(num);
        else if (lsize == rsize) //Push one element in maxheap for sure
        {
            if (num < minheap.top()) //num can be pushed to maxheap (1st half) to maintain order
                maxheap.push(num);
            else //Push root of minheap to maxheap (Push num to 2nd half)
            {
                int temp = minheap.top(); //Save root of minheap
                minheap.pop();            //Pop the root from minheap
                minheap.push(num);        //Push num in minheap
                maxheap.push(temp);       //Push the previous saved root of minheap in the maxheap
            }
        }
        else ///We assume that maxheap can be larger than minheap by a max of 1 element only
        {
            if (minheap.size() == 0)
            {
                if (num > maxheap.top()) //Push num to 2nd half
                    minheap.push(num);
                else //Push num to 1st half
                {
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
            }
            else if (num >= minheap.top()) //Push the element directly in minheap (2nd half)
                minheap.push(num);
            else //Push root of maxheap to minheap
            {
                if (num < maxheap.top()) //Push num to 1st half
                {
                    int temp = maxheap.top(); //Save root of maxheap
                    maxheap.pop();            //Pop root of maxheap
                    maxheap.push(num);        //Push num to maxheap
                    minheap.push(temp);       //Push previous saved root of maxheap to minheap
                }
                else //Push num to 2nd half
                    minheap.push(num);
            }
        }
    }
    //Function to return Median.
    double getMedian()
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if (lsize > rsize) //Return top of maxheap for odd no of elements
            return double(maxheap.top());
        else //Else return avg of top of maxheap and minheap
            return (double(maxheap.top()) + double(minheap.top())) / 2;
    }
};