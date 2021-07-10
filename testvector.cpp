#include <vector>
#include <iostream>
using namespace std;

void print(vector<int> const &V)
{
    for (auto const &i : V)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

//把奇术放在前半部分，偶数放在后半部分
void reOrderArrayFromLeft(vector<int> &array)
{
    //4 3 7  8 5 9 7 1   3 7 5 9 7 1 4 8
    //由
    int size = array.size();
    cout << "size=" << size << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j <= i; j++)
        {
            if (array.at(j)% 2 == 0 && array.at(j+1) % 2 == 1) //为啥这里不需要考虑数组越界？
            {
                swap(array[j], array[j + 1]);
                cout << "j+1=" << j + 1 << " "
                     << "i=" << i << endl;
            }
        }
    }
}

void reOrderArrayFromRight(vector<int> &array)
{
    //4 3 7  8 5 9 7 1   3 7 5 9 7 1 4 8
    int size = array.size();

    for (int i = 0; i < size; ++i)
    {
        for (int j = size - 1; j > i; --j)
        {
            // if (array[j] % 2 != 0 && array[j - 1] % 2 == 0)
            if (array.at(j) % 2 != 0 && array.at(j-1)% 2 == 0)
            {
                swap(array[j], array[j - 1]);
                print(array);
            }
        }
    }
}
//下面代码可能不太行
void reOrderArrayFromCarray(int *array)
{
    int size = sizeof(array) / sizeof(array[0]);
    cout << "size=" << size << endl;
    for (int i = 0; i < size + 4; ++i)
    {
        for (int j = 0; j <= i; j++)
        {
            if (array[j] % 2 == 0 && array[j + 1] % 2 == 1) //为啥这里不需要考虑数组越界？
            {
                swap(array[j], array[j + 1]);
                cout << "j+1=" << j + 1 << " "
                     << "i=" << i << endl;
            }
        }
    }
}

void reOrderArrayTwoPointers(vector<int> &array) //没有考虑之间的相对顺序
{
    int size = array.size();
    int left = 0;
    int right = size - 1;
    int stateleft = 0;
    int stateright = 0;
    while (left < right)
    {
        
        int stateleft = 0;
        int stateright = 0;
        if ((array[left] & 0x1) == 0)//左边是偶数
        {
            stateleft = 1;
        }
        if ((array[right] & 0x1) == 1) //右边是奇数
        {
            stateright = 1;
        }
        if (stateleft == 1 && stateright == 1)
        {
            swap(array[left], array[right]);
            left++;
            right--;
        }
        else if(stateright==1)
        {
            left++;
        }
        else
        {
            right--;
        }
        cout<<"right"<<stateright<<" "<<"left"<<stateleft<<endl;
        
    }
}

int main()
{

     vector<int> V1{4, 3, 7, 8, 5, 9, 7, 1, 3};
     reOrderArrayFromRight(V1);
     print(V1);
    //  reOrderArrayTwoPointers(V1);
    //  print(V1);
    //cout<<V1[9]<<endl;
    //int array[] = {4, 3, 7, 8, 5, 9, 7, 1, 3};
    // reOrderArrayFromCarray(array);
    // for(int i=0;i<9;++i)
    // {
    //     cout<<V1.at(i)<<endl;
        
    // }
    // cout <<V1.at(16) << endl;

    // vector<int> V2{4, 3, 7, 8, 5, 9, 7, 1, 6};
    // reOrderArrayFromRight(V2);
    // print(V2);
}