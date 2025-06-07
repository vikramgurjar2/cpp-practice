#include <iostream>
using namespace std;

void countPairs(vector<int> &nums)
{
    int n = nums.size();

    vector<string> nums_str(n);

    for (int i = 0; i < nums.size(); i++)
    {
        int t = nums[i];
        string st = to_string(t);

        int j = st.size() - 1;
        while (st[j] == '0')
        {
            j--;
        }
        string s = st.substr(0, j);
        nums_str[i] = s;
    }
    vector<string> reverse1(n);
    for (int i = 0; i < n; i++)
    {
        string s = nums_str[i];
        reverse(s.begin(), s.end());
        reverse1[i] = s;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                ans++;
            }
        }
    }
    for (auto i : nums_s)
}

int main()
{

    vector<int> nums = {3, 34, 30, 5, 6, , 8};
    countPairs(nums);

    cout << arr[1];

    return 0;
}