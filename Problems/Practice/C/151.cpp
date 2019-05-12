// A. Mafia : CF #202 - 1
// 2 cases: case 1: NUmber of rounds, in which sum of rounds for all players reduces by 1 each ==> # ROunds in which someone can become supervisor
// If x rounds played--> x - round(i) can be played satisfying prev line
//case 2: uneven distribution of min rounds, and rounds = max of all has to b played
// ans = max( case1, case2)
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];
	ll ans = 0,sum=0;
	for (int i = 0; i < n; ++i){
		ans = max(ans, a[i]);
		sum +=a[i];
	}

	ll ans2 = (sum / (n - 1)) + ((sum % (n - 1)) != 0) ;
	ans = max(ans, ans2);
	cout << ans << endl;
}