#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tests;
ll num_points, seg_length;
vector<ll> x_coords, y_coords;

vector<vector<ll>> dp;

void init(){
	x_coords.clear();
	y_coords.clear();
	dp.clear();
}

void take_input(){
	scanf("%lld%lld",&num_points, &seg_length);
	x_coords.resize(num_points);
	y_coords.resize(num_points);
	dp.resize(num_points, vector<ll>(3, 0));
	for(int i = 0;i < num_points;i++) scanf("%lld",&x_coords[i]);
	for(int i = 0;i < num_points;i++) scanf("%lld",&y_coords[i]);
}

void calc_ans(){
	dp[0][1] = 1;
	dp[0][2] = 1;
	for(ll segs = 1; segs <= 2; segs++){
		for(ll n = 1; n < num_points;n++){
			dp[n][segs] = dp[n - 1][segs];
			ll seg_end = x_coords[n], seg_start = seg_end - seg_length;
			
			ll idx = lower_bound(x_coords.begin(), x_coords.end(), seg_start) - x_coords.begin();
			
			if(idx == 0)dp[n][segs] = max(n + 1, dp[n][segs]);
			else dp[n][segs] = max(dp[idx - 1][segs - 1] + (n - idx + 1), dp[n][segs]);
		}
	}
	// cout << "DP Matrix: " << endl;
	// for(int i = 0;i <=2;i++){
	// 	for(int j = 0;j < num_points;j++) cout << dp[j][i] << " ";
	// 	cout << endl;
	// }
}


int main(){
	scanf("%lld",&tests);
	for(int t =0;t < tests;t++){
		init();
		take_input();
		// relation of x with y breaks
		sort(x_coords.begin(), x_coords.end());
		calc_ans();
		printf("%lld\n", dp[num_points - 1][2]);

	}

	return 0;
}