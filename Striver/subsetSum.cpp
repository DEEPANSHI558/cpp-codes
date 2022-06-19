void helper(vector<int> num, vector<int> &output, int index, int sum, int n)
{
    if (index == n)
    {
        output.push_back(sum);
        return;
    }
    //     we have to options to pick an index and to not pick and index
    helper(num, output, index + 1, sum + num[index], n);
    //     not pick an element
    helper(num, output, index + 1, sum, n);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> output;
    helper(num, output, 0, 0, num.size());
    sort(output.begin(), output.end());
    return output;
}