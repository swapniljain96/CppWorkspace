#include<iostream>
#include<list>
#include<cstring>

using namespace std;

class HashTable
{  private:
    static const int tableSize=10;
    list<pair<int,string>> table[tableSize]; //List 1->Index 0 ,list2->index1

   public:
    bool isEmpty();
    int hashFunction(int key);
    void insert(int key,string value);
    void remove(int);
   // string search(int key,);
    void print();
};

bool HashTable::isEmpty()
{     int sum=0;
        for(int i=0;i<tableSize;i++)
        { sum+=table[i].size(); }
      if(!sum)
       { return true;}
       else
       {
         return false;
       }
}

int HashTable::hashFunction(int key)
{      return key%tableSize; }

void HashTable::insert(int key,string value){ 
    int hashvalue=hashFunction(key);
    auto& cell = table[hashvalue];
    auto bItr=begin(cell);
    bool keyExists=false;
    for(;bItr!=end(cell);bItr++)
    { if(bItr->first==key)
       { keyExists=true;  
         bItr->second=value;
         cout<<"[WARNING]Key Exist. Value replaced.\n";
         break;
       }
    }

    if(!keyExists){
       cell.emplace_back(key,value);
      }
      return ;
}

void HashTable::remove(int key){
    int hashvalue=hashFunction(key);
    auto& cell = table[hashvalue];
    auto bItr=begin(cell);
    bool keyExists=false;
    for(;bItr!=end(cell);bItr++)
    { if(bItr->first==key)
       { keyExists=true;  
         bItr=cell.erase(bItr);
         cout<<"[INFO]Pair removed.\n";
         break;
       }
    }
    if(!keyExists){
       cout<<"Key not found.Pair not removed";
      }
      return ;
}
void HashTable::print(){
  for(int i=0;i<tableSize;i++)
  { if(table[i].size()==0) continue;
    auto bItr = table[i].begin();
    for(;bItr!=table[i].end();bItr++){
      cout<<"[INFO] Key:"<<bItr->first<<" Value:"<<bItr->second<<"\n";
    }  
  }
  return;
}

int main()
{ HashTable ht;
  if(ht.isEmpty())
   { cout<<"Table is empty.\n";}
   else
   { cout<<"Table has content.\n";}

    ht.insert(1,"Swapnil");
    ht.insert(1,"Swetang");
    ht.insert(2,"Himanshu");
    ht.insert(3,"Satyam");
    ht.insert(3,"KK");
    ht.insert(3,"Heena");
    ht.insert(4,"Nikita");
    ht.insert(5,"Shrey");
    ht.insert(6,"Paras");

    ht.print();
    
    ht.remove(4);
    ht.remove(6);

   if(ht.isEmpty())
   { cout<<"\nTable is empty.\n";}
   else
   { cout<<"\nTable has content.\n";}
     ht.print();

 

    
    system("pause");  
    return 0;
}