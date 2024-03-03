#include <iostream>
#include <climits>

using namespace std;


class List {
protected:
    struct Node {
        int v;
        Node* next;

        Node(int v, Node* next) :
            v(v),
            next(next)
        {        }

        Node(int v) :
            v(v),
            next(nullptr)
        {

        }
    };
    Node* head;
public:
    static int size;
    List(int v) : head(new Node(INT_MAX))
    {
        head->next = new Node(v);
        size++;
    }

    List() : head(new Node(INT_MAX))
    {
        size++;
    }

    ~List()
    {
        if (head->next) clear();
        delete head;
        --size;
    }

    void push_back(int v)
    {
        if (!head->next) {
            head->next = new Node(v);
        }
        else {
            Node* t = head->next;
            while (t->next) t = t->next;
            t->next = new Node(v);
        }
    }

    void clear()
    {
        try {
            if (!head->next) {
                throw "List is empty!";
            }
            Node* t, * b = head;
            t = head->next;
            while (t) {
                b = t;
                t = t->next;
                delete(b);
                b = nullptr;
            }
            head->next = nullptr;
        }
        catch (const char* exception) {
            cerr << "ERROR:" << exception << endl;
        }
    }

    void print()
    {
        try {
            if (!head->next) {
                throw "List is empty!";
            }
            Node* t = head->next;
            while (t) {
                cout << t->v;
                t = t->next;
            }
        }
        catch (const char* exception) {
            cerr << "ERROR:" << exception << endl;
        }
    }
};

class Queue : public List {
public:
    int pop()
    {
        try {
            if (!head->next) {
                throw "List is empty!";
            }
            Node* t = head->next;
            head->next = t->next;
            int c = t->v;
            cout << c ;
            delete(t);
            t = nullptr;
            return c;
        }
        catch (const char* exception) {
            cerr << "ERROR:" << exception << endl;
        }
    }
};

class Stack : public List {
public:
    int pop()
    {
        try {
            if (!head->next) {
                throw "List is empty!";
            }
            Node* t = head->next;
            while (t->next->next) t = t->next;
            int c = t->next->v;
            delete(t->next);
            t->next = nullptr;
            return c;
        }
        catch (const char* exception) {
            cerr << "ERROR:" << exception << endl;
        }
    }
};

int List::size = 0;


int main()
{
    Stack s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(4);
    s.push_back(7);
    s.push_back(6);
    s.pop();
    s.print();
    cout << endl;
    cout << "Count of Lists:" << s.size << endl;
    Queue t;
    t.push_back(1);
    t.push_back(3);
    t.push_back(2);
    t.push_back(4);
    t.push_back(7);
    t.push_back(6);
    t.pop();
    t.print();
    cout << endl;
   cout << "Count of Lists:" << t.size << endl;
    return 0;
}
