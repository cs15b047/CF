#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,q;scanf("%lld%lld",&n,&q);
	char s[100002];scanf("%s",s);string str(s);
	vector<string> strings(3 ,"");

	map<char, set<ll>> char_locns;char_locns.clear();
	for(int i=0;i < str.length();i++)char_locns[str[i]].insert(i);
	vector<vector<ll>> perms(6, vector<ll>(3, 0));
	perms[0] = {1,2,3};perms[1] = {1,3,2};perms[2] = {2,1,3};perms[3] = {2,3,1};perms[4] = {3,1,2};perms[5] = {3,2,1};

	for(int i=0;i<q;i++){
		// cout << "I : " << i << endl;
		char op[2];scanf("%s",op);ll id;scanf("%lld",&id);
		char app[2];
		if(op[0] == '+'){
			scanf("%s",app);
			strings[id-1] += app;
		}
		else strings[id - 1].pop_back();
		// gen perm of 3 numbers
		ll glob_flag = 0;
		for(auto it1: perms){
			ll p1 = it1[0],p2=it1[1],p3=it1[2];p1--;p2--;p3--;
			int loc_flag = 1;
			map<char, set<ll>> temp1, temp2, temp3;
			// cout << "Perm:" << p1 << " " << p2 << " " << p3 << endl;
			// consume acc to perm
			for(int j = 0;!strings[p1].empty() && j < strings[p1].length();j++){
				char ch = strings[p1][j];
				// if not in orig map or ran out, break
				if((char_locns.find(ch) == char_locns.end()) || (char_locns[ch].empty())){
					loc_flag = 0;
					break;
				}
				else if(j > 0){
					char prev = strings[p1][j-1];
					auto it = temp1[prev].rbegin();
					ll prev_loc = *it;
					auto it2 = char_locns[ch].upper_bound(prev_loc);
					if(it2 == char_locns[ch].end()){
						loc_flag = 0;
						break;
					}
					else{
						temp1[ch].insert(*it2);
						char_locns[ch].erase(*it2);
					}
				}
				else{
					ll loc = *(char_locns[ch].begin());
					temp1[ch].insert(loc);
					char_locns[ch].erase(loc);
				}
			}
			for(int j = 0; !strings[p2].empty() && j < strings[p2].length();j++){
				char ch = strings[p2][j];
				// if not in orig map or ran out, break
				if((char_locns.find(ch) == char_locns.end()) || (char_locns[ch].empty())){
					loc_flag = 0;
					break;
				}
				else if(j > 0){
					char prev = strings[p2][j-1];
					auto it = temp2[prev].rbegin();
					ll prev_loc = *it;
					auto it2 = char_locns[ch].upper_bound(prev_loc);
					if(it2 == char_locns[ch].end()){
						loc_flag = 0;
						break;
					}
					else{
						temp2[ch].insert(*it2);
						char_locns[ch].erase(*it2);
					}
				}
				else{
					ll loc = *(char_locns[ch].begin());
					temp2[ch].insert(loc);
					char_locns[ch].erase(loc);
				}
			}
			for(int j = 0; !strings[p3].empty() && j < strings[p3].length();j++){
				char ch = strings[p3][j];
				// if not in orig map or ran out, break
				if((char_locns.find(ch) == char_locns.end()) || (char_locns[ch].empty())){
					loc_flag = 0;
					break;
				}
				else if(j > 0){
					char prev = strings[p3][j-1];
					auto it = temp3[prev].rbegin();
					ll prev_loc = *it;
					auto it2 = char_locns[ch].upper_bound(prev_loc);
					if(it2 == char_locns[ch].end()){
						loc_flag = 0;
						break;
					}
					else{
						temp3[ch].insert(*it2);
						char_locns[ch].erase(*it2);
					}
				}
				else{
					ll loc = *(char_locns[ch].begin());
					temp3[ch].insert(loc);
					char_locns[ch].erase(loc);
				}
			}
			if(loc_flag == 1)glob_flag = 1;

			// restore
			for(auto it:temp1){
				// cout << it.first << endl;
				for(auto it2:it.second){char_locns[it.first].insert(it2);//cout << it2 << " ";
			}
				// cout << endl;
			}
			for(auto it:temp2){
				// cout << it.first << endl;
				for(auto it2:it.second){char_locns[it.first].insert(it2);//cout << it2 << " ";
			}
				// cout << endl;
			}
			for(auto it:temp3){
				// cout << it.first << endl;
				for(auto it2:it.second){char_locns[it.first].insert(it2);//cout << it2 << " ";
			}
				// cout << endl;
			}
		}
		if(glob_flag == 1)printf("YES\n");
		else printf("NO\n");
	}

}