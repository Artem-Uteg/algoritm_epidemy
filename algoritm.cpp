#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    Graph(int64_t n) : size(n) {
        matrix.resize(n);
        epidemy.resize(n);
        true_epidemy.resize(n);
        neighbours.resize(n);
    }

    void add_edge(int64_t v, int64_t u) {
        matrix[v].push_back(u);
        matrix[u].push_back(v);
    }

    vector<int64_t> get_vertex() {
        int64_t answer = find_vertex();

        vector<int64_t> result;

        for (size_t i = 0; i < size; ++i) 
            if (true_epidemy[i]) result.push_back(i);
        
        return result;
    }

private:
    int64_t size;
    vector<bool> epidemy;
    vector<bool> true_epidemy;
    vector<int64_t> neighbours;
    vector< vector<int64_t> > matrix;

    int64_t add_vertex(int64_t v) {
        int64_t result = 0;
        vector<int64_t> new_neighbours = neighbours;
        vector<bool> used(size), new_infected = epidemy;
        DFS(v, used, new_infected, new_neighbours, result);
        return result;
    }

    int64_t add(int64_t v) {
        int64_t result = 0;
        vector<bool> used(size);
        DFS(v, used, epidemy, neighbours, result);
        return result;
    }

    int64_t add_one_edge_vertex() {
        int64_t count = 0;
        for (size_t i = 0; i < size; ++i) {
            if (matrix[i].size() <= 1) {
                add(i);
                true_epidemy[i] = true;
                count++;
            }
        }
        return count;
    }

    void DFS(int64_t v, vector<bool>& used, vector<bool>& new_infected, vector<int64_t>& new_vertex, int64_t& result) {

        if (!new_infected[v]) {
            result++;
            new_infected[v] = true;

            for (int64_t to : matrix[v]) {
                new_vertex[to]++;
            }
        }
        
        used[v] = true;
        
        for (int64_t to : matrix[v]) {
            if (used[to]) continue;

            if (new_vertex[to] > 1) DFS(to, used, new_infected, new_vertex, result);
        }
    }

    int64_t find_vertex() {
        int64_t answer = add_one_edge_vertex(), count = 0;
        for (size_t i = 0; i < size; ++i)
            if (epidemy[i]) count++;

        while (count < size) {
            int64_t max_value = -1, opt_vertex = -1;
            
            for (size_t v = 0; v < size; ++v) {
                if (epidemy[v]) continue;
                int64_t value = add_vertex(v);
                
                if (value > max_value) {
                    opt_vertex = v;
                    max_value = value;
                }
            }
            answer++;
            count += add(opt_vertex);
            true_epidemy[opt_vertex] = true;
        }
        return answer;
    }

};
int main() {
    size_t m;
    cin >> m;

    vector< pair<int64_t, int64_t> > edges(m);
    
    int64_t n = 0, max_v;
    
    for (size_t i = 0; i < m; ++i) {
        
        cin >> edges[i].first >> edges[i].second;

        max_v = max(edges[i].first, edges[i].second);
        n = max(n, max_v);
    }

    Graph graph(n);
    
    for (auto [u, v] : edges)
        graph.add_edge(u - 1, v - 1);

    cout << '\n';

    vector<int64_t> result = graph.get_vertex();
    
    cout << result.size() << '\n';
    
    for (size_t i = 0; i < result.size() - 1; ++i)
        cout << result[i] + 1 << ", ";
    cout << result[result.size() - 1] + 1; 
    
    cout << '\n';
}
