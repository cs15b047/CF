#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n ;cin>>n;
	string str; cin >> str;
	ll ans = 1e18;
	for(int i=0;i <= n - 4;i++){
		int tmp = 0;
		int chr1 = str[i] - 'A',chr2 = str[i+1] - 'A',chr3 = str[i+2] - 'A',chr4 = str[i + 3] - 'A';
		// cout << chr1 << " " << chr2 <<  " " <<  chr3 << " " <<chr4 << endl;
		tmp = min(chr1 - 0, 26-chr1) + min(abs(chr2 - 2), 26-abs(chr2 - 2)) + min(abs(chr3 - 19), 26-abs(chr3 - 19)) + min(abs(chr4 - 6), 26-abs(chr4 - 6)) ;
		// cout << tmp << endl;
		ans = min((ll)tmp, ans);
	}
	cout << ans << endl;
}