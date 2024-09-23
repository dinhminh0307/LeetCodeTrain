#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
 
// A queue node used in BFS
struct Node
{
    // (x, y) represents coordinates of a cell in the matrix
    int x, y;
 
    // `parent` stores the parent node of the current cell.
    Node* parent;
 
    Node(int x, int y, Node* parent) {
        this->x = x;
        this->y = y;
        this->parent = parent;
    }
 
    // As we are using struct as a key in a `std::set`,
    // we need to overload the below operators
 
    bool const operator==(const Node& ob) const {
        return x == ob.x && y == ob.y;
    }
 
    bool operator<(const Node& ob) const {
        return x < ob.x || (x == ob.x && y < ob.y);
    }
};
 
// Below arrays detail all four possible movements from a cell
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };
 
// The function returns false if (x, y) is not a valid position
bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N) && (y >= 0 && y < N);
}
 
// Function to print the complete path from source to destination
void findPath(Node* node, vector<pair<int,int>> &path)
{
    if (node != nullptr) {
        findPath(node->parent, path);
        path.push_back(make_pair(node->x, node->y));
    }
}
 
// Find the shortest route in a matrix from source cell (x, y) to
// destination cell (N-1, N-1)
vector<pair<int,int>> findPath(vector<vector<int>> const &matrix, int x, int y)
{
    // vector to store the shortest path
    vector<pair<int,int>> path;
 
    // `N × N` matrix
    int N = matrix.size();
 
    // base case
    if (N == 0) {
        return path;
    }
 
    // create a queue and enqueue the first node
    queue<Node*> q;
    Node* src = new Node(x, y, nullptr);
    q.push(src);
 
    // set to check if the matrix cell is visited before or not
    set<Node*> visited;
    visited.insert(src);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and process it
        Node* curr = q.front();
        q.pop();
 
        int i = curr->x;
        int j = curr->y;
 
        // if the destination is found, print the shortest path and
        // return the shortest path length
        if (i == N - 1 && j == N - 1)
        {
            findPath(curr, path);
            return path;
        }
 
        // get the value of the current cell
        int n = matrix[i][j];
 
        // check all four possible movements from the current cell
        // and recur for each valid movement
        for (int k = 0; k < 4; k++)
        {
            // get next position coordinates using the value of the current cell
            int x = i + row[k] * n;
            int y = j + col[k] * n;
 
            // check if it is possible to go to the next position
            // from the current position
            if (isValid(x, y, N))
            {
                // construct the next cell node
                Node* next = new Node(x, y, curr);
 
                // if it isn't visited yet
                if (!visited.count(next))
                {
                    // enqueue it and mark it as visited
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
    }
 
    // we reach here if the path is not possible
    return path;
}
 
template <typename T>
void printPairs(vector<pair<T,T>> const &input)
{
    int n = input.size();
    for (auto const &p: input) {
        cout << '(' << p.first << ", " << p.second << ')';
        if (--n) {
            cout << ", ";
        }
    }
}

int solution(vector<int> a, vector<int> b)
{
    vector<vector<int>> r = {a, b};
    vector<int> result;
    vector<pair<int,int>> path = findPath(r, 0, 0);

    for(auto s : findPath(r, 0, 0))
    {
        cout << r[s.first][s.second] << endl;
        result.push_back(r[s.first][s.second]);
    }
    return *std::max_element(result.begin(), result.end());
}

int main(void)
{
    vector<int> a = {1, 2, 1, 1, 1, 4}; 
    vector<int> b = {1, 1, 1, 3, 1, 1};
    cout << "Maximum value on smallest path: " << solution(a, b) << endl;
}
