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

//write a program to print the sum  of two vector:

#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<vector<int>>v1;
    int row, col;
    int val;
    cout<<"enter size of row\n";
    cin>>row;
    cout<<"enter size of column\n";
    cin>>col;
    for(int i=0; i<row;i++){
        vector<int>v2;
        for(int j=0;j<col;j++){
            cout<<"enter value\n";
            cin>>val;
            v2.push_back(val);
        }
        v1.push_back(v2);
    }
    cout<<"stored values in 2d vector\n";
    for(int i=0; i<v1.size();i++){
        for(int j=0;j<v1[i].size();j++){
            cout<<v1[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
// Q2: sum of the total values of two vector :
// v1=3,1,2,5
// v2= 7,2,3,4
// v1+v2= 10, 3, 5, 9 