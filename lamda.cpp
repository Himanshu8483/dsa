// lambda function has no name and denote by []
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
bool cybrom(int a, int b) {
    return a>b;
}
int main(){
    vector<int>v{2,1,5,4,6};
    sort(v.begin(), v.end());
    for(auto p:v){
        cout<<p<<"\n";
    }
    cout<<[](int a, int b){return a>b;}(4,20);
    cout<<"\n";
    sort(v.begin(), v.end(), less<int>());
    sort(v.begin(), v.end(), greater<int>());   // built in 
    sort(v.begin(), v.end(), [] (int a, int b){return a>b;});   // lambda fun
    for(auto p:v){
        cout<<p<<"\t";
    }


}

int main(){
    // all_of()none_of(), any_of(); built in function
    cout<<[](int a) {return a+2;} (4)<<endl;    // single parameter
    auto p = [] (int a, int b) {return a+b};        // pointer p function store by auto
    cout<<p(45,6)<<endl;
    vector<int> v={23,100,59};
    vector<int> v2={2,1,5};
    cout<<all_of(v.begin(), v.end(),)
}
