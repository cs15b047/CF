#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	vector<ll>v(3);cin>>v[0]>>v[1]>>v[2];
	sort(v.begin(),v.end());
	cout << max(v[2]-(v[1]+v[0]) + 1, (ll)0) << endl ;
}