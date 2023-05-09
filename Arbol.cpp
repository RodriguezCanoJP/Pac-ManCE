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
