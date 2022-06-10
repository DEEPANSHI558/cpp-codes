

#include <iostream>
using namespace std;
void shellSort(int array[], int n) {
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}
int main() {
   int n;
    cout<<"enter the size of the array :";
    cin>>n;
    int *arr=new int [n];
    cout<<"enter the array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    shellSort(arr,n);
    cout << "Sorted array is (Shell Sort):\n";
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
}