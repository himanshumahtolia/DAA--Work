
#include <bits/stdc++.h>
using namespace std;
void Insertion_Sort(int*,int);
int main()
{
    int t,n,i;
    
    cin>>t;
    while(t--)
    {
    cin>>n;
    
    int arr[n];

    for(i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    
    Insertion_Sort(arr,n);
    }
    
    return 0;
}

void Insertion_Sort(int *arr, int n)
{
    int i,j,temp,comp=0,shft=0;
    
    for(i=1 ; i<n ; i++)
    {
        temp = arr[i];
        for(j=i-1 ; j>=0 && temp<arr[j] ; j--)
        { 
            comp++;
            shft++;
            arr[j+1] = arr[j];
        }
        comp++;
        arr[j+1] = temp;
    }
    
    for(i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Comparison = "<<comp;
    cout<<endl;
    cout<<"shift = "<<shft;


}
