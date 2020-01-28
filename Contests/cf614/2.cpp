#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n;
	double answer = 0;
	for(ll i = 1;i <= n; i++){
		answer += (double)1/(double)i;
	}
	printf("%.12lf\n",answer );
}