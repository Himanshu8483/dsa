#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
 
 vector<int>vec{34,5,12,87,87,5,3};
 sort(vec.begin(),vec.end());
 int m = vec[vec.size()-1]; 
 for(int i=vec.size()-1; i>=0; i--){
    if(vec[i]<m){
        cout<<vec[i];
        break;
    }
 }
  cout<<"\n second minimum value = "<<*(vec.begin()+2);   
}