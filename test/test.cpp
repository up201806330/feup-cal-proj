#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "DFS.h"
#include "Kosaraju.h"
#include "KosarajuV.h"

TEST_CASE("Depth-First Search", "[reachability-dfs]"){
    DUGraph G;  
    for (size_t i = 0 ; i < 9 ; i++) G.addNode(i);
    G.addEdge(0,1); G.addEdge(1,2); G.addEdge(2,3); G.addEdge(2,4); G.addEdge(3,0);
    G.addEdge(4,5); G.addEdge(5,6); G.addEdge(6,4); G.addEdge(7,6); G.addEdge(7,8);

    Reachability *r = new DFS();
    r->initialize(&G, 0);
    r->run();
    
    REQUIRE(r->is_reachable(0) == true );
    REQUIRE(r->is_reachable(1) == true );
    REQUIRE(r->is_reachable(2) == true );
    REQUIRE(r->is_reachable(3) == true );
    REQUIRE(r->is_reachable(4) == true );
    REQUIRE(r->is_reachable(5) == true );
    REQUIRE(r->is_reachable(6) == true );
    REQUIRE(r->is_reachable(7) == false);
    REQUIRE(r->is_reachable(8) == false);

}

TEST_CASE("Graph transpose", "[graph-transpose]"){
    DUGraph G;  
    for (size_t i = 0 ; i < 9 ; i++) G.addNode(i);
    G.addEdge(0,1); G.addEdge(1,2); G.addEdge(2,3); G.addEdge(2,4); G.addEdge(3,0);
    G.addEdge(4,5); G.addEdge(5,6); G.addEdge(6,4); G.addEdge(7,6); G.addEdge(7,8);
    G = G.getTranspose();

    REQUIRE(G.getNodes() == std::list<DUGraph::node_t>({0, 1, 2, 3, 4, 5, 6, 7, 8}));
    REQUIRE(G.getAdj(0)  == std::list<DUGraph::node_t>({3}));
    REQUIRE(G.getAdj(1)  == std::list<DUGraph::node_t>({0}));
    REQUIRE(G.getAdj(2)  == std::list<DUGraph::node_t>({1}));
    REQUIRE(G.getAdj(3)  == std::list<DUGraph::node_t>({2}));
    REQUIRE(G.getAdj(4)  == std::list<DUGraph::node_t>({2,6}));
    REQUIRE(G.getAdj(5)  == std::list<DUGraph::node_t>({4}));
    REQUIRE(G.getAdj(6)  == std::list<DUGraph::node_t>({5, 7}));
    REQUIRE(G.getAdj(7)  == std::list<DUGraph::node_t>({}));
    REQUIRE(G.getAdj(8)  == std::list<DUGraph::node_t>({7}));
}


TEST_CASE("DFS on transpose", "[dfs-transpose]"){
    DUGraph G;  
    for (size_t i = 0 ; i < 9 ; i++) G.addNode(i);
    G.addEdge(0,1); G.addEdge(1,2); G.addEdge(2,3); G.addEdge(2,4); G.addEdge(3,0);
    G.addEdge(4,5); G.addEdge(5,6); G.addEdge(6,4); G.addEdge(7,6); G.addEdge(7,8);
    G = G.getTranspose();

    Reachability *r = new DFS();
    r->initialize(&G, 0);
    r->run();
    
    REQUIRE(r->is_reachable(0) == true );
    REQUIRE(r->is_reachable(1) == true );
    REQUIRE(r->is_reachable(2) == true );
    REQUIRE(r->is_reachable(3) == true );
    REQUIRE(r->is_reachable(4) == false);
    REQUIRE(r->is_reachable(5) == false);
    REQUIRE(r->is_reachable(6) == false);
    REQUIRE(r->is_reachable(7) == false);
    REQUIRE(r->is_reachable(8) == false);
}

TEST_CASE("Kosaraju variant testing", "[scc-kosarajuv]"){
    DUGraph Graph;  
    for (size_t i = 0 ; i < 9 ; i++) Graph.addNode(i);
    Graph.addEdge(0,1); Graph.addEdge(1,2); Graph.addEdge(2,3); Graph.addEdge(2,4); Graph.addEdge(3,0);
    Graph.addEdge(4,5); Graph.addEdge(5,6); Graph.addEdge(6,4); Graph.addEdge(7,6); Graph.addEdge(7,8);

    DFS r;
    KosarajuV k(&r); 
    k.initialize(&Graph, 0); 
    k.run();

    REQUIRE(k.is_scc(0) == true);
    REQUIRE(k.is_scc(1) == true);
    REQUIRE(k.is_scc(2) == true);
    REQUIRE(k.is_scc(3) == true);

    REQUIRE(k.is_scc(4) == false);
    REQUIRE(k.is_scc(5) == false);
    REQUIRE(k.is_scc(6) == false);

    REQUIRE(k.is_scc(7) == false);
    REQUIRE(k.is_scc(8) == false);

}

TEST_CASE("Classic Kosaraju testing", "[SCC-KOSARAJU]"){
    DUGraph Graph;  
    for (size_t i = 0 ; i < 9 ; i++) Graph.addNode(i);
    Graph.addEdge(0,1); Graph.addEdge(1,2); Graph.addEdge(2,3); Graph.addEdge(2,4); Graph.addEdge(3,0);
    Graph.addEdge(4,5); Graph.addEdge(5,6); Graph.addEdge(6,4); Graph.addEdge(7,6); Graph.addEdge(7,8);

    Kosaraju k; 
    k.initialize(&Graph); 
    k.run();
    REQUIRE(k.get_scc(0) == k.get_scc(1));
    REQUIRE(k.get_scc(0) == k.get_scc(2));
    REQUIRE(k.get_scc(0) == k.get_scc(3));

    REQUIRE(k.get_scc(4) == k.get_scc(5));
    REQUIRE(k.get_scc(4) == k.get_scc(6));

    REQUIRE(k.get_scc(7) == 7);

    REQUIRE(k.get_scc(8) == 8);
}
