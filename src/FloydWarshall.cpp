#include "FloydWarshall.h"

typedef DWGraph::weight_t weight_t;
typedef DWGraph::node_t node_t;
typedef DWGraph::Edge Edge;



void FloydWarshall::initialize() {

    for (size_t i = 0; i < G->getNodes().size(); ++i) {
        for (size_t j = 0; j < G->getNodes().size(); ++j) {
            this->dist[i][j] = DWGraph::INF;
            this->next[i][j] = NULL;
        }
    }

    // weight of a path from a node to itself is 0
    for (size_t i = 0; i < G->getNodes().size(); ++i) {
        this->dist[i][i] = 0;
        this->next[i][i] = i;
    }

    std::list<node_t>::const_iterator it1;
    std::list<node_t>::const_iterator it2;
    int i;
    int j;

    for (it1 = G->getNodes().begin(), i = 0; it1 != G->getNodes().end(); ++it1, ++i) {
        for (it2 = G->getNodes().begin(), j = 0; it2 != G->getNodes().end(); ++it2, ++j) {

            if (i != j) {
                this->dist[i][j] = pathWeight(*it1, *it2);
                this->next[i][j] = j;
            }
        }
    }
}

void FloydWarshall::run() {
    size_t nNodes = this->G->getNodes().size();

    for (size_t k = 0; k < nNodes; ++k) {
        for (size_t i = 0; i <  nNodes; ++i) {
            for (size_t j = 0; j < nNodes; ++j) {
                weight_t new_weight = this->dist[i][k] + this->dist[k][j];
                if (this->dist[i][j] > new_weight) {
                    this->dist[i][j] = new_weight;
                    this->next[i][j] = this->next[i][k];
                }
            }
        }
    }
}

weight_t FloydWarshall::pathWeight(DWGraph::node_t u, DWGraph::node_t v) {

    for (const Edge &e : this->G->getAdj(u)) {
        if (e.v == v) {
            return e.w;
        }
    }
    return DWGraph::INF;
}

std::list<DWGraph::node_t> FloydWarshall::getPath(DWGraph::node_t i, DWGraph::node_t j) {

    std::list<DWGraph::node_t> result;

    size_t u = i;
    size_t v = j;

    result.push_back(u);
    printf("%d ", u);

    do {
        u = next[u - 1][v - 1];
        result.push_back(u);
        printf("%d ", u);

    } while (u != v);

    return result;
}

