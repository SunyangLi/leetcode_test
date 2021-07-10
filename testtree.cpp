#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

void print(vector<int> vec)
{
	for (auto s : vec)
	{
		cout << s << endl;
	}
}

void printvector(vector<vector<int>> vec)
{
	for (auto s : vec)
	{
		for (auto s1 : s)
		{
			cout << s1 << " ";
		}
		cout << endl;
	}
}

std::vector<std::string> stringSplit(const std::string &str, char delim)
{
	std::stringstream ss(str);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, delim))
	{
		if (!item.empty())
		{
			elems.push_back(item);
		}
	}
	return elems;
}

//使用层级遍历法把一个字符串转化成二叉树
char SEP = ',';
char ZERO = '#';
TreeNode *ToBinaryTree(string const &str)
{
	vector<std::string> vec = stringSplit(str, ',');
	int r = stoi(vec[0]);
	TreeNode *node = new TreeNode(r);
	//cout<<node->val<<endl;
	queue<TreeNode *> que;
	que.push(node);
	int length = vec.size();
	//cout<<length<<endl;

	for (int i = 1; i < length;)
	{
		TreeNode *parent = que.front();
		que.pop();
		string left = vec[i++];

		if (left != "#")
		{

			int l = stoi(left);
			parent->left = new TreeNode(l);
			que.push(parent->left);
		}
		else
		{
			parent->left = nullptr;
		}
		if (i == length)
		{
			break;
		}
		string right = vec[i++];

		if (right != "#")
		{
			//cout<<right<<endl;
			int r = stoi(right);
			parent->right = new TreeNode(r);
			que.push(parent->right);
		}
		else
		{
			parent->right = nullptr;
		}
	}
	return node;
	//queue<TreeNode*> que;
}
//二叉树的递归
//1、不需要辅助函数   单树和双树   单树：只要利用根节点左右子树的对称性即可进行递归   双树：不需要构造函数
//2、需要辅助函数     节点子树对称性无法完全解决问题，
//                   必须要用到子树的某一部分进行递归，即要调用辅助函数比较两个部分子树。形式上主函数参数列表只有一个根节点，辅助函数参数列表有两个节点
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//一棵树由众多节点构成，如何判定两树相等或者部分包含，肯定需要一个节点一个节点进行对比
//成功的条件是比完了还没有出现不相等
//失败的条件是一个左边不够了或者是值不相等
bool hasSubTree(TreeNode *A, TreeNode *B) // A是主，B是子树，判断A中是否包含B的东西？
{
	//注意双方如果都是空那么应该是完全相等，应该算是匹配上了。
	if (B == nullptr)
		return true;
	if (A == nullptr || A->val != B->val)
		return false;
	else
		return hasSubTree(A->left, B->left) && hasSubTree(A->right, B->right);
}
//广度优先+迭代
bool isSubStructureBFS(TreeNode *A, TreeNode *B)
{
	bool ret = false;
	if (B == nullptr || A == nullptr)
		return ret;
	queue<TreeNode *> que; //创建队列
	que.push(A);		   //把原来的数据结构加入到队列中去
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			auto node = que.front();
			que.pop();
			if (node->val == B->val)
				ret = hasSubTree(node, B);
			if (ret == true)
				return ret;
			if (node->left != nullptr)
				que.push(node->left);
			if (node->right != nullptr)
				que.push(node->right);
		}
	}
	return ret;
}
//深度优先+递归
bool isSubStructureDFS(TreeNode *A, TreeNode *B)
{
	if (A == nullptr || B == nullptr)
		return false;
	bool ret = false;
	if (A->val == B->val)
		ret = hasSubTree(A, B);
	if (ret == false)
		ret = isSubStructureDFS(A->left, B) || isSubStructureDFS(A->right, B);
	return ret;
}

// c
bool helpermy(TreeNode *Node, TreeNode *B)
{
	if (B == nullptr)
	{
		return true;
	}
	if (Node == nullptr || Node->val != B->val)
	{
		return false;
	}
	return helpermy(Node->left, B->left) && helpermy(Node->right, B->right);
}

