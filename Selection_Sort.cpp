#include <bits/stdc++.h>
using namespace std;
void Selection_Sort(int*,int);
int main()
{
    int n,t,i;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int arr[n];
        
        for(i=0 ; i<n ; i++)
            cin>>arr[i];
            
        Selection_Sort(arr,n);
    }
    
    return 0;
}
void Selection_Sort(int *a, int n)
{
    int i,j,temp,min,comp=0,swap=0;
    
    for(i=0 ; i<n ; i++)
    {
        min = i;
        
        for(j=i+1 ; j<n ; j++)
        {
            if(a[min]>a[j])
            {
                min = j;
            }
            comp++;
        }
        
        if(min!=i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            swap++;
        }
    }
    cout<<endl;
    for(i=0 ; i<n ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Comparison = "<<comp;
    cout<<endl;
    cout<<"Swap = "<<swap;
}
