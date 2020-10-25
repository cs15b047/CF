#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll get_dist(pair<ll,ll> pt1, pair<ll,ll> pt2){
	return llabs(pt1.first - pt2.first) + llabs(pt1.second - pt2.second);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll x0, y0, ax, ay, bx, by, xs, ys, t; cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;

	vector<pair<ll,ll>> points;
	ll currx = x0, curry = y0;
	pair<ll,ll> strt=  make_pair(xs, ys);

	// ll prev_currx = 0, prev_curry = 0;
	
	// while corrds in range and not overflowing
	while(((llabs((ll)currx - xs) + llabs((ll)curry - ys) <= t) || (currx <= xs || curry <= ys)) && (currx <= 1e18 && curry <= 1e18 && currx >= 0 && curry >= 0)){ // refine
		points.push_back(make_pair(currx, curry));
		currx = currx * ax + bx;
		curry = curry * ay + by;
	}
	ll len = points.size();
	// cout << len << endl;
	// for(auto it:points)cout << it.first << " " << it.second << endl;

	ll answer = 0;
	for(ll left = 0;left < len;left++){
		for(ll right = left;right < len;right++){
			ll dist_bw = get_dist(points[left], points[right]);
			ll dist_to1 = get_dist(points[left], strt), dist_to2 = get_dist(points[right], strt);
			if(dist_bw + min(dist_to1, dist_to2) <= t){
				// cout << left << " " << right << endl;
				answer = max(answer, right - left + 1);
				// cout << answer << endl;
			}
		}
	}

	cout << answer << endl;


}