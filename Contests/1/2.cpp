#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n ;
    string s,t ;
    cin >> n >> s >> t ;

    vector<int> cnt1,cnt2 ;cnt1.resize(26);cnt2.resize(26);
    for(int i=0;i<26;i++)
    {
        cnt1[i]=0;cnt2[i] = 0;
    }
    for(int i=0;i<t.length();i++)
    {
        cnt1[t[i]-'a']++;
        cnt2[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(cnt1[i] !=cnt2[i]){
            cout << "-1" ;
            exit(0) ;
        }
    }
    
    int i =0;
    while(s[i] == t[i])i++;
    
    if(i == n)cout<<"0" ;

    vector<pair<int,int>> moves ;
    for(;i<n;i++)
    {
        int st = s.length()-1 ;
        if(s[i] == t[i])continue ;
        // cout << i <<" "; 
        while(s[st] != t[i])st --;
        // cout << st<<" " ;
        moves.push_back(make_pair(i,st));        
        s.erase(s.begin()+st);
        s.insert(s.begin()+i,t[i]) ;
        // cout << s <<endl;
    }
    int ans = 0 ;
    for(int  i=0;i< moves.size();i++)
        ans+=moves[i].second - moves[i].first ;
    cout << ans << endl ;
    for(int i=0;i<moves.size();i++)
    {
        for(int j=moves[i].second-1;j>=moves[i].first;j--)
            cout << j+1 <<" " ;
    }


    return 0;
}
