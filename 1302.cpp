// n == 2的示例代码
#include <iostream>
using namespace std;
int a[1024 + 1];
int query(int x, int y);
// merge sort
void solve(int l, int r) {
    if (l >= r) return;
    if (r - l > 1) {
        int mid = (l+r)/2;
        solve(l,mid);
        solve(mid+1,r);
        int i = l;int j = mid+1;int k;
        while(j<r+1 && i<j){
            while(i<j && query(a[i],a[j])<=0)i++;
            if(i<j){
            for(k=j;k>=i+1;k--)swap(a[k],a[k-1]);
            i++;
            j++;
            }
        }
        return;
    }
    else if (query(a[l], a[r]) == 1) {
        swap(a[l], a[r]);
}    
}
void optimal_sort(int n) {
    for (int i = 1; i <= n; i++) a[i] = i;
    solve(1, n);
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
}


// 测试代码
#include <iostream>
int __qcnt = 0;
int __hidden_array[1024];
int query (int x, int y) {
    __qcnt ++;
    int d = __hidden_array[x] - __hidden_array[y];
    return d > 0 ? 1 : (d == 0 ? 0 : -1);
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> __hidden_array[i];
    optimal_sort(n);
    std::cout << "number of queries : " << __qcnt << std::endl;
}