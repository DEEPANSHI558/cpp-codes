int countSmallerThanEqualTo(int mid, vector<vector<int>> &matrix)
{
    int count = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        int l = 0;
        int h = matrix[0].size() - 1;
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (matrix[i][m] <= mid)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
        count += l;
    }
    return count;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    //     here we wiil be using binary search to find the median we will place binary search in the numbers possible and find how many numbers are lesser than that number in that array and and the number of elements that are lesser that that in that in the
    int low = 0;
    int high = 1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        //         now find how many elements are smaller than this number in the matrix;
        if (countSmallerThanEqualTo(mid, matrix) <= (n * m) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}