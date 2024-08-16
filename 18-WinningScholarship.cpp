#include <bits/stdc++.h>
using namespace std;

bool is_possible(int middle,int n,int m,int x,int y){
    int needs = middle*x;
    int wehad = m + (n - middle)*y;
    return needs <= wehad;
}

int max_students(int n,int m,int x,int y){
    int s = 0;
    int e = n;
    int ans = INT_MIN;
    while(s <= e){
        int middle = (s+e)/2;
        if(is_possible(middle,n,m,x,y)){
            s = middle + 1;
            ans = max(middle,ans);
        }
        else{
            e = middle - 1;
        }
    }
    return ans;
}

int main() {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    cout<<max_students(n,m,x,y);
}
