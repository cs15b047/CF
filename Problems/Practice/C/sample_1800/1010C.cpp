#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a % b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k; cin >> n >> k;

	vector<ll> arr(n);for(int i = 0;i < n;i++)cin >> arr[i];
	bool all = false;
	ll g = arr[0] % k;
	for(int i = 0;i < n;i++){
		arr[i] = arr[i] % k;
		g = gcd(arr[i], g);
	}
	ll total_cnt= 0;
	vector<ll> d_values(k, 0);
	
	for(int i = 1;i <= k;i++){
		d_values[(g * i) % k] = 1;
	}

	for(int i = 0 ;i < k;i++){
		total_cnt += d_values[i];
	}
	
	cout << total_cnt << endl;
	for(int i = 0 ;i < k;i++){
		if(d_values[i])cout << i << " ";
	}
	cout << endl;




}