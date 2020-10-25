#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests;cin >> tests;
	for(int t = 0;t < tests;t++){
		string str; cin >> str;
		vector<ll> cnts(26, 0);
		vector<ll> letters;
		for(auto ch: str)cnts[ch - 'a']++;
		for(int i = 0;i < 26;i++){
			if(cnts[i] != 0)
				letters.push_back(i);
		}
		string solution1 = "", solution2 = "", half1 = "", half2 = "";
		for(int i = 0;i < letters.size();i++){
			for(int j = 0;j < cnts[letters[i]];j++){
				if(i % 2 == 0){
					half2 += ('a' + letters[i]);
				} else{
					half1 += ('a' + letters[i]);
				}
			}
		}
		// cout << half1 << " " << half2 << endl;
		solution1 = half1 + half2;
		solution2 = half2 + half1;
		ll len = str.length();
		bool poss1 = true, poss2 = true;
		for(int i = 0;i < len - 1;i++){
			if((solution1[i] == solution1[i + 1] + 1 || solution1[i] == solution1[i + 1] - 1)){
				poss1 = false;
				break;
			}
		}
		for(int i = 0;i < len - 1;i++){
			if((solution2[i] == solution2[i + 1] + 1 || solution2[i] == solution2[i + 1] - 1)){
				poss2 = false;
				break;
			}
		}
		if(!poss1 && !poss2){
			cout << "No answer" << endl;
		} else{
			if(poss1)cout << solution1 << endl;
			else if(poss2) cout << solution2 << endl;
		}
	}

}