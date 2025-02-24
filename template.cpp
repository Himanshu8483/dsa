// #include <iostream>
// using namespace std;
// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) { // Outer loop runs (n-1) times
//         bool swapped = false; // To check if swapping happened
        
//         for (int j = 0; j < n - i - 1; j++) { // Inner loop for comparison
//             if (arr[j] > arr[j + 1]) { // If current element is greater than next
//                 swap(arr[j], arr[j + 1]); // Swap elements
//                 swapped = true; // Mark swapped as true
//             }
//         }
        
//         if (!swapped) break; // If no swaps, array is already sorted
//     }
// }
// void printArray(int arr[], int n){
//     for(int i =0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// int main(){
//     // int arr[]={1,2,3,5,4};
//     // int size=sizeof(arr)/sizeof(arr[0]);
//     // printArray(arr, size);
//     // cout<<"After Sorting"<<endl;
//     // bubbleSort(arr, size);
//     // printArray(arr,size);

//     int n;
//     cout<<"Enter Size of Array";
//     cin>>n;
//     cout<<"Enter Values";
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     printArray(arr, n);
//     cout<<"After Sort"<<endl;
//     bubbleSort(arr, n);
//     printArray(arr,n);
    
//     return 0;
// }

// // 22 feb 
// // template 
// #include <iostream>
// using namespace std;
// template<typename t1>
// t1 sum (t1 a, t1 b){
//     return a+b;
// }
// template<typename x1, typename x2>
// x1 multiply(x1 x, x2 y)
// {
//     return x*y;
// }
// int  main()
// {
//     cout<<sum(8.3, 9.9)<<"\n";
//     cout<<multiply(3,2.3);
// }

// // 24 feb Monday
// // class template 
// #include <iostream>
// using namespace std;
// template<typename v1>
// class cybrom {
//     v1 a;
//     public: 
//     cybrom(v1 x) {
//         a=x;
//     }
//     v1 show(){
//         return a+1;
//     }
// };

// int main(){
//     cybrom<int>obj(34);         // allocate run time memory type
//     cout<<obj.show();
// }

// 2 data types class 
#include <iostream>
using namespace std;
template<typename v1, typename v2>
class cybrom {
    public: 
    void show(v1 t1, v2 t2){
        cout<<t1+t2;
    }
};

int main(){
    cybrom<int, double>obj;         // allocate run time memory type
    obj.show(3, 4.4);
}