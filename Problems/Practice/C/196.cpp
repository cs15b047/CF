// 1151E - Number of Components  CF# 553 - 2
// Method: Contribution to Sum of adjacent pair : For each l <= a(i) <= r, if a(i - 1) is not in range, then increase 1 component
// If a(i - 1) < a(i) , l can be [a[i - 1] + 1, a[i]] & r is in [a[i], n] : value = (a[i] - a[i-1]) * (n - a[i] + 1)
// else a(i - 1) > a(i), l can be [1, a[i]] and r can be [a[i], a[i - 1] - 1] : vlaue = a[i] * (a[i] - a[i-1])
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> val(n + 1, 0);for(int i=1;i<=n;i++)cin >> val[i];
	ll answer =0 ;
	for(int i = 1;i <= n; i++){
		if(val[i] >= val[i - 1]){
			answer += (val[i] - val[i - 1]) * (n - val[i] + 1);
		}
		else{
			answer += val[i] * (val[i - 1] - val[i]);
		}
	}
	cout << answer << endl;
}