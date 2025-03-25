// // // map(key, value): associate container 
// // // order, unorder, multimap
// // // key always unique, 
// // // in order: 
// // // key value, data sorted , self balance , binary search tree(red black tree) 

// // // in unorder :
// // // key value, unsorded, hashing technique use 
 
// // // multi map :
// // // key duplicate 

// // // set(key): 
// // // order, unorder, multiset

// // // ==============
// // // map is discontiunous 
// // // that's why not use i=i+1 in place of i++
// // // and it will arrange the order 

// // // time coplexity of string: s.size()*log(n)
// // // of integers: s.log(n)


unordered_map
everything is same like map with unordered
# include <iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int, string> up;
    up.insert({103, "Jatin"});
    up.insert({101, "Vijay"});
    up.insert({102, "Himanshu"});

    for(auto p:up){
        cout<<p.first<<","<<p.second<<"\n";
    }
}
complex data type doesn't support in unordered_map because it doesn't have it's own hashing function (like pair in map)
timecomplexity of unordered_map o(1) because of hashing function and o(logn) in map
insertion timecomplexity o(1), find or delete will o(logn)

multi map 
duplicate support 
# include <iostream>
#include<map>
using namespace std;
int main(){
    multimap<int, string> mp;
    mp.insert({103, "Jatin"});
    mp.insert({101, "Vijay"});
    mp.insert({102, "Himanshu"});
    mp.insert({102, "Himanshu"});

    for(auto p:mp){
        cout<<p.first<<","<<p.second<<"\n";
    }
    auto t = mp.find(102);
    if(t!=mp.end()){
        mp.erase(t);
    }
    else{
        cout<<"not found\n";
    }
    cout<<"with iterator it delete only first found\n";
    for(auto p:mp){
        cout<<p.first<<","<<p.second<<"\n";
    }
     cout<<"without iterator delete all insertion of matched\n ";
     mp.erase(102);
     for(auto p:mp){
        cout<<p.first<<","<<p.second<<"\n";
    }
}

que: a= [1,0,5,2,4]
target sum: 6
find index and  value of it
// set :
