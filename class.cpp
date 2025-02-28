#include <iostream>
using namespace std;

void bubbleSort(int arr[], int s) {
    int temp;
    int count = 0;
    bool swapped;  

    for (int i = 0; i < s; i++) {
        swapped = false;  // Set to false at the start of each pass
        for (int j = 0; j < s - i - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;  // Swap occurred, so set it to true
            }
        }
        if (!swapped) {  // If no swap, array is already sorted
            break;
        }
    }
    // Print sorted array
    for (int i = 0; i < s; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\nCounter hit = " << count << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};  // Already sorted array
    int s = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: \n";
    for (int i = 0; i < s; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\nAfter applying Bubble Sort:\n";
    bubbleSort(arr, s);
    return 0;
}


#include <iostream>
using namespace std;
void insertionSort(int arr[], int s) {
    for (int i = 1; i < s; i++) {
        int mn = i;
        while (mn > 0 && arr[mn] < arr[mn - 1]) {
            int temp = arr[mn - 1];
            arr[mn - 1] = arr[mn];
            arr[mn] = temp;
            mn--;
        }
    }
    for (int i = 0; i < s; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main() {
    int arr[] = {10, 5, 50, 2, 20};
    int s = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: \n";
    for (int i = 0; i < s; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\nAfter applying Insertion Sort:\n";
    insertionSort(arr, s);
    return 0;
}
#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element of the unsorted part is the smallest
        // Find the actual minimum in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "Sorted Array: ";
    printArray(arr, n);
    return 0;
}
 
#include <iostream> // not work
using namespace std;

// Function to partition the array
int part(int arr[], int low, int high) {
    int pivot = arr[low]; // Choosing first element as pivot
    int i = low + 1;    
    int j = high;

    do {
        while (arr[i] < pivot) { // Move i to the right until finding a larger element
            i++;
        }
        while (arr[j] > pivot) { // Move j to the left until finding a smaller element
            j--;
        }
        if (i < j) { // Swap elements to keep smaller elements on left and larger on right
            swap(arr[i], arr[j]);
        }
    } while (i < j);

    // Swap pivot with the correct position
    swap(arr[low], arr[j]);

    return j; // ✅ We use return j; to get the correct pivot position so that Quick Sort can divide and sort the array properly.
}

// Function to perform Quick Sort
void qksrt(int arr[], int low, int high) {
    if (low < high) {
        int pv = part(arr, low, high); // Get pivot index
        qksrt(arr, low, pv - 1);  // Sort left part
        qksrt(arr, pv + 1, high); // Sort right part
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}                     
// Main function
int main() {
    int arr[] = {1, 3, 1, 2, 1}	;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, size);

    qksrt(arr, 0, size - 1);

    cout << "After Quick Sort:\n"; 
    printArray(arr, size);

    return 0;
}
#include <iostream>
using namespace std;
void combine(int arr[], int low, int mid, int high){
    int i=low;
    int j= mid+1;
    int k=low;
    int bk[high+1];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            bk[k]= arr[i];
            i++;
            k++;
        }
        else{
            bk[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        bk[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        bk[k]=arr[j];
        j++;
        k++;
    }
    for(int i=low;i<k;i++){
        arr[i]=bk[i];
    }
}
void mergesrt(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesrt(arr, low, mid);
        mergesrt(arr, mid+1, high);
        combine(arr,low, mid, high);
    }
}
int main(){
    int arr[] = {12, 11, 13, 5, 6, 7, 1};
    int s=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<s;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\nAfter merge sort\n";
    mergesrt(arr,0,s-1);
    for(int i=0;i<s;i++){
        cout<<arr[i]<<"\t";
    }
}

// ✅✅✅✅✅✅✅✅✅✅✅✅🚨🚨🚨