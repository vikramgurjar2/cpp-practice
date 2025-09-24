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
        int white_cell = 1;

        for (int person = 1; person <= n; person++)
        {
            int current_cell = 1;

            // Execute first 'person' commands
            // start the cmd from white cell

            for (int cmd = white_cell - 1; cmd < person; cmd++)
            {
                if (cmd < person - 1)
                {
                    // check if current cell is white
                    if (black_cells.find(current_cell) == black_cells.end())
                    {
                        // color it black
                        white_cell = current_cell;
                    }
                }
                if (s[cmd] == 'A')
                {
                    current_cell++;
                }
                else
                { // s[cmd] == 'B'
                    // Find next white cell after current_cell
                    current_cell++;

                    // Use set operations for efficiency
                    auto it = black_cells.lower_bound(current_cell);
                    while (it != black_cells.end() && *it == current_cell)
                    {
                        current_cell++;
                        it++;
                    }
                }
            }

            // Color the final cell black
            black_cells.insert(current_cell);
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
