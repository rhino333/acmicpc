#include <cstdio>
#include <cmath>
using namespace std;

int n;

int main(){
    scanf("%d",&n);
    int sqrtn = (int)sqrt(n);
    for (int i=2; i<=sqrtn; ++i) {
        while (n % i == 0) {
            n /= i;
            printf("%d\n",i);
        }
    }
    if (n > 1) {
        printf("%d",n);
    }
}
