#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

string h,n;
vector<int> pi(1000001,0), kmp;

int main(){
    ios::sync_with_stdio(); cin.tie(0);
    getline(cin,h), getline(cin,n);
    int hs = (int)h.size(), ns = (int)n.size();
    
    for(int i=1, j=0; i<ns; ++i){
        while(j > 0 && n[i] != n[j]) j = pi[j-1];
        if(n[i] == n[j]) pi[i] = ++j;
    }
    
    for(int i=0, j=0; i<hs; ++i){
        while(j > 0 && h[i] != n[j]) j = pi[j-1];
        if(h[i] == n[j]) {
            ++j;
            if(j == ns){
                kmp.push_back(i - j + 2);
                j = pi[j-1];
            }
        }
    }
    cout << kmp.size() << '\n';
    for(auto &a : kmp)
        cout << a << ' ';
}
