#include <cmath>
#include <cstdio>
using namespace std;

int m,k,cnt, prime[1001];

int main(){
    scanf("%d %d",&m,&k);
    for(int i=2; i<=m; ++i){
        if(prime[i]) continue;
        for (int j=i; j<=m; j += i) {
            if(prime[j]) continue;
            cnt++;
            if(cnt == k) {
                printf("%d",j);
                return 0;
            }
            prime[j] = 1;
        }
    }
}
