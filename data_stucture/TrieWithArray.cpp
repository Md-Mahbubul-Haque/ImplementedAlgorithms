#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define PQ priority_queue
#define ld long double
#define ll long long
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-12
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}
template<class T>
void print(vector<T> &vec){
    fof(i,0,vec.size()) cout<<vec[i]<<" "; cout<<endl;
}
template<class T>
void print(set<T> &s){
    for(auto it: s) cout<<it<<" "; cout<<endl;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

const int total_len=100500;///maxnumber of chars in all strings
const int max_alpha =26;///only lower/uppercase

pair<int,bool> trie[total_len][max_alpha];
int node;
pair<int,bool> root;


pair<int,bool> newNode(){
    return mp(++node,false);
}

void inserT(char *s){
    size_t len=strlen(s);
    pair<int,bool> v=root;

    for(int i=0;i<len;i++){
        int id=s[i]-'a';

        if(trie[v.first][id].first==0) trie[v.first][id]=newNode();

        if(i==len-1){
            trie[v.first][id].second=true;
        }
        v=trie[v.first][id];
    }
}

bool searcH(char *s){
    size_t len=strlen(s);

    pair<int,bool> v=root;
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(trie[v.first][id].first==0){
            return false;
        }
        v=trie[v.first][id];
    }
    return v.second;
}

int main()
{
    //FI;FO;
    FastIO;

    root=newNode();
    char insrt[total_len],srch[total_len];

    while(true){

        scanf("%s %s",insrt,srch);

        if(!strcmp(insrt,"STOP")) break;

        inserT(insrt);
        cout<<searcH(srch)<<endl;

        
    }

    return 0;
}

