#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

class weightedGraph 
{
    private:
    int n;
    int last_vert;
    bool directed;
    std::vector<std::unordered_map<int, std::vector<double>>> adj;
    std::vector<std::string> label;

    public:
    weightedGraph(int n, bool directed = false)
        : n(n), last_vert(0), directed(directed), adj(n), label(n) {}

    bool add_vertex(const std::string& name = "") 
    {
        if (last_vert < n)
        {
            label[last_vert++] = name;
            return true;
        }
        return false;
    }

    bool add_edge(int u, int v, double weight) 
    {
        if (u < last_vert && v < last_vert) 
        {
            adj[u][v].push_back(weight);
            if (!directed) adj[v][u].push_back(weight);
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
        for (int i = 0; i < adj.size(); i++) 
        {
            std::cout << i;
            for (auto& edge : adj[i])
            {
                int dest = edge.first;
                const std::vector<double>& weights = edge.second;

                std::cout << " -> (" << dest << ": [";
                for (size_t j = 0; j < weights.size(); j++) 
                {
                    std::cout << weights[j];
                    if (j + 1 < weights.size()) std::cout << ", ";
                }
                std::cout << "])";
            }
            std::cout << std::endl;
        }
    }

};