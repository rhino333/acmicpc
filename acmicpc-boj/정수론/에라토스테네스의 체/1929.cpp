#include <vector>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxv = 1000000;
int n,m, prime[maxv + 1];
void eratos(){
    prime[0] = prime[1] = 1;
    int sq = (int)sqrt(maxv);
    for(int i=2;i<= sq; ++i) {
        if(prime[i]) continue;
        for(int j=i*i; j<= maxv; j += i) {
            prime[j] = 1;
        }
    }
}

int main(){
    eratos();
    scanf("%d %d",&n,&m);
    for(int i=n; i<=m; ++i) {
        if(!prime[i]){
            printf("%d\n",i);
        }
    }
}
