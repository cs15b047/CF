#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll>a(n);for(int i=0;i<n;i++)cin >> a[i];
	ll sum=0, mxm=a[0];for(int i=0;i<n;i++){sum += a[i];mxm = max(mxm, a[i]);}
	if((sum % 2 != 0) || (mxm > (sum / 2)))cout << "NO" << endl;
	else cout << "YES" << endl;
}