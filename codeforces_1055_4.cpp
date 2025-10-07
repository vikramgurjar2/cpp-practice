#include <iostream>
#include <vector>
using namespace std;

void temp(const vector<long long> &source, vector<long long> &cumulative)
{
    int size = source.size();
    cumulative[0] = 0;

    for (int i = 1; i < size; i++)
    {
        cumulative[i] = cumulative[i - 1] + source[i];
    }
}
long long res(long long value)
{
    long long depth = 0;

    for (;;)
    {
        depth++;
        long long halved = value >> 1; // Bit shift instead of division

        if (halved <= 1)
            return depth;

        value = halved + 1;
    }
}

bool sp(long long value)
{
    if (value < 3)
        return false;

    value--; // Check if (value - 1) is power of two

    int bits = 0;
    long long temp = value;

    while (temp)
    {
        temp &= (temp - 1);
        bits++;
    }

    return bits == 1;
}

long long range_query(const vector<long long> &cumulative, int start, int end)
{
    return cumulative[end] - cumulative[start - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_count;
    cin >> test_count;

    while (test_count--)
    {
        int size, query_count;
        cin >> size >> query_count;

        vector<long long> elements(size + 1);
        for (int i = 1; i <= size; i++)
        {
            cin >> elements[i];
        }

        vector<long long> depth_values(size + 1);
        vector<long long> special_flags(size + 1);

        for (int i = 1; i <= size; i++)
        {
            depth_values[i] = res(elements[i]);
            special_flags[i] = sp(elements[i]) ? 1 : 0;
        }

        vector<long long> depth_c(size + 1);
        vector<long long> flag_c(size + 1);

        temp(depth_values, depth_c);
        temp(special_flags, flag_c);

        for (int q = 0; q < query_count; q++)
        {
            int left_bound, right_bound;
            cin >> left_bound >> right_bound;

            long long depth_sum = range_query(depth_c, left_bound, right_bound);
            long long flag_sum = range_query(flag_c, left_bound, right_bound);

            long long final_answer = depth_sum + (flag_sum / 2);

            cout << final_answer << "\n";
        }
    }

    return 0;
}