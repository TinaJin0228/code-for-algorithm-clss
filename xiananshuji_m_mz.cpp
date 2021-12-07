#include <iostream>
using namespace std;

int main(){
    cout<<"设m = 21，构造Z/mZ的加法表和乘法表"<<endl;
    int a[22][22];
    int i,j;

    // 输出加法表
    cout<<"加法表："<<endl;
    for(i=0;i<22;i++){
        for(j=0;j<22;j++){
            if(i==0 && j==0)cout<<"  ";
            else if(i==0)cout<<j-1<<" ";
            else if(j==0)cout<<i-1<<" ";
            else {
                cout<<(i+j-2)%21<<" ";
            }
            if(j==21)cout<<endl;
        }
    }

    // 输出乘法表
    cout<<"乘法表："<<endl;
    for(i=0;i<22;i++){
        for(j=0;j<22;j++){
            if(i==0 && j==0)cout<<"  ";
            else if(i==0)cout<<j-1<<" ";
            else if(j==0)cout<<i-1<<" ";
            else {
                cout<<((i-1)*(j-1))%21<<" ";
            }
            if(j==21)cout<<endl;
        }
    }
    return 0;
}