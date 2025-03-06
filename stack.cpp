// stack: for temprary 
// it is a built in c++ follow lifo 
// Here push and pop, empty(), top() method
// used for searching not store any data(temprary) so loop cannot be performed to print stack  so store in ram
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
int main(){
    stack<int>st;
    st.push(10);
    st.push(4);
    st.push(5);
    st.push(11);
    st.push(3);
    // for(auto p:st){
    //     cout<<p<<"\t"
    // }   // loop not work
    // cout<<st.top();
    cout<<st.empty()<<endl;     // condition false so result: 0(false)
    while(!st.empty()){
        cout<<st.top()<<"\t";
        st.pop();
    }
    cout<<endl<<st.empty()<<endl;     // condition true so result: 1(true)

}