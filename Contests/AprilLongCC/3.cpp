#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int q=0;q<t;q++){
		ll n,m,k; cin >> n >> m >> k;
		set<pair<ll,ll>> pts;for(int i=0;i<k;i++){ll x,y;cin >> x >> y;pts.insert(make_pair(x,y));}
		ll answer = 0;
		for(auto it:pts){
			pair<ll,ll> top,bot,left,right;
			ll nbh = 0;
			top = make_pair(it.first - 1, it.second);bot = make_pair(it.first + 1, it.second);
			left = make_pair(it.first, it.second - 1);right = make_pair(it.first, it.second + 1);
			if(pts.find(top) != pts.end())nbh++;if(pts.find(bot) != pts.end())nbh++;
			if(pts.find(left) != pts.end())nbh++;if(pts.find(right) != pts.end())nbh++;
			answer += (4 - nbh);
		}
		cout << answer << endl;
	}	
}