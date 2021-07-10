#include "include.h"
class Subsets
{
public:
    // result = []
    // def backtrack(路径, 选择列表):
    //     if 满足结束条件:
    //         result.add(路径)
    //         return
    //     for 选择 in 选择列表:
    //         做选择
    //         backtrack(路径, 选择列表)
    //         撤销选择
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> track;
    void dfs(vector<int> &nums, int x)
    {
        res.push_back(track);
        for (int i = x; i < nums.size(); i++)
        {
            track.push_back(nums[i]);
            dfs(nums, i + 1);
            track.pop_back();
        }
    }
};


class Permutation {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
private:
    vector<string> res;
    void dfs(string s, int x) {
        if(x == s.size() - 1) {
            res.push_back(s);                       // 添加排列方案
            return;
        }
        set<int> st;
        for(int i = x; i < s.size(); i++) {
            if(st.find(s[i]) != st.end()) continue; // 重复，因此剪枝
            st.insert(s[i]);
            swap(s[i], s[x]);                       // 交换，将 s[i] 固定在第 x 位
            dfs(s, x + 1);                          // 开启固定第 x + 1 位字符,
            swap(s[i], s[x]);                       // 恢复交换
        }
    }
};

class Combine {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        dfs(n,k,1);
        return ans;
    }
private:
    // result = []
    // def backtrack(路径, 选择列表):
    //     if 满足结束条件:
    //         result.add(路径)
    //         return
    //     for 选择 in 选择列表:
    //         做选择
    //         backtrack(路径, 选择列表)
    //         撤销选择
    vector<vector<int>> ans;
    vector<int> track;
    void dfs(int n,int k,int l)//增加一个l用来递归调用的参数
    {
        if(k==track.size())
        {
            ans.push_back(track);
            return;
        }
        for(int i=l;i<=n;++i)
        {
            track.push_back(i);
            //cout<<"l+1="<<l+1<<endl;
            //cout<<"l+1="<<l+1<<endl;
            //cout<<"l+1="<<l+1<<endl;
            dfs(n,k,i+1);
            track.pop_back();
        }

    }  
    
};

int main()
{
    printTwoD(Combine().combine(4,2));
    //Combine().combine(4,2);
    //cout<<"sss"<<endl;
    return 0;
}
