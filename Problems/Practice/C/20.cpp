#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	int n;cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;i++)cin>>a[i]; 

	if(n <= 2){
		cout << n << endl;
	}
	else{
		vector<ll>inc_start(n),inc_end(n);
		inc_end[0] = 1;
		for(int i=1;i<n;i++){
			if(a[i] > a[i-1]){
				inc_end[i] = inc_end[i-1] + 1;
			}
			else{
				inc_end[i] = 1;
			}
		}
		inc_start[n-1] = 1;
		for(int i = n-2;i>=0;i--){
			if(a[i] < a[i+1]){
				inc_start[i] = inc_start[i+1] +1;
			}
			else{
				inc_start[i] = 1;
			}
		}

		ll ans = 0, index = 0 ;

		while(index < n){
			if(index == 0){
				ans = max(ans, 1 + inc_start[1]) ;
			}
			else if(index == n-1){
				ans = max(ans, 1 + inc_end[n-2]) ;
			}
			else{
				if(a[index + 1] - a[index - 1] >= 2){
					ans = max(ans, inc_end[index - 1] + 1 + inc_start[index + 1]) ;
				}
				else{
					ans = max(ans, max(inc_end[index - 1],inc_start[index + 1]) + 1) ;
				}
			}
			index++ ;
		}
		cout << ans <<endl ;
	}




	return 0;
}