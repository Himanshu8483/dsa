#include <iostream>
using namespace std;
void bubles(int arr[], int s) {
    int temp;
    int count=0;
    bool t;
    for(int i=0; i<s; i++){
        t= true;
        for(int j=0; j<s-i-1; j++){
            count++;
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                t=false;
            }
        }
        if(t==true){
            break;
        }
    }
    for(int i=0; i<s; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\ncounter hit = "<<count;
}
int main(){
    // int arr[]={5,4,3,2,1};
    int arr[]={1,2,3,4,5};
    int s= sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<s;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\nAfter applying bubble sort\n";
    bubles(arr,s);
}