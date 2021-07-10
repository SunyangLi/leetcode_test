#include <iostream>
using namespace std;
#include <bitset>
#include <stdint.h>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
int NumberOf1(int n)
{
    int count = 0;
    while (n)
    {
        //cout<<"第"<<count+1<<"次"<<bitset<32>(n)<<endl;
        n = n & (n - 1); // 把最后一位1变成0
        ++count;
    }
    return count;
}
int NumverOf12(int res)
{
    int n = 0;
    while (res)
    {
        if (res & 0x1)
        {
            n++;
        }
        res = res >> 1;
    }
    return n;
}
void testnandnminus1()
{
    int a = 16;
    cout << bitset<32>(a) << endl;
    cout << bitset<32>(a - 1) << endl;
    cout << bitset<32>((a - 1) & a) << endl;
}
void testxor(int a, int b)
{
    int c = a ^ b;
    cout << bitset<32>(a) << endl;
    cout << bitset<32>(b) << endl;
    cout << bitset<32>(c) << endl;
}
int test_distance_hanming(int x, int y)
{
    int n = 0;
    int res = x ^ y;
    while (res)
    {
        if (res & 0x1)
        {
            n++;
        }
        res = res >> 1;
    }
    return n;
}
uint32_t test_reverse_bit(uint32_t a)
{
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans += ((a & 0x1) << (31 - i));
        a >>= 1;
    }
    return ans;
}
template <class T>
void show2(T a, T b)
{
    cout << bitset<32>(a) << endl;
    cout << bitset<32>(b) << endl;
}
void show2power()
{
    for (int i = 0; i < 16; ++i)
    {
        cout << bitset<64>(pow(8, i)) << endl;
    }
}
// int maxProduct(vector<string>& words)
//  {
// unoWrdered_map<int, int> hash;
// int ans = 0;
// for (const string & word : words)
// {
// int mask = 0, size = word.size();
// for (const char & c : word) {
//     mask |= 1 << (c - 'a');
//     }
//     //cout<<"mask="<<mask<<endl;
//     cout<<"hash[mask]="<<hash[mask]<<" size="<<size<<endl;
//     hash[mask] = max(hash[mask], size);//没看懂啊
//     //cout<<"hash[mask]="<<hash[mask]<<" size="<<size<<endl;
//     for (const auto& [h_mask, h_len]: hash) {
//     if (!(mask & h_mask)) {
//     ans = max(ans, size * h_len);
// }
// }
// }
// return ans;
// }
void shownum(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << bitset<32>(i) << endl;
    }
    return;
}
vector<int> countingbits(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        if (dp[i - 1] & 1 == 1)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = dp[i >> 1];
        }
    }
    return dp;
}
void test_last_bit_and_log_right(int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((i & 1) != 1)
        {
            cout << bitset<32>(i) << endl;
            cout << bitset<32>(i >> 1) << endl;
        }
    }
}
int missingNumber(vector<int> &nums)
{
    int res = 0;
    int len = nums.size();
    res = res ^ len;
    for (int i = 0; i < len; ++i)
    {
        res = res ^ i ^ nums[i];
    }
    return res;
}

bool hasAlternatingBits(int n)
{
    int prev = 2;
    while (n)
    {
        cout << bitset<32>(n) << endl;
        int i = n & 1;
        printf("i=%d\n", i);
        printf("prev=%d\n", prev);
        if (prev == i)
        {
            return false;
        }
        n = n >> 1;
        prev = i;
    }
    return true;
}
void testfei(int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << bitset<32>(i) << endl;
        cout << bitset<32>(~i) << endl;
    }
}
int findComplement(int num)
{
    int n = num;
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ((n & 0x1) == 1)
        {
            count = max(i, count);
        }
        n = n >> 1;
    }
    // cout<<count<<endl;
    //  cout<<bitset<32>(num)<<endl;
    int res = 0;
    for (int i = 0; i < count; i++)
    {
        res = res + (((num & 0x1) ^ 1) << i);
        num = num >> 1;
    }
    cout << res << endl;
    return res;
}
void show2(int a, string str)
{
    cout << str << endl;
    cout << bitset<32>(a) << endl;
}

