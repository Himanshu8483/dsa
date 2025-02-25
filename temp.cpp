
#include <iostream>
using namespace std;
template <typename t1>

class Fact{
public:
    t1 Sum(t1 n)
    {
    if(n<=1)
    {
        return n;
    }
    else{
        return n * Sum(n-1);
    }
}};

int main(){
    Fact<int> obj;
    cout<<obj.Sum(5);
}