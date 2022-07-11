// time complexity is log2(m*10^d) where d is the decimal places upto which we want the ans
double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans = ans * number;
    }
    return ans;
}
double findNthRootOfM(int n, long long m)
{
    // Write your code here.
    double low = 1;
    double high = m;
    double eps = 1e-7; // means they are differentiating only one decimal place after 6 decimal places we stop

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) > m)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return high;
}
