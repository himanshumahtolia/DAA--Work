  #include<bits/stdc++.h>
  using namespace std;
  
  // working function..........
  
   void search_linear(int arr[],int n,int key){
   	   // for linear search i will check one by one element...
   	  int flag=0,c=0,i=0;
   	  while(i<n){
        c++;
   	  	  if(arr[i]==key){
   	  	  	flag=1;
   	  	  	break;
			   }
			   i++;
		 }
	    if(flag==1){
		 	cout<<"Present"<<" "<<c<<"\n";
		 }
		else{
		 	cout<<"Not Present"<<" "<<c<<"\n";
		 }
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
	   search_linear(arr,n,key);
      }
	    return 0;
   }

