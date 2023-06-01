#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Number of cities
int numCities = 6;

// Find the vertex with the minimum distance value
int findMinDistance(const vector<int> &distances, const vector<bool> &visited)
{
    int minDistance = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < numCities; v++)
    {
        if (!visited[v] && distances[v] <= minDistance)
        {
            minDistance = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Print the shortest path distances from the source city
void printDistance(const vector<int> &distances, int sourceCity)
{
    for (int i = 0; i < numCities; i++)
    {
        cout << "Shortest time from city " << sourceCity << " to city " << i << " = " << distances[i] << endl;
    }
}

// Dijkstra's algorithm to find the shortest path
void dijkstra(const vector<vector<int> > &graph, int srcCity)
{
    vector<int> distances(numCities);
    vector<bool> visited(numCities);

    for (int i = 0; i < numCities; i++){
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[srcCity] = 0;

    for (int i = 0; i < numCities - 1; i++)
    {
        int u = findMinDistance(distances, visited);
        visited[u] = true;

        for (int v = 0; v < numCities; v++)
        {
            if (!visited[v] && graph[u][v] && distances[u] != INT64_MAX &&
                distances[u] + graph[u][v] < distances[v])
            {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    printDistance(distances, srcCity);
}

int main()
{
    vector<vector<int> > graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}};

    dijkstra(graph, 0);

    return 0;
}