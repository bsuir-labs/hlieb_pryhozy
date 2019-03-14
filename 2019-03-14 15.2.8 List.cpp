#include <iostream>
#include <algorithm>
#include <time.h>

struct List
{
    int info;
    List *next, *prev;

    List() : next(nullptr), prev(nullptr)
    {}
};

void pushBack(List **first, List **last, int value)
{
    if (*first == nullptr)
    {
        *first = *last = new List;
        (*first)->info = value;
        return;
    }

    List *tmp = new List;
    tmp->info = value;
    tmp->prev = *last;
    (*last)->next = tmp;
    *last = tmp;
}

void print(List *first)
{
    if (!first)
    {
        printf("List's empty.\n");
        return;
    }

    while (first) {
        std::cout << first->info << " ";
        first = first->next;
    }
    std::cout << std::endl;
}

void generateRandomList(List** first, List** last, unsigned size = 10, unsigned seed = -1)
{
    srand(seed == -1 ? time(NULL) : seed);

    while (size--)
        pushBack(first, last, rand() % 30 - 15);
}

void removeFirstAndLast(List** first, List** last)
{
    if (*first == nullptr) return;

    if (*first == *last || (*first)->next == *last) // 1-2 elements
    {
        delete *first;
        if (*last) delete *last;
        *first = *last = nullptr;
        return;
    }

    List* to_delete = *first;
    *first = (*first)->next;
    delete to_delete;

    to_delete = *last;
    *last = (*last)->prev;
    delete to_delete;

    if (*first)
    {
        (*first)->prev = nullptr;
        (*last)->next = nullptr;
    }
}

int main()
{
    List* first, *last;
    first = last = nullptr;

    generateRandomList(&first, &last, 2);
    print(first);

    removeFirstAndLast(&first, &last);
    print(first);
    return 0;
}
