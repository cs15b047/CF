#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
    ll sm = a[0], sma = a[0];
    vector<ll> c;c.push_back(0);
    for(int i=1;i<n;i++){
        if(2*a[i] <= a[0]){c.push_back(i);sma += a[i];}
        sm+=a[i];
    }
    if(2*sma > sm){
        cout << c.size() << endl;
        for(auto it: c)cout << it + 1 << " ";cout << endl;
    } else {
        cout << 0 << endl;
    }
}