#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

class graph 
{
    private:
    int n; 
    int last_vert; 
    bool directed; 
    std::vector<std::unordered_set<int>> adj; 
    std::vector<std::string> label; 

    public:
    graph(int n, bool directed = false)
        : n(n), last_vert(0), directed(directed), adj(n), label(n) {}

    bool add_vertex(const std::string& name = "") 
    {
        if (last_vert < n) {
            label[last_vert++] = name;
            return true;
        }
        return false;
    }

    bool add_edge(int u, int v) 
    {
        if (u < last_vert && v < last_vert) 
        {
            adj[u].insert(v);
            if (!directed) adj[v].insert(u);
            return true;
        }
        return false;
    }

    bool has_edge(int u, int v) const 
    {
        if (u < last_vert && v < last_vert)
            return adj[u].count(v) > 0;
        return false;
    }

    void print_raw() const 
    {
        for (int i = 0; i < last_vert; i++)
        {
            std::cout << i;
            if (!label[i].empty()) std::cout << " (\"" << label[i] << "\")";
            std::cout << " -> ";
            for (auto v : adj[i]) std::cout << v << " ";
            std::cout << "\n";
        }
    }
};