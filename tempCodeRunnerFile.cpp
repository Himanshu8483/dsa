#include<iostream>
#include<stack>
using namespace std;

void displayReverse(stack<int> s) { // Copy of stack
    if (s.empty()) return;
    int temp = s.top();
    s.pop();
    displayReverse(s);
    cout << temp << " ";
}

int main() {
    stack<int> s;
    s.push(10); s.push(20); s.push(30);
    cout << "Original Stack (Without Change): 10 20 30" << endl;
    cout << "Stack in Reverse: "; 
    displayReverse(s); 
    cout << endl;
    return 0;
}
