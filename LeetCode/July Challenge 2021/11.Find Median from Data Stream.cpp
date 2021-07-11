/* The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]
Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
Constraints:
-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.*/

class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if (lsize == 0)
            maxheap.push(num);
        else if (lsize == rsize)
        {
            if (num < minheap.top())
            {
                maxheap.push(num);
            }
            else
            {
                int tmp = minheap.top();
                minheap.pop();
                minheap.push(num);
                maxheap.push(tmp);
            }
        }
        else
        {
            if (minheap.size() == 0)
            {
                if (num > maxheap.top())
                {
                    minheap.push(num);
                }
                else
                {
                    int tmp = maxheap.top();
                    maxheap.pop();
                    minheap.push(tmp);
                    maxheap.push(num);
                }
            }
            else if (num >= minheap.top())
            {
                minheap.push(num);
            }
            else
            {
                if (num < maxheap.top())
                {
                    int tmp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(tmp);
                }
                else
                    minheap.push(num);
            }
        }
    }

    double findMedian()
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if (lsize > rsize)
        {
            return (double)maxheap.top();
        }
        else
        {
            return (double(maxheap.top()) + double(minheap.top())) / 2;
        }
    }
};