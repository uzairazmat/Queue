#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class Queue {
public:
    Node<T>* rear;
    Node<T>* front;

    Queue() {
        rear = nullptr;
        front = nullptr;
    }

    Queue(T data) {
        Node<T>* n = new Node<T>(data);
        rear = n;
        front = n;
    }

    void enqueue(T data) {
        Node<T>* n = new Node<T>(data);
        if (rear == nullptr) {
            rear = n;
            front = n;
        } else {
            rear->next = n;
            rear = n;
        }
    }

    void display() {
        Node<T>* temp = front;
        if (front == nullptr) {
            cout << "queue is empty" << endl;
        } else {
            while (temp != nullptr) {
                cout << temp->data << ",";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node<T>* temp = front;
        T d = front->data;
        front = front->next;
        delete temp;
        cout << d << " is deleted" << endl;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    T frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return T();
        }
        return front->data;
    }
};

int main() {
    Queue<int>* q = new Queue<int>(1);
    q->display();
    q->enqueue(10);
    q->display();
    q->enqueue(12);
    q->display();

    q->dequeue();
    q->display();

    cout << "Is queue empty? " << (q->isEmpty() ? "Yes" : "No") << endl;

    cout << "Front element of the queue: ";
    cout << q->frontElement() << endl;

    return 0;
}
