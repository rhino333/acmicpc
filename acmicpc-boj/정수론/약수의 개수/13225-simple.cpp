#include <cstdio>
#include <cmath>
using namespace std;

int n,m, factors[10001];

int main(){
    for (int div = 1; div <= 10000; ++div)
        for (int m = div;  m <= 10000; m += div)
            factors[m] += 1;
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        printf("%d %d\n",n,factors[n]);
    }
}
