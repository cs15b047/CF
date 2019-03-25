#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll y,b,r; cin >> y >> b >> r;
	ll ans =  min(min(y , b - 1), r - 2);
	cout << 3*(ans + 1) << endl;
}