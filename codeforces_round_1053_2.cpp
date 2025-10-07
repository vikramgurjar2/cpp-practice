#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        set<int> black_cells;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            black_cells.insert(x);
        }

        // For each person i (1 to n), execute first i commands starting from cell 1

        for (int person = 1; person <= n; person++)
        {
            int curr_cell = 1;
            if (person < 3)
            {
                for (int i = 0; i < person; i++)
                {
                    if (s[i] == 'A')
                    {
                        curr_cell++;
                    }
                    else if (s[i] == 'B')
                    {
                    }
                }
            }
        }

        // Output the result
        cout << black_cells.size() << "\n";
        bool first = true;
        for (int cell : black_cells)
        {
            if (!first)
                cout << " ";
            cout << cell;
            first = false;
        }
        cout << "\n";
    }

    return 0;
}
