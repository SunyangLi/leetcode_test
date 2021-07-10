/* STL 最大堆、最小堆的应用 */
#include <iostream>
#include <vector>
#include <algorithm> //
#include <queue>
using namespace std;

/*
STL 堆操作
（1）make_heap()构造堆
void make_heap(first_pointer,end_pointer,compare_function);
默认比较函数是(<)，即最大堆。
函数的作用是将[begin,end)内的元素处理成堆的结构

（2）push_heap()添加元素到堆
void push_heap(first_pointer,end_pointer,compare_function);
新添加一个元素在末尾，然后重新调整堆序。该算法必须是在一个已经满足堆序的条件下。
先在vector的末尾添加元素，再调用push_heap

（3）pop_heap()从堆中移出元素
void pop_heap(first_pointer,end_pointer,compare_function);
把堆顶元素取出来，放到了数组或者是vector的末尾。
要取走，则可以使用底部容器（vector）提供的pop_back()函数。
先调用pop_heap再从vector中pop_back元素

（4）sort_heap()对整个堆排序
排序之后的元素就不再是一个合法的堆了。
*/

//最大堆
struct MaxHeapCmp
{
    inline bool operator()(const int &x, const int &y)
    {
        return x < y;
    }
};

//最小堆
struct MinHeapCmp
{
    inline bool operator()(const int &x, const int &y)
    {
        return x > y;
    }
};

void test()
{
    std::vector<int> data{3, 1, 7, 4, 99, 75, 34, 10};

    //堆排序
    std::make_heap(data.begin(), data.end(), MinHeapCmp());
    for (int n : data)
    {
        cout << n << endl;
    }

    printf("------------------\n");

    sort_heap(data.begin(), data.end(), MaxHeapCmp());
    for (int n : data)
    {
        cout << n << endl;
    }

    printf("2*------------------\n");

    //添加元素
    data.push_back(111);
    //再次堆排序
    std::push_heap(data.begin(), data.end(), MaxHeapCmp());
    for (int n : data)
    {
        cout << n << endl;
    }
}

// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index)
{
    int left = 2 * index + 1;  // index的左子节点
    int right = 2 * index + 2; // index的右子节点

    int maxIdx = index;
    if (left < len && arr[left] > arr[maxIdx])
        maxIdx = left;
    if (right < len && arr[right] > arr[maxIdx])
        maxIdx = right;

    if (maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
}

// 堆排序
void heapSort(vector<int> &arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }

    // 调整大根堆
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]); // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);    // 将未完成排序的部分继续进行堆排序
    }
}
void test1()
{
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}
void copyAdjust(vector<int> &nums, int size, int index)
{
    int l = 2 * index + 1;
    int r = 2 * index + 2; //这里表示的是根节点从0开始
    int maxIndex = index;
    if (l < size && nums[l] > nums[maxIndex])
        maxIndex = l;
    if (r < size && nums[r] > nums[maxIndex])
        maxIndex = r;
    if (maxIndex != index)
    {
        swap(nums[index], nums[maxIndex]);
        copyAdjust(nums, size, maxIndex);
    }
}

void copySortHeap(vector<int> &nums)
{
    //初步构造堆
    for (int i = nums.size() / 2 - 1; i >= 0; --i) //可以取画张图就知道了,root呀需要取到
    {
        copyAdjust(nums, nums.size(), i);  
    }
    for (int i = nums.size() - 1; i > 0; --i)
    {
        swap(nums[0], nums[i]);
        copyAdjust(nums, i, 0); //为啥这里是0????? 因尾秩序要动根节点
    }
}

void copyAdjustBy1(vector<int> &nums, int size, int index)
{
    int l = 2 * index;
    int r = 2 * index+1; //这里表示的是根节点从0开始
    int maxIndex = index;
    if (l < size && nums[l] > nums[maxIndex])
        maxIndex = l;
    if (r < size && nums[r] > nums[maxIndex])
        maxIndex = r;
    if (maxIndex != index)
    {
        swap(nums[index], nums[maxIndex]);
        copyAdjust(nums, size, maxIndex);
    }
}

void copySortHeapBy1(vector<int> &nums)  //not finished
{
    //初步构造堆
    for (int i = nums.size() / 2 - 1; i >= 0; --i) //可以取画张图就知道了,root呀需要取到
    {
        copyAdjust(nums, nums.size(), i);  
    }
    for (int i = nums.size()-1; i >0; --i)
    {
        swap(nums[0], nums[i]);
        copyAdjust(nums, i, 0); //为啥这里是0????? 因尾秩序要动根节点
    }
}
void test3()
{
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    copySortHeap(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}
void test5()
{
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    copySortHeapBy1(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

//堆排序  升序采用大顶堆，降序采用小顶堆


int a[500001];

void adjust(int v, int n)
{
    for (int i = 2 * v; i <= n; i = i * 2)
    {
        if (i + 1 <= n && a[i] < a[i + 1]) //修改当前的节点信息后
            i++;                           //可能导致整个树失衡，
                                           //应该继续往下调整，使下面调整过的依然满足大顶堆
        if (a[i] > a[v])
        {
            swap(a[i], a[v]);
            v = i;
        }
        else
        {
            break;
        }
    }
}

void slove(int n)
{
    for (int i = n / 2; i >= 1; i--) //从第一个非叶子节点进行调整，
    {                                //叶子全都不用考虑，因为在调整其父节点时会处理叶子节点
        adjust(i, n);
    }

    for (int i = n; i > 1; i--) //每次把a[1]也就是最大的元素放到数组最后，
    {                           //并把数组顺序减一，因为不能再调整已经交换过的点了
        swap(a[i], a[1]);
        adjust(1, i - 1);
    }
}

void test4()
{
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    slove(n);

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}

class MedianFinder
{
public:
    // 最大堆，存储左边一半的数据，堆顶为最大值
    priority_queue<int, vector<int>, less<int>> maxHeap; //可以有一个，也就可以是三个
    // 最小堆， 存储右边一半的数据，堆顶为最小值
    priority_queue<int, vector<int>, greater<int>> minHeap;
    /** initialize your data structure here. */
    MedianFinder()
    {
    }
    //优先队列和队列的操作一样都是对尾进，队首出，只不过那些出来的是最大的
    // 维持堆数据平衡，并保证左边堆的最大值小于或等于右边堆的最小值
    void addNum(int num)
    {
        /*
         * 当两堆的数据个数相等时候，左边堆添加元素。
         * 采用的方法不是直接将数据插入左边堆，而是将数据先插入右边堆，算法调整后
         * 将堆顶的数据插入到左边堆，这样保证左边堆插入的元素始终是右边堆的最小值。
         * 同理左边数据多，往右边堆添加数据的时候，先将数据放入左边堆，选出最大值放到右边堆中。
         */
        if (maxHeap.size() == minHeap.size())
        {
            minHeap.push(num); //右边的堆
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
        else
        {
            maxHeap.push(num); //左边的堆
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) * 1.0 / 2;
        }
        else
        {
            return maxHeap.top() * 1.0;
        }
    }
};

int main()
{
    test5();
    printf("-ok-\n");
    getchar();

    return 0;
}

// int main()
// {

//     return 0;
// }