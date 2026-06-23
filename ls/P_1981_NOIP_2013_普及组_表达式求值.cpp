#include<iostream>
#include<stack>
#include<string>
#include<map>
#include <unordered_map>

using namespace std;

stack<char>op;
stack<int>num;


void eval()//求值
{
    int b = num.top();//栈顶元素是后面那个  所以先存下b 在弹出栈顶
    num.pop();

    int a = num.top();
    num.pop();


    char p = op.top();
    op.pop();

    int ans = 0;

    //计算
    if (p == '+') ans = a+b;
    if (p == '-') ans = a-b;
    if (p == '*') ans = a*b;
    if (p == '/') ans = a/b;

    num.push(ans);
}



int main()
{
    unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };
    
    string s;
    cin>>s;
   for(int i=0;i<s.size();i++)
    {
       if(isdigit(s[i]))//判断是否为数
       {
           
           int j=i;//存下坐标
           int x=0;
           
           while(j<s.size()&&isdigit(s[j]))//继续判断 以为这个数可能不只有一位
           {
               
               x=x*10+s[j]-'0';
               j++;
           }
          // cout<<x<<endl;
           num.push(x);//数入栈
           i=j-1;//跳到数的个位，i++后就来到了符号位
       }
       else if(s[i]=='(')
       {
           op.push(s[i]);
       }
       else if(s[i]==')')//计算到上一个括号内
       {
           while(op.top()!='(')
           {
               eval();
           }
           
           op.pop();//去掉上一个括号
       } 
       else
       {
           
           while(op.size()&&h[s[i]]<=h[op.top()])//如果为+ 前面是a*b 那么前面先算a*b  a+b同理
           {                                    //  h['(']为0 到这里就会停下
              eval();
           }
           op.push(s[i]);

       }
    }
  
  while(op.size())eval();
  
  cout<<num.top()<<endl;
    
}






























// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef pair<int,int>PII;
// const int N=1e6+10;
// const int mod=998244353;
// const int INF  = 0x3f3f3f3f;
// const ll INFll  = 0x3f3f3f3f3f3f3f3f;
// #define endl "\n" 
// #define x first
// #define y second

// //vector<vector<int>>adj(N);




// void solve()
// {


    
//     stack<int> num;
//     stack<char> op;
//     string s;
//     const int mod = 1e5;
    
//     auto eval = [&]() -> void {
//         ll a = num.top(); num.pop();
//         ll b = num.top(); num.pop();
//         if(op.top() == '*') {
//             num.push(1ll * a * b % mod);
//         } else {
//             num.push(1ll * (a + b) % mod);
//         }
//         op.pop();
//     };

//     cin >> s;
//     for(int i = 0; i < s.size(); i ++) {
//         ll x = 0;
//         if('0' <= s[i] && s[i] <= '9') {
//             x = s[i] - '0';
//             int j = i + 1;
//             while(j < s.size() && '0' <= s[j] && s[j] <= '9') {
//                 x = x * 10 + s[j] - '0';
//                 j ++;
//                 x %= mod;
//             }
//             i = j - 1;
//             num.push(x);

//         } else if(s[i] == '*') {
//             op.push('*');
//         } else {
//             while(op.size() && op.top() == '*') {
//                 eval();
//             }
//             op.push('+');
//         }
//     }
//     while(op.size()) {
//         eval();
//     }
//     cout << num.top() % 10000;
// }


// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     cout << setprecision(11) << fixed;
//     int t;t=1;
//     //cin>>t;
//     for(int i=1;i<=t;i++){
//         //printf("Case %d: ",i);
//         solve();
//     }
//     return 0;
// }