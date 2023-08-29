#include<bits/stdc++.h>
  using namespace std;
      int  search_Binary(int arr[],int p,int q,int key){
        int c=0;
     	while(p<q){
     	 	 int mid=(p+q)/2;
     	 	  if(arr[mid]==key){
                  c++;
                  cout<<"present"<<" "; 
                 return c;
			   }
     	 	  else if(arr[mid]>key){
     	 	    c++;
                q=mid-1;
			    }
			  else if(arr[mid]<key){
				   c++;
                  p=mid+1;
			   }
		   }
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
	   int k=search_Binary(arr,0,n,key);  
	    cout<<k<<"\n";
    }
	    return 0;
   }

