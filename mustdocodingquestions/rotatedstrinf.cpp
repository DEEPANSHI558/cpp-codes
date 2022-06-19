class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isSame(string str1, string str2)
    {
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
        }
        return true;
    }
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if (str1.size() != str2.size())
            return false;
        string s1;
        string s2;

        s1 = str1.substr(str1.size() - 2, str1.size());
        s2 = str1.substr(0, str1.size() - 2);

        string s3;
        string s4;
        s3 = str1.substr(0, 2);
        s4 = str1.substr(2, str1.size());

        return isSame(s1 + s2, str2) || isSame(s4 + s3, str2);
    }
};