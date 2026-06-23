#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

int main()
{
    ll n,p,h;
    cin>>n>>p>>h;
    p--;
    h--;
    vector<int>w;

    for(int i=n-1;i>=0;i--)
    {
        w.push_back(h>=(1ll<<i));
        if(w.back())h=(1ll<<(i+1))-h-1;
    }
    vector<char>ans;
    for(int i=n-1;i>=0;i--){
        //cout<<w[i]<<" "<<p<<endl;
        if(w[i]){

            if(p<(1ll<<i)){
                ans.push_back('L');
                p=(1ll<<i)-p-1;
            }
            else {
                ans.push_back('R');
                p=(1ll<<(i+1))-p-1;
            }
        }
        else{
             if(p<(1ll<<i)){
                ans.push_back('R');
             }
             else {
                p-=(1ll<<i);
                ans.push_back('L');
             }
        }
    }

    for(auto t:ans)cout<<t;

}