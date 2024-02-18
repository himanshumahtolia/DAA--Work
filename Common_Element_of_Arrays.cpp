#include<bits/stdc++.h>
using namespace std;


  void matching (int arr[],int brr[],int n,int m){ 
     int temp[m+n];
    int i=0,j=0,k=0;
    while(i<n && j<m){
      if(arr[i]==brr[j]){
           temp[k]=arr[i];
            i++,j++;
            k++;
            }
          else if(arr[i]>brr[j]){
                j++;
            }
           else{
              i++;
            }
         }
      for(int a=0;a<k;a++){
         cout<<temp[a]<<" ";
           } 
 }

int main() {
     int n,m;
     cin>>n;
    int arr[n],brr[m] ;
    for (int i = 0; i < n; i++)
       cin>>arr[i];
     sort(arr,arr+n);
    
        cin >>m;
    for(int i = 0; i < m; i++)
       cin>>brr[i];
     sort(brr,brr+m);  
      matching(arr,brr, n, m);
  return 0;
}
