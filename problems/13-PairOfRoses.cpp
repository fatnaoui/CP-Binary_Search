#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i,a,b) for(int i=a;i<=b;i++)
#define RF(i,a,b) for(int i=a;i>=b;i--)

void find_roses(ll n,ll m,ll arr[],ll &x,ll &y){
    ll dif = LLONG_MAX;
    F(i,0,n-1){
        if(arr[i] >= m){
            break;
        }
        bool present = binary_search(arr+i+1,arr+n,m-arr[i]);
        if(present){
            ll secondidx = lower_bound(arr+i,arr+n,m-arr[i])-arr;
            ll newdiff = abs(arr[i] - arr[secondidx]);
            if(newdiff <= dif){
                x = arr[i];
                y = arr[secondidx];
                dif = newdiff;
            }
        }
    }
}

int main() {
    ll t; cin>>t;
    while(t--){
        ll n,arr[100],m;
        cin>>n;
        F(i,0,n-1){
            cin>>arr[i];
        }
        cin>>m;
        sort(arr,arr+n);
        ll x = 0, y = 0; 
        find_roses(n,m,arr,x,y);
        cout<<'('<<x<<','<<y<<')'<<endl;
    }
}
