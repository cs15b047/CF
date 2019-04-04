#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,h,m;cin >> n >> m >> h;
	vector<ll> s(m + 1);for(int i=1;i<=m;i++)cin >> s[i];

	double answer = 0.0;
	double tot = 0.0;
	for(int i=1;i<=m;i++){
		if(i!=h)tot += (double)s[i];
	}

	if((ll)tot + s[h] < n)answer = -1;
	else if(s[h] == 1){
		answer = 0.0;
	}
	else{
		double sub = 1.0;

		if((ll)tot >= n - 1){
			for(int i=1;i<=n-1;i++){
				// cout << (tot - (double)(i - 1)) << " " << (double)(tot + (double)s[h] - (double)1.0 - (double)(i-1)) << endl;
				sub = sub * (tot - (double)(i - 1))/ (double)(tot + (double)s[h] - (double)1.0 - (double)(i-1));
			}
		}
		else sub = 0.0;

		answer = 1 - sub ;
	}
	cout << answer << endl;
}