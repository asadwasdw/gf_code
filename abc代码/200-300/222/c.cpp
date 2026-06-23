#include<iostream>
#include<algorithm>

using namespace std;

const int N=110;

string s[N];
typedef pair<int,int>PII;

PII st[N];
int ans[N];

bool pd(char a,char b){
    if(a=='G'){
        if(b=='C')return true;
        return false;
    }

        if(a=='C'){
        if(b=='P')return true;
        return false;
    }
        if(a=='P'){
        if(b=='G')return true;
        return false;
    }
    return true;

}


bool cmp(PII a,PII b)
{
    if(a.first!=b.first)return a.first>b.first;
    else return a.second<b.second;
}



int main()
{
    int n;cin>>n;
    int m;cin>>m;

    for(int i=1;i<=2*n;i++)
    {
        cin>>s[i];
        s[i]=" "+s[i];
        st[i]={0,i};
    }

    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int b=2*i;
            int a=2*i-1;
            if(s[st[a].second][j]!=s[st[b].second][j]){
                if(pd(s[st[a].second][j],s[st[b].second][j])){
                    st[a].first++;
                }
                else {
                    st[b].first++;
                }
            }
            else {
            }
        }
        sort(st+1,st+2*n+1,cmp);

   // for(int i=1;i<=n*2;i++)
    //cout<<st[i].second<<endl;
             // cout<<"("<<st[i].first<<" "<<st[i].second<<") ";
            //  cout<<endl;


       
    }

 for(int i=1;i<=n*2;i++)
    cout<<st[i].second<<endl;


}