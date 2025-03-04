#include <iostream>
#include <string>
using namespace std;
template <typename T>
class LinkedList {
public:
    // Класс для узла списка
    class Node {
    public:
        T data;
        Node* next;

        Node() { this->data = 0; this->next = nullptr; }

        Node(T value) { this->data = value; this->next = nullptr; }
    };

    Node* Head;

    LinkedList() { this->Head = nullptr; }
    LinkedList(Node* head) { this->Head = head; }

    void push(T value) {
        if (Head == nullptr) {
            Head = new Node(value);
        }
        else {
            Node* current = Head;

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }
    void print() {
        if (Head == nullptr) {
            cout << "Список пустой";
        }
        else {
            Node* current = Head;

            while (current->next != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << current->data << " ";
            cout << endl;
        }
    }
    T get(int index) {
        if (Head == nullptr) {
            return 0;
        }
        else {
            Node* current = Head;

            while (current->next != nullptr && index > 0) {
                current = current->next;
                index--;
            }
            return current->data;
        }
    }
    void remove(T data) {
        Node* current = Head;

        while (current->next != nullptr && current->data != data) {
            current = current->next;
        }
    }
    void removeAt(int index) {

        Node* current = Head;

        while (current->next != nullptr && index > 1) {
            current = current->next;
            index--;
        }
        Node* buffer = current->next->next;
        delete current->next;
        current->next = buffer;
    }
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        if (list.Head == nullptr) {
            os << "Список пустой";
        }
        else {
            Node* current = list.Head;

            while (current != nullptr) {
                os << current->data << " ";
                current = current->next;
            }
        }
        return os;
    }
    friend istream& operator>>(istream& istream, T value) {
        istream >> value;
        if (Head == nullptr) {
            Head = new Node(value);
        }
        else {
            Node* current = Head;

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
        }
        return istream;
    }
    T& operator[](int i) {
        Node* current = Head;
        while (i > 0) {
            current = current->next;
            i--;
        }
        return current->data;
    }
    LinkedList operator=(const LinkedList& cur) {
        this->Clean();
        Node* currentScond = cur.Head;
        while (currentScond = cur.Head) {
            this->push(currentScond->data);
            currentScond = currentScond->next;
        }
        return *this;
    }
    void Clean()
    {
        Node* current = Head;
         Node* p1;
         

        while (current != NULL) {
            p1 = current->next;

            delete current;
            current = p1;
        }
        Head = nullptr;
        
    }


};

int main() {
    setlocale(LC_ALL, "rus");
    LinkedList<int> list;
    LinkedList<int> list1;

    list.push(1);
    list.push(2);
    list.push(3);
    list.print();
    list.push(5);
    list1 = list;
    list.push(5);
    list1.print();
   

    //LinkedList<int>* list = new LinkedList<int>();
   

}
