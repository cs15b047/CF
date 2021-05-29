#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string ltrim(const string &);
string rtrim(const string &);

void count_substrings(vector<string> strings) {
	ll sz = strings.size();
	for(int t = 0;t < sz;t++){
		ll n = strings[t].length();
		string str = strings[t];
		vector<ll> a_cnts(n, 0), b_cnts(n , 0), c_cnts(n, 0);
		a_cnts[0] = (str[0] == 'a');
		b_cnts[0] = (str[0] == 'b');
		c_cnts[0] = (str[0] == 'c');

		for(int i = 1;i < n;i++){
			a_cnts[i] = a_cnts[i - 1] + (str[i] == 'a');
			b_cnts[i] = b_cnts[i - 1] + (str[i] == 'b');
			c_cnts[i] = c_cnts[i - 1] + (str[i] == 'c');
		}
		ll ans = 0;
		for(int i = 0;i < n - 2;i++){
			if(str[i] == 'a'){
				ll pos_b = lower_bound(b_cnts.begin(), b_cnts.end(), b_cnts[i] + 1) - b_cnts.begin();
				ll pos_c = lower_bound(c_cnts.begin(), c_cnts.end(), c_cnts[i] + 1) - c_cnts.begin();
				ll pos = max(pos_b, pos_c);
				if(pos == n){
					break;
				} else{
					ans += (n - pos);
				}
			} else if(str[i] == 'b'){
				ll pos_a = lower_bound(a_cnts.begin(), a_cnts.end(), a_cnts[i] + 1) - a_cnts.begin();
				ll pos_c = lower_bound(c_cnts.begin(), c_cnts.end(), c_cnts[i] + 1) - c_cnts.begin();
				ll pos = max(pos_a, pos_c);
				if(pos == n){
					break;
				} else{
					ans += (n - pos);
				}
			} else if(str[i] == 'c'){
				ll pos_b = lower_bound(b_cnts.begin(), b_cnts.end(), b_cnts[i] + 1) - b_cnts.begin();
				ll pos_a = lower_bound(a_cnts.begin(), a_cnts.end(), a_cnts[i] + 1) - a_cnts.begin();
				ll pos = max(pos_b, pos_a);
				if(pos == n){
					break;
				} else{
					ans += (n - pos);
				}
			}
		}
		cout << ans << endl;
		a_cnts.clear();b_cnts.clear();c_cnts.clear();
	}
}

int main()
{
    string strings_count_temp;
    getline(cin, strings_count_temp);

    int strings_count = stoi(ltrim(rtrim(strings_count_temp)));

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    count_substrings(strings);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}