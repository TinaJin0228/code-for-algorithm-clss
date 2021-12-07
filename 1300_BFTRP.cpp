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

    // 投机取巧警告
    // 救命啊真的有用
    int mid = (start+end)/2;
    swap(a,start,mid);

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

// int takeMedian(int* a,int l,int r){

// }

int main(){
    // 提交用
    read_input_data();

    // 测试用
    // int a[10] = {3,9,10,7,2,4,1,8,5,6};
    // int n = 10;
    // int k = 7;
    

    // 思路2：
    /*
    step1:将a分成5组，分别取出中位数 这一步如果最坏情况不是O(n^2/25)吗？？
    step2：取出中位数的中位数，以它为基准快排，返回分隔坐标
    step3：若p>k，end = p-1，若p<k,start = p+1,若p=k,输出
    step4:重复step1
    */
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