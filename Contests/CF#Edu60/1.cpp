#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n; scanf("%lld",&n);
	vector<ll> a(n);
	ll mxm = 0;
	for(ll i=0;i<n;i++){
		scanf("%lld",&a[i]);
		mxm = max(mxm, a[i]);
	}

	ll start = 0, curr = 0, answer = 1;
	while(start < n){
		while(start < n && a[start] != mxm)start++;
		if(start == n)break;
		curr = start;
		while(curr < n && a[curr] == mxm)curr++;
		answer = max(curr - start, answer);
		start = curr; 
	}

	cout << answer << endl;
}