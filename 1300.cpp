# include <iostream>
using namespace std;



const int N = 4e7 + 1;
int n, k;
int a[N];
void read_input_data() {
    int m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    unsigned int z = a[m];
    for (int i = m + 1; i <= n; i++) {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}

void swap(int* a,int i,int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partition(int* a,int start,int end){
    if(start>=end)return start;
    int pivot = a[start];
    // int i=start;int j = end;

    while(start!=end){
        while(start!=end && a[end]>=pivot)end--;
        swap(a,start,end);
        while(start!=end && a[start]<=pivot)start++;
        swap(a,start,end);
    }
    return start;
}

int main(){
    // 提交用
    read_input_data();

    // 测试用
    // int a[10] = {3,9,10,7,2,4,1,8,5,6};
    // int n = 10;
    // int k = 7;
    

    // 思路：利用快排中的partition函数，返回中点坐标p；若p = k;返回a[p];若p<k,令start = p+1;p = partition(a,start,end);
    // 若p>k,end = p-1;partition(a,start,end);
    int start = 1;int end = n;
    int p = partition(a,start,end);
    while(p!=k){
        if(p>k)end = p-1;
        else start = p+1;
        p = partition(a,start,end);
    }

    cout<<a[k];

    return 0;

}