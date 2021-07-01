// Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

// In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:
class Solution {
public:
    vector<vector<int>> generate(int n) { 
        if(n==0) return {};
        if(n==1) return {{1}};
        if(n==2) return {{1},{1,1}};
   
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        
       for(int i=2;i<n;i++)
       { vector<int> tmp;     
           for(int j=0;j<=i;j++)
           { if(j==0 || j==i)
               { tmp.push_back(1);   }
              else
               { tmp.push_back(ans[i-1][j-1]+ans[i-1][j]);      }
           }
         ans.push_back(tmp);
        }
      return ans;
    }
};