#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	vector<ll> x(n);for(int i = 0;i < n;i++)cin >> x[i];
	sort(x.begin(), x.end());
	vector<vector<ll>> ans_max(n, vector<ll>(3, -1)), ans_min(n, vector<ll>(3, 1e9));

	for(int i = 0;i < 3;i++){
		ans_max[0][i] = 1;
		ans_min[0][i] = 1;
	}

	for(int i = 1;i < n;i++){
		for(int j = 0;j < 3;j++){
			for(int k = 0;k < 3;k++){
				if(x[i - 1] + (k - 1) <= x[i] + (j - 1)){
					ans_max[i][j] = max(ans_max[i][j], ans_max[i - 1][k] + ((x[i - 1] + (k - 1)) != (x[i] + (j - 1))));
					ans_min[i][j] = min(ans_min[i][j], ans_min[i - 1][k] + ((x[i - 1] + (k - 1)) != (x[i] + (j - 1))));
				}
			}
		}
	}

	ll mnm = 1e9, mxm = -1;
	for(int i = 0;i < 3;i++){
		mnm = min(mnm, ans_min[n - 1][i]);
		mxm = max(mxm, ans_max[n - 1][i]);
	}
	cout << mnm << " " << mxm << endl;
}