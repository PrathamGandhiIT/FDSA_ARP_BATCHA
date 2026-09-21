#include <iostream>
#include <string>
using namespace std;

struct node{
    string song;
    node* next;
    node* prev;

       node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Songslist {
    node* head;
    node* tail;

public:
    Songslist() {
        head = NULL;
        tail = NULL;
    }

    void addbeg(string s) {
        node* n = new node(s);

        if (head == NULL) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

     void addEnd(string s) {
        node* n = new node(s);

        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }


    void insertat(string target, string s) {
        node* temp = head;

        while (temp != NULL && temp->song != target) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found" << endl;
            return;
        }

        node* n = new node(s);

        n->prev = temp;
        n->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = n;
        else
            tail = n;

        temp->next = n;
    }

    void rfirst() {
        if (head == NULL)
            return;

        node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    int count() {
        int c = 0;
        node* temp = head;

        while (temp != NULL) {
            c++;
            temp = temp->next;
        }

        return c;
    }

    void display() {
        node* temp = head;

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Songslist p;

    p.addbeg("A");
    p.display();

    p.addEnd("B");
    p.display();

    p.addEnd("C");
    p.display();

    p.insertat("B", "X");
    p.display();

    cout << "Count: " << p.count() << endl;

    p.rfirst();
    p.display();

    cout << "Count: " << p.count() << endl;

    return 0;
}
