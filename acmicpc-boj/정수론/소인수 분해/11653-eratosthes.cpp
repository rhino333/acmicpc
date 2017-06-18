#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 1e7;
int minFactor[MAXN];
int n;

void eratosthenes(){
    minFactor[0] = minFactor[1] = -1;
    for (int i=2; i<= n; ++i) {
        minFactor[i] = i;
    }
    int sqrtn = (int)sqrt(n);
    for (int i=2; i<=sqrtn; ++i){
        if(minFactor[i] != i) continue;
        for (int j=i*i; j<=n; j += i) {
            if(minFactor[j] == j)
                minFactor[j] = i;
        }
    }
}

int main(){
    scanf("%d",&n);
    eratosthenes();
    while (n > 1) {
        printf("%d\n",minFactor[n]);
        n /= minFactor[n];
    }
}
