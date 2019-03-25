#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n ;cin >> n ;
	vector<int>a(n+1);
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}

	int answer = 1e9;
	for(int x = 1;x <= n;x++){
		int tmp_ans = 0;
		for(int i=1;i<=n;i++){
			tmp_ans += 2*a[i] *(abs(x-i) + abs(i-1) + abs(1-x)) ;
		}
		answer = min(answer, tmp_ans);
	}
	cout << answer << endl;
}