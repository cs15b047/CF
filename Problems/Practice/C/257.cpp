#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int q = 0; q < t ;q ++){
		ll n, l; cin >> n >> l;
		vector<double> arr(n + 2, 0.0); arr[0] = 0.0; arr[n + 1] = (double)l;
		for(int i = 1;i <= n;i++)cin >> arr[i];

		vector<double> time1(n + 2), time2(n + 2), diff12(n + 2);

		time1[0] = 0.0; time2[n + 1] = 0.0;
		for(int i = 1;i <= n + 1;i++){
			time1[i] = time1[i - 1] + (arr[i] - arr[i - 1])/(double)i;
		}

		for(int i = n;i >= 0;i--){
			time2[i] = time2[i + 1] + (arr[i + 1] - arr[i])/(double)(n + 1 - i);
		}

		for(int i = 0;i <= n + 1;i++) diff12[i] = time1[i] - time2[i];

		ll idx = lower_bound(diff12.begin(), diff12.end(), 0.0) - diff12.begin();

		double dist_subtract = 0.0;
		double ans_time  = 0.0;
		if(time1[idx - 1] < time2[idx]){
			dist_subtract = (time2[idx] - time1[idx - 1]) * idx;
			ans_time = time2[idx] + (arr[idx] - arr[idx - 1] - dist_subtract)/(double)(n + 2);
		} else {
			dist_subtract = (time1[idx - 1] - time2[idx]) * (n + 1 - idx + 1);
			ans_time = time1[idx - 1] + (arr[idx] - arr[idx - 1] - dist_subtract)/(double)(n + 2);
		}

		printf("%.20lf\n", ans_time);
	}
}