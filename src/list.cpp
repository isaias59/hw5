#include "list.hpp"
#include <cstring>
#include <iostream>

namespace list {

//Pre: none
//Post: Makes and returns list
Node* from_string(const char* s) {
    Node* head = nullptr;
    Node** current = &head;
    while (*s) {
        *current = new Node{*s, nullptr};
        current = &((*current)->next);
        ++s;
    }
    return head;
}

//Pre:Needs pointer
//Post: Dealloactes memort
void free(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//Pre:none
//Post:Prints list
void print(std::ostream& out, Node* head) {
    while (head) {
        out << head->data;
        head = head->next;
    }
}

//Pre: Needs pointer
//Post: Makes exavt copy
Node* copy(Node* head) {
    Node* newHead = nullptr;
    Node** newTail = &newHead;
    while (head) {
        *newTail = new Node{head->data, nullptr};
        newTail = &((*newTail)->next);
        head = head->next;
    }
    return newHead;
}

//Pre:Needs pointer
//Post: Compares two lists
int compare(Node* lhs, Node* rhs) {
    while (lhs && rhs && lhs->data == rhs->data) {
        lhs = lhs->next;
        rhs = rhs->next;
    }
    if (!lhs && !rhs) return 0; 
    if (!lhs) return -1;
    if (!rhs) return 1;  
    return lhs->data < rhs->data ? -1 : 1;
}

//Pre:None
//Post: Returns number of nodes
int length(Node* head) {
    int len = 0;
    while (head) {
        ++len;
        head = head->next;
    }
    return len;
}
//Pre: Has head pointer
//Post: Reverses node order
Node* reverse(Node* head) {
    Node* reversed = nullptr;
    while (head) {
        Node* next = head->next;
        head->next = reversed;
        reversed = head;
        head = next;
    }
    return reversed;
}

//Pre:Needs pointer
//Post: Works with new list and leaves orginal alone
Node* append(Node* lhs, Node* rhs) {
    if (!lhs) return copy(rhs); 
    Node* newHead = copy(lhs); 
    Node* tail = newHead;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = copy(rhs); 
    return newHead;
}

//Pre: needs pointer
//Post: returns position 
int index(Node* head, Node* node) {
    int idx = 0;
    while (head) {
        if (head == node) return idx;
        head = head->next;
        ++idx;
    }
    return -1;
}

//Pre:Needs pointer
//Post: Searchs through list for character
Node* find_char(Node* head, char c) {
    while (head) {
        if (head->data == c) return head;
        head = head->next;
    }
    return nullptr; 
}

//Pre:Needs two pointers
//Post:Looks for first occurance
Node* find_list(Node* haystack, Node* needle) {
    if (!needle) return haystack;
    Node* haystackStart = haystack;
    Node* needleStart = needle;
    while (haystack) {
        Node* h = haystack;
        Node* n = needle;
        while (h && n && h->data == n->data) {
            h = h->next;
            n = n->next;
        }
        if (!n) return haystackStart; 
        haystackStart = haystackStart->next;
        haystack = haystack->next;
    }
    return nullptr; 
}

//Pre: Has pointer to the head of linked list
//Post: Returns pointer
Node* nth(Node* head, int n) {
    while (n-- > 0 && head) {
        head = head->next;
    }
    return head;
}

//Pre: Pointer for the head of list
//Post: Returns pointer to last node
Node* last(Node* head) {
    if (!head) return nullptr;
    while (head->next) {
        head = head->next;
    }
    return head;
}

} 