bool isSubStructuremy(TreeNode *A, TreeNode *B)
{
	//写个BFS的
	//子结构还是需要
	bool ret = false;
	if (A == nullptr || B == nullptr)
		return false;
	queue<TreeNode *> que;
	que.push(A);
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode *node = que.front();
			que.pop();
			if (node->val == B->val)
			{
				ret = helpermy(node, B);
			}

			if (ret == true)
			{
				return true;
			}
			if (node->left)
			{
				que.push(node->left);
			}
			if (node->right)
			{
				que.push(node->right);
			}
		}
	}
	return ret;
}

//对树进行映像
TreeNode *mirrorTreeRecur(TreeNode *root)
{
	// 1.递归：
	// 二叉树首先想到的方法就是递归
	// 递归终止条件：遍历到叶节点
	if (root == nullptr)
		return nullptr;
	swap(root->left, root->right);
	mirrorTreeRecur(root->left);
	mirrorTreeRecur(root->right);
	return root;
}

TreeNode *mirrorTreePreOrder(TreeNode *root)
{
	//先序遍历的方式
	if (root == nullptr)
		return nullptr;
	stack<TreeNode *> stk;
	TreeNode *node = root; //node是一根表面指针，而root带面根本的链，表面指针会在后面进行操作和改变
	while (!stk.empty() || node)
	{
		if (node)
		{
			swap(node->left, node->right);
			stk.push(node);
			node = node->left;
		}
		else
		{
			node = stk.top();
			stk.pop();
			node = node->right;
		}
	}
	return root;
}

TreeNode *mirrorTreeQueue(TreeNode *root)
{
	// 3.队列模拟层次遍历（从上到下）：
	queue<TreeNode *> q;
	q.push(root); // 根节点入队
	while (!q.empty())
	{
		TreeNode *node = q.front();
		q.pop();
		// 判断是否是叶节点，
		// 叶节点不进行子树镜像，直接进行下一个循环
		if (node == nullptr)
			continue;
		swap(node->left, node->right);
		// 已经完成子树镜像的节点的子节点入队
		q.push(node->left);
		q.push(node->right);
		// 队列先进先出
		// 入队时候是一层一层的入队
		// 所以模拟成二叉树的层次遍历
	}
	return root;
}

void preorderStack(TreeNode *root) //注意下这里与下面一个都是前序遍历
{								   //前序遍历就要在第一次入栈前把节点进行操作
	if (root == nullptr)
		return;
	TreeNode *node = root;
	stack<TreeNode *> stk;
	while (!stk.empty() || node)
	{
		if (node)
		{
			cout << node->val << endl; //这里是对节点做具体操作的
			stk.push(node);
			node = node->left;
		}
		else
		{
			node = stk.top();
			stk.pop();
			node = node->right;
		}
	}
}

void inorderStack(TreeNode *root) //注意下这里与下面一个都是前序遍历
{								  //前序遍历就要在第一次入栈前把节点进行操作
	if (root == nullptr)
		return;
	TreeNode *node = root;
	stack<TreeNode *> stk;
	while (!stk.empty() || node)
	{
		if (node)
		{

			stk.push(node);
			node = node->left;
		}
		else
		{
			node = stk.top();
			stk.pop();
			cout << node->val << endl; //这里是对节点做具体操作的
			node = node->right;
		}
	}
}

void depthFirstSearchLeftFirst(TreeNode *root)
{
	stack<TreeNode *> nodeStack; //使用C++的STL标准模板库
	nodeStack.push(root);
	TreeNode *node;
	while (!nodeStack.empty())
	{
		node = nodeStack.top();
		cout << node->val << endl; //遍历根结点
		nodeStack.pop();

		if (node->right)
		{
			nodeStack.push(node->right); //先将右子树压栈
		}
		if (node->left)
		{
			nodeStack.push(node->left); //再将左子树压栈
		}
	}
}

