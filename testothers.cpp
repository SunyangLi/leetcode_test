#include "include.h"
#define INT_MAX 50000

//计算1出现的次数
int countDigitOneByOne(int n)
{
    string str = std::to_string(n);
    int length = str.size();
    char c;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        c = str[i];
        if (c == '1')
        {
            count++;
        }
    }
    return count;
}
int countDigit(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += countDigitOneByOne(i);
    }
    return count;
}
string minNumber(vector<int> &nums)
{
    int size = nums.size();
    vector<string> str_vec;
    for (int i = 0; i < size; i++)
    {
        string str = std::to_string(nums[i]);
        str_vec.push_back(str);
    } //其实这边的证明很难
    sort(str_vec.begin(), str_vec.end(), [](string &x, string &y)
         { return x + y < y + x; });
    string res;
    for (int i = 0; i < str_vec.size(); i++)
    {
        res.append(str_vec[i]);
    }
    return res;
}
/*
在字符串 s 中找出第一个只出现一次的字符。
如果没有，返回一个单空格。 s 只包含小写字母。
*/
// char firstUniqChar(string s)
// {
//     unordered_map<char, int> map; //其中前面的表示次数，后面的表示第一次出现在string s中的位置
//     int size = s.size();
//     for (int i = 0; i < size; i++)
//     {
//         if(map[s[i]]==size)  continue;
//         if(map[s[i]]==0) map[s[i]]=i+1;
//         if(map[s[i]]!=0) map[s[i]]=size;
//     }
//     printunorderedMap(map);
//     int minV = INT_MAX;
//     for (auto pair : map)
//     {
//         if (pair.second == size)
//             continue;
//         minV = min(minV, pair.second);
//     }
//     cout<<"最小"<<minV<<endl;
//     return minV == INT_MAX ? ' ' : s[minV];
// }

char firstUniqCharByVetor(string s)
{
    if (s.empty())
        return ' ';
    vector<int> vec(26, 0);
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (vec[s[i] - 'a'] == size)
            continue;
        else if (vec[s[i] - 'a'] == 0)
            vec[s[i] - 'a'] = i + 1;
        else if (vec[s[i] - 'a'] != 0)
            vec[s[i] - 'a'] = size;
    }
    int res = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
        if (vec[i] == 0)
            continue;
        else if (vec[i] == size)
            continue;
        else
            res = min(res, vec[i]);
    }
    cout << res << endl;
    return res == INT_MAX ? ' ' : s[res - 1];
}

char firstUniqCharByQueue(string s)
{
    if (s.empty())
        return ' ';
    unordered_map<char, int> map;
    queue<char> que;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        map[s[i]]++;
        que.push(s[i]);
    }
    while(!que.empty()&&map[que.front()]>1)
    {
        que.pop();
    }
    return que.front();
}

char firstUniqCharSTD(string s)
{
    unordered_map<char, int> map;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        map[s[i]]++;
    }
    printunorderedMap(map);
    for (int i = 0; i < size; i++)
    {
        if (map[s[i]] == 1)
        {
            return s[i];
        }
    }
    //char s=' ';
    return ' ';
}
int main()
{
    string s = "loveleetcode";
    cout << "test:" << endl;
    //cout<<firstUniqChar(s)<<endl;
    cout << "标准:" << endl;
    cout << firstUniqCharSTD(s) << endl;
    // map<int,int> map1;
    // for(int i=0;i<100;i++)
    // {
    //     map1.insert(make_pair(i,i));

    // }
    // printMap(map1);
}