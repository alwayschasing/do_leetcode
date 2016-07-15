/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年07月01日 星期五 10时04分53秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
void helpfun(vector<vector<int> >& ans,vector<int> temp,int i,int len,vector<int>& nums);
void swap(int &i,int &j ){
    int temp = i;
    i = j;
    j = temp;
}
*/
void recursion(vector<int> num,int i ,int j,vector<vector<int> > &res);
vector<vector<int> > permute(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int> > ans;
    vector<int> temp;
    int len = nums.size();
    if(len == 0) return ans;
    //helpfun(ans,temp,0,len,nums);
    recursion(nums,0,len,ans);
    return ans;
}
/*
void helpfun(vector<vector<int> >& ans,vector<int> temp,int i,int len,vector<int>& nums){
    if(i<len){
        for(int j=i;j<len;j++){
            if(i!=j && nums[i] == nums[j]) continue;
            swap(nums[i],nums[j]);
            temp.push_back(nums[i]);
            helpfun(ans,temp,i+1,len,nums);
            swap(nums[i],nums[j]);
            temp.pop_back();
        }
    } 
    else ans.push_back(temp);
}
*/
void recursion(vector<int> num,int i ,int j,vector<vector<int> > &res){
    if(i == j-1){
        res.push_back(num);
        return;
    }
    for(int k = i;k<j;++k){
        if(i!=k && num[i] == num[k]) continue;
        swap(num[i],num[k]);
        recursion(num,i+1,j,res);
    }
}
int main(){
    vector<int> nums;
    int in = 0;
    while(cin>>in){
        nums.push_back(in);
    }
    vector<vector<int> > wegot = permute(nums);
    for(vector<vector<int> >::size_type i=0;i<wegot.size();++i){
        for(vector<int>::size_type j=0;j<nums.size();++j){
            cout<<wegot[i][j]<<" ";
        }    
        cout<<endl;
    }
}
