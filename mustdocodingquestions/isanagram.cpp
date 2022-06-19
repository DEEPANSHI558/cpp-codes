class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {

        // Your code here
        if (a.size() != b.size())
        {
            return false;
        }
        unordered_map<char, int> map;
        for (int i = 0; i < a.size(); i++)
        {
            map[a[i]]++;
            map[b[i]]--;
        }
        for (auto i : map)
        {
            if (i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};