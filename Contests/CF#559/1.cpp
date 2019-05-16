#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;string str; cin >> str;
	ll curr = 0, ans = 0;
	for(int i=0;i<n;i++){
		if(str[i] == '+')curr++;
		else curr--;
		ans = min(ans, curr);
	}
	cout << curr - ans << endl;
}