class Solution {
public:
    string longestDiverseString(int A, int B, int C) {
        int length=A+B+C;
        int currA=0, currB=0, currC=0;
        string output = "";
        while(length--){
            
            if((A>=B && A>=C && currA!=2) || (A>0 && (currB==2|| currC==2))){
                output+='A'; 
                A--;
                currA++;
                currB=currC=0;
            }
            else if((B>=A && B>=C && currB!=2) || (B>0 && (currA==2|| currC==2))){
                output+='B';
                B--;
                currB++;
                currA=currC=0;
            }
            else if((C>=A && C>=B && currC!=2) || (C>0 && (currA==2|| currB==2))){
                output+='C';
                C--;
                currC++;
                currA=currB=0;
            }
        }
        return output;
    }
};