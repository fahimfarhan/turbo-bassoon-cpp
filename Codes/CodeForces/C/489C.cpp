/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
/**
Dread it, run from it, destiny arrives all the same !
I find your lack of faith in the CodeForces disturbing! >_<
Love you 3000 !
Keep It Simple Stupid (KISS)!
Good Hunting 47!
*/
/**
AC I - Redemption AC II - Revenge AC: Brotherhood - Justice AC: Revelation - Answers 
AC III - Freedom AC IV - Glory AC Rogue - Betrayal AC Unity - Love AC Syndicate - Family 
AC Origins - Beginnings 
*/

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

bool can(int m, int s)
{
    return (s >= 0) && (s <= 9*m);
}

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

    int m,s;

    cin>>m>>s;
    if(s<1&&m>1||s>m*9){
        cout<<-1<<" "<<-1<<"\n";
    }
    else{
        int j=0, k = s;
        for(int i=m-1; i>=0; i--){
            j = max(0, k-9*i);
            if(j==0&&i==m-1&&k){    j=1;    }
            cout<<j;
            k=k-j;
        }cout<<" ";
        k=s;
        for(int i=m-1;i>=0;i--)
        {
            j=min(9,k);
            cout<<j;
            k=k-j;
        }cout<<"\n";
    }
    return 0;
}