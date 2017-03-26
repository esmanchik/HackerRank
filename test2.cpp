#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int v) {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

struct nodedist {
    int data;
    int dist;
    int level;
};

using nodedists = list<nodedist>;

void print_top_view(node *n, int d, int l, nodedists &ns)
{
    if (n == nullptr) return;
    auto nd = ns.begin();
    for (; nd != ns.end(); ++nd)
        if (nd->dist == d)
            break;
    if (nd == ns.end()) {
        ns.push_back({ n->data, d, l });
    } else {
        if (nd->level > l) {
            nd->data = n->data;
            nd->level = l;
        }
    }
    print_top_view(n->left, d - 1, l + 1, ns);
    print_top_view(n->right, d + 1, l + 1, ns);
}

void top_view(node * root)
{
    nodedists ns;
    print_top_view(root, 0, 0, ns);
    for(auto & n : ns) cout << n.data << " ";
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);
    top_view(root);
    return 0;
}
