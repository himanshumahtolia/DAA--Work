#include <bits/stdc++.h>
using namespace std;

  int c=0;
int inv=0 ;
void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
      L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
       M[j] = arr[q + 1 + j];
  int i=0, j=0, k=p;
  while (i < n1 && j < n2) {

    if (L[i] <= M[j]) { 
       arr[k] = L[i];
        i++;
     } 
    else {
      arr[k] = M[j];
       inv+=(n1-i);
         j++;
    }
    k++;
    c++;
  }
    while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
      }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
 
}

void  mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
     
  } 
}
   void print(int arr[] ,int r){
   for (int i = 0; i < r; i++)
    cout << arr[i] << " ";
    }

int main() {
   int t;
    cin>>t;
    while(t--){
     c=0;
     int n;
     cin>>n;
    int arr[n] ;
    for (int i = 0; i < n; i++)
       cin>>arr[i];
      mergeSort(arr, 0, n - 1);
     print(arr,n);
    cout<<"\n"<<"comparison= "<<c<<"\n"<<"inversion= "<<inv;
    
}
  return 0;
}

