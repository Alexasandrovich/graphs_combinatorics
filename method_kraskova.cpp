#include <iostream>
#include <vector>
//#include <tuple>
//#include <algorithm>
//vector<tuple<int,int,int>> t;
//sort(t.begin(), t.end());
//vector.push_back(make_tuple(a,b,c));
//get<0>(vector[i]);

using namespace std;

vector<int> graph;

class Rebro
{
public: int a, b, c; // вершины и вес
    Rebro() {};
    Rebro(int a, int b, int c): a(a), b(b), c(c) {}
};

bool compare(const Rebro& a, const Rebro& b)
{
    if (a.c - b.c > 0)
    {
        return 1;
    } else if (a.c - b.c < 0)
        return -1;
           else return 0;
}

int find(int v) { // реккурсивный поиск корня элемента
    if (v == graph[v])
        return v;
    return graph[v] = find(graph[v]);
}
bool unite(int a, int b)
{
    a=find(a);
    b=find(b);
    if (a==b)
        return false;
    if (a!=b)
        graph[a]=b;
        return true;
}
int main()
{
    int n; // кол-во вершин
    cin >> n;
    vector<int> graph;

}