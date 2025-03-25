
// //             SET(single key)
// //         set, unordered, multi 
    
// // in map<int, string>
// // set: <int>
// // unique, sorted, red black tree 
// // unordered:
// // random, hashing technique, 
// // insertion time complexity O(1) 
// // Multi:
// // sorted, duplicate 
// // set use in graph and map use in tree  

// // #include<iostream>
// // using namespace std;
// // #include<set>
// // int main(){
// //     set<int>s{10, 20, 1, 2, 6};
// //     for (auto p:s){
// //         cout<<p<<"\t";
// //     }
// //     cout<<endl;
// //     s.insert(35);
// //     for (auto p:s){
// //         cout<<p<<"\t";
// //     }
// //     s.erase(20);
// //     cout<<"\n";
// //     auto t=s.find(2);
// //     if(t!=s.end()){
// //         cout<<"found = "<< *t;
// //     }
// //     else{
// //         cout<<"not found";
// //     }
// // } 
// // // unordered   
// // #include<iostream>
// // using namespace std;
// // #include<unordered_set>
// // int main(){
// //     unordered_set<int>s{10, 20, 1, 2, 6};
// //     for (auto p:s){
// //         cout<<p<<"\t";
// //     }
// //     cout<<endl;
// //     s.insert(35);
// //     for (auto p:s){
// //         cout<<p<<"\t";
// //     }
// //     s.erase(20);
// //     cout<<"\n";
// //     auto t=s.find(2);
// //     if(t!=s.end()){
// //         cout<<"found = "<< *t;
// //     }
// //     else{
// //         cout<<"not found";
// //     }
// // }   
// // multi set   
// #include<iostream>
// using namespace std;
// #include<set>
// int main(){
//     multiset<int>s{10,10, 20, 1, 2, 6};
//     for (auto p:s){
//         cout<<p<<"\t";
//     }
//     cout<<endl;
//     s.insert(35);
//     for (auto p:s){
//         cout<<p<<"\t";
//     }
//     s.erase(20);
//     cout<<"\n";
//     auto t=s.find(2);
//     if(t!=s.end()){
//         cout<<"found = "<< *t;
//     }
//     else{
//         cout<<"not found";
//     }
//     cout<<"\n";
//     for(auto p:s){
//         cout<<p<<"\t";
//     }
//     auto p=s.find(10);      // also delete all exist
//     if(p!=s.end()){
//         s.erase(p);
//     }
//     cout<<"\n after delete\n";
//     for(auto p:s){
//         cout<<p<<"\t";
//     }
    
// }   
// WAP to search given string is panagram or not 
#include<iostream>
using namespace std;    
int panagram(string &s){
    if(auto a)
    for(auto p:s){
        cout<<p<<"\t";
    }
}    

int main(){
    string s="The quick brown fox jumps over the lazy dog";
    if(panagram(s)){
        cout<<"it is panagram string";
    }
    else{
        cout<<"not panagram";
    }
}
