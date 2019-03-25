#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll w1,w2,h1,h2; cin >> w1 >> h1 >> w2 >> h2;
	ll ans = w1 + w2 + h1 + h2 + h1 + h2 + 4 + abs(w1 - w2) ;
	cout << ans << endl;
}