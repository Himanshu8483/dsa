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
    cout<<[](int a, int b){return a>b;}(4,20);;
    cout<<"\n";
    sort(v.begin(), v.end(), less<int>());
    sort(v.begin(), v.end(), greater<int>());   // built in 
    sort(v.begin(), v.end(), [] (int a, int b){return a>b;});   // lambda fun
    for(auto p:v){
        cout<<p<<"\t";
    }
}