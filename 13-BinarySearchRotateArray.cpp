#include <bits/stdc++.h>
using namespace std;

int binary_search_inv(int arr[],int n,int key){
    int s = 0;
    int e = n-1;
    while(s <= e){
        int middle = (s+e)/2;
        if(arr[middle] == key){ return middle;}
        else if(arr[s] <= arr[middle]){
            if((key <= arr[middle]) && (key >= arr[s])){
                e = middle-1;
            }
            else{
                s = middle+1;
            }
        }
        else{
            if((key <= arr[e]) && key >= arr[middle]){
                s = middle+1;
            }
            else{
                e = middle-1;
            }
        }
    }
    return -1;
}

int main() {
    int n; cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key; cin>>key;
    cout<<binary_search_inv(arr,n,key);
}
