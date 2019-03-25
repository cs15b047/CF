#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	int n,m ;cin>>n>>m ;
	vector<ll> d(m),h(m);
	for(int i=0;i<m;i++)cin >> d[i] >> h[i] ;

	int flag = 1;
	ll ans = max(h[0] + d[0]-1, n - d[m-1] + h[m-1])  ;
	for(int i=0;i<m-1;i++){
		if(abs(h[i+1]-h[i]) > (d[i+1] - d[i])){
			flag = 0;
			break;
		}
		if(h[i+1] >= h[i]){
			ll left = (d[i+1] - d[i]) - (h[i+1] - h[i]);
			ans = max(ans, h[i+1] + left/2) ;
		}
		else{
			ll left = (d[i+1] - d[i]) - (h[i] - h[i+1]);
			ans = max(ans, h[i] + left/2) ;
		}
	}
	if(flag == 1){
		cout << ans <<endl ;
	}
	else{
		cout << "IMPOSSIBLE"<<endl ;
	}

}