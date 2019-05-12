// A. Nephren gives a riddle  CF# 449 - 1
// Do recursion and take the branch depending on offset
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll> lengths;
ll max_l;
string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?", p1 = "What are you doing while sending \"", p2 = "\"? Are you busy? Will you send \"", p3 = "\"?";
char calc_ans(ll n, ll k){
	if(n == 0){
		if(k <= s0.length())return s0[k - 1];
		else return '.';
	}
	if(k <= p1.length())return p1[k - 1];
	else if((k > p1.length()) && ((n - 1 > max_l) || (k <= p1.length() + lengths[n - 1]) ))return calc_ans(n - 1, k - p1.length());
	else if(k > p1.length() + lengths[n - 1] && k <= p1.length() + lengths[n - 1] + p2.length())return p2[k - (p1.length() + lengths[n - 1] + 1)] ;
	else if(k > p1.length() + lengths[n - 1] + p2.length() && k <= p1.length() + 2*lengths[n - 1] + p2.length())return calc_ans(n - 1, k - (p1.length() + lengths[n - 1] + p2.length()));
	else if(k > p1.length() + p2.length() + 2 * lengths[n - 1] && k <= lengths[n])return p3[k - (p1.length() + p2.length() + 2 * lengths[n - 1] + 1)];
	else return '.';
}

int main(){
	ll q; cin >> q;
	lengths.resize(100);
	lengths[0] = s0.length();
	
	ll i=0;
	while(lengths[i] <= 2e18){
		// if(lengths[i] <= 500)cout << lengths[i] << endl;
		lengths[i + 1] = p1.length() + p2.length() + p3.length() + 2* lengths[i] ;
		i++;
	}
	max_l = i;
	string answer = "";
	for(int j=0;j<q;j++){
		ll n,k; cin >> n >> k;
		char ans = calc_ans(n, k);
		answer += ans;
	}
	cout << answer << endl;
}