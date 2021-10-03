#include <iostream>
#include <vector>
#define INF 99999
using namespace std;
vector<vector<int>> v{ { 0, 4, 1, 3 },{ 4, 0, 2, 1 },{ 1, 2, 0, 5 },{ 3, 1, 5, 0 } };
vector<int> erase(vector<int> v, int j)
{
    v.erase(v.begin() + j);
    vector<int> vv = v;
    return vv;
}
int TSP(vector<int> neighbor, int index)
{
    if (neighbor.size() == 0)
        return v[index][0];
    int min = INF;
    for (int j = 0; j < neighbor.size(); j++)
    {
        int cost = v[index][neighbor[j]] + TSP(erase(neighbor, j), neighbor[j]);
        if (cost < min)
            min = cost;
    }
    return min;
}
int main()
{
    vector<int> neighbor{ 1, 2, 3 };
    cout << TSP(neighbor, 0) << endl;
    return 0;
}
