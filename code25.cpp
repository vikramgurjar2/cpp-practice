#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solveSudoku(vector<vector<char>> &board)
  {
    // row[i][d] = true if digit d (1..9) used in row i
    // col[j][d] = true if digit d used in column j
    // box[b][d] = true if digit d used in box b (b = 0..8)
    vector<vector<bool>> row(9, vector<bool>(10, false));
    vector<vector<bool>> col(9, vector<bool>(10, false));
    vector<vector<bool>> box(9, vector<bool>(10, false));

    // initialize states
    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        if (board[i][j] != '.')
        {
          int d = board[i][j] - '0';     // 1..9
          int b = (i / 3) * 3 + (j / 3); // 0..8
          row[i][d] = true;
          col[j][d] = true;
          box[b][d] = true;
        }
      }
    }

    backtrack(board, row, col, box, 0, 0);
  }

private:
  bool backtrack(vector<vector<char>> &board,
                 vector<vector<bool>> &row,
                 vector<vector<bool>> &col,
                 vector<vector<bool>> &box,
                 int i, int j)
  {
    // move to next cell
    if (i == 9)
      return true; // solved
    if (j == 9)
      return backtrack(board, row, col, box, i + 1, 0);

    if (board[i][j] != '.')
    {
      return backtrack(board, row, col, box, i, j + 1);
    }

    int b = (i / 3) * 3 + (j / 3);

    for (int d = 1; d <= 9; ++d)
    {
      if (!row[i][d] && !col[j][d] && !box[b][d])
      {
        // place digit
        board[i][j] = char('0' + d);
        row[i][d] = col[j][d] = box[b][d] = true;

        if (backtrack(board, row, col, box, i, j + 1))
          return true;

        // undo (backtrack)
        board[i][j] = '.';
        row[i][d] = col[j][d] = box[b][d] = false;
      }
    }
    return false; // no digit fits here
  }
};

int main()
{
  Solution sol;
  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  sol.solveSudoku(board);

  for (const auto &row : board)
  {
    for (const auto &ch : row)
      cout << ch << ' ';
    cout << '\n';
  }
  return 0;
}
