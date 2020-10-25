//Q: How to find longest palindrome in a string which is either a prefix/suffix of the string?
//Ans: longest_prefix_as_suffix(string + $ + str_reverse) or longest_prefix_as_suffix(str_reverse + $ + string)

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string lps(string &str){
	ll len = str.length();
	vector<ll> lps_arr(len, 0);
	for(int i = 1; i < len; i++){
		if(str[i] == str[lps_arr[i - 1]]){
			lps_arr[i] = lps_arr[i - 1] + 1;
		} else {
			ll loc = lps_arr[i - 1];
			while(loc != 0 && str[i] != str[loc]){
				loc = lps_arr[loc - 1];
			}
			if(loc == 0 && str[i] == str[0]){
				lps_arr[i] = 1;
			} else if(loc == 0 && str[i] != str[0]){
				lps_arr[i] = 0;
			} else {
				lps_arr[i] = loc + 1;
			}
		}
	}
	if(lps_arr.back() == 0)return "";
	return str.substr(0, lps_arr[len - 1]);


}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0;t < tests;t++){
		string str; cin >> str;
		string str_rev = str;
		reverse(str_rev.begin(), str_rev.end());

		ll pal_len = 0;
		for(int i = 0;i < str.length()/2;i++){
			if(str[i] == str_rev[i])pal_len++;
			else break;
		}
		if(2 * pal_len == str.length()){
			cout << str << endl;
		} else{
			ll reqd_len = (ll)str.length() - 2* pal_len;
			string reqd = str.substr(pal_len, reqd_len), reqd_rev = reqd;reverse(reqd_rev.begin(), reqd_rev.end());
			string combined1 = (reqd + "$") + reqd_rev, combined2 = (reqd_rev + "$") + reqd;

			string ans1 = lps(combined1), ans2 = lps(combined2);
			string answer, strt = "", end = "";
			if(pal_len > 0){
				strt = str.substr(0, pal_len);
				end = str_rev.substr(0, pal_len);
				reverse(end.begin(), end.end());
			}
			if(ans1.length() < ans2.length()){
				answer = (strt + ans2) + end;
			} else answer = (strt + ans1) + end;
			cout << answer << endl;
		}
	}
}