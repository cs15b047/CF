#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

vector<ll>h;
bool comp(ll a, ll b){return h[a] < h[b];}
int main()
{
	ll n;cin>>n;
	h.resize(n);vector<ll>ind(n);for(int i=0;i<n;i++)cin >> h[i];
	for(int i=0;i<n;i++)ind[i]=i;
	stable_sort(ind.begin(),ind.end(),comp);
	map<ll,ll> ind_map;
	for(int i=0;i<n;i++){
		ind_map[ind[i]] = i;
	}
	ll curr = -1;
	ll ans = 0;
	for(int i=0;i<n;i++){
		curr = max(curr, ind_map[i]);
		if(curr == i){
			ans++;
			curr = -1;
		}
	}
	cout<<ans<<endl;

}