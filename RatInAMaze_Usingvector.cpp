void insertCurrentState(vector<vector<int>> &solution, vector<vector<int>> &ans, int n)
{
    //insert the solution matrix element by element in ans
    vector<int> currentState;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            currentState.push_back(solution[i][j]);
        }
    }

    ans.push_back(currentState);
}

void solveMaze(vector<vector<int>> &maze, vector<vector<int>> &solution, vector<vector<int>> &ans, int x, int y, int n)
{
    // base case that we reach our destination
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;
        insertCurrentState(solution, ans, n); // call to add the updated solution matrix in ans

        return;
    }

    // condition of out of boundary of the maze
    if (x > n - 1 || x < 0 || y > n - 1 || y < 0)
    {
        return;
    }

    // condition for (maze[x][y]==0) - if that particular cell is block
    //               (solution[x][y]==1) - if it is already visited or already we go through it

    if (maze[x][y] == 0 || solution[x][y] == 1)
    {
        return;
    }

    // no problem comes in visiting this cell so visit it
    solution[x][y] = 1;

    // recursive calls (call to function having same name with diff value of params)
    solveMaze(maze, solution, ans, x - 1, y, n); // up move
    solveMaze(maze, solution, ans, x + 1, y, n); // down move
    solveMaze(maze, solution, ans, x, y - 1, n); // left move
    solveMaze(maze, solution, ans, x, y + 1, n); // right move

    // backtracking if there is no further path exists
    solution[x][y] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> maze, int n)
{
    // initialize the solution matrix by all 0s
    vector<vector<int>> solution(n, vector<int>(n, 0));

    // vector used to store all the paths
    vector<vector<int>> ans;

    //final call to function to print the solutions
    solveMaze(maze, solution, ans, 0, 0, n);

    //return the updated ans
    return ans;
}
