//
// Created by Mauricio Del Castillo on 04/10/23.
//
#include <iomanip>
#include <algorithm>
#include "AdjacencyList.h"

// returns 1 if string a is alphabetically
// less than string b
bool mycomp(string a, string b){
    return a<b;
}

AdjacencyList::AdjacencyList(int powIter, int numEdges) {
    // constructing the obj
    this->powIter = powIter;
    this->numEdges = numEdges;
}
void AdjacencyList::PageRank(int n) {
    // iterator to use to iterate through graph
    map<string, vector<string>>::iterator it;

    // vector to sort the urls strings
    vector<string> pages;
    for (it = this->adjacencyList.begin(); it != this->adjacencyList.end(); it++)
    {
        // pushing key url strings into the vector
        pages.push_back(it->first);
    }

    // sort function to alphabetize the list of url strings
    sort(pages.begin(), pages.end(), mycomp);

    // rounding the rankings and formatting the values to print out
    for(const auto& i: pages){
        double plus = this->rankings[i] + 0.005;
        double d = stod(to_string(plus).substr(0,4));
        cout << i <<" ";
        cout << fixed;
        cout << setprecision(2);
        cout << d << endl;
    }
}

void AdjacencyList::insertEdge(const string& from, const string& to) {
    // first outDegree
    // second inDegree
    this->adjacencyList[from].push_back(to);
    this->inDegreeList[to].push_back(from);

    // increment out degree when there is a from, because a from means that there is an out degree
    this->degrees[from].first++;

    // same goes for the in degree
    this->degrees[to].second++;
    if(this->adjacencyList.find(to) == this->adjacencyList.end()){
        this->adjacencyList[to] = {};
    }
    // if the FROM word isn't in the in degree map yet, then make it go into the map but with an empty list.
    if(this->inDegreeList.find(from) == this->inDegreeList.end()){
        this->inDegreeList[from] = {};
    }
}

void AdjacencyList::initRankings() {
    map<string, vector<string>>::iterator it;

    // Fill rankings with default rankings 1/size of graph
    for (it = this->adjacencyList.begin(); it != this->adjacencyList.end(); it++)
    {
        // it->first returns the key aka website name
        this->rankings[it->first] = (double)(1.0/(double)(this->adjacencyList.size()));
    }

    map<string, double> temp;
    while(this->powIter > 1){
        for (it = this->adjacencyList.begin(); it != this->adjacencyList.end(); it++)
        {
            // it->first returns the key aka website name
            temp[it->first] = 0.0;
            for (int i = 0; i < this->inDegreeList[it->first].size(); i++){
                temp[it->first] += ((double) this->rankings[this->inDegreeList[it->first][i]]) / ((double) this->degrees[this->inDegreeList[it->first][i]].first);
            }
        }
        rankings = temp;
        this->powIter--;
    }
}
