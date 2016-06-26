/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月26日 星期日 14时03分32秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

void generator(vector<int>& nums,int start,int end,vector<int> temp,vector<vector<int> >& ans);
vector<vector<int> > permute(vector<int>& nums){
    int len = nums.size();
    vector<vector<int> > ans;
    vector<int> temp;
    if(len==0){
        return ans;
    }
    generator(nums,0,len,temp,ans);    
    return ans;
}
void generator(vector<int>& nums,int start,int end,vector<int> temp,vector<vector<int> >& ans){
    if(start == end){
        ans.push_back(temp);
        return;
    }
    int i=0;
    int t=0;
    for(i=start;i<end;++i){
        t=nums[i];
        nums[i]=nums[start];
        nums[start]=t;
        
        temp.push_back(nums[start]);
        generator(nums,start+1,end,temp,ans);
        temp.pop_back();

        t=nums[i];
        nums[i]=nums[start];
        nums[start]=t;
    }
}
int main(){

}
