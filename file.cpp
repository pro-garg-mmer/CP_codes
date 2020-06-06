#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

#define MOD 998244353
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>b;--i)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}


ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}

ll pow(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }

return ans;
}



/*const int N=200000;

ll fac[N+1];
ll inv[N+1];
ll p=998244353;

ll c(ll a, ll b,ll m)
{
  if(a<b)return 0;
  return (fac[a]*inv[b]%m)*(inv[a-b])%m;
}

*/
 //const int N=1001;

 //const int M=1001;

//ll vis[1001][1001];

ll dis[1001][1001];

char came_from[1001][1001];

char ch[1001][1001];

ll dx[]={0,1,0,-1};

ll dy[]={1,0,-1,0};

char blah[]={'R','D','L','U'};

ll xa,xb,ya,yb;
ll n,m;

bool valid(ll x,ll y)
{
  if(x<1||x>n||y<1||y>m)return false;

  if(ch[x][y]=='#')return false;

  return true;
}

void bfs(ll x,ll y)
{

//vis[x][y]=1;

queue<pll>q;

q.push({x,y});

dis[x][y]=0;

while(!q.empty())
{
  ll a=q.front().ff,b=q.front().ss;


  q.pop();

  for(int i=0;i<4;i++)
  {
    ll nx=a+dx[i],ny=b+dy[i];

    if(valid(nx,ny))
    {
      if(dis[a][b]+1<dis[nx][ny])
      {
        dis[nx][ny]=dis[a][b]+1;
        came_from[nx][ny]=blah[i];
        //vis[nx][ny]=1;
      q.push({nx,ny});
      }
      
    }
     //if(nx==xb&&ny==yb)return;
  }
}


}

int main()
{ fast


cin>>n>>m;

//memset(dis,INT_MAX,sizeof(dis));

for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    cin>>ch[i][j];
    if(ch[i][j]=='A')xa=i,ya=j;
  if(ch[i][j]=='B')xb=i,yb=j;
   dis[i][j]=INT_MAX;

  }

}


bfs(xa,ya);

if(dis[xb][yb]==INT_MAX)
{
  cout<<"NO"<<endl;
  return 0;
}


cout<<"YES"<<endl;

cout<<dis[xb][yb]<<endl;

ll curx=xb,cury=yb;

vector<char>ans;

while(curx!=xa||cury!=ya)
{
  

   for(int i=0;i<4;i++)
   {
    if(blah[i]==came_from[curx][cury])
    {
      ans.pb(came_from[curx][cury]);
      curx-=dx[i],cury-=dy[i];
      break;
    }
   }



}

ll sz=ans.size();


for(int i=sz-1;i>=0;i--)cout<<ans[i];

  cout<<endl;


 return 0;

}