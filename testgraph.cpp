#include<vector>
using namespace std;
#include<iostream>
vector<int> printMatrix(vector<vector<int>> matrix)
{
    vector<int> result;
    int row = matrix.size();
    if (row == 0)
        return result;
    int col = matrix[0].size();

    int left = 0;
    int right = col - 1;
    int top = 0;
    int bottom = row - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; ++i)
            result.push_back(matrix[top][i]);

        if (top < bottom)
        {
            for (int i = top + 1; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
        }

        if (top < bottom && left < right)
        {
            for (int i = right - 1; i >= left; --i)
                result.push_back(matrix[bottom][i]);
        }

        if (top + 1 < bottom && left < right)
        {
            for (int i = bottom - 1; i >= top + 1; --i)
                result.push_back(matrix[i][left]);
        }

        left++;
        right--;
        top++;
        bottom--;
    }

    return result;
}
void print(vector<int> const &V)
{
    for (auto const &i : V)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}
int main()
{
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> v=printMatrix(matrix);
    print(v);

}