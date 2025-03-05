// template = for same datatype

// function template

#include <iostream>
using namespace std;
template <typename t1>

t1 sum(t1 a , t1 b){
    return a+b;
}
int main() {
  cout<<sum(3,5);
}




// class template

#include <iostream>
using namespace std;
template<typename v1>
class cybrom{
v1 a;
public:cybrom(v1 x)
{
    a=x;
}
v1 show(){
    return a+1;
}      
};
int main() {
cybrom<int>obj(10);
cout<<obj.show();
}



// without constructure
#include <iostream>
using namespace std;
template<typename x1 , typename x2>
class sehore
{
  public:void sum(x1 t1, x2 t2)
  {
      cout<<t1+t2;
  }
};

int main() {
sehore<int,float>obj;
obj.sum(5,4.5);
}




// namespace std  ==============


#include <iostream>
using namespace std;
namespace cybrom
{
    int a=50;
    int b=10;
    void show(){
        cout<<"return = "<<a+b;
    }
    class bhopal
    {
        public:int sqr(int a)
        {
            return a*a;
        }
    };
    class iostreamx{
      public:void fun()
      {
          cout<<"\n fun is fun \n";
      }
    } coutx;
}

using namespace cybrom;

int main() {
 cout<<a<<"\n";
 cout<<b<<"\n";
 show();
 bhopal b;
 cout<<"\n";
 cout<<b.sqr(8);
 coutx.fun();
}
// ans 
// 50
// 10
// return = 60
// 64
//  fun is fun 


//  multiple namespace

#include <iostream>
using namespace std;
namespace cybrom
{
    void student()
    {
        cout<<"\n student \n";
    }
    namespace bhopal
    {
        void student()
        {
            cout<<"\n bhopal \n";
        }
    }
}
int main() {
  cybrom::student();
  cybrom::bhopal::student();
}
// ans 
student
bhopal





// array template = 

#include <iostream>
using namespace std;
#include <array>
#include <algorithm>

int main() {
 
 array<int,6>arr{34,5,12,87,5,3};
 sort(arr.begin(),arr.end());
 cout<<"min = "<<arr.front();
 cout<<"\n max = "<<arr.back();
 cout<<"\n size of array = "<<arr.size()<<"\n";
 for(int i=0; i<arr.size();i++)
 {
     cout<<arr.at(i)<<"\t";
 }
 
 cout<<"\n first value of array = "<<arr.front();
 cout<<"\n last value of array = "<<arr.back();
 cout<<"\n second (with pointer)last value = "<<*(arr.end()-2);   //   it gives second highest value   (not perfect in  duplicate)
 cout<<"\n second (with arr )last value = "<<arr[arr.size()-3];   // another method                 (not perfect in  duplicate)
 
}
// ans
min = 3
 max = 87
 size of array = 6
3	5	5	12	34	87	
 first value of array = 3
 last value of array = 87
 second (with pointer * )last last value = 34
 second (with arr )last last value = 12



// find largest number in case of duplicate

 
#include <iostream>
using namespace std;
#include <array>
#include <algorithm>

int main() {
 
 array<int,6>arr{5,5,2,3,4,1};
 sort(arr.begin(),arr.end());
int m = arr[arr.size()-1];
 for(int i=arr.size()-1; i>=0; i--){
     if(arr[i]<m){
         cout<<arr[i];
              break;
     }

 }
 
}




// multiple vector with static value and auot function


#include <iostream>
using namespace std;
#include <vector>
int main() {
  vector<int>v{2,3,4,5,6};
  for(auto p:v){
      cout<<p<<"\t";
  }
  cout<<"\n";
  
  vector<string>v2{"sun","mon","tuesday"};
  for(auto k:v2){
      cout<<k<<"\t";
  }
  cout<<"\n";
  
  vector<int>v3(5);  //   defalut value =0
  for(auto a:v3){
      cout<<a<<"\t";
  }
  cout<<"\n";
  
  vector<int>v4(5,10);
  v4[3]=1000;
   for(auto s:v4){
      cout<<s<<"\t";
  }
}


