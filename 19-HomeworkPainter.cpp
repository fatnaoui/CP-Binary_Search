#include <bits/stdc++.h>
using namespace std;

bool is_possible(int middle,int k,int n,int arr[],int m){
    if(middle < m){
        return false;
    }
    int cur = 0;
    for(int i=0;i<n;i++){
        if(cur+arr[i] > middle){
            k--;
            cur = arr[i];
            if(k == 0){
                return false;
            }
        }
        else{
            cur += arr[i];
        }
    }
    return true;
}

int min_time(int k,int n,int arr[],int sum,int m){
    int s = 1;
    int e = sum;
    int ans = INT_MAX;
    while(s <= e){
        int middle = (s+e)/2;
        if(is_possible(middle,k,n,arr,m)){
            e = middle - 1;
            ans = min(middle,ans);
        }
        else{
            s = middle + 1;
        }
    }
    return ans;
}

int main() {
    int k,n; cin>>k>>n;
    int arr[100];
    int sum = 0;
    int m = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
        m = max(m,arr[i]);
    }
    cout<<min_time(k,n,arr,sum,m);
}
