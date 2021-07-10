#include <vector>
#include <iostream>
using namespace std;
#include<string>
#include<unordered_map>
int main()
{
    string a;
    cin>>a;                      //从屏幕中读取
    int length=a.size();
    unordered_map<char,int> map;
    for(auto const& c:a)
    {
        map[c]++;
    }
    vector<string> vec;
    for(auto const& it:map)
    {
        string b(it.second,it.first);   //string的构造
        vec.push_back(b);
    }
    for(auto const& c :vec)
    {
        cout<<c<<endl;
    }
}