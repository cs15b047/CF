#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; cin >> t;
	for(int i=0;i<t;i++){
		ll n;scanf("%lld",&n);
		vector<pair<ll,ll>> pts;
		pts.resize(n);for(int j=0;j<n;j++)scanf("%lld%lld",&pts[j].first, &pts[j].second);
		map<ll, ll> sum, diff;sum.clear();diff.clear();
		vector<ll> s_val, d_val;
		for(int j=0;j<n;j++){
			sum[pts[j].first + pts[j].second]++;
			diff[pts[j].first - pts[j].second]++;
			s_val.push_back(pts[j].first + pts[j].second);
			d_val.push_back(pts[j].first - pts[j].second);
		}
		sort(s_val.begin(), s_val.end());sort(d_val.begin(), d_val.end());
		double answer = 0.0;
		if(sum.size() <= n - 1 || diff.size() <= n - 1)answer = 0.0;
		else{
			double answer1 = 1e18, answer2 = 1e18 ;
			for(int j = 0; j < n - 1; j++){
				answer1 = fmin(answer1, (double)(s_val[j + 1] - s_val[j]));
				answer2 = fmin(answer2, (double)(d_val[j + 1] - d_val[j]));
			}
			answer = fmin(answer1, answer2) / 2.0;
		}
		printf("%.9lf\n", answer);
	}
}