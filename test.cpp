/*
 * ShortestPath v1.0.0
 * Updated: 2024-08-24
 * --------------------------------------------
 * Created by Luis on 2024-08-22
 */

#include <cstring>
#include <string>
#include "catch.hpp"
#include "Node.h"
#include "LinkedList.h"

using std::string;

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

    SECTION("Linked Nodes"){
        Node<int> * nodeA = new Node<int>(12);

        Node<int> * nodeB = new Node<int>(18);

        Node<int> * nodeC = new Node<int>(15);

        // nullptr<-nodeA[12]<->nodeB[18]->nullptr
        nodeB->setPreviousNode(nodeA);
        nodeA->setNextNode(nodeB);
        REQUIRE(*(nodeA->getNextNode()->getData()) == 18);
        REQUIRE(*(nodeB->getPreviousNode()->getData()) == 12);

        // nullptr<-nodeA[12]<->nodeB[18]<->nodeC[15]->nullptr
        nodeC->setPreviousNode(nodeB);
        nodeB->setNextNode(nodeC);
        REQUIRE(*(nodeB->getNextNode()->getData()) == 15);
        REQUIRE(*(nodeC->getPreviousNode()->getData()) == 18);

        // nullptr<-nodeA[12]<->nodeB[18]<->nodeC[15]<->nodeD[10]->nullptr
        Node<int> * nodeD = new Node<int>(Node<int>(10),nullptr, nodeC);
        nodeC->setNextNode(nodeD);

        REQUIRE(*(nodeD->getData()) == 10);
        REQUIRE(*(nodeD->getPreviousNode()->getData()) == 15);
        REQUIRE(*(nodeC->getNextNode()->getData()) == 10);

        delete nodeA;
        delete nodeB;
        delete nodeC;
        delete nodeD;
    }
}

TEST_CASE("LinkedList", "LinkedList<T>"){

    SECTION("Default Constructor") {
        SECTION("Common Scenario") {
            LinkedList<string> * myList = new LinkedList<string>();

            REQUIRE(myList->getLinkedList_head() == nullptr);
            REQUIRE(myList->getLinkedList_tail() == nullptr);
            REQUIRE(myList->getLinkedList_iterator() == nullptr);
            REQUIRE(myList->getListSize() == 0);

            Node<string> * null_node = nullptr;

            REQUIRE(myList->getLinkedList_head()->getData() == null_node->getData());

            delete myList;
            delete null_node;

        }SECTION("Other") {
            LinkedList<Node<string>> * myList = new LinkedList<Node<string>>();

            REQUIRE(myList->getLinkedList_head() == nullptr);
            REQUIRE(myList->getLinkedList_tail() == nullptr);
            REQUIRE(myList->getLinkedList_iterator() == nullptr);
            REQUIRE(myList->getListSize() == 0);

            Node<Node<string>> * null_node = nullptr;
            REQUIRE(myList->getLinkedList_head()->getData() == null_node->getData());

            delete myList;
            delete null_node;
        }
    }

    SECTION("Append to LinkedList"){
        LinkedList<string>* myList = new LinkedList<string>();

        myList->append("string");
        REQUIRE(*(myList->getLinkedList_head()->getData()) == "string");

        myList->append("string2");
        REQUIRE(*(myList->getLinkedList_head()->getData()) == "string");
        REQUIRE(*(myList->getLinkedList_tail()->getData()) == "string2");

        myList->append("string3");
        REQUIRE(*(myList->getLinkedList_head()->getData()) == "string");
        REQUIRE(*(myList->getLinkedList_tail()->getData()) == "string3");

        REQUIRE(myList->getAt(0) == "string");
        REQUIRE(myList->getAt(1) == "string2");
        REQUIRE(myList->getAt(2) == "string3");

        delete myList;
    }
}