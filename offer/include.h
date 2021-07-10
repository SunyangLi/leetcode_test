#include<vector>
#include<list>
#include<iostream>
#include<set>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

template<typename T>
void printOneD(vector<T> const&vec)
{
    for(auto s:vec)
    {
        cout<<s<<" ";
    }
    cout<<endl;
}

template<typename T>
void printTwoD(vector<vector<T>> const&vec)
{
    for(auto s:vec)
    {
        for(auto l:s)
        {
            cout<<l<<" ";
        }
        cout<<endl;
    }
    
}
template <class T>
class Container
{
public:
    void print(T& c)
    {
        for (m_it = c.begin(); m_it != c.end(); ++m_it)
        {
            cout << *m_it << " ";
        }
        cout << endl;
    }
private:
    decltype(T().begin()) m_it;  // 这里不能确定迭代器类型
};



template<typename T,typename P>
void printunorderedMap(unordered_map<T,P> map)
{
    for(auto iter:map)
    {
        cout<<"key="<<iter.first<<" "<<" value="<<iter.second<<endl;
    }
}

template<typename T,typename P>
void printMap(map<T,P> map)
{
    for(auto iter:map)
    {
        cout<<"key="<<iter.first<<" "<<" value="<<iter.second<<endl;
    }
}