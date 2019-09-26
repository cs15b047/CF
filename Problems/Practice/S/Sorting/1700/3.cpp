#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool cmp(string str1, string str2){
    return str1.length() < str2.length();
}
int main(){
    ll n; cin >> n;
    vector<string> answers(n);
    vector<bool> done(n, false);
    vector<string> numbers(n);for(int i=0;i<n;i++){char s[10]; scanf("%s",s); string st(s); numbers[i] = st;}
    map<string, ll> mapping, cnt;
    set<string> unique_str;
    for(int i=0;i<n;i++){
        for(int j = 0;j < 9;j++){
            string str = numbers[i].substr(j, 1);
            for(int len = 1;len <= 9 - j; len++){
                mapping[str] = i;
                unique_str.insert(str);
                if(len < 9 - j)str += numbers[i][j + len];
            }
        }
        for (auto it: unique_str){
            cnt[it]++;
        }
        unique_str.clear();
    }
    
    vector<string> vec;
    for(auto it: cnt){
        if(it.second == 1) {
            vec.push_back(it.first);
        }
    }
    cnt.clear();
    sort(vec.begin(), vec.end(), cmp);
    for(auto it: vec){
        if(!done[mapping[it]]){
            done[mapping[it]] = true;
            answers[mapping[it]] = it;
        }
    }
    for(auto it: answers){
        printf("%s\n",it.c_str());
    }
}