// output

2	3	4	5	6	
sun	mon	tuesday	
0	0	0	0	0	
10	10	10	1000	10	





// insert dynamic data in vector = 

#include <iostream>
using namespace std;
#include <vector>
int main() {
    
    vector<int>vec;
    int n,a;
    cout<<"Enter The Size of Vetor = ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter digit = ";
        cin>>a;
        vec.push_back(a);
    }
    
    cout<<"\n data of vector \n";
    
    for(auto p:vec){
        cout<<p<<"\t";
    }
    

}



// delete last data in vector =  pop_back

#include <iostream>
using namespace std;
#include <vector>
int main() {
    
    vector<int>vec;
    int n,a;
    cout<<"Enter The Size of Vetor = ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter digit = ";
        cin>>a;
        vec.push_back(a);
    }
    cout<<"\n data of vector \n";
    
    for(auto p:vec){
        cout<<p<<"\t";
    }
    
    cout<<"\n after deletion \n";
    
    vec.pop_back();
     for(auto p:vec){
        cout<<p<<"\t";
    }
    

}



// with iterator and insert = to add at random place from starting


#include <iostream>
using namespace std;
#include <vector>
#include <iterator>
int main() {
    
    vector<int>vec;
    int n,a;
    cout<<"Enter The Size of Vetor = ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter digit = ";
        cin>>a;
        vec.push_back(a);
    }
    cout<<"\n data of vector \n";
    
    for(auto p:vec){
        cout<<p<<"\t";
    }
    
    cout<<"\n with iterator \n";
    
    vector<int>::iterator it=vec.begin();
    vec.insert(it+1,100);
    cout<<"\n after iteration \n";
    for(auto j:vec){
        cout<<j<<"\t";
    }
    
}



// with iterator and insert = to add at random place in last

#include <iostream>
using namespace std;
#include <vector>
#include <iterator>
int main() {
    
    vector<int>vec;
    int n,a;
    cout<<"Enter The Size of Vetor = ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter digit = ";
        cin>>a;
        vec.push_back(a);
    }
    cout<<"\n data of vector \n";
    
    for(auto p:vec){
        cout<<p<<"\t";
    }
    
    cout<<"\n with iterator \n";
    
    vector<int>::iterator it=vec.end();
    vec.insert(it-1,100);
    cout<<"\n after iteration \n";
    for(auto j:vec){
        cout<<j<<"\t";
    }


}


// PAIR

#include <iostream>
using namespace std;
#include <vector>
int main() {
    
pair<int,string>p;
p=make_pair(101,"jatin");
cout<<p.first<<"\n";
cout<<p.second;

}



// vector with pair

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <vector>
int main() {
    
vector<pair<int,string>>v;
int roll,n;
string name;
cout<<"Enter Number of Records = ";
cin>>n;
for(int i=1; i<=n;i++){
    cout<<"Enter roll number = ";
    cin>>roll;
    cout<<"Enter Name = ";
    cin>>name;
    // v.push_back(make_pair(roll,name));        //  or     
     v.push_back({roll,name});                 // prefer this method as both works
}

cout<<"Results are \n";
for(int i=0; i<v.size();i++){
    cout<<v[i].first<<":"<<v[i].second<<"\n";
}

}



// nested vestor  = imp

#include <iostream>
using namespace std;
#include<vector>

int main() {
    vector<vector<int>>v1;
    int row,col;
    int val;
    cout<<"Enter Size of Row =";
    cin>>row;
    cout<<"Enter Size of Col =";
    cin>>col;
    for(int i=0;i<row;i++){
        vector<int>v2;
        for(int j=0;j<col;j++){
            cout<<"Enter value = ";
            cin>>val;
            v2.push_back(val);
        }
        v1.push_back(v2);
    }
    cout<<" Stored Values In 2-d Formate : \n";
    for(int i=0;i<v1.size();i++){
        for(int j=0; j<v1[i].size();j++){
            cout<<v1[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
}