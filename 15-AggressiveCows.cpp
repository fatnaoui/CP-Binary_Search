#include <bits/stdc++.h>
using namespace std;

int min_distance(int n,int m,int arr[]){
    int ans = 0;
    int s = arr[0];
    int e = arr[n-1] - arr[0];
    while(s <= e){
        int middle = (s+e)/2;
        int c = m-1;
        int ss = 0;
        for(int i=1;i<n;i++){
            if((arr[i]-arr[ss]) >= middle){
                c--;
                ss = i;
            }
            if(c == 0){
                ans = middle;
                s = middle+1;
                break;
            }
        }
        if(c != 0){
            e = middle-1;
        }
    }
    return ans;
}

int main() {
    int n,m;cin>>n>>m;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<min_distance(n,m,arr);
}
