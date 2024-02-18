//Check if duplicate elements present or not (in time complexity:- O(nlogn))
#include <bits/stdc++.h>
using namespace std;
void Binary_Search(int*,int,int,int,int,int*);
int main()
{
    int t,n,i,check=0;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int arr[n];
        
        for(i=0 ; i<n ; i++)
        {
            cin>>arr[i];
        }
        
        for(i=0 ; i<n ; i++)
        {
            Binary_Search(arr,n,arr[i],i+1,n-1,&check);
            if(check==1)
            {
				cout<<"YES";
				break;
			}
			else
			{
				cout<<"NO";
				break;
			}
        }
    }
    
    return 0;
}
void Binary_Search(int *arr, int n, int key, int p, int q,int *check)
{
    int mid;
    if(p<q)
    {
        mid = (p+q)/2;
        if(arr[mid]==key)
        {
            *check = 1;
            return ;
        }
        else if(arr[mid]<key)
        {
            Binary_Search(arr,n,key,mid+1,q,check);
        }
        else if(arr[mid]>key)
        {
            Binary_Search(arr,n,key,p,mid-1,check);
        }
    }
}

