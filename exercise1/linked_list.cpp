#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> struct node {
    int num;
    int numCount;
    struct node<T> * next = NULL;
};

template <class T> struct linked_list {
    struct node<T> * head = NULL;
    int size = 0;
};

// get node item at position i
template <class T> struct node<T> * access_node(linked_list<T> &linked_list, int i) {
    if (i < 0 || i >= linked_list.size) throw out_of_range("the index is out of range");
    struct node<T> *current = linked_list.head;
    for (int k = 0; k < i; k++) current = current->next;
    return current;
}

// get node num at position i
template <class T> T accessNum(linked_list<T> &linked_list, int i) {
    struct node<T> *item = access_node(linked_list, i);
    return item->num;
}


//get node numCount at position i
template <class T> T accessNumCount(linked_list<T> &linked_list, int i) {
    struct node<T> *item = access_node(linked_list, i);
    return item->numCount;
}

// increase the numCount of item i
template <class T> void increaseNumCount(linked_list<T> &linked_list, int i) {
    struct node<T> *item = access_node(linked_list, i);
    item->numCount = item->numCount + 1;
}


// get the position of item x
template <class T> int search(linked_list<T> &linked_list, int x) {
    struct node<T> *current = linked_list.head;
    int i = 0;
    while (current != NULL) {
        if (current->num == x) return i;
        i++;
        current = current->next;
    }
    return -1;
}

// append item x at the end of the list
template <class T> void push_back(linked_list<T> &l, T x) {
    struct node<T> *new_node, *current;
    new_node = new node<T>();
    new_node->num = x;
    new_node->numCount = 1;
    new_node->next = NULL;
    current = l.head;
    if (current == NULL) {
        l.head = new_node;
        l.size++;  
    } else {
        while (current->next != NULL) current = current->next;
    current->next = new_node;
    l.size++;
    }
}

// append item x and y after position i
template<class T> void insert_after(linked_list<T> &linked_list, int i, int x, int y) {
    if (i < 0 || i >= linked_list.size) throw out_of_range("the index is out of range");
    struct node<T> *ptr = access_node(linked_list, i);
    struct node<T> *new_node = new node<T>();
    new_node->num = x;
    new_node->numCount = y;
    new_node->next = ptr->next;
    ptr->next = new_node;
    linked_list.size++;
}

// append item x and y at the head
template <class T> void insert_head(linked_list<T> &linked_list, int x, int y) {
    struct node<T> *new_node = new node<T>();
    new_node->num = x;
    new_node->numCount = y;
    new_node->next = linked_list.head;
    linked_list.head = new_node;
    linked_list.size++;
}

// append item x and y at position i
template <class T> void insert(linked_list<T> &linked_list, int i, int x, int y) {
    if (i == 0) {
        insert_head(linked_list, x, y);
    }
    else { 
        insert_after(linked_list, i - 1, x, y);
    }
}

// delete the item at position i
template <class T> void delete_item(linked_list<T> &l, int i) {
    if (i < 0 || i >= l.size) throw out_of_range("the index is out of range");
    if (i == 0) {
        struct node<T> *ptr = l.head;
        l.head = ptr->next;
        delete ptr;
    } else {
        struct node<T> *ptr = access_node(l, i - 1);
        struct node<T> *to_be_deleted = ptr->next;
        ptr->next = to_be_deleted->next;
        delete to_be_deleted;
    }
    l.size--;
}

// prints the list of numbers, also prints the number counts if withCount is true
template <class T> void print_list(linked_list<T> &l, bool withCount) {
    struct node<T> *current = l.head;
    if (withCount) {
        cout << "histogram: ";
        while (current != NULL) {
            cout << "[";
            cout << current->num << ", ";
            cout << current->numCount << "] ";
            current = current->next;
        }
    } else {
        cout << "L: ";
        while (current != NULL) {
            cout << current->num << ", ";
            current = current->next;
        }
    }
    cout << endl;
}