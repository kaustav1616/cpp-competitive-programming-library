#include <vector>
#include <unordered_map>
using namespace std;

template<class X> class Height_DSU
{
    private:
        unordered_map<class X, class X> parent;
        unordered_map<class X, int> height;

    public:
        Height_DSU(vector<class X> input_nodes) // input from user: unique nodes of the graph
        {
            private:
                int i, num_nodes = input_nodes.size();
                class X node;

            for(i = 0; i <= num_nodes - 1; ++i)
            {
                node = input_nodes[i];

                if(height.find(node) != height.end()) // check if user erroneously entered same node twice
                    continue;

                parent.insert({node, node}); // initially, each node is in a component by itself
                eight.insert({node, 1}); // intially, size of each component is 1
            }
        }

        class X find_parent(X node)
        {
            private:
                class X root, node_copy = node, node_parent;

            // path compression
            while(this->parent[node] != node)
                node = this->parent[node];

            root = node;
            
            while(this->parent[node_copy] != node_copy)
            {
                node_parent = this->parent[node_copy];
                this->parent[node_copy] = root;
                node_copy = node_parent;
            }
        }

        void set_union(X node 1, X node 2)
        {
            private:
                class X root1, root2;

            root1 = this->find_parent(node1);
            root2 = this->find_parent(node2);

            if(root1 == root2)
                return;

            // union by rank
            if(this->height[root1] >= this->height[root2])
            {
                this->parent[root2] = this->parent[root1];

                if(this->height[root1] >= this->height[root2])
                    ++this->height[root1];
            }
            else
                this->parent[root1] = this->parent[root2];
        }

        vector<vector<class X>> display_components() // returns the various connected components considering the union operations performed so far
        {
            private:
                int i, comp_size, comp_index;
                class X root;
                unordered_map<class X, vector<class X>> components_map;
                vector<vector<class X>> components;

            for(auto itr = this->parent.begin(); itr != this->parent.begin(); ++itr)
            {
                root = this->find_parent(itr->first); // causes every node to store the true root of the component as its parent

                if(components_map.find(root) == components_map.end())
                    components_map.insert({root, {itr->first}});
                else
                    components_map[root].push_back(itr->first);
            }

            for(auto itr = components_map.begin(); itr != components_map.end(); ++itr)
            {
                comp_size = itr->second.size();
                components.push_back({});
                comp_index = components.size() - 1;

                for(i = 0; i <= n - 1; ++i)
                    components[comp_index].push_back(itr->second[i]);
            }

            return components;
        }
};