#include<iostream>

using namespace std;
bool arr[7]={false,false,false,false,false,false,false};

int divide(int i,int j)
{ int lhs=0,rhs=0;  
    for(int s=i;s<=j;s++)
    if(arr[s]==0) rhs++;
    if(lhs==rhs) return i-1;
    
    for(int s=i;s<=j;s++){
        if(arr[s]==0){
            rhs--;
            if(lhs==rhs) return s;
        }
        else{
            lhs++;
            if(lhs==rhs) return s;
        }
    }
}

int update(int i,bool b,int k){
    if (arr[i]==true && b==false)
    {
        arr[i]=false;
        k=k+1;
        return k;
    }
    else if (arr[i]==false && b==true)
    {
        arr[i]=true;
        k=k-1;
        return k;
    }
    else return k;
}

int main(){
int k=divide(2,5);
cout<<k<<endl;
cout<<update(2,true,k);
    return 0;
}