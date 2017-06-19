#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

ull a,b;
ull gcd(ull p, ull q){
    if(q == 0) return p;
    return gcd(q, p%q);
}

int main(){
    scanf("%lld %lld",&a,&b);
    ull ans = gcd(max(a,b),min(a,b));
    cout << string(ans,'1');
}
