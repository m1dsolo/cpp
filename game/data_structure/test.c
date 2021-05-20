#include "hash_table/hash_table.h"
#include "pair/pair.h"
#include "vector/vector.h"
#include "list/list.h"
#include "unordered_map/unordered_map.h"


int main()
{
    char *names[] = {"yang", "zou", "liu"};
    int ages[] = {20, 21, 22};

    UnorderedMap *um = new_unordered_map(NULL, 0, UK_STRING);
    for (int i = 0; i < 3; i++) {
        um->insert(um, new_pair(names[i], sizeof(char *), &ages[i], sizeof(int)));
    }
    UnorderedMapIterator *umi = um->begin(um);
    UnorderedMapIterator *end = um->end(um);
    um->erase(um, "zou");
    for (; umi->get_val(umi) != end->get_val(end); umi->pp(umi)) {
        Pair *p = *(Pair **)umi->get_val(umi);
        char *name = p->first(p);
        printf("%s\n", name);
    }
}