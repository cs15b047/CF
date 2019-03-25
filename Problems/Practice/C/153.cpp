#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m; cin >> n;
	vector<ll>a(n);for(int i=0;i<n;i++)cin >> a[i];
	cin >> m;
	vector<ll>b(m);for(int i=0;i<m;i++)cin >> b[i];
	sort(a.begin(),a.end());sort(b.begin(),b.end());

	set<ll> pool;for(int i=0;i<n;i++)pool.insert(a[i]);for(int i=0;i<m;i++)pool.insert(b[i]);
	pool.insert(0);pool.insert(1e18); // extreme cases
	ll ans = -1e18, a_score = -1,  b_score = -1;
	for(auto dist: pool){
		auto itr1 = upper_bound(a.begin(),a.end(), dist);
		auto itr2 = upper_bound(b.begin(),b.end(), dist);

		ll idx1, idx2;idx1 = itr1 - a.begin();idx2 = itr2 - b.begin();

		ll local_ans = 3*((n - idx1) - (m - idx2)) + 2*(idx1 - idx2) ;
		
		if(ans < local_ans){
			ans = local_ans;
			a_score = 3*(n - idx1) + 2*idx1;
			b_score = 3*(m - idx2) + 2*idx2;
		}
	}
	cout << a_score << ":" << b_score << endl;
}