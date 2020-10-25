#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	string str1, str2; cin >> str1 >> str2;
	if(str1.length() == str2.length()){
		cout << 0 << endl;
	} else{
		map<char, vector<ll>> letter_posns;
		for(int i = 0;i < str1.length();i++){
			letter_posns[str1[i]].push_back(i);
		}
		ll len1 = str1.length(), len2 = str2.length();
		vector<ll> shortest_from_first(str2.length()), shortest_from_last(str2.length());

		ll pos1 = -1, pos2 = len1;
		for(int i = 0;i < str2.length();i++){
			char letter1 = str2[i], letter2 = str2[len2 - 1 - i];
			
			auto it = upper_bound(letter_posns[letter1].begin(), letter_posns[letter1].end(), pos1);
			shortest_from_first[i] = *it;
			pos1 = *it;

			auto it2 = lower_bound(letter_posns[letter2].begin(), letter_posns[letter2].end(), pos2);
			it2--;
			shortest_from_last[len2 - 1 - i] = *it2;
			pos2 = *it2;
			// cout << pos1 << " "  << pos2 << endl;
		}


		ll answer = 0;
		for(int i = 0;i < len2 - 1;i++){
			answer = max(answer, shortest_from_last[i + 1] - shortest_from_first[i] - 1);
		}
		answer = max(answer, len1 - 1 - shortest_from_first.back());
		answer = max(answer, shortest_from_last[0]);
		cout << answer << endl;
	}
}