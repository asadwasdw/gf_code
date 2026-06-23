#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<char,int>num;
char ans[10];
int n;
int res;
int t;
void dfs(int x)
{
    if(x==n+1)
    {
        res++;
        if(res==t)
        {
            for(int i=1;i<=n;i++)cout<<ans[i];
        }
    }

    for(char i='a';i<='z';i++)
    {
        if(!num[i])continue;
        
        num[i]--;
        ans[x]=i;
        dfs(x+1);
        num[i]++;
    }
}


int main()
{
    string s;
    cin>>s;
 
    cin>>t;
    n=s.size();
    for(auto a:s)
    {
        num[a]++;
    }

    dfs(1);

}
