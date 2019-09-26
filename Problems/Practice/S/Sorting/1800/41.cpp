#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n, x, y; cin >> n >> x >> y;
	vector<ll>a(n);for(int i=0;i<n;i++)cin >> a[i];

	vector<ll> merged(x + y, 0);
	ll p1 = 1, p2 = 1;
	for(int i = 0;i < x + y;){
		double n1 = (double)p1/(double)x, n2=(double)p2/(double)y;
		if(p1*y == p2*x){
			p1++;p2++;
			merged[i] = 3;merged[i + 1] = 3;
			i+=2;
		} else if(n1 < n2){
			merged[i] = 1;
			p1++;
			i++;
		} else if(n1 > n2){
			merged[i] = 2;
			p2++;
			i++;
		}
	}
	for(int i = 0;i < n;i++){
		ll num = a[i] % (x + y);
		if(num == 0)cout << "Both" << endl;
		else{
			if(merged[num - 1] == 3)cout << "Both" << endl;
			else if(merged[num - 1] == 1)cout << "Vanya" << endl;
			else if(merged[num - 1] == 2)cout << "Vova" << endl;
		}
	}
}