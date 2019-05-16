// 933A - A Twisty Movement CF# 462 - 1
// 1* 2* 1* 2* is the form of the solution we require--> which is = to (1* 2*) (1* 2*) which is max(i,j)((ending at i) + (strting at j)) 
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> arr(n);for(int i=0;i<n;i++)cin >> arr[i];
	vector<ll> dp_end(n), dp_strt(n);
	dp_end[0] = 1;
	for(int i=1;i<n;i++){
		dp_end[i] = 1;
		for(int j = 0;j < i;j++){
			if(arr[j] <= arr[i])dp_end[i] = max(dp_end[i], dp_end[j] + 1);
		}
	}
	dp_strt[n - 1] = 1;
	for(int i=n-2;i>=0;i--){
		dp_strt[i] = 1;
		for(int j = i + 1;j < n;j++){
			if(arr[j] >= arr[i])dp_strt[i] = max(dp_strt[i], dp_strt[j] + 1);
		}
	}
	ll answer = 1;
	for(int i=0;i<n;i++){
		for(int j = i + 1;j<n;j++){
			answer = max(answer, dp_end[i] + dp_strt[j]);
		}
	}
	cout << answer << endl;


}