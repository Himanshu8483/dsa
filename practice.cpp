// // hardcoding of stack 
// #include <iostream>
// #include <vector>
// using namespace std;

// class stacks {
//     public:
//     int n, top;
//     stacks(int s){
//         n=s;
//         arr=new int[n];
//         top=-1;
//     }
//     void pushs(int a){
//         if(top==n-1){
//             cout<<"overflow\n";
//             return;
//         }
//         top++;
//         arr[top]=a;
//     }
//     int pops(){
//         if(top==-1){
//             cout<<"there is no element";
//             return -1;
//         }
//         return arr[top];
//     }
// };

// int main(){
//     int val;
//     cout<<"enter size\n";
//     cin>>val;
//     int c;
//     stacks st(val);
//     for(int i=1; i<=val; i++){
//         cin>>c;
//         st.pushs(c);
//         while(st.top!=-1){
//             cout<<st.tops()<<"\n";
//             st.pops();
//         }
//         cout<<"top value = "<<st.tops()<<"\n";
//         st.pops();
//         cout<<"top value = "<<st.tops()<<"\n";
//     }
// }
//     // stacks st(5);
//     // st.pushs(10);
//     // st.pushs(4);
//     // st.pushs(5);
//     // st.pushs(23);
//     // st.pushs(89);
    
#include<iostream>
using namespace std;
class stacks{
    public:
    int *arr;
    int n, top;
    stacks(int s){
        n=s;
        arr=new int[n];
        top=-1;
    }
    void pushs(int a){
        if(top==n-1){
            cout<<"overflow\n";
            return;
        }
        top++;
        arr[top]=a;
    }
    int pops(){
        if(top==-1){
            cout<<"underflow";
            return -1;
        }
        return top--;
    }
    int tops(){
        if(top==-1){
            cout<<"there is no element";
            return -1;
        }
        return arr[top];
    }
};
int main(){
    int val;
    cout<<"enter size\n";
    cin>>val;
    int c;
    stacks st(val);
    for(int i=1;i<=val;i++){
        cin>>c;
        st.pushs(c);
    }
    while(st.top!=-1){
        cout<<st.tops()<<"\n";
        st.pops();
    }
    cout<<"top value = "<<st.tops()<<"\n";
    st.pops();
    cout<<"top value = "<<st.tops()<<"\n";
}