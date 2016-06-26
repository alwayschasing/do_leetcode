/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月23日 星期四 15时03分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int jump(vector<int>& nums){
    int len=nums.size();
    if(len==0||nums[0]==0) return 0;
    vector<int> pathlen(len,INT_MAX);
    pathlen[0]=0;
    for(int i=0;i<len;i++){
        int step=nums[i];
        for(int j=1;j<=step&&i+j<len;++j){
            if(pathlen[i+j]>pathlen[i]+1){
                pathlen[i+j]=pathlen[i]+1;
            }
        }
    } 
    return pathlen[len-1];
}
int main(){
    vector<int> nums;
    int in;
    while(cin>>in){
        nums.push_back(in);
    }
    int ans=jump(nums);
    cout<<ans<<endl;
    return 0;
}

