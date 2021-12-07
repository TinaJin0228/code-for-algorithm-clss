#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class point{
    public:
    point(long long x1,long long y1):x(x1),y(y1){}
    point(){}
    point(const point& a1):x(a1.x),y(a1.y){}
    point& operator=(const point& a1){x = a1.x;y = a1.y;return *this;}

    long long x,y;
};

    long long distance_2(point a1,point a2){
        return (a1.x-a2.x)*(a1.x-a2.x)+(a1.y-a2.y)*(a1.y-a2.y);
    }

void swap(point* a,int i,int j){
    point tmp;
    // tmp = a[i];
    // a[i] = a[j];
    // a[j] = tmp;
    tmp.x = a[i].x;tmp.y = a[i].y;
    a[i].x = a[j].x;a[i].y = a[j].y;
    a[j].x = tmp.x;a[j].y = tmp.y;
}

void mergesort_x(point* a,int start,int end){
    if(start>=end)return;
    if(start == end-1){
        if(a[start].x>a[end].x)swap(a,start,end);
    }
    int mid = (start+end)/2;
    mergesort_x(a,start,mid);
    mergesort_x(a,mid+1,end);
    point* reg = new point[end-start+1];
    int start1 = start;int end1 = mid;
    int start2 = mid+1;int end2 = end;
    int k=0;
    while(start1<=end1 && start2<=end2)
        reg[k++] = a[start1].x<a[start2].x?a[start1++]:a[start2++];
    while(start1<=end1)reg[k++] = a[start1++];
    while(start2<=end2)reg[k++] = a[start2++];
    for(k=start;k<=end;k++)a[k] = reg[k-start];
    delete []reg;
}


int partition_x(point* a,int start,int end){
    if(start>=end)return start;
    int l = start;
    int r = end;
    srand(time(0));
    int rnd = rand()%(end-start+1)+start;
    swap(a,start,rnd);
    int pivot = a[start].x;    
    while(l<r){
        while(l<r && a[r].x>=pivot)r--;
        swap(a,l,r);
        while(l<r && a[l].x<=pivot)l++;
        swap(a,l,r);}
    return l;
}

void quicksort_x(point* a,int start,int end){
    if(start>=end)return;
    int partition1 = partition_x(a,start,end);
    quicksort_x(a,start,partition1-1);
    quicksort_x(a,partition1+1,end);
}

int partition_y(point* a,int start,int end){
    if(start>=end)return start;
    srand(time(0));
    int rnd = rand()%(end-start+1)+start;
    swap(a,start,rnd);
    int pivot = a[start].y;
    int l = start;
    int r = end;
    // wow
    while(l<r){
        while(l<r && a[r].y>=pivot)r--;
        swap(a,l,r);
        while(l<r && a[l].y<=pivot)l++;
        swap(a,l,r);        
    }
    return l;
}

void quicksort_y(point* a,int start,int end){
    if(start>=end)return;
    int partition1 = partition_y(a,start,end);
    quicksort_y(a,start,partition1-1);
    quicksort_y(a,partition1+1,end);
}

void order_y(int* y_ord,point* a,int l, int r) {
    if (l >= r) return;
    if(l == r-1)if(a[y_ord[l]].y>a[y_ord[r]].y)swap(y_ord[l],y_ord[r]);
    int mid =(l+r)/2;
    order_y(y_ord,a,l,mid);
    order_y(y_ord,a,mid+1,r);
    int* reg = new int[r-l+1];
    int start1 = l;int end1 = mid;
    int start2 = mid+1;int end2 = r;
    int k=0;
    while(start1<=end1 && start2<=end2)
        reg[k++] = a[y_ord[start1]].y<a[y_ord[start2]].y?y_ord[start1++]:y_ord[start2++];
    while(start1<=end1)reg[k++] = y_ord[start1++];
    while(start2<=end2)reg[k++] = y_ord[start2++];
    for(k=l;k<=r;k++)y_ord[k] = reg[k-l];
    delete []reg;
}



long long solve(point* a,int start,int end){
    if(start>=end)return 80000000000000;//8*10^14
    if(start+1==end)return distance_2(a[start],a[end]);
    int mid = (start+end)/2;
    long long  a1 = solve(a,start,mid);
    long long a2 = solve(a,mid+1,end);
    long long res1 = a1<a2?a1:a2;

    int i=0,j=0;
    int i1=-1,i2=-1;

    for(i=start;i<=mid;i++){
        if((a[i].x-a[mid].x)*(a[i].x-a[mid].x)<=res1){
            i1 = i;
            break;
        }
    }
    for(i = end;i>=mid+1;i--){
        if((a[i].x-a[mid+1].x)*(a[i].x-a[mid+1].x)<=res1){
            i2 = i;
            break;}
    }
    // result: i1<=mid;i2>=mid+1

    // long long res2 = 80000000000000;
    long long tmp_dis;

    int* y_ord = new int[i2-i1+1];
    for(i=0;i<=i2-i1;i++)y_ord[i] = i1+i;

    // for(i=0;i<=i2-i1;i++)cout<<y_ord[i]<<" ";

    // quicksort_y(a,i1,i2);
    // for(i = i1;i<=i2;i++){
    //     for(j=i+1;j<=i+7 && j<=i2;j++){
    //         tmp_dis = distance_2(a[i],a[j]);
    //         res1 = res1<tmp_dis?res1:tmp_dis;
    //     }
    // }
    // quicksort_x(a,i1,i2);

    // order_y(y_ord,a,i1,i2);
    order_y(y_ord,a,0,i2-i1);
    for(i=0;i<=i2-i1;i++){
        for(j = i+1;j<=i2-i1 && j<=i+7;j++){
            if((a[y_ord[j]].y-a[y_ord[i]].y)*(a[y_ord[j]].y-a[y_ord[i]].y)>res1)break;
            tmp_dis = distance_2(a[y_ord[i]],a[y_ord[j]]);
            res1 = res1<tmp_dis?res1:tmp_dis;
        }
    }

    // res1 = res1<res2?res1:res2;
    return res1;

}


int main(){
    // freopen("1299.in","r",stdin);
    int n,i,x,y;
    scanf("%d",&n);

    point* a = new point[n];
    for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    a[i] = point(x,y);
    }

    // quicksort_x(a,0,n-1);
    mergesort_x(a,0,n-1);
    
    cout<<solve(a,0,n-1);



    return 0;


}