void depthFirstSearchRightFirst(TreeNode *root)
{
	stack<TreeNode *> nodeStack; //使用C++的STL标准模板库
	nodeStack.push(root);
	TreeNode *node;
	while (!nodeStack.empty())
	{
		node = nodeStack.top();
		cout << node->val << endl; //遍历根结点
		nodeStack.pop();
		if (node->left)
		{
			nodeStack.push(node->left); //再将左子树压栈
		}
		if (node->right)
		{
			nodeStack.push(node->right); //先将右子树压栈
		}
	}
}
bool isSymmetrical(TreeNode *lroot, TreeNode *rroot)
{
	if (!lroot && !rroot)
	{
		return true;
	}
	if (!lroot || !rroot)
	{
		return false;
	}
	if (lroot->val == rroot->val)
	{
		return isSymmetrical(lroot->left, rroot->right) && isSymmetrical(lroot->right, rroot->left);
	}
	return false;
}
bool isSymmetrical(TreeNode *root)
{
	return isSymmetrical(root->left, root->right);
}

vector<int> levelOrder(TreeNode *root)
{
	queue<TreeNode *> que;
	que.push(root);
	vector<int> res;
	while (!que.empty())
	{
		TreeNode *node = que.front();
		que.pop();
		res.push_back(node->val);
		if (node->left)
		{
			que.push(node->left);
		}
		if (node->right)
		{
			que.push(node->right);
		}
	}
	return res;
}

vector<vector<int>> levelOrderByvec(TreeNode *root)
{
	//
	queue<TreeNode *> q;
	vector<vector<int>> ans;
	if (root)
		q.push(root);
	while (!q.empty())
	{
		vector<int> vec;
		int size = q.size();
		while (size) //这里通过一个for循环可以把层次给分隔开来
		{
			TreeNode *node = q.front();
			q.pop();
			vec.push_back(node->val);
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
			size--;
		}
		ans.push_back(vec);
	}
	return ans;
}
//从左到右从右到左,注意翻转还得配合前取和后取，前驱和后驱才是真正反映那个了从左到右和从右到左，但是还需要和子树进行配合
vector<vector<int>> levelOrderByS(TreeNode *root)
{
	vector<vector<int>> res;
	if (root == NULL)
		return res;
	bool flag = true; //从左向右打印为true，从右向左打印为false
	deque<TreeNode *> q;
	q.push_back(root);
	while (!q.empty())
	{
		int n = q.size();
		vector<int> out;
		TreeNode *node;
		while (n > 0)
		{
			if (flag) // 前取后放：从左向右打印，所以从前边取，后边放入
			{

				node = q.front();
				q.pop_front();
				if (node->left)
					q.push_back(node->left); // 下一层顺序存放至尾
				if (node->right)
					q.push_back(node->right);
			}
			else //后取前放： 从右向左，从后边取，前边放入
			{
				node = q.back(); //这表示小的部分内的换一下   例如 4 5 6 7    大的反了就是   6 7 4 5
				q.pop_back();	 //小的反了就是       5 4 7 6
				if (node->right)
					q.push_front(node->right); // 下一层逆序存放至首
				if (node->left)
					q.push_front(node->left); //这里表示大的一块内得反一下
			}

			n--;
		}
		flag = !flag;
		res.push_back(out);
	}
	return res;
}

vector<vector<int>> levelOrderTest(TreeNode *root)
{
	queue<TreeNode *> q;
	vector<vector<int>> ans;
	if (root)
		q.push(root);
	int index = 0;
	while (!q.empty())
	{
		vector<int> vec;
		int size = q.size();
		for (int i = 0; i < size; i++) //这里通过一个for循环可以把层次
		{
			TreeNode *node = q.front();
			q.pop();
			vec.push_back(node->val);
			if (index == 0)
			{
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
				index = 1;
			}
			else
			{
				if (node->right)
					q.push(node->right);
				if (node->left)
					q.push(node->left);
				index = 0;
			}
		}
		ans.push_back(vec);
	}
	return ans;
}
// BS树后续遍历  后续遍历时左右种，判定失败的条件是右子树种有比根结点小的
// 因为可以不停的递归

