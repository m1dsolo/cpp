// #include "hash_table.h"
// #include "../pair/pair.h"


// int main()
// {
//     char *names[] = {"yang", "zou", "liu"};
//     int ages[] = {20, 21, 22};
//     HashTable *ht = new_hash_table(NULL, 0, HK_STRING);
//     for (int i = 0; i < 3; i++) {
//         ht->insert(ht, new_pair(&names[i], sizeof(char *), &ages[i], sizeof(int)));
//     }

//     int a = *(int *)ht->at(ht, "yang");
//     printf("%d\n", a);
// }