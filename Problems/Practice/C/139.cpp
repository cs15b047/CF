// D. Paths in a Complete Binary Tree --> #Edu 18
// calculate effect (on node number) of each step depending on nxt move and curr state. Keep curr path in stack
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll my_log2(ll x){
	ll ans = 0;
	while(x % 2 == 0){
		x = x / 2;
		ans++;
	}
	return ans ;
}

int main()
{
	ll n, q; cin >> n >> q;
	for(ll i = 1;i <= q; i++){
		ll start;string seq; cin >> start >> seq ;
		stack<char> pth;

		// get to start
		ll init = (n + 1)/ 2, ht = (ll)my_log2(init);
		while(init != start){
			if(start > init){
				init += (ll)pow(2, ht - 1);
				pth.push('R');
				ht--;
			}
			else if(start < init){
				init -= (ll)pow(2, ht - 1);
				pth.push('L');
				ht--;
			}
		}
		ll curr = start;
		for(ll j = 0; j < seq.length();j++){
			if(ht == 0 && seq[j] != 'U'){}
			else if(seq[j] == 'U' && pth.empty()){}
			else if(seq[j] == 'U'){
				curr = curr + ((pth.top()=='L') - (pth.top()=='R')) * (ll)pow(2, ht);
				ht++;
				pth.pop();
			}
			else if(seq[j] != 'U'){
				curr = curr + (-(seq[j] =='L') + (seq[j] == 'R')) * (ll)pow(2, ht - 1);
				ht--;
				pth.push(seq[j]);
			}
		}
		cout << curr << endl ;
	}

	return 0;
}