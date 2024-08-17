#include <bits/stdc++.h>
using namespace std;

int calc(int r, int middle) {
    int ans = 0;
    int time = 0;
    int k = 1;
    while (true) {
        time += k * r;
        if (time > middle) break;
        ans++;
        k++;
    }
    return ans;
}

bool is_possible(int p,int c,int arr[],int middle){
    for(int i=0;i<c;i++){
        int np = calc(arr[i],middle);
        if(np >= p){
            return true;
        }
        p -= np;
    }
    return false;
}

int min_time(int p,int c,int arr[]){
    int s = p;
    int e = arr[c-1]*(p*(p+1)/2);
    int ans = INT_MAX;
    while(s <= e){
        int middle = (s+e)/2;
        if(is_possible(p,c,arr,middle)){
            ans = min(ans,middle);
            e = middle - 1;
        }
        else{
            s = middle +1;
        }
    }
    return ans;
}

int main() {
    int t; cin>>t;
    while(t--){
        int p,c;
        cin>>p>>c;
        int arr[100];
        for(int i=0;i<c;i++){
            cin>>arr[i];
        }
        cout<<min_time(p,c,arr)<<endl;
    }
}
