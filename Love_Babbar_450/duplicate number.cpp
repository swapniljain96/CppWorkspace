//Method 1 by sorting
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       for(int i=1;i<nums.size();i++)
        { if(nums[i]==nums[i-1])
           {return nums[i];} 
        }
        return -1;
    }
};

//Method 2 by set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       set<int> s;
        for(int i:nums)
        {  auto pos=s.find(i);
            if(pos!=s.end())
            { return i;}
            s.insert(i); 
        }
        return -1;
    }
};