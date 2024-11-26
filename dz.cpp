#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

Node* InitializeList(int size) {
    Node* head = new Node(); 
    Node* current = head; 
    current->value = 0; 
    for (int i = 0; i < size - 1; i++) {
        current->next = new Node();
        current = current->next;
        current->value = 0;  
    }
    return head; 
}

Node* InitializeList(int size, int defaultValue) {
    Node* head = new Node(); 
    Node* current = head; 
    current->value = defaultValue;
    for (int i = 0; i < size - 1; i++) {
        current->next = new Node(); 
        current = current->next; 
        current->value = defaultValue;  
    }
    return head; 
}

void PrintList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int GetByIndexList(Node* head, int index) {
    Node* current = head;
    while (current != nullptr) {
        if (index == 0) {
            return current->value;
        }
        index--;
        current = current->next;
    }
    return -1;
}

void count(Node* head, int counter) {
    bool s = true;
    Node* current = head;
    while (current != nullptr) {
        if (current->value == counter) {
            cout << "find";
            s = false;
            break;
        }
        else {
            cout << "not find";
        }
    }
}

int max(Node* head) {
    int max = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->value > max) {
            max = current->value;
            current = current->next;
        }
        return max;
    }
}
int MinOfList(Node* head) {
    int min = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->value < min) {
            min = current->value;
            current = current->next;
        }
        return min;
    }

}

int SumOfList(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->value;
        current = current->next;

    }
    return sum;
}
Node* DeleteElementFromList(Node* head, int index) {
    Node* current = head;
    while (current != nullptr) {
        if (1 == index) {
            Node* rep = current->next;
            current->next = current->next->next;
            delete rep;
        }
        index--;

        return head;
    }

}

Node* CopyList(Node* head) {
    Node* current = head;
    Node* cur = head;
    cur = current;
    return cur;

}
void SwapList(Node*& head, int index1, int index2) {
    Node* current = head;
    Node* current1 = head;
    Node* Index1Node = nullptr;
    Node* Index2Node = nullptr;
    int ind1 = 0; int ind2 = 0;

    while (current != nullptr) {
        if (ind1 == index1) {
            cout << current << endl;
            Index1Node = current;
            break;

        }
        else {
            ind1++;
            current = current->next;
        }




    }
    while (current1 != nullptr) {
        if (ind2 == index2) {
            cout << 't';
            Index2Node = current1;
            break;
        }
        else {
            ind2++;
            current1 = current1->next;
        }


    }

    int buf = Index1Node->value;
    Index1Node->value = Index2Node->value;
    Index1Node->value = buf;
    cout << Index1Node->value;
    cout << Index2Node->value;
    cout << Index1Node << endl;
    PrintList(head);
}

void DeleteList(Node* head) {

    Node* current = head;
    current = current->next;
    while (head->next != nullptr) {

        while (current->next->next != nullptr) {
            current = current->next;

        }
        delete current->next->next;
        current->next = nullptr;

    }
    delete head;
}
/*void StaticArrayToList(int array[], int size) {
    Node* head = new Node();
    Node* current = head;
    while (current != nullptr) {
        for (int i = 0; i < size; i++) {
            array[i] = current->value;

        }


    }


}*/

/*Node* DynamicArrayToList(int* array, int size) {


}*/
int main()
{
    int array[5];
    Node* test = InitializeList(5, 1);
    Node* test1 = InitializeList(5, 2);
    test1->value = 0;
    test1->next->value = 1;
    test1->next->next->value = 2;
    test1->next->next->next->value = 3;
    test1->next->next->next->next->value = 4;


    //PrintList(test);
    //count(test, 1);
    //cout << endl;
    //cout << max(test) << end
    //DeleteList(test);
    //StaticArrayToList(array,5);
    //PrintList(test);
    SwapList(test1, 2, 3);
    PrintList(test1);
}

