#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    // pred[i] stores the predecessor of element i in the decreasing sequence
    vector<int> pred(n * n + 2, 0);

    // Initially, all elements from 1 to n*n+1 are unassigned
    vector<int> unassigned;
    for (int i = 1; i <= n * n + 1; i++)
    {
        unassigned.push_back(i);
    }

    // Make at most n queries to narrow down the sequence
    for (int iter = 0; iter < n; iter++)
    {
        if ((int)unassigned.size() < n + 1)
            break;

        // Query: send all unassigned elements
        cout << "? " << unassigned.size();
        for (int x : unassigned)
        {
            cout << " " << x;
        }
        cout << endl;
        cout.flush();

        // Read response: first number is count, followed by visible elements
        vector<int> response(n + 2);
        for (int i = 0; i < (int)unassigned.size() + 1; i++)
        {
            cin >> response[i];
        }

        // Check for error
        if (response[0] == -1)
            return;

        int visible_count = response[0];
        vector<int> visible_indices(response.begin() + 1,
                                    response.begin() + 1 + visible_count);

        // If we found n+1 visible elements, we have our answer
        if (visible_count >= n + 1)
        {
            cout << "!";
            for (int i = 0; i < n + 1; i++)
            {
                cout << " " << visible_indices[i];
            }
            cout << endl;
            cout.flush();
            return;
        }

        // Process the response to update predecessors and unassigned elements
        vector<int> next_unassigned;
        int vp = 0; // visible pointer

        for (int u : unassigned)
        {
            if (vp < visible_indices.size() && u == visible_indices[vp])
            {
                // This element is visible, move to next visible element
                vp++;
            }
            else
            {
                // This element is hidden behind the previous visible element
                pred[u] = visible_indices[vp - 1];
                next_unassigned.push_back(u);
            }
        }

        unassigned = next_unassigned;
    }

    // Reconstruct the decreasing sequence by following predecessors
    int start = unassigned[0];
    vector<int> dec_seq;
    int curr = start;

    for (int i = 0; i < n + 1; i++)
    {
        dec_seq.push_back(curr);
        curr = pred[curr];
    }

    // Reverse to get decreasing order
    reverse(dec_seq.begin(), dec_seq.end());

    // Output the final answer
    cout << "!";
    for (int x : dec_seq)
    {
        cout << " " << x;
    }
    cout << endl;
    cout.flush();
}

int main()
{
    int t;
    if (!(cin >> t))
        return 0;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
