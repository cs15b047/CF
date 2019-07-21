#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n; scanf("%lld",&n);
    char s[1000001];
    vector<string> words(n);for(int i=0;i<n;i++){scanf("%s", s); string str(s);words[i] = str;}
    map<ll, map<char, vector<string>>> mymap;
    for(int i=0;i<n;i++){
        char lastVowel;
        ll cnt = 0;
        for(int j = 0;j < words[i].length();j++){
            if(words[i][j] == 'a' || words[i][j] == 'e' || words[i][j] == 'i' || words[i][j] == 'o' || words[i][j] == 'u') {
                lastVowel = words[i][j];
                cnt++;
            }
        }
        mymap[cnt][lastVowel].push_back(words[i]);
    }
    ll tot_ans = 0, x = 0, y = 0;
    for(auto it: mymap){
        ll tmp_x = 0, tmp_y = 0;
        for(auto it2: it.second){
            tmp_x += it2.second.size()/2 ; 
            tmp_y += it2.second.size() % 2;
        }
        x += tmp_x; y += tmp_y/2;
    }
    if(x <= y){
        tot_ans = x;
    } else {
        tot_ans = (x + y) / 2;
    }
    vector<string> ans_second_part;
    vector<string> ans_first_part;
    for(auto it: mymap){
        for(auto it2: it.second){
            ll sz = it2.second.size();
            for(int i=0;i<sz/2;i++){
                ans_second_part.push_back(it2.second[2*i]);
                ans_second_part.push_back(it2.second[2*i + 1]);
            }
            if(sz % 2 == 1){
                ans_first_part.push_back(it2.second.back());
            }
        }
        ll sz2 = ans_first_part.size();
        if(sz2 % 2 != 0)ans_first_part.pop_back();
    }
    printf("%lld\n", tot_ans);
    if(x <= y){
        for(int i=0;i<x;i++){
            // printf("%s %s\n%s %s\n", ans_first_part[2*i].c_str(), ans_second_part[2*i].c_str(), ans_first_part[2*i + 1].c_str(), ans_second_part[2*i + 1].c_str());
            cout << ans_first_part[2*i] << " " << ans_second_part[2*i] << endl;
            cout << ans_first_part[2*i + 1] << " " << ans_second_part[2*i + 1] << endl;
        }
    } else{
        for(int i=0;i<y;i++){
            // printf("%s %s\n%s %s\n", ans_first_part[2*i].c_str(), ans_second_part[2*i].c_str(), ans_first_part[2*i + 1].c_str(), ans_second_part[2*i + 1].c_str());
            cout << ans_first_part[2*i] << " " << ans_second_part[2*i] << endl;
            cout << ans_first_part[2*i + 1] << " " << ans_second_part[2*i + 1] << endl;
        }
        if(x - y >= 2){
            for(int i = y; i < x;i+=2){
                if(2*i + 3 < ans_second_part.size()){
                    cout << ans_second_part[2*i] << " " << ans_second_part[2*i + 2] << endl;
                    cout << ans_second_part[2*i + 1] << " " << ans_second_part[2*i + 3] << endl;
                    // printf("%s %s\n%s %s\n", ans_second_part[2*i].c_str(), ans_second_part[2*i + 2].c_str(), ans_second_part[2*i + 1].c_str(), ans_second_part[2*i + 3].c_str());
                }
                
            }
        }
    }
}