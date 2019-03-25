#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n, m;
ll dist(ll s, ll d){
	if(d > s)return d - s;
	return (d + n - s) % n ;
}

class cmp{
public:
	bool operator()(pair<ll,ll> a, pair<ll,ll> b){
		return (a.first > b.first) || ((a.first == b.first) && (a.second < b.second));
	}
};

int main(){
	scanf("%lld%lld",&n,&m);
	vector<set<pair<ll,ll>, cmp>> adj(n + 1);
	vector<vector<ll>> edge_cnt(n + 1, vector<ll>(n + 1, 0));
	for(int i=0;i<m;i++){
		ll s,d;
		scanf("%lld%lld",&s,&d);
		adj[s].insert(make_pair(dist(s,d), d));
		edge_cnt[s][d]++;
	}
	vector<ll> answer(n + 1);
	for(int st=1;st<=n;st++){
		ll ans = 0;
		ll curr = st;
		ll remn_candies = m ;
		vector<vector<ll>> edge_cnt2 = edge_cnt;
		vector<set<pair<ll,ll>, cmp>> adj2 = adj;

		vector<ll> carry(n + 1, 0);
		while(remn_candies > 0){
			remn_candies -= carry[curr];
			carry[curr] = 0;
			if(remn_candies == 0)break;

			auto it = adj2[curr].begin();
			if(!adj2[curr].empty()){
				carry[it->second]++;
				if(edge_cnt2[curr][it->second] == 1){
					edge_cnt2[curr][it->second] = 0;
					adj2[curr].erase(make_pair(dist(curr, it->second), it->second));
				}
				else edge_cnt2[curr][it->second]--;
			}
			if(curr != n)curr = curr + 1;
			else curr = 1;
			ans++;
		}
		answer[st] = ans ;
	}
	for(int i=1;i<=n;i++)cout << answer[i] << " ";
}