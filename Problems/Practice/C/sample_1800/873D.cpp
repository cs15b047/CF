#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k; cin >> n >> k;
	if(k % 2 == 0){
		cout << -1 << endl;
	} else{
		queue<pair<ll,ll>> q;
		pair<ll,ll> strt = make_pair(0, n);
		q.push(strt);
		ll tot_pairs = 1;
		while(!q.empty()){
			if(tot_pairs == k)break;
			pair<ll,ll> top = q.front();q.pop();
			if(top.second - top.first > 1){
				pair<ll,ll> nbh1 = make_pair(top.first, (top.first + top.second)/2);
				pair<ll,ll> nbh2 = make_pair((top.first + top.second)/2, top.second);
				q.push(nbh1);
				q.push(nbh2);
				tot_pairs+=2;
			}
		}
		if(tot_pairs == k){
			vector<ll> arr(n);
			for(int i = 0;i < n;i++)arr[i] = n - i;
			while(!q.empty()){
				pair<ll,ll> top = q.front();q.pop();
				sort(arr.begin() + top.first, arr.begin() + top.second);
			}
			for(auto it: arr)cout << it << " ";cout << endl;
		} else if(tot_pairs < k){
			cout << -1 << endl;
		}
	}
}