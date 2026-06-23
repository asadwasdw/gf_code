#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

struct per{
    int pi[20][20];
    bool st = false;
    int size = 0;
}q[N];

int x=1;
int t=1;
int ne=2;
int m;
deque<PII>d;

int bhcolor(char t)
{
    if(t=='R')return 1;
    if(t=='Y')return 2;
    if(t=='B')return 3;
    return 4;
}

int bhgn(char t)
{
    if(t=='+')return 10;
    if(t=='R')return 11;
    if(t=='S')return 12;
    return 4;
}

void printPII(PII a)
{
    cout<<a.first<<" "<<a.second<<"| ";
}

void mupai(int x)
{
    auto t = d.front();d.pop_front();

    q[x].pi[t.first][t.second]++;
    q[x].size++;
    
     //cout<<m-1<<"回合，"<<x<<"摸了";printPII(t);cout<<endl;

}

void jsne()
{
    ne=x+t;
    if(ne>4)ne-=4;
    if(ne<1)ne+=4;
}

void cp(int x,int i,int j)
{
    q[x].size--;
    q[x].pi[i][j]--;
    d.push_back({i,j});
    
    if(j==10){
        q[ne].st=false;

        mupai(ne);
        mupai(ne);
    }
    else if(j==11){
        t=-t;
        jsne();
    }
    else if(j==12)
    {
        q[ne].st=false;
    }

   /// cout<<m-1<<"回合，"<<x<<"出了"<<i<<" "<<j<<endl;
}

bool chupai(int x)
{
 
    auto t = d.back();
    
    for(int i=0;i<t.second;i++)
    {
        if(q[x].pi[t.first][i]==0)continue;
        cp(x,t.first,i);
        return true;
    }

    for(int i=1;i<=4;i++)
    {
        if(q[x].pi[i][t.second]==0)continue;
        cp(x,i,t.second);
        return true;
    }

    for(int i=t.second+1;i<=12;i++)
    {
        if(q[x].pi[t.first][i]==0)continue;
        cp(x,t.first,i);
        return true;
    }
    return false;
}

void solve()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=5;j++)
        {
            string s;
            cin>>s;

            PII t;
            t.first =bhcolor(s[0]);
            if(s[1]>='0'&&s[1]<='9')t.second=s[1]-'0';
            else t.second=bhgn(s[1]);

            q[i].pi[t.first][t.second]++;
            q[i].size++; 

        //    printPII(t);
        }
       // cout<<endl;
        q[i].st=true;
    }

    cin>>m;

    while(m--)
    {
        string s;
        cin>>s;

        PII t;
        t.first =bhcolor(s[0]);
        if(s[1]>='0'&&s[1]<='9')t.second=s[1]-'0';
        else t.second=bhgn(s[1]);

        d.push_back(t);

        //printPII(t);

    }
    m=1;
    while(m)
    {
       // cout<<m-1<<"回合，底牌是";printPII(d.back());cout<<endl;
        jsne();
        //cout<<"s"<<endl;
        if(q[x].st==false){
            q[x].st=true;
            x=ne;
            continue;
        }
        m++;

        if(!chupai(x))
        {
            mupai(x);
            chupai(x);
        }

        if(q[x].size==0){
            cout<<char('A'+x-1);
            return;
        }

        x=ne;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}