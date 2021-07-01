// Given a rectangular cake with height `h` and width `w`, and two arrays of integers `horizontalCuts` and `verticalCuts` where `horizontalCuts[i]` is the distance from the top of the rectangular cake to the `ith` horizontal cut and similarly, `verticalCuts[j]` is the distance from the left of the rectangular cake to the `jth` vertical cut.

// Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays `horizontalCuts` and `verticalCuts`.* Since the answer can be a huge number, return this modulo 10^9 + 7.
class Solution
{
public:
    int maxArea(int h, int w, vector<int> &hc, vector<int> &vc)
    {
        sort(vc.begin(), vc.end());
        sort(hc.begin(), hc.end());
        int hmax = max(hc[0], h - hc.back()), vmax = max(vc[0], w - vc.back());
        for (int i = 1; i < hc.size(); i++)
        {
            hmax = max(hmax, hc[i] - hc[i - 1]);
        }
        for (int i = 1; i < vc.size(); i++)
        {
            vmax = max(vmax, vc[i] - vc[i - 1]);
        }
        long ans = 1L * hmax * vmax;
        return (int)(ans % 1000000007);
    }
};