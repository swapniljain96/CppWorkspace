class Solution {
public:
     bool isNumber(string s) {
        int n=s.length();
        bool numSeen=false;
        bool eSeen=false;
        bool dotSeen=false;
        
        for(int i=0;i<n;i++){
         switch(s[i]){
             case '.':if(dotSeen||eSeen)return false;
                     dotSeen=true;                 
                     break;
             case 'e':
             case 'E': if(eSeen||!numSeen) return false;
                       eSeen=true;
                       numSeen=false;
                       break;
                 
             case '+':
             case '-':if(i!=0 and s[i-1]!='e') return false;
                      numSeen=false;
                      break;
             default:if(!isdigit(s[i])) return false;
                    numSeen=true;
              }
        }
        return numSeen;
    }
};