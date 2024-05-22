#include <iostream>
using namespace std;

// Структура вузла кільцевого однонаправленого списку
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

// Функція для виведення списку на екран
void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
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

int main() {
    Node* head = nullptr;

    // Формування списку
    appendNode(head, 1);
    appendNode(head, 3);
    appendNode(head, 5);
    appendNode(head, 7);

    // Виведення списку на екран
    cout << "Список: ";
    printList(head);

    // Перевірка, чи список впорядкований за не спаданням
    if (isSorted(head)) {
        cout << "Список впорядкований за не спаданням." << endl;
    } else {
        cout << "Список не впорядкований за не спаданням." << endl;
    }

    return 0;
}
