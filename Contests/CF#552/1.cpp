#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> c;
vector<pair<ll,ll>>data;

bool cmp(ll a, ll b){
	return (data[a-1].first - data[a-1].second) > (data[b-1].first - data[b-1].second);
}

int main(){
	ll n;cin >> n;
	c.clear();data.clear();data.resize(n);c.resize(n);
	for(int i=0;i<n;i++){cin >> data[i].first >> data[i].second;}
	vector<ll> ind(n);
	for(int i=1;i<=n;i++)ind[i-1] =i;
	sort(ind.begin(),ind.end(), cmp);
	// for(int i=1;i<=n;i++)cout << ind[i-1] << " ";cout << endl;
	ll answer = 0;
	for(int i=0;i<n;i++){
		answer += ((i+1) *(data[ind[i] - 1].first - data[ind[i] - 1].second)) + (data[ind[i] - 1].second * n - data[ind[i] - 1].first) ;
	}
	cout << answer <<endl;
}