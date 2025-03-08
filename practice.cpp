// // stack 
// #include<iostream>
// using namespace std;
// int valid(string s){
// if(s.size()>4){
//     return true;           // or return true
// }
// else{
//     return false;
// }
// }
// int main(){
//     string s;
//     cout<<"enter name";
//     cin>>s;
//     if(valid(s)){
//         cout<<"YES";
//     }
//     else{
//         cout<<"No";
//     }
    
// }

// #include<iostream>
// using namespace std;
// #include<bits/stdc++.h>     // for including all files in one include, memory use extra so waste of memory because of taking all include files
// bool valid(string s){

// }
// int main(){
//     string s;
//     cout<<"Enter Combination of Bracket";
// // }

// // 8 mar 

// #include<iostream>
// using namespace std;
// #include<stack>
// bool valid(string s){
//     stack<char>st;
//     bool r =true;
//     for(int i = 0; i<s.size(); i++){
//         if(s[i]=='[' || s[i]=='{' || s[i]=='(' ){
//             st.push(s[i]);
//         }
//         else if(s[i]==']'){
//             if(!st.empty() && st.top()=='['){
//                 st.pop();
//             }
//             else{
//                 r=false;
//                 break;
//             }
//         }
//         else if(s[i]=='}'){
//             if(!st.empty() && st.top()=='{'){
//                 st.pop();
//             }
//             else{
//                 r=false;
//                 break;
//             }
//         }
//         else if(s[i]==')'){
//             if(!st.empty() && st.top()=='('){
//                 st.pop();
//             }
//             else{
//                 r=false;
//                 break;
//             }
//         }
//     }
//     if(!st.empty()){
//         return false;
//     }
//     else{
//         return r;
//     }

// }
// int main(){
//     string s="{([])}";
//     if(valid(s)){
//         cout<<"valid";
//     }
//     else{
//         cout<<"invalid";
//     }
// }

#include <iostream>
using namespace std;
#include<stack>

bool valid(string s) {
    stack<char> st;
    bool r = true;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            st.push(s[i]); // Push opening brackets to stack
        }
        else if (s[i] == '}') {
            if (!st.empty() && st.top() == '{') {
                st.pop(); // Correct match, remove from stack
            } else {
                r = false;
                break; // Mismatch found, stop checking
            }
        }
        else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                r = false;
                break;
            }
        }
        else if (s[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                r = false;
                break;
            }
        }
    }

    // Move return statement outside the loop
    return st.empty() && r;
    // or 
    if(!st.empty()){
        return false;
    }
    else{
        return r;
    }
}
int main() {
    string s = "{([])}"; // Input string
    if (valid(s)) {
        cout << "valid";
    } else {
        cout << "invalid";
    }
}
    