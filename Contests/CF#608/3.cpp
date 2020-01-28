#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n, sx, sy; scanf("%lld%lld%lld",&n, &sx,&sy);
	vector<ll> x(n),y(n);for(int i=0;i<n;i++)scanf("%lld%lld",&x[i],&y[i]);

	ll x_right= 0, x_left = 0, y_bot = 0, y_top = 0;
	pair<ll,ll> ans1 = make_pair(sx + 1, sy), ans2 = make_pair(sx - 1, sy), ans3 = make_pair(sx, sy - 1), ans4 = make_pair(sx, sy + 1);
	for(int i=0;i<n;i++){
		if(x[i] > sx)x_right++; else if(x[i] < sx) x_left++;
		if(y[i] > sy)y_top++; else if(y[i] < sy) y_bot++;
	}
	ll mxm = max(max(x_right, x_left), max(y_top, y_bot));
	pair<ll,ll> ans;
	if(mxm == x_right && sx + 1 <= 1e9)ans = ans1;
	else if(mxm == x_left && sx - 1 >= 0)ans = ans2;
	else if(mxm == y_bot && sy - 1 >= 0)ans = ans3;
	else if(mxm == y_top && sy + 1 <= 1e9)ans = ans4;

	cout << mxm << endl;
	cout << ans.first << " " << ans.second << endl;

}