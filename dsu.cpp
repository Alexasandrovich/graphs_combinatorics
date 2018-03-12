#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector <int> parent, size;
    DSU() {}
    DSU (int size) {  // создаёт массив с размерностью size, который можно увеличивать
        parent.resize(size, -1);
    }
    void print(){
        for(int i = 0; i < parent.size(); ++i){
            if(parent[i] != -1)
                cout << i << " -> " << parent[i]<< endl;
            else
                cout << i << endl;
        }
    }
    int find(int v) { // реккурсивный поиск корня элемента
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int a, int b)
    {
        a=find(a);
        b=find(b);
        if (a!=b) { // ранговая эвристика на основе размеров деревьев
            if (size[a] < size[b])
            {
                swap(a,b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }

};

int main()
{
    string str;
    DSU u(1);
    while (cin >> str) {
        if (str == "RESET") {
            int n;
            cin >> n;
            DSU u(n);
            cout << "RESET DONE" << endl;
        }
        if (str == "JOIN") {
            int a,b;
            cin >> a >> b;
            if (u.find(a)!=u.find(b)) {
                u.unite(a,b);
            } else {
                cout << "ALREADY " << a << " " << b << endl;
                }
            }
        if (str == "CHECK") {
            int a,b;
            cin >> a >> b;
            if (u.find(a)==u.find(b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return  0;
}