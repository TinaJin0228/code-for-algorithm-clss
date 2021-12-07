/*
冒泡排序每个元素交换次数算法
冒泡排序每个元素交换次数 = 包含该元素的逆序对的对数
设原数列a[n] = {乱序的1~n}，构建数列bit[n+1]，其中bit[i]=0表示i没有出现过，bit[i]=1表示i出现过
bit：binary indexed tree, 可以方便地算出前i个数的和的重构数组
对a中元素从a[0]~a[n-1]进行遍历，对a[i],step1:通过求sum(bit[a[i]]),算出a中在a[i]之前出现、比a[i]小的数的个数k；
所以a中在a[i]之前出现、比a[i]大的数有i-k个。step2：将bit[a[i]]置为1
同时可知在a[i]之后出现、比a[i]小的数有a[i]-1-k个。所以包含数字a[i]的逆序对有(a[i]+i-1-2k)个.
将res[a[i]-1]置为(a[i]+i-1-2k)。
*/
/*
bit的性质：
*/


#include <iostream>
#include <stdio.h>
using namespace std;

// 返回序号第1~x的元素的和
int getSum(int bit[],int x){
    int s = 0;
    while(x>0){
        s += bit[x];
        x -= x&(-x);//效果是二进制下，把最低位的1设成0
    }
    return s;
}

// 给一个含有n个元素的bit的第i位+x
void update(int bit[],int n,int i,int x){
    while(i<=n){
        bit[i] += x;
        i += i&(-i);
    }
}


int main(){
    int n,i,j,k,tmp;
    freopen("1301.in","r",stdin);
    scanf("%d",&n);

    int* a = new int[n];
    int* bit = new int[n+1];
    int* res = new int[n];

    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        a[i] = tmp;
        bit[i] = 0;
    }
    bit[n] = 0;

    // O(n^2)
    // for(i=0;i<n;i++){
    //     res[a[i]-1] = 0;
    //     for(j=0;j<i;j++){
    //         if(a[j]>a[i])res[a[i]-1]++;
    //     }
    //     for(j=i+1;j<n;j++){
    //         if(a[j]<a[i])res[a[i]-1]++;
    //     }
    // }
    for(i=0;i<n;i++){
        k = getSum(bit,a[i]);
        update(bit,n,a[i],1);
        res[a[i]-1] = a[i]+i-1-2*k;
    }





    for(i=0;i<n;i++)printf("%d ",res[i]);
    return 0;
}