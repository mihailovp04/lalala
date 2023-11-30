#include <iostream>
#include <vector>

struct Node {
    int data;
    std::vector<Node> neighbors;

    // Конструктор для удобного создания ноды
    Node(int d) : data(d) {}
};


int sumOfNeighbors(Node* graph) {
    int sum = 0;

    for (int i = 0; i < graph->neighbors.size(); i++)
    {
        sum += graph->neighbors[i].data;
    }


    return sum;
}

//КОНФИГУРАЦИЯ ГРАФА НОМЕР 1
int main() {
    // Создание графа
    std::vector<Node> graph;

    // Добавление вершин и рёбер
    graph.push_back(Node(1)); // Вершина 1
    graph.push_back(Node(2)); // Вершина 2
    graph.push_back(Node(3)); // Вершина 3
    graph.push_back(Node(4)); // Вершина 4

    // Добавление рёбер между вершинами
    graph[0].neighbors.push_back(graph[1]);
    graph[0].neighbors.push_back(graph[2]);
    graph[0].neighbors.push_back(graph[3]);

    graph[1].neighbors.push_back(graph[2]);

    graph[2].neighbors.push_back(graph[3]);
    graph[3].neighbors.push_back(graph[0]);

    // Вывод суммы соседних вершин для каждой вершины
    for (size_t i = 0; i < graph.size(); ++i) {
        std::cout << "neighbor vertex sum " << i + 1 << ": " << sumOfNeighbors(&graph[i]) << std::endl;
    }

    return 0;
}
/*
ЗАДАНИЕ НОМЕР 3
В направленных графах, нод A может быть соседом для нода B,
при том что нод B на обязательно является соседом нода A.
Для ненаправленных графов, ноды A и B всегда являются соседями друг друга.
Объясните как эта идея отобразится в том, как граф будет выглядеть в памяти.

В случае если граф ненаправленный то из любого нода есть доступ в ноды с которыми он связан ребрами. Получается так что движение по ненаправленному ноду в памяти
теоритически быстрее так как каждый нод имеет указатель(в зависимости от реализации) обратно.
В случае с направленным графом из каждого нода можно попасть лишь в тот нод на который указывает. Это значит что могут быть тупики.


*/