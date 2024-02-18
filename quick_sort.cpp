#include <bits/stdc++.h>
using namespace std;  

  int c=0,sw=0;
void swap(int* a, int* b) 
{ 
  sw++;
    int t = *a; 

    *a = *b; 

    *b = t; 
} 
int partition (int arr[], int p, int q) { 
    int pivot = arr[q]; // pivot 
    int i = (p - 1);  
    for (int j = p; j <= q - 1; j++,c++){ 
        if (arr[j] < pivot) 
        { 
            i++; 
          swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[q]);     
    return (i + 1); 
} 
void quickSort(int arr[], int p, int q) { 
    if (p < q) { 
        int pi = partition(arr, p, q); 
        quickSort(arr, p, pi - 1); 
        quickSort(arr, pi + 1, q); 
    } 
} 

void printArray(int arr[], int size) { 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main() { 
  int t;
  cin>>t;
while(t--){    c=0,sw=0;
    int n ;
     cin>>n;
  int arr[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];
    quickSort(arr, 0, n - 1); 
    printArray(arr, n);
    cout<<"\n"<<"comparison= "<<c;
    cout<<"\n"<<"swap= "<<sw<<"\n";
    }
    return 0; 
}
