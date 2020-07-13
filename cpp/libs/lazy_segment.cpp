#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector <int> tree(4 * N), lazy(4 * N, 0), a(N);

int apply(int node, int val) {
    tree[node] += val;
    lazy[node] += val;
}


void push(int node) {
    if(lazy[node] != 0) {
        apply(2 * node, lazy[node]);
        apply(2 * node + 1, lazy[node]);
        lazy[node] = 0;
    }
}

void build(int node, int left, int right) {
    if(left == right) {
        tree[node] = a[left];
    } else {
        int mid = (left + right) / 2;
        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int left, int right, int l, int r, int val) {
    if(left > r || right < l) return;
    if(left >= l && right <= r) {
        apply(node, val);
        return;
    }
    int mid = (left + right) / 2;
    // push lazy node down and compute further
    push(node);
    update(2 * node, left, mid, l, r, val);
    update(2 * node + 1, mid + 1, right, l, r, val);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int left, int right) {
    if(left == right) {
        return left;
    }
    int mid = (left + right) / 2;
    push(node);
    int res = -1;
    if(tree[2 * node + 1] == 0) {
        res = query(2 * node + 1, mid + 1, right);
    } else {
        res = query(2 * node, left, mid);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    return res;
}


int main() {

}