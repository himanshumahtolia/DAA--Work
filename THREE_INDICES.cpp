#include <bits/stdc++.h>
using namespace std;
void Sum_Of_Three(int*,int);
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
        Sum_Of_Three(arr,n);
    }
    return 0;
}

void Sum_Of_Three(int *arr, int n)
{
    int i,j,k;
    
    for(i=0 ; i<n ; i++)
    {
        for(j=i+1 ; j<n ; j++)
        {
            for(k=j+1; k<n; k++)
            {
                if(arr[i]+arr[j]==arr[k])
                {
                     cout<<i+1<<" "<<j+1<<" "<<k+1;
                     return;
                }
                   
            }
        }
    }
    cout<<"Element not found";
}

