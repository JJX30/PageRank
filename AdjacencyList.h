//
// Created by Mauricio Del Castillo on 04/10/23.
//

#ifndef PAGERANK_ADJACENCYLIST_H
#define PAGERANK_ADJACENCYLIST_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <map>


using namespace std;
class AdjacencyList {

    // vars that are equal to user input
    int powIter;
    int numEdges;

    // graph of the urls from -> to
    map<string, vector<string>> adjacencyList;

    //graph of the urls to->from
    map<string, vector<string>> inDegreeList;
    // first outDegree
    // second inDegree
    map<string, pair<int,int>> degrees;

    //rankings of each URL
    map<string, double> rankings;
public:
    AdjacencyList(int powIter, int numEdges);
    void PageRank(int n);
    void insertEdge(const string& from, const string& to);
    void initRankings();
};

#endif //PAGERANK_ADJACENCYLIST_H
