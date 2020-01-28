#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

pair<ll,ll> step(char x, pair<ll,ll> curr){
    if(x == 'U')curr = make_pair(curr.first, curr.second + 1);
    else if(x == 'D')curr = make_pair(curr.first, curr.second - 1);
    else if(x == 'L')curr = make_pair(curr.first - 1, curr.second);
    else if(x == 'R')curr = make_pair(curr.first + 1, curr.second);
    return curr;
}

int main(){
    ll a, b; cin >> a >> b;
    string str; cin >> str;

    vector<pair<ll,ll>> possible_positions(str.length());
    possible_positions[0] = make_pair(0,0);
    pair<ll,ll> curr = make_pair(0,0);
    ll n = str.length();
    for(int i = 1;i < n;i++){
        curr = step(str[i - 1], curr);
        possible_positions[i] = curr;
    }
    pair<ll,ll> one_round = step(str.back(), curr);
    // cout << one_round.first << " " << one_round.second << endl;
    bool global_poss = false;
    for(int i = 0; i < n ;i++){
        bool poss = false;
        pair<ll,ll> diff = make_pair(a - possible_positions[i].first, b - possible_positions[i].second);
        // cout << diff.first << " " << diff.second << endl;
        pair<ll,ll> zero = make_pair(0,0);
        if( diff == zero ){
            poss = true;
        } else {
            if((one_round.first == 0 && diff.first != 0) || (one_round.second == 0 && diff.second != 0)){
                poss = false;
            } else{
                if((one_round.first != 0) && (one_round.second != 0)){
                    if(((diff.first / one_round.first) == (diff.second / one_round.second) && (diff.second / one_round.second) >= 0) && (diff.first % one_round.first == 0) && (diff.second % one_round.second == 0))poss = true;
                    else poss = false;
                }
                else if((one_round.first == 0) && (one_round.second != 0)){
                    if((diff.first == 0) && (diff.second % one_round.second == 0) && (diff.second * one_round.second >= 0) )poss = true;
                    else poss = false;
                }
                else if((one_round.first != 0) && (one_round.second == 0)){
                    if((diff.second == 0) && (diff.first % one_round.first == 0) && (diff.first * one_round.first >= 0) )poss = true;
                    else poss = false;
                }
                else{
                    if((diff.first == 0) && (diff.second == 0))poss = true;
                    else poss = false;
                }
            }
        }
        if(poss){global_poss = true;break;}
    }
    if(global_poss)cout << "Yes" << endl;
    else cout << "No" << endl;
}