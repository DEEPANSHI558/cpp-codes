bool isSafe(bool graph[101][101], int m, int n, int node, int color[], int col)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[i][node] && color[i] == col && i != node)
            return false;
    }
    return true;
}
bool helper(bool graph[101][101], int m, int n, int node, int color[])
{
    if (node == n)
    {
        return true; // means we have reaches all the possible solutions of the
    }
    // trying out for each colo at each node so
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(graph, m, n, node, color, i))
        {
            color[node] = i;
            if (helper(graph, m, n, node + 1, color))
                return true; // if we find one possible ans we return from here otherwise backtrack
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    // every vertex has a map associated with it where it can fill a particular element  or not if it is not possible then return 0 and if it is possible then return 1
    int color[n] = {0}; // we are keeping this to check which node is filled with which color  abhi we are putting no color in this
    if (helper(graph, m, n, 0, color))
        return true;
    return false;
}