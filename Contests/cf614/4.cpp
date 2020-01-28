#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dist(pair<ll,ll> pt1, pair<ll,ll> pt2){
	double answer = fabs(pt1.first - pt2.first) + fabs(pt1.second - pt2.second);
	if(answer >= (double)(1e18))return -1;
	else return (ll)answer;
}

int main(){
	ll x0, y0, ax, bx, ay, by, xs, ys, t; cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;

	vector<pair<ll,ll>> points;
	pair<ll,ll> curr = make_pair(x0, y0);
	pair<ll,ll> strt = make_pair(xs, ys);
	vector<pair<ll,ll>> pt_list;
	for(int i = 0;i < 100;i++){
		if(i > 0)curr = make_pair(curr.first * ax + bx, curr.second* ay + by);
		if(dist(curr, strt) >= 0 && dist(curr, strt) <= t){
			pt_list.push_back(curr);
		} else if(curr.first >= 1e17 || curr.second >= 1e17 || curr.first <= 0 || curr.second <= 0){
			break;
		} else if(dist(curr, strt) < 0){
			break;
		}
		// cout << curr.first << " " << curr.second << endl;
	}
	// for(auto it:pt_list)cout << it.first << " " << it.second << endl;
	ll sz = pt_list.size();
	// cout << sz << endl;
	ll answer = 0;
	for(int i = 0;i < sz;i++){
		for(int j = i;j < sz;j++){
			ll total_dist = min(dist(strt, pt_list[i]), dist(strt, pt_list[j])) + dist(pt_list[i], pt_list[j]);
			bool possible = (total_dist <= t);
			if(possible)answer = max(answer, (ll)(j - i + 1));
			// cout << i << " " << j << " " << total_dist <<endl;
		}
	}
	cout << answer << endl;
}