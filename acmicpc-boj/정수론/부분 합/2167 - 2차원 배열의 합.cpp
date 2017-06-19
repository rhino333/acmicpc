#include <cstdio>
using namespace std;

int n,m,k, mp[301][301], psum[301][301];

int gridSum(int i, int j, int x, int y) {
    int ret = psum[x][y];
    if(i >0) ret -= psum[i-1][y];
    if(j >0)ret -= psum[x][j-1];
    if(i >0 && j >0) ret += psum[i-1][j-1];
    return ret;
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            scanf("%d",&mp[i][j]);
            psum[i][j] = psum[i-1][j] + psum[i][j-1] -psum[i-1][j-1] + mp[i][j];
        }
    }
    scanf("%d",&k);
    while (k--) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",gridSum(x1, y1, x2, y2));
    }
}

