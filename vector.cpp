// #include<iostream>
// using namespace std;
// #include<vector>
// int main(){
//     vector<vector<int>>v1;
//     int row, col;
//     int val;
//     cout<<"enter size of row\n";
//     cin>>row;
//     cout<<"enter size of column\n";
//     cin>>col;
//     for(int i=0; i<row;i++){
//         vector<int>v2;
//         for(int j=0;j<col;j++){
//             cout<<"enter value\n";
//             cin>>val;
//             v2.push_back(val);
//         }
//         v1.push_back(v2);
//     }
//     cout<<"stored values in 2d vector\n";
//     for(int i=0; i<v1.size();i++){
//         for(int j=0;j<v1[i].size();j++){
//             cout<<v1[i][j]<<"\t";
//         }
//         cout<<"\n";
//     }
// }

//Q1: write a program to print the sum  of two vector:

// Q2: sum of the total values of two vector :
// v1=3,1,2,5
// v2= 7,2,3,4
// // v1+v2= 10, 3, 5, 9 

// Q1 
// #include<iostream>
// using namespace std;
// #include<vector>
// int main(){
//     vector<int>v1{3,1,2,5};
//     vector<int>v2{ 7,2,3,4};

//     for(int i=0; i<v1.size();i++){
//         cout<<v1[i]+v2[i]<<" ";
//     }
// }

// #include<iostream>
// using namespace std;
// #include<vector>
// int main(){
//     vector<int>v1{3,1,2,5};
//     vector<int>v2{ 7,2,3,4};
//     vector<int>v3;

//     for(int i=0; i<v1.size();i++){
//         int sum =v1[i]+v2[i];
//         v3.push_back(sum);
//     }
//     for(auto p:v3){
//         cout<<p<<"\t";
//     }
// }

// Q2.
// #include<iostream>
// using namespace std;
// #include<vector>
// int main(){
//     vector<int>v1{3,1,2,5};
//     vector<int>v2{ 7,2,3,4};
//     int sum=0;

//     for(int i=0; i<v1.size();i++){
//         sum+=v1[i]+v2[i];
//     }
//     cout<<sum;
// }

// // with two variable 
// #include<iostream>
// using namespace std;
// #include<vector>
// int main(){
//     vector<int>v1{3,1,2,5};
//     vector<int>v2{ 7,2,3,4};
//     int sum1=0, sum2=0;

//     for(int i=0; i<v1.size();i++){
//         sum1+=v1[i];
//         sum2+=v2[i];

        
//     }
//     cout<<sum1+sum2;
// }

// // q3 
// #include<iostream>
// using namespace std;
// #include<vector>
// int main(){
//     vector<int>v1{3,11,2,5};
//     vector<int>v2{ 7,2,3,4};
//     int sum1=0, sum2=0;

//     for(int i=0; i<v1.size();i++){
//         sum1+=v1[i];
//         sum2+=v2[i];

        
//     }
//     if (sum1 == sum2){
//         cout<<"equal";
//     }
//     else if (sum1 > sum2){
//         cout<<"First Greater";
//     }
//     else{
//         cout<<"second Greater";
//     }
// }

// q4 for not equal vector
#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int>v1{3,1,2,5};
    vector<int>v2{ 7,2,4};
    vector<int>v3;

    for(int i=0; i<v1.size();i++){
        int sum =v1[i]+v2[i];
        v3.push_back(sum);
    }
    for(auto p:v3){
        cout<<p<<"\t";
    }
}

// 5th: remove duplicate and print in ascending order 

// 6th: Second Minimum value 