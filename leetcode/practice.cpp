
#include<iostream>
#include<vector>
using namespace std;

int sumArrays(vector<int>& a1, vector<int>& a2) {
    long long num1 = 0, num2 = 0;
    for (int n : a1) num1 = num1 * 10 + n;
    for (int n : a2) num2 = num2 * 10 + n;
    return num1 + num2;
}

int main() {
    vector<int> A1 = {2, 3, 1, 4};
    vector<int> A2 = {6};
    cout << "Sum: " << sumArrays(A1, A2) << endl;

    vector<int> B1 = {2, 3, 1, 4};
    vector<int> B2 = {2, 3};
    cout << "Sum: " << sumArrays(B1, B2) << endl;
    
    return 0;
}