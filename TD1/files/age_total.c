#include <stdio.h>

#include "famille.h"

int main()
{
}

int age_total(struct Famille obj)
{
    int total = obj.pere.age + obj.mere.age;
    for (int i = 0; i < obj.nb_enfants; i++)
    {
        total += obj.enfants[i].age;
    }
    return total;
}