void testBitwiseOperation(int a)
{
    //去掉最后一位
    show2(a, "初始值");
    a = a >> 1;
    show2(a, "去掉最后一位");
    //在最后一位加个0
    a = a << 1;
    show2(a, "在最后一位加0");
    //在最后一位加个1
    a = (a << 1) + 1;
    show2(a, "在最后一位加1");
    //把最后一位变成1
    a = a | 1;
    show2(a, "把最后一位变成1");
    //把最后一位变成0
    a = (a | 1) - 1;
    show2(a, "把最后一位变成0");
    //最后一位取反
    a = a ^ 1;
    show2(a, "把最后一位取反");
    //把右数第k位变成1
    int k = 3;
    a = (a | (1 << (k - 1))); //取k-1的原因是最后1位是<<0
    show2(a, "把右数第k位变为1");
    //把右数第k位边位0
    a = (a & (~(1 << (k - 1))));
    show2(a, "把右数第k位变为0");
    //右数第k位取反    //与1一伙就是取反，与0亦或保持不动
    a = (a ^ (1 << (k - 1)));
    show2(a, "右数第k位取反");
    //取尾巴上的三位
    int b = a;
    b = b & 7;
    show2(b, "取最后三位");
    //取右边第k位,这里的4也是2的（k-1）次方
    int c = (a & 4) >> (k - 1);
    int d = (a >> (k - 1)) & 1;
    show2(c, "取右边的第k位");
    show2(d, "取右边的第k位");
}

int main()
{
    testBitwiseOperation(100);
    //findComplement(6);
    //testfei(10);
    //test_last_bit_and_log_right(100);
    //shownum(30);
    // vector<string> words={"bdcecbcadca","caafd","bcadc","eaedfcd","fcdecf","dee","bfedd","ffafd","eceaffa","caabe","fbdb","acafbccaa","cdc","ecfdebaafde","cddbabf","adc","cccce","cbbe","beedf","fafbfdcb","ceecfabedbd","aadbedeaf","cffdcfde","fbbdfdccce","ccada","fb","fa","ec","dddafded","accdda","acaad","ba","dabe","cdfcaa","caadfedd","dcdcab","fadbabace","edfdb","dbaaffdfa","efdffceeeb","aefdf","fbadcfcc","dcaeddd","baeb","beddeed","fbfdffa","eecacbbd","fcde","fcdb","eac","aceffea","ebabfffdaab","eedbd","fdeed","aeb","fbb","ad","bcafdabfbdc","cfcdf","deadfed","acdadbdcdb","fcbdbeeb","cbeb","acbcafca","abbcbcbaef","aadcafddf","bd","edcebadec","cdcbabbdacc","adabaea","dcebf","ffacdaeaeeb","afedfcadbb","aecccdfbaff","dfcfda","febb","bfffcaa","dffdbcbeacf","cfa","eedeadfafd","fcaa","addbcad","eeaaa","af","fafc","bedbbbdfae","adfecadcabe","efffdaa","bafbcbcbe","fcafabcc","ec","dbddd","edfaeabecee","fcbedad","abcddfbc","afdafb","afe","cdad","abdffbc","dbdbebdbb"};
    // maxProduct(words);
    // int mask=0;
    // string word="abcdef";

    // for (const char & c : word)
    // {
    // mask |= 1 << (c - 'a');
    // cout<<bitset<32>(c - 'a')<<endl;
    // cout<<bitset<32>(1 << (c - 'a'))<<endl;
    // cout<<bitset<32>(mask)<<endl;
    // cout<<"*****************我是分隔符"<<endl;
    // }

    return 0;
}
