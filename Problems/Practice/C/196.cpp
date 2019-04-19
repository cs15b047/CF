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