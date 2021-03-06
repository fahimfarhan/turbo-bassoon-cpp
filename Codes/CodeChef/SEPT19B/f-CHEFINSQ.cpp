/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

class nCr{
private:
    ll n,r;
    ll **dp;
public:
    int getDpIJ(int i, int j){ return dp[i][j];   }
    nCr(int N, int R){
        n=N; r=R;
        dp = new ll*[n+1];
        for(int i=0; i<=n;i++){ dp[i] = new ll[r+1]; }
        dp[0][0] = 1;
        /*for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i=0; i<=r; i++){
            dp[0][i] = 1;
        }*/
        for(int i=1; i<=n; i++){
            for(int j=0; j<=r; j++){
                if(j>i){ dp[i][j]=0; }
                else if(j==i || j==0){ dp[i][j]=1;}
                else dp[i][j] = dp[i-1][j-1]+dp[i-1][j]; // nCr = n-1Cr-1 + n-1Cr
            }
        }
    }

    void printer(){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=r; j++){
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
        }
    }
    ~nCr(){
        for(int i=0; i<=n;i++)
        { if(!dp[i]) delete[] dp[i]; }
        if(!dp)delete[] dp;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T, N,K,temp, count[110];

    cin>>T;
    while(T--){
        cin>>N>>K;
        for(int i=0; i<=110; i++){  count[i] = 0; }
        for(int i=0; i<N; i++){
            cin>>temp;
            count[temp]++;
        }

        ll res=1;
        ll j=0;
        while(K>0){
            if(count[j]!=0){   
                if(count[j]<=K){    res*=count[j]; }
                else{
                    nCr ncr(count[j],K);
                    res*=ncr.getDpIJ(count[j],K);
                }
                K-=count[j];
                
            }
            j++;
        }
        cout<<res<<"\n";
    }


    return 0;
}