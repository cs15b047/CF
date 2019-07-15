// B. Password  CF# 93 - 1
// Calculate LPS of whole string. Apply KMP on string using that lps, and check if matches are prefix & suffix both
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

char s[1000002];
int main(){
	scanf("%s",s);string str(s);
	ll n = str.length();
	vector<ll> lps(n, -1);
	lps[0] = 0;
	for(int i=1;i<n;i++){
		ll len = lps[i - 1];
		while(true){
			if(str[len] == str[i]){lps[i] = len + 1;break;}
			else{
				if(len == 0){lps[i] = 0;break;}
				len = lps[len - 1];
			}
		}
	}
	ll lps_whole = lps[n - 1];
	// for(int i=0;i<n;i++)cout << lps[i] << " ";cout << endl;
	ll start = 1, matched_len = 0, curr = start;
	vector<pair<ll,ll>> matches;
	while(start < n){
		if(matched_len == 0){
			while((start < n) && (str[start] != str[0]))start++;
			if(start >= n)break;
			else{
				matched_len = 1;
			}
		}
		else{
			ll len = matched_len;
			curr = start + matched_len;
			while(curr < n - 1 && str[curr] == str[len]){len++;curr++;}
			matches.push_back(make_pair(len, start));
			if(curr >= n - 1)break;
			matched_len = lps[curr];
			start = curr - lps[curr] + 1;
		}
	}

	if(!matches.empty() && matches.back().second == n - 1){
		matches.back().first--;
	}
	sort(matches.begin(), matches.end());
	reverse(matches.begin(), matches.end());
	if(!matches.empty()){
		// for(auto it: matches)cout << it.first <<" " << it.second << endl;
		ll length = lps[n - 1], ml = matches[0].first;
		while(ml < length)length = lps[length - 1];
		if(length == 0)cout << "Just a legend" << endl;
		else{
			string substr = str.substr(matches[0].second, length);
			cout << substr << endl;
		}
	}
	else{
		cout << "Just a legend" << endl;
	}
}