#include <iostream>
#include <vector>
#include<stack>
using namespace std;
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    if(pushed.size()!=popped.size())
    {
        return false;
    }
    stack<int> stk;
    for(auto const& p:pushed)
    {
        stk.push(p);
        for(int i=0;i<popped.size();i++)
        {
            if(!stk.empty()&&stk.top()==popped[i])
            {
                stk.pop();
            }
        }
        
    }
    return stk.empty();
}
int main()
{
    vector<int> pushed{1,2,3,4,5};
    vector<int> poped{4,5,3,2,1};
    validateStackSequences(pushed,poped);
}