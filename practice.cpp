// Forward List (singly link list) use in Directed Graph
// list (doubly link list) use in Undirected Graph
// it has so many inbuilt function 
// for unique value must sort an array to remove duplicate 
#include <iostream>
using namespace std;
#include <forward_list>

int main(){
    forward_list<int>f;     // or {3,9,1,4,5};
    f.push_front(3);
    f.push_front(3);
    f.push_front(3);
    f.push_front(56);
    cout<<"\n list \n";
    for(auto p: f){
        cout<<p<<"\t";
    }
    // f.pop_front();       // for delete
    f.sort();           // for sorting
    f.unique();         // for unique (remove duplicate)
cout<<"\nafter delete \n";
    for(auto p: f){
        cout<<p<<"\t";
    }
    cout<<"\n f1 list\n";
    forward_list<int>f1{50,3,1,2,5};
    forward_list<int>f2{4,30,70,32,1,3};
    for(auto p: f1){
        cout<<p<<"\t";
    }
    cout<<"\n f2 list\n";
    for(auto p: f2){
        cout<<p<<"\t";
    }
    cout<<"\nmerge\n";
    f1.sort();
    f2.sort();
    f1.merge(f2);

    for(auto p: f1){
        cout<<p<<"\t";
    }

    return 0;
}