#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n; cin >> n;
    vector<ll> sz(n);for(int i=0;i<n;i++)cin >> sz[i];sort(sz.begin(), sz.end());
    vector<ll> first, second;for(int i=0;i<n/2;i++)first.push_back(sz[i]);for(int i=n/2;i<n;i++)second.push_back(sz[i]);
    ll visible = 0;
    ll ptr2 = (ll)(second.size()) - 1, ptr1 = (ll)(first.size()) - 1;
    while(ptr2 >= 0 && ptr1 >= 0){
        if(second[ptr2] >= 2*first[ptr1]){
            ptr1--;
            ptr2--;
        } else {
            ptr1--;
        }
    }
    visible = n - ((second.size() - 1) - (ptr2));
    cout << visible << endl;
}