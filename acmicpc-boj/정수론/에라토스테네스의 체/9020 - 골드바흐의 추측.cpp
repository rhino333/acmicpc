#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int t,n, prime[10001];

void eratos(){
    int sqn = (int)sqrt(10000);
    for(int i=2; i<=sqn; ++i) {
        if(prime[i]) continue;
        for(int j=i*i; j<=10000; j += i){
            prime[j] = 1;
        }
    }
}

int main(){
    eratos();
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=n/2; i >= 2; --i) {
            if(!prime[i] && !prime[n-i]){
                printf("%d %d\n",i,n-i);
                break;
            }
        }
    }
}

