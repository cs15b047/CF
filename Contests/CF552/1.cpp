#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,m; cin >>n >> m;
	ll even_a=0,odd_a=0,even_b=0,odd_b=0;
	vector<ll> a(n), b(m);for(int i=0;i<n;i++){cin >> a[i];if(a[i] % 2 == 0)even_a++;else odd_a++;}
	for(int i=0;i<m;i++){cin >> b[i];if(b[i] % 2 == 0)even_b++;else odd_b++;}
	ll answer = min(even_a, odd_b) + min(even_b, odd_a) ;
	cout << answer << endl;
}