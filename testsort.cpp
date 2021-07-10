#include "include.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
int countout = 0;
int countin = 0;
void quickSortIn(vector<int> &nums, int l, int r)
{

    //取最左边位基准
    if (l >= r)
        return;
    // 哨兵划分操作（以 arr[l] 作为基准数）
    int i = l, j = r;

    while (i < j)
    {
        while (i < j && nums[j] >= nums[l])
        {
            j--;
        }
        while (i < j && nums[i] <= nums[l])
        {
            i++;
        }
        cout << nums[i] << " " << nums[l] << endl;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[i]);
    quickSortIn(nums, l, i - 1);
    quickSortIn(nums, i + 1, r);
}
void quickSortOut(vector<int> &nums)
{
    quickSortIn(nums, 0, nums.size() - 1);
}
vector<int> randVector(int n)
{
    vector<int> res;
    unsigned seed;
    seed = time(0);
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000 + 1;
        res.push_back(x);
    }
    return res;
}

vector<int> getLeastNumbers(vector<int> &arr, int k)
{
    vector<int> vec(k, 0);
    if (k == 0)
    { // 排除 0 的情况
        return vec;
    }
    priority_queue<int> Q;
    for (int i = 0; i < k; ++i)
    {
        Q.push(arr[i]);
    }
    for (int i = k; i < (int)arr.size(); ++i)
    {
        if (Q.top() > arr[i])
        { //最大的换掉
            Q.pop();
            Q.push(arr[i]);
        }
    }
    for (int i = 0; i < k; ++i)
    {
        vec[i] = Q.top();
        Q.pop();
    }
    return vec;
}
void merge(vector<int> &nums, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    int size = r - l;
    vector<int> res(size + 1, 0);
    while (i <= mid && j <= r)
    {
        if (nums[i] <= nums[j])
        {
            res[k++] = nums[i++];
        }
        else
        {
            res[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        res[k++] = nums[i++];
    }
    while (j <= r)
    {
        res[k++] = nums[j++];
    }
    for (int t = 0; t < k; t++)
    {
        nums[l++]=res[t];
    }
}
void mergeSort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + ((r - l) >> 1);
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    merge(nums, l, mid, r);
}

int main()
{

    vector<int> nums = {4, 345, 35, 232, 53, 1, 20, 33, 18, 90};
    mergeSort(nums, 0, nums.size() - 1);
    printOneD(nums);
}