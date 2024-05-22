#include <gtest/gtest.h>

struct Node {
    int data;
    Node* next;
};

// Функція для створення нового вузла
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Функція для додавання вузла в кінець списку
void appendNode(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        head->next = head; // Робимо список кільцевим
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

// Функція для перевірки, чи елементи списку впорядковані за не спаданням
bool isSorted(Node* head) {
    if (!head) return true;
    Node* temp = head;
    do {
        if (temp->next != head && temp->data > temp->next->data) {
            return false;
        }
        temp = temp->next;
    } while (temp != head);
    return true;
}

TEST(CircularLinkedListTest, IsSortedTest) {
Node* head = nullptr;

// Тест: порожній список
EXPECT_TRUE(isSorted(head));

// Тест: впорядкований список
appendNode(head, 1);
appendNode(head, 3);
appendNode(head, 5);
appendNode(head, 7);
EXPECT_TRUE(isSorted(head));

// Тест: не впорядкований список
Node* head2 = nullptr;
appendNode(head2, 1);
appendNode(head2, 5);
appendNode(head2, 3);
appendNode(head2, 7);
EXPECT_FALSE(isSorted(head2));
}