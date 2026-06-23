#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

map<string,string>st;

void init()
{
    st["iu"]="q";
    st["ei"]="w";
    st["uan"]="r";
    st["ue"]="t";
    st["un"]="y";
    st["sh"]="u";
    st["ch"]="i";
    st["uo"]="o";
    st["ie"]="p";
    st["ong"]="s";
    st["iong"]="s";
    st["ai"]="d";
    st["en"]="f";
    st["eng"]="g";
    st["ang"]="h";
    st["an"]="j";
    st["uai"]="k";
    st["ing"]="k";
    st["uang"]="l";
    st["iang"]="l";
    st["ou"]="z";
    st["ia"]="x";
    st["ua"]="x";
    st["ao"]="c";
    st["zh"]="v";
    st["ui"]="v";
    st["in"]="b";
    st["iao"]="n";
    st["ian"]="m";

}

void bh(string s)
{
    if(s.size()==1)cout<<s<<s;
    else if(s.size()==2){
        cout<<s;
    }
    else 
    {
        if(st.count(s)){
            cout<<s[0]<<st[s];
            return;
        }
        for(int i=1;i<=s.size();i++){
            string s1 = s.substr(0,i);
            string s2 = s.substr(i);
            //cout<<s1<<" "<<s2<<endl;

           // cout<<st.count(s1)<<" "<<st.count(s2)<<endl;
            
            if((st.count(s1)&&st.count(s2))||(s1.size()==1&&st.count(s2))||(s2.size()==1&&st.count(s1))){
                if(s1.size()==1)cout<<s1;
                else cout<<st[s1];

                if(s2.size()==1)cout<<s2;
                else cout<<st[s2];
                //cout<<st[s1]<<st[s2];
            }
        }
    }

}

void solve()
{

    char t;
    string s;
    string ans;
    while(scanf("%c",&t)!=EOF)
    {
        ans+=t;

        if(t=='\n'){
            bh(s);
            cout<<" ";
            cout<<t;
            s.clear();
        }
        else if(t==' '){
            bh(s);
            cout<<" ";
            s.clear();
        }
        else if(t>='a'&&t<='z')
        {
            s+=t;
        }
    }

   // bh(s);

   // cout<<ans<<endl;



}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}