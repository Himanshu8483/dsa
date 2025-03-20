// map(key, value): associate container 
// order, unorder, multimap
// key always unique, 
// in order: 
// key value, data sorted , self balance , binary search tree(red black tree) 

// in unorder :
// key value, unsorded, hashing technique use 
 
// multi map :
// key duplicate 

// set(key): 
// order, unorder, multiset

// ==============
// map is discontiunous 
// that's why not use i=i+1 in place of i++
// and it will arrange the order 

// time coplexity of string: s.size()*log(n)
// of integers: s.log(n)

# include <iostream>
#include<map>
using namespace std;
int main(){
    map<int, string> mp{{100, "Himanshu"}, {102, "Jatin"}, {101, "Vijay"}};
    for(auto p:mp){
        cout<<p.first<<":"<<p.second<<"\n";
    }
    // or
    map<string, int> student{{"Vijay", 10}, {"Jatin", 11}, {"Himanshu", 12}};
    for(auto i=student.begin(); i!=student.end(); i++){
        cout<<i->first<<":"<<i->second<<"\n";
    }
    cout<<"new Technique\n";
    map<int, int>mapp;
    // mapp.insert({101, "Jatin"});
    // mapp.insert({103, "Vijay"});
    // mapp.insert({102, "Himanshu"});
    // mapp.insert({102, "Yash"});
    // mapp[101]="Yash";
    // mapp[]="Ok";
    // mapp[104]="";
    mapp[105];
    mapp[105]--;
    mapp[105]++;
    for(auto p:mapp){
        cout<<p.first<<":"<<p.second<<"\n";
    }
}