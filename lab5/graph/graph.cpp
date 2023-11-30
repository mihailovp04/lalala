#include <iostream>
#include <vector>

struct Node {
    int data;
    std::vector<Node> neighbors;

    // ����������� ��� �������� �������� ����
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

//������������ ����� ����� 1
int main() {
    // �������� �����
    std::vector<Node> graph;

    // ���������� ������ � ����
    graph.push_back(Node(1)); // ������� 1
    graph.push_back(Node(2)); // ������� 2
    graph.push_back(Node(3)); // ������� 3
    graph.push_back(Node(4)); // ������� 4

    // ���������� ���� ����� ���������
    graph[0].neighbors.push_back(graph[1]);
    graph[0].neighbors.push_back(graph[2]);
    graph[0].neighbors.push_back(graph[3]);

    graph[1].neighbors.push_back(graph[2]);

    graph[2].neighbors.push_back(graph[3]);
    graph[3].neighbors.push_back(graph[0]);

    // ����� ����� �������� ������ ��� ������ �������
    for (size_t i = 0; i < graph.size(); ++i) {
        std::cout << "neighbor vertex sum " << i + 1 << ": " << sumOfNeighbors(&graph[i]) << std::endl;
    }

    return 0;
}
/*
������� ����� 3
� ������������ ������, ��� A ����� ���� ������� ��� ���� B,
��� ��� ��� ��� B �� ����������� �������� ������� ���� A.
��� �������������� ������, ���� A � B ������ �������� �������� ���� �����.
��������� ��� ��� ���� ����������� � ���, ��� ���� ����� ��������� � ������.

� ������ ���� ���� �������������� �� �� ������ ���� ���� ������ � ���� � �������� �� ������ �������. ���������� ��� ��� �������� �� ��������������� ���� � ������
������������ ������� ��� ��� ������ ��� ����� ���������(� ����������� �� ����������) �������.
� ������ � ������������ ������ �� ������� ���� ����� ������� ���� � ��� ��� �� ������� ���������. ��� ������ ��� ����� ���� ������.


*/