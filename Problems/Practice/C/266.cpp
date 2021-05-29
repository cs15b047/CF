#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tests;
ll n;
vector<pair<ll,ll>> segments;

vector<ll> sorted_starts, sorted_ends;

void init(){
	segments.clear();
	sorted_starts.clear();
	sorted_ends.clear();
}

void take_input(){
	scanf("%lld", &n);
	for(int i = 0; i < n; i++){
		ll start, end; scanf("%lld%lld", &start, &end);
		segments.push_back(make_pair(start, end));
		sorted_starts.push_back(start);
		sorted_ends.push_back(end);
	}
	sort(sorted_starts.begin(), sorted_starts.end());
	sort(sorted_ends.begin(), sorted_ends.end());
}

ll calc_ans(){
	ll ans = 1e9;
	for(auto seg: segments){
		ll end_earlier = lower_bound(sorted_ends.begin(), sorted_ends.end(), seg.first) - sorted_ends.begin();
		ll start_later = n - (upper_bound(sorted_starts.begin(), sorted_starts.end(), seg.second) - sorted_starts.begin());
		// cout << "Segment: " << seg.first << " " << seg.second << ": " << end_earlier << " " << start_later << endl;
		ans = min(ans, end_earlier + start_later);
	}
	return ans;
}

int main(){
	scanf("%lld", &tests);
	for(int q = 0;q < tests; q++){
		init();
		take_input();
		ll ans = calc_ans();
		printf("%lld\n", ans);
	}
}