#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> arr;

int main(){
	ll n, m, w; cin >> n >> m >> w;
	arr.resize(n);for(int i=0;i<n;i++)cin >> arr[i];
	ll mnm = 1e18, mxm = 1;for(int i=0;i<n;i++){mnm = min(mnm, arr[i]);mxm = max(mxm, arr[i]);}mxm += m;
	ll curr = mnm;
	while(mnm <= mxm){
		vector<ll> posn, starts(n, 0);
		ll mid = (mnm + mxm)/ 2;
		for(int i=0;i<n;i++){
			if(arr[i] < mid)posn.push_back(i);
		}
		ll moves = 0;
		ll window_sum = 0;set<ll> window;
		for(int i=0; i < posn.size(); i++){
			while(!window.empty() && *(window.begin()) <= posn[i] - w ){
				ll first = *(window.begin());
				window_sum -= starts[first];
				window.erase(first);
			}
			ll strt = (mid - arr[posn[i]]) - window_sum;
			if(strt > 0){
				window.insert(posn[i]);
				window_sum += strt;
				starts[posn[i]] = strt;
				moves += strt;
			}
		}

		if(moves <= m){curr = mid;mnm = mid + 1;}
		else mxm = mid - 1;
	}
	cout << curr << endl;
}