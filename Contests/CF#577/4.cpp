#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll> b;


ll get_nearest(ll loc){
	ll idx = lower_bound(b.begin(), b.end(), loc) - b.begin();
	if(idx != b.size() && b[idx] == loc)return loc;
	if(idx == b.size()){
		return b[idx - 1];
	} else if(idx == 0)return b[idx];
	else {
		if(llabs(b[idx] - loc) < llabs(b[idx - 1] - loc)){
			return b[idx];
		} else return b[idx - 1];
	}
}


int main(){
	ll n, m, k, q; cin >> n >> m >> k >> q;
	vector<ll> x(k), y(k);for(int i=0;i<k;i++)cin >> x[i] >> y[i];
	b.resize(q);for(int i=0;i<q;i++)cin >> b[i];

	// convert to pts for every row
	map<ll, vector<ll>> pts;for(int i=0;i<k;i++)pts[x[i]].push_back(y[i]);
	for(auto &it:pts)sort(it.second.begin(), it.second.end());

	// dp[row, pos]
	vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
	ll last_to_go = 0;
	for(int i = n; i >= 1;i--){
		if(pts.find(i) != pts.end()){
			last_to_go = i;
			break;
		}
	}
	ll ans;
	if(last_to_go == 0){
		ans = 0;
	} else{
		ll prev_loc1=b[0], prev_loc2=b[0], loc1, loc2;
		if(pts.find(1) == pts.end()){
			dp[1][0] = 0;dp[1][1] = 0;
			loc1 = prev_loc1;loc2=prev_loc2;
		} else{
			ll first = pts[1][0], last = pts[1].back() ;
			loc1 = get_nearest(first);
			loc2 = get_nearest(last);
			dp[1][0] = (last - 1) + llabs(last - loc2);
			dp[1][1] = (last - 1) + (last - first) + llabs(first - loc1);
			prev_loc1 = loc1;
			prev_loc2 = loc2;
		}
		// cout << dp[1][0] << " " << dp[1][1] << endl;

		for(int i = 2;i <= last_to_go;i++){
			ll dist1, dist2, dist3, dist4;
			if(pts.find(i) == pts.end()){
				dp[i][0] = dp[i - 1][0] + 1;dp[i][1] = dp[i - 1][1] + 1;
				loc1 = prev_loc1;loc2=prev_loc2;
				prev_loc1 = loc1;prev_loc2 = loc2;
			}
			else{
				ll first = pts[i][0], last = pts[i].back() ;
				loc1 = get_nearest(first);
				loc2 = get_nearest(last);
				// cout << loc1 << " " << loc2 << endl;

				dist1 = 1 + llabs(prev_loc1 - last) + llabs(last - first) + llabs(first - loc1);
				dist2 = 1 + llabs(prev_loc1 - first) + llabs(last - first) + llabs(last - loc2);
				dist3 = 1 + llabs(prev_loc2 - last) + llabs(last - first) + llabs(first - loc1);
				dist4 = 1 + llabs(prev_loc2 - first) + llabs(last - first) + llabs(last - loc2);
				// cout << dist1 << " "  << dist2 << " " << dist3 << " " << dist4 << endl;
				dp[i][0] = dp[i - 1][0] + min(dist1, dist3);
				dp[i][1] = dp[i - 1][1] + min(dist2, dist4);
				prev_loc1 = loc1, prev_loc2 = loc2;
				if(i == last_to_go){
					dp[i][0] = dp[i][0] - llabs(loc1 - first);
					dp[i][1] = dp[i][1] - llabs(loc2 - last);
				}
			}
			// cout << dp[i][0] << " " << dp[i][1] << endl;
		}
		ans = min(dp[last_to_go][0], dp[last_to_go][1]);
	}
	
	cout << ans << endl;
}