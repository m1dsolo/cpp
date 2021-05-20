// #include <stdio.h>
// #include <stdlib.h>
// #include "list.h"

// typedef struct person {
//     char *name;
//     int age;
// } Person;

// int main()
// {
//     char *names[] = {"yang", "zou", "liu"};
//     int ages[] = {20, 21, 22};
//     Person *persons[3];
//     for (int i = 0; i < 3; i++) {
//         persons[i] = malloc(sizeof(Person));
//         persons[i]->name = names[i];
//         persons[i]->age = ages[i];
//     }

//     List *l = new_list(NULL, 0, sizeof(Person *));
//     l->push_back(l, persons[0]);
//     l->push_back(l, persons[1]);
//     // ListIterator *le = l->end(l);
//     // for (ListIterator *lb = l->begin(l); lb->get_val(lb) != le->get_val(le); lb->pp(lb)) {
//     //     Person *p = *(Person **)lb->get_val(lb);
//     //     printf("%s\n", p->name);
//     // }

// }