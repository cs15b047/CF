#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int m,n;
    cin >>n>>m ;
    vector<int> l,r ;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y ;
        l.push_back(x);r.push_back(y);
    }
    vector<int> pres ;pres.resize(m+1);
    for(int i=0;i<n;i++)
    {
        for(int j=l[i];j<=r[i];j++)pres[j] = 1 ;        
    }
    vector<int> ans ;
    int  k = 0;
    for(int i=1;i<=m;i++)
    {
        if(pres[i] == 0){
            k++;
            ans.push_back(i) ;
        }
    }
    cout << k <<endl ;
    for(int i=0;i<ans.size();i++)cout << ans[i]<<" ";


    return 0;
}
