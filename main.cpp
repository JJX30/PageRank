#include <iostream>
#include "AdjacencyList.h"

using namespace std;
int main()
{
    int numLines, power_iter;

    string from, to;
    cin >> numLines;
    cin >> power_iter;

    // This initializes the adjacenct list that will have all the data
    AdjacencyList graph(power_iter, numLines);

    // loop through all the inputs and add them as edges to the graph
    for(int i = 0; i < numLines; i++)
    {
        cin >> from;
        cin >> to;

        // insert edges from and to
        graph.insertEdge(from, to);
    }

    // initialize rankings with correct number of power iterations
    graph.initRankings();

    // print out the rankings with the url in alphabetical order
    graph.PageRank(power_iter);
    return 0;
}