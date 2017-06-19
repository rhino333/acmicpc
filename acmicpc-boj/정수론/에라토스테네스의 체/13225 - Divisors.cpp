#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 10001;
int n,m, minFactor[MAXN], minFactorPower[MAXN], factors[MAXN];

void eratos(){
    minFactor[0] = minFactor[1] = -1;
    for (int i=2; i< MAXN; ++i) {
        minFactor[i] = i;
    }
    int sqrtn = (int)sqrt(MAXN);
    for (int i=2; i<= sqrtn; ++i) {
        if(minFactor[i] != i) continue;
        for (int j=i*i; j< MAXN; j += i) {
            if(minFactor[j] == j)
                minFactor[j] = i;
        }
    }
}

void getFactors(){
    factors[1] = 1;
    for (int i =2; i < MAXN; ++i) {
        if(minFactor[i] == i){
            minFactorPower[i] = 1;
            factors[i] = 2;
        } else {
            int p = minFactor[i];
            int m = i / p;
            if(p != minFactor[m]){
                minFactorPower[i] = 1;
            } else {
                minFactorPower[i] = minFactorPower[m] + 1;
            }
            int a = minFactorPower[i];
            factors[i] = (factors[m]/a) * (a+1);
        }
    }
}

int main(){
    scanf("%d",&m);
    eratos();
    getFactors();
    while(m--){
        scanf("%d",&n);
        printf("%d %d\n",n,factors[n]);
    }
}
