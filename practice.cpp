#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
      for (int i = 0; i < 3; i++) {
          int minIndex = i; // Assume the first element of the unsorted part is the smallest

          // Find the actual minimum in the unsorted part
          for (int j = i + 1; j < 5; j++) {
              if (arr[j] < arr[minIndex]) {
                  minIndex = j;
              }
cout<<minIndex;

          }
cout<<minIndex;

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