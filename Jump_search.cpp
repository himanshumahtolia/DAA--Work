#include<bits/stdc++.h>
        using namespace std;
         int search_Jump(int arr[],int n,int key){
          int c=0,i=0,j=sqrt(n),k;
         	while(arr[j]<key && j<n){
         		i=j;
         		j=j+sqrt(n);
         		if(i>=n){
         			return c;
         		}
			 }
			 for(int k=i;k<=j;k++){
                    c++;
			 	if(arr[k]==key){
				   cout<<"present"<<" ";
			 	    return c;
		       }
			  }
                       c++;
			   cout<<"Not present"<<" "; 
			   return c;
		 }
       int main(){
   	    int t;
    	cin>>t;
   	   while(t--){	
     	int n,key;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++){
   		    cin>>arr[i];
	    }
	   cin>>key;
	    int k=search_Jump(arr,n,key);  
	    cout<<k<<"\n";
     }
	    return 0;
   }

