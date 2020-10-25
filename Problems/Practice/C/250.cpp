#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0;t < tests;t++){
		ll num_words; cin >> num_words;
		vector<string> words(num_words);
		for(int i = 0;i < num_words;i++)cin >> words[i];

		ll cnt_00 = 0, cnt_11 = 0, cnt_01 = 0, cnt_10 = 0;

		for(int i = 0;i < words.size();i++){
			if(words[i][0] == '0' && words[i].back() == '0')cnt_00++;
			else if(words[i][0] == '0' && words[i].back() == '1')cnt_01++;
			else if(words[i][0] == '1' && words[i].back() == '0')cnt_10++;
			else if(words[i][0] == '1' && words[i].back() == '1')cnt_11++;
		}

		bool possible = true;
		ll answer;
		if(cnt_00 != 0 && cnt_11 != 0 && cnt_01 == 0 && cnt_10 == 0){
			possible = false;
			answer = -1;
			cout << answer << endl;
		} else{
			ll diff = max(cnt_01, cnt_10) - min(cnt_01, cnt_10);
			answer = ceil((double)(diff - 1) / (double) 2);

			set<string> word_set(words.begin(), words.end());
			vector<ll> idxs;
			if(answer != 0){
				for(int i = 0;i < words.size();i++){
					string it = words[i];
					bool cond1 = (cnt_01 > cnt_10) && (it[0] == '0' && it.back() == '1');
					bool cond2 = (cnt_10 > cnt_01) && (it[0] == '1' && it.back() == '0');
					if(cond1 || cond2){
						auto it_set = word_set.find(it);
						if(it_set != word_set.end()){
							string str = it;
							reverse(str.begin(), str.end());
							if(word_set.find(str) == word_set.end() && idxs.size() < answer){
								idxs.push_back(i);
							}
						}
					}
				}
			}
			cout << answer << endl;
			for(auto it: idxs)cout << it + 1 << " ";cout << endl;
		}

	}

}