bool VerifySquenceOfBST(vector<int> sequence, int start, int end) //前闭后开
{
	//使用前闭后开的操作
	if (start + 1 >= end)
	{
		return true;
	}
	int rear = sequence[end - 1];
	//int front = sequence[start];
	int mid = start;
	// for (int i = start; i < end; i++)
	// {
	// 	if (sequenece[i] > rear)
	// 	{
	// 		mid = i; //这里mid是取到了的，相当于是右子树了
	// 		break;
	// 	}
	// }
	while (mid < end && sequence[mid] < rear)
		mid++; //找个一个比根节点大的，若没找到，则前面全是左子树，右子树是空，
			   //还有可以mid就是节点的前一个
	for (int i = mid; i < end; i++)
	{
		if (sequence[i] < rear)
		{
			cout << " i=" << i << "sequence[i]=  " << sequence[i] << "   " << rear << endl;
			return false;
		}
	}
	return VerifySquenceOfBST(sequence, start, mid) && VerifySquenceOfBST(sequence, mid, end - 1); //这个减1是去掉根节点
}

bool VerifySquenceOfBST(vector<int> sequence)
{
	return VerifySquenceOfBST(sequence, 0, sequence.size());
}

void test1(vector<int> sequence, int start, int end)
{
	int rear = sequence[end - 1];
	//int front = sequence[start];
	int mid = start;
	for (int i = start; i < end; i++)
	{
		if (sequence[i] > rear)
		{
			mid = i; //这里mid是取到了的，相当于是右子树了
			//cout<<" i="<<i<<"sequence[i]=  "<<sequence[i]<<"   "<<rear<<endl;
			break;
		}
		if (mid == start)
		{
			mid = end - 1;
		}
	}
	cout << mid << "for loop" << endl;
	mid = start;
	while (mid < end && sequence[mid] < rear)
		mid++;
	cout << mid << "while loop" << endl;
}

//[二叉树中和为某一值的路径]
void dfsPathSum(TreeNode *node, int target, vector<vector<int>> &ret)
{

	vector<int> path;
	if (node == nullptr)
		return;
	//做选择前序遍历
	target -= node->val;
	path.push_back(target);

	if (target != 0 && node->left != nullptr && node->right != nullptr)
	{
		ret.push_back(path);
	}
	dfsPathSum(node->left, target, ret);
	dfsPathSum(node->right, target, ret);
	path.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int target)
{
	vector<vector<int>> ans;
	dfsPathSum(root, target, ans);
	return ans;
}

//把二叉搜索树变成双向排序的链表。




void test5()
{
	
}
int main()
{
	test5();
	//TreeNode *node1 = ToBinaryTree("4,8,6,12,16,14,10");
	// vector<int> vec = {4, 6, 7, 5};
	// //vector<int> vec1 = {4, 8, 6, 12, 16, 14, 10};
	// //test1(vec,0,vec.size());
	// test1(vec, 0, 1);
	// test1(vec, 1, vec.size() - 1);
	//vector<vector<int>> vec= levelOrderByvec(node1);
	//vector<vector<int>> vec=levelOrderTest(node1);
	//print(vec);
	// printvector(vec);
	//print(vec);
	//  cout<<isSymmetrical(node1)<<endl;
	// //depthFirstSearch(node1);
	// cout<<"*************"<<endl;
	// TreeNode *node2 = ToBinaryTree("1,2,3,4,5,6,7,8,9");
	// inorderStack(node2);
	//cout << isSubStructuremy(node, node1) << endl;
	// stack<TreeNode *> stk;
	// while (node)
	// {
	// 	cout << node->val << endl;
	// 	stk.push(node);
	// 	node = node->left;
	// }
	// TreeNode *p = stk.top();
	// cout << p->val << endl;
	//cout<<node->val<<endl;
}
