#include "include/list.h"

void List::push_back(int val) {
    Node *newNode = new Node;
    newNode -> value = val;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
    }
}

void List::push_front(int val) {
    Node *newNode = new Node;
    newNode -> value = val;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }
}

void List::pop_back() {
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }

    if (tail != nullptr) {
        Node *toDel = tail;

        tail = tail -> prev;
        tail -> next = nullptr;

        delete toDel;
    }
}

void List::pop_front() {
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }

    if (head != nullptr) {
        Node *toDel = head;

        head = head -> next;
        head -> prev = nullptr;

        delete toDel;
    }
}

void List::insert_before(size_t index, int val) {
    // Insert new value to list, so that it  will be at `index`-th position
    size_t i = 0;

    Node *temp = head;
    while (temp != nullptr && i != index) {
        temp = temp -> next;
        i++;
    }

    Node *newNode = new Node;
    newNode -> value = val;

    if (temp != nullptr) {
        if (temp -> prev != nullptr) {
            temp -> prev -> next = newNode;
        } else {
            head = newNode;
        }

        newNode -> next = temp;
        newNode -> prev = temp -> prev;
        temp -> prev = newNode;

    } else if (i == index) {
        head = tail = newNode;
    } else {
        // Wrong index
    }
}

int List::at(size_t index) {
    // Returns zero if there is no such value
    size_t i = 0;
    Node *temp = head;
    while (temp != nullptr && i != index) {
        temp = temp -> next;
        i++;
    }

    if (temp != nullptr) {
        return temp -> value;
    }

    return 0;
}

void List::remove(size_t index) {
    size_t i = 0;

    Node *temp = head;
    while (temp != nullptr && i != index) {
        temp = temp -> next;
        i++;
    }

    if (temp != nullptr) {
        if (temp -> prev == nullptr && temp -> next != nullptr) {
        // Remove head
            head = temp -> next;
            head -> prev = nullptr;

            delete temp;
        } else if (temp -> prev != nullptr && temp -> next == nullptr) {
        // Remove tail
            tail = temp -> prev;
            tail -> next = nullptr;
            delete temp;
        } else if (temp -> prev == nullptr && temp -> next == nullptr) {
        // Remove only one item
            delete temp;
            head = tail = nullptr;
        } else if (temp -> prev != nullptr && temp -> next != nullptr) {
        // Remove from middle
            temp -> next -> prev = temp -> prev;
            temp -> prev -> next = temp -> next;
            delete temp;
        }
    }
}

size_t List::size() {
    size_t i = 0;

    Node *temp = head;
    while (temp != nullptr) {
        temp = temp -> next;
        i++;
    }

    return i;
}

void List::display() {
    Node *temp = head;

    while (temp != nullptr) {
        std::cout << temp -> value << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;
}

void List::clear() {
    while (head != nullptr) {
        pop_back();
    }
}

void List::set(size_t index, int val) {
    size_t i = 0;

    Node *temp = head;
    while (temp != nullptr && i != index) {
        temp = temp -> next;
        i++;
    }

    if (temp != nullptr) {
        temp -> value = val;
    }
}

bool List::isEmpty() {
    return head == nullptr;
}

bool List::contains(int val) {
    Node *temp = head;

    while (temp != nullptr) {
        if (temp -> value == val) {
            return true;
        }
        temp = temp -> next;
    }

    return false;
}

bool List::contains(List &rhs) {
    Node *temp = rhs.head;

    while (temp != nullptr) {
        bool state = (this -> contains(temp -> value));
        if (!state) {
            return false;
        }
        temp = temp -> next;
    }

    return true;
}

List::~List() {
    clear();
}
