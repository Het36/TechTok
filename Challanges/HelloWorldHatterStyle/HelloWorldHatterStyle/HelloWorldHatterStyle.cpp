// HelloWorldHatterStyle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct HWorld {
    char ltr;
    HWorld *next;
};

class Stack {
private:
    HWorld* top;
public:
    Stack();
    ~Stack();
    void AddToBack(char a);
    void Display(ostream& out);
};

Stack::Stack() {

    top = nullptr;
}

Stack::~Stack() {
    HWorld* p = nullptr;

    while (top->next != nullptr) {
        p = top;
        top = top->next;
        delete p;
    }
}

void Stack::AddToBack(char a) {
    HWorld* Letter = new HWorld;
    Letter->ltr = a;
    Letter->next = nullptr;

    if (top == nullptr) {
        top = Letter;
    }
    else {
        HWorld* p = top;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = Letter;
    }

}

Stack* Word(const char a[], const int Letter_Count) {
    Stack* Word1 = new Stack;
    for (int i = 0; i < Letter_Count; i++) {
        Word1->AddToBack(a[i]);
    }
    return Word1;
}

void Stack::Display(ostream& out) {
    HWorld *p = top;
    while (p != nullptr) {
        out << p->ltr;
        p = p->next;
    }
}

Stack Word1;
Stack Word2;

int main()
{


    const int Letter_Count = 5;
    char Hello[Letter_Count] = {
        'H',
        'e',
        'l',
        'l',
        'o'

    };

    char World[Letter_Count] = {
        'W',
        'o',
        'r',
        'l',
        'd'
    };

    Word1 = *Word(Hello, Letter_Count);
    Word1.Display(cout);
    cout << " ";
    Word2 = *Word(World, Letter_Count);
    Word2.Display(cout);


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
