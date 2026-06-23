#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>a;
int n,m;

int maxjl(int x,int y){
    int t=x+y-2;
    t=max(abs(n-x)+y-1,t);
    t=max(x-1+abs(m-y),t);
    t=max(t,abs(n-x)+abs(m-y));
    return t;
}


void solve()
{
     cin>>n>>m;
     a.clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            a.push_back(maxjl(i,j));
        }
    }

    sort(a.begin(),a.end());

    for(auto t:a){
        cout<<t<<" ";
    }
    cout<<endl;
}



int main()
{
    int t;cin>>t;while(t--)
    solve();

    
   



}