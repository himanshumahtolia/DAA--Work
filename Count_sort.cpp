#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255

void countSort(char arr[]){
    char output[strlen(arr)];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

char mostFrequent(char arr[], int n){
    int max_count = 1, x = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else
            curr_count = 1;
        if (curr_count > max_count) {
            max_count = curr_count;
            x = arr[i - 1];
        }
    }
    return x;
}

int countOccurrences(char arr[], int n){
    int res = 1;
    char j=mostFrequent(arr, n);
    for (int i=0; i<n; i++)
        if (j == arr[i+1]){
            res++;
        }
    return res;
}

int main()
{   
    int v;
    cin>>v;
    while(v>0){
        int n;
        cin>>n;
        char arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        countSort(arr);
        cout<<mostFrequent(arr, n)<<" - "<<countOccurrences(arr, n);
        v--;
    }
    return 0;
}
