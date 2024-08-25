/*
 * ShortestPath v1.0.0
 * Updated: 2024-08-24
 * --------------------------------------------
 * Created by Luis on 2024-08-22
 */

#include <cstring>
#include "catch.hpp"
#include "Node.h"

TEST_CASE("Node", "Node<T>"){

    SECTION("Default Constructor"){
        Node<int> * newNode = new Node<int>();

        // ToDo: Think of test: newNode.getData() == empty
        REQUIRE(newNode->getNextNode() == nullptr);
        REQUIRE(newNode->getPreviousNode() == nullptr);
        delete newNode;
    }

    SECTION("Constructor - Assign `node.data` (w/ `data`)"){
        Node<int> * newNode_A = new Node<int>(8);
        REQUIRE(*(newNode_A->getData()) == 8);

        Node<int> * newNode_B;
        newNode_B = new Node<int>(15);
        REQUIRE(*(newNode_B->getData()) == 15);

        delete newNode_A;
        delete newNode_B;
    }

    SECTION("Constructor - Assign `node.data` (w/ `node`)"){
        Node<int> * newNode_A = new Node<int>(18);

        Node<int> * newNode_B = new Node<int>(*newNode_A);
        REQUIRE(*(newNode_B->getData()) == 18);

        delete newNode_A;
        delete newNode_B;
    }

    SECTION("Constructor - Assign `node.data`, `node.next`, `node.previous` (w/ 3x `node`)"){

        Node<int> * nodeA = new Node<int>(12);
        Node<int> * nodeB = new Node<int>(*nodeA, nullptr, nullptr);

        REQUIRE(*(nodeB->getData()) == 12);
        REQUIRE(*(nodeA->getData()) == *(nodeB->getData()));

        delete nodeA;
        delete nodeB;
    }

    SECTION("Setter/Getter - Next Node"){
        Node<int> * nodeA = new Node<int>(12);
        Node<int> * nodeB = new Node<int>(15);

        nodeA->setNextNode(nodeB);
        REQUIRE(nodeA->getNextNode() == nodeB);
        REQUIRE(nodeA->getNextNode()->getData() == nodeB->getData());

        delete nodeA;
        delete nodeB;
    }

    SECTION("Setter/Getter - Previous Node"){
        Node<int> * nodeA = new Node<int>(12);
        Node<int> * nodeB = new Node<int>(15);

        nodeA->setPreviousNode(nodeB);
        REQUIRE(nodeA->getPreviousNode() == nodeB);
        REQUIRE(nodeA->getPreviousNode()->getData() == nodeB->getData());

        delete nodeA;
        delete nodeB;
    }
}