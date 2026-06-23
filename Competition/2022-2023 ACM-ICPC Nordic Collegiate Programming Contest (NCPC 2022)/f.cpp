#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n;
string s[510][510];
struct node
{
    vector<int>f;
    
}mrr[510][510];
vector<int>q;
vector<string>ans;
int get_dis(int l,int r,int x,int y)
{
    return mrr[x][y].f[r]-mrr[x][y].f[l-1]*q[r-l+1];
}
void get_hash_init()
{
    q.push_back(1);
    for(int i=1;i<=1e7+10;i++)
    {
        int t=q[i-1]*131;
        q.push_back(t);
    }
}
void get_hash(int i,int j,string s,int m)
{
    string p=" "+s;
    int n=m;
    //cout<<n<<endl;
    vector<int>f;
    f.push_back(0);

    for(int i=1;i<=n;i++)
    {
        int t=f[i-1]*131+p[i]-'a'+1;
        f.push_back(t);
        
    }
    mrr[i][j].f=f;
}
void solve()
{
    cin>>n;
    int cnt=0;
    get_hash_init();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            string k;
            cin>>k;
            s[i][j]=k;
            get_hash(i,j,k,k.size());
        }
    }
    if(n==2)
    {
        for (int i = 1; i < s[1][2].size(); i++)
        {
            vector<int> p(1010);
            string l[1010];
            int f = 0;
            for (int j = 1; j <= n; j++)
            {

                if (j == 1)
                {
                    p[j] = get_dis(1, 1 + i - 1, 1, 2);
                    l[j] = s[1][2].substr(0, i);
                }
                else
                {
                    if (s[1][j].size() < i)
                    {
                        f = 1;
                        break;
                    }
                    string q = s[1][j].substr(i, 1e6);
                    p[j] = get_dis(i + 1, i + 1 + q.size() - 1, 1, j);
                    l[j] = q;
                }
            }
            if (f)
                continue;
            int flag2 = 1;
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (j == k)
                        continue;
                    int a = get_dis(1, s[j][k].size(), j, k);
                    int b = p[j] * q[l[k].size()] + p[k];
                    // cout<<s[j][k]<<" "<<l[j]+l[k]<<a<<" "<<b<<endl;
                    if (a != b)
                    {
                        flag2 = 0;
                    }
                }
            }
            if (flag2)
            {
                cnt++;
                ans.clear();
                for (int j = 1; j <= n; j++)
                {
                    ans.push_back(l[j]);
                }
            }
        }
        if (cnt == 1)
        {
            cout << "UNIQUE" << endl;
            for (auto it : ans)
            {
                cout << it << endl;
            }
        }
        else if (cnt == 0)
        {
            cout << "NONE";
        }
        else
            cout << "MANY";
    }else 
    {
        
        for (int i = 1; i < s[1][2].size(); i++)
        {
            string l[1010];
            int f=1;
            for (int j = 1; j <= n; j++)
            {

                if (j == 1)
                {
                    l[j] = s[1][2].substr(0, i);
                }
                else
                {
                    if (s[1][j].size() < i)
                    {
                        f = 0;
                        break;
                    }
                    string q = s[1][j].substr(i, 1e6);
                    l[j] = q;
                }
            }
            for(int k=1;k<=2;k++)
            for(int j=1;j<=n;j++)
            {
                if(k==j)continue;
                if(s[j][k]!=l[j]+l[k])
                {
                    f=0;
                }
            }
            if(f==1)
            {
                cout<<"UNIQUE"<<endl;
                for(int i=1;i<=n;i++)
                {
                    cout<<l[i]<<endl;
                }
                return ;
            }
        }
        cout<<"NONE";
        return ;
    }
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);    
    solve();
    return signed(0);
}

