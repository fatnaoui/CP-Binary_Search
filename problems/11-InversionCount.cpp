#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void count(ll s,ll e,ll arr[],ll &c){
    if(s == e){
        return;
    }
    ll middle = (s + e)/2;
    count(s,middle,arr,c);
    count(middle+1,e,arr,c);
    ll i = s, j = middle+1, k = 0;
    vector<ll> temp(e-s+1);
    while((j <= e) && (i <= middle)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            c += (middle - i + 1);
        }
    }
    while (i <= middle) {
        temp[k++] = arr[i++];
    }
    while (j <= e) {
        temp[k++] = arr[j++];
    }
    for (ll i = s, k = 0; i <= e; i++, k++) {
        arr[i] = temp[k];
    }
    return ;
}

int main() {
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll arr[100];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll c = 0;
        count(0,n-1,arr,c);
        cout<<c<<endl;
    }
}
