// 12.2 Erase and Push Front.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// ConsoleApplication2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
        Node(int val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* first = nullptr;
    Node* last = nullptr;
    unsigned int num_elems = 0;

public:
    List() {
        first = nullptr;
        last = nullptr;
        num_elems = 0;
    }
    ~List() {
        while (first != nullptr) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
    }

    //Push Back == insertar al final
    void push_back( const int& value) {
        Node* newNode = new Node(value);
        if (last == nullptr) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
        num_elems++;
    }

    //Push Front == insertar al princicio
    void push_front( int valor)
    {
        Node* nuevo_n = new Node(valor);
        //Posicion == 0
        if (first == nullptr) //num_elements == 0
        {
            first = last = nuevo_n;
            first->value = valor;
            first->prev = nullptr;
            first->next = nullptr;
        }
        else {
            nuevo_n->next = first;
            first = last = nuevo_n;
            first = nuevo_n;
        }
        num_elems++;
    }

    //Erase, eliminar un valor y mover los demas para rellenar el hueco
    void erase(int posicion)
    {
        if (posicion == 0)
        {
            //Si queremos eliminar la primera posicion
        }
        else { //Si la posicion no es la primera
            Node* current = first;
            unsigned int index = 0;
            //Para encontrar que posicion es
            while (index < posicion) {
                current = current->next;
                index++;
            }
            //Una vez la tenemos
            int aux = current->value;
            for (int i = index; i < num_elems; i++)
            {
                current->value = aux;
                while (current->next != nullptr)
                {
                    aux = current->next->value;
                }
                current->value = current->next->value;
            }
        }
        num_elems--;
    }
    void insert(unsigned int position, const int& value) {
        if (position == 0) {
            Node* newNode = new Node(value);
            if (first == nullptr) {
                first = last = newNode;
            }
            else {
                newNode->next = first;
                first->prev = newNode;
                first = newNode;
            }
            num_elems++;
        }
        else if (position >= num_elems) {
            push_back(value);
        }
        else {
            Node* current = first;
            unsigned int index = 0;
            while (index < position) {
                current = current->next;
                index++;
            }
            Node* newNode = new Node(value);
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != nullptr) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
            num_elems++;
        }
    }

    void print() const {
        Node* current = first;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
        cout << "Numero de elementos: " << num_elems << endl << endl;
    };

    void recursivePrint(Node current) const {    }

};


int main() {
    List myList;
    cout << "Push Back (1):" << endl;
    myList.push_back(1);
    myList.print();

    cout << "Insert num 0 en posicion 3 (3, 0):" << endl;
    myList.insert(3, 0);
    myList.print();

    cout << "Insert num 2 en posicion 2 (2, 2):" << endl;
    myList.insert(2, 2);
    myList.print();

    cout << "Push Front (1)" << endl;
    myList.push_front(1);
    myList.print();

    cout << "Push Front (1)" << endl;
    myList.push_front(0);
    myList.print();

    cout << "Erase posicion 1 (1)" << endl;
    myList.erase(2);
    myList.print();

    return 0;
}
