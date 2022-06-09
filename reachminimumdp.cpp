#include <iostream>
#include<climits>
using namespace std;
int reachto1(int n,int *arr){
    //base case
    if(n==1){
        arr[n]=0;
        return arr[n]; 
    }
    //recursive case
    int op1=INT_MAX;
    int op2=INT_MAX;
    int op3=INT_MAX;
    if(arr[n]!=-1){
        return arr[n];
    }
    op1=reachto1(n-1,arr);
    if(n%2==0){
        op2=reachto1(n/2,arr);
    }
    if(n%3==0){
        op3=reachto1(n/3,arr);
    }
    arr[n]=min(op1,min(op2,op3))+1;
    return arr[n];
}
int main() {
    // cout<<"Hello World!";
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    int ans=reachto1(n,arr);
    cout<<ans<<endl;
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;

}