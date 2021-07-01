// You are assigned to put some amount of boxes onto **one truck**. You are given a 2D array `boxTypes`, where `boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]`:

// - `numberOfBoxesi` is the number of boxes of type `i`.
// - `numberOfUnitsPerBoxi`is the number of units in each box of the type `i`.

// You are also given an integer `truckSize`, which is the **maximum** number of **boxes** that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed `truckSize`.

// Return *the **maximum** total number of **units** that can be put on the truck.*
class Solution
{
public:
    bool static compare(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] > v2[1];
    }

    int maximumUnits(vector<vector<int>> &a, int truck)
    {
        sort(a.begin(), a.end(), compare);
        int res = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (truck >= a[i][0])
            {
                res += a[i][0] * a[i][1];
                truck -= a[i][0];
            }
            else if (truck > 0 and truck < a[i][0])
            {
                res += truck * a[i][1];
                return res;
            }
        }
        return res;
    }
};