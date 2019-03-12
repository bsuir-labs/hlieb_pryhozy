#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

struct Stack {
    int value;
    Stack *next;
};

Stack* push(Stack* parent, int value)
{
    Stack *temp = new Stack;
    temp->value = value;
    temp->next = parent;
    return temp;
}

Stack* pop(Stack* parent, int& out)
{
    if (parent == nullptr) return nullptr;
    out = parent->value;
    Stack* tmp = parent->next;
    delete parent;
    return tmp;
}

void printStack(Stack* first)
{
    while (first != nullptr)
    {
        cout << first->value << " ";
        first = first->next;
    }
    cout << endl;
}

Stack* generateRandomStack(unsigned size = 10, unsigned seed = -1)
{
    srand(seed == -1 ? time(NULL) : seed);

    Stack* s = nullptr;
    while (size--)
        s = push(s, rand() % 30 - 15);

    return s;
}

int main()
{
    Stack* s = generateRandomStack();
    printStack(s);

    int minValue = 100;
    int minNumber = -1;
    int cnt = 0;
    Stack* ptr = s;

    while (ptr != nullptr)
    {
        if (ptr->value < minValue)
        {
            minValue = ptr->value;
            minNumber = cnt;
        }
        cnt++;
        ptr = ptr->next;
    }

    printf("Minimal value: %4d|     Answer: %d\n", minValue, minNumber);
    return 0;
}
