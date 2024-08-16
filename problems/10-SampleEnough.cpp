#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ones(ll s,ll e,ll l,ll r,ll n){
    if(s == e){
        return n;
    }
    ll mid = (s + e)/2;
    ll a = 0, b = 0, c =0; 
    if(l < mid){
        a = ones(s,mid-1,l,r,n/2);
    }
    if(r > mid){
        b = ones(mid+1,e,l,r,n/2);
    }
    if((l <= mid) && (r >= mid)){
        c = n%2;
    }
    return a+b+c;
}

int main() {
    ll n,l,r;
    cin>>n>>l>>r;
    ll nc = n;
    ll len = 1;
    ll add = 2;
    while(nc > 1){
        nc >>= 1;
        len += add;
        add <<= 1;
    }
    cout<<ones(1,len,l,r,n);
}
