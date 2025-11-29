#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
    double ratio;
};

struct Node {
    int level;
    int profit;   // giá tr? hi?n t?i
    int weight;   // tr?ng lu?ng hi?n t?i
    double bound; // c?n trên (u?c lu?ng t?i da)
};

// Tính c?n trên b?ng fractional knapsack
double bound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W) return 0;

    double profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    // l?y tr?n item khi còn ch?
    while (j < n && totweight + items[j].weight <= W) {
        totweight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }

    // l?y fractional item cu?i cùng
    if (j < n)
        profit_bound += (W - totweight) * items[j].ratio;

    return profit_bound;
}

int knapsack(int W, vector<Item> items) {
    int n = items.size();

    // s?p x?p theo value/weight gi?m d?n
    sort(items.begin(), items.end(), [](Item a, Item b) {
        return a.ratio > b.ratio;
    });

    queue<Node> Q;
    Node u, v;

    // node g?c
    v.level = -1;
    v.profit = v.weight = 0;
    v.bound = bound(v, n, W, items);

    int maxProfit = 0;
    Q.push(v);

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();

        // n?u dã xét h?t item
        if (v.level == n - 1) continue;

        // Nhánh trái: l?y item level+1
        u.level = v.level + 1;
        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].value;

        if (u.weight <= W && u.profit > maxProfit)
            maxProfit = u.profit;

        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit)
            Q.push(u);

        
        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit)
            Q.push(u);
    }

    return maxProfit;
}

int main() {
    vector<Item> items = {
        {2, 12, 12.0/2},
        {1, 10, 10.0/1},
        {3, 20, 20.0/3},
        {2, 15, 15.0/2}
    };

    int W = 5;

    cout << "Maximum value = " << knapsack(W, items) << endl;
    return 0;
}

