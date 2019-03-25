// C. Inna and Huge Candy Matrix -- >#234 - 2
// rotate each point
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,m;
pair<ll,ll> rotate(ll x, ll y, ll rotn){
    pair<ll,ll> ans = make_pair(x,y);
    if(rotn == 1){ans.first = y; ans.second = n - x + 1;}
    if(rotn == 2){ans.first = n-x + 1; ans.second = m - y + 1;}
    if(rotn == 3){ans.first = m-y + 1; ans.second = x;}
    return ans;
}

int main(){
    ll x,y,z,p;cin>>n>>m>>x>>y>>z>>p;

    ll rotn1 = x % 4;
    ll rotn2 = (3*z) % 4;
    ll hor = y % 2;
    ll on=n,om=m;
    for(int i=0;i<p;i++){
        n = on;m = om;
        ll tx,ty;
        scanf("%lld%lld",&tx,&ty);

        pair<ll,ll> pt = rotate(tx,ty, rotn1);
        // swap axes
        if(rotn1 % 2 == 1){
            ll tmp =n;n = m;m = tmp;
        }
        if(hor == 1)pt.second = m - pt.second + 1;
        pt = rotate(pt.first, pt.second, rotn2);
        cout << pt.first << " " << pt.second << endl;
    }
}