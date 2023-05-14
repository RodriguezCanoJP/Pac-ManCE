//
// Created by yitzy on 08/05/23

#include <stdio.h>
#include <iostream>

class Node {
public:
    int x;
    int y;
    Node* izquierda;
    Node* derecha;

    Node(int x, int y){
        this->x = x;
        this->y = y;
    }

    void printValues(){
        std::cout << this->x <<std::endl;
        std::cout << this->y << std::endl;
    };
};

struct ListNode {
    Node* data;
    ListNode* next;

    ListNode(Node* info) : data(info), next(nullptr) {}
};

class Queue {
private:
    ListNode* front;
    ListNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front != nullptr) {
            ListNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(Node* data) {
        ListNode* newNode = new ListNode(data);

        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "La cola está vacía" << std::endl;
        } else {
            ListNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    Node* peek() {
        if (front == nullptr) {
            std::cout << "La cola está vacía" << std::endl;
            return new Node(0,0);
        } else {
            return front->data;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void printQueue() {
        ListNode* temp = front;

        while (temp != nullptr) {
            std::cout << temp->data->x << " ";
            std::cout << temp->data->y << " ";
            std::cout << std::endl;
            temp = temp->next;
        }

        std::cout << std::endl;
    }

    ListNode* getFront(){
        return this->front;
    }
};


class Tree {
private:
    Node *root;
public:
    Tree(){
        this->root = nullptr;
    };

    void insert(int x, int y) {
        if (this->root == nullptr) {
            Node *temp = new Node(x,y);
            root = temp;
            return;
        }

        Node* current = root;
        while (true) {
            if (x < current->x) {
                if (current->izquierda == nullptr) {
                    current->izquierda = new Node(x,y);
                    return;
                }
                current = current->izquierda;
            }
            else {
                if (current->derecha == nullptr) {
                    current->derecha = new Node(x,y);
                    return;
                }
                current = current->derecha;
            }
        }
    };

    Node* getRoot(){
        return this->root;
    };

    Node* getDerechaChild(Node* node){
        return node->derecha;
    }

    Node* getIzquierdaChild(Node* node){
        return node->izquierda;
    }

    void traversePreorder(Node* node) {
        if (node != nullptr) {
            std::cout << node->x << " ";
            std::cout << node->y << " "<< std::endl;
            traversePreorder(getIzquierdaChild(node));
            traversePreorder(getDerechaChild(node));
        }
    }

    void printPreorder() {
        std::cout << "Árbol de decisiones: " << std::endl;
        traversePreorder(getRoot());
        std::cout << std::endl;
    }

    void print() {
        std::cout << "Árbol de decisiones: " << std::endl;
        levelOrderTraversal(getRoot());
        std::cout << std::endl;
    }



    void levelOrderTraversal(Node* root) {
        if (root != nullptr){

            Queue* q = new Queue();
            q->enqueue(root);

            while (!q->isEmpty()) {
                ListNode* node = q->getFront();
                q->dequeue();

                std::cout << "Imprime:" << " "<<std::endl;
                node->data->printValues();

                if (node->data->izquierda != nullptr) q->enqueue(node->data->izquierda);
                if (node->data->derecha != nullptr) q->enqueue(node->data->derecha);
            }

        }}
};





int main()
{
    Tree* myTree = new Tree();

    myTree->insert(5,5);
    myTree->insert(3,6);
    myTree->insert(6,7);
    myTree->insert(4,7);
    myTree->insert(8,7);

    myTree->printPreorder();
    myTree->print();
    return 0;
}

