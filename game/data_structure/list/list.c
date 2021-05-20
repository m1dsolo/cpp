#include "list.h"
#include "_list.h"


List *new_list(void *vals, int num, size_t val_size)
{
    List *l = malloc(sizeof(List));

    l->_private = new_list_private(vals, num, val_size);

    // 增
    l->push_front = list_push_front;
    l->push_back = list_push_back;
    // 删
    l->pop_front = list_pop_front;
    l->pop_back = list_pop_back;
    l->erase = list_erase;
    // 改
    l->front = list_front;
    l->back = list_back;
    // 查
    l->size = list_size;
    l->empty = list_empty;
    // itarator
    l->begin = list_begin;
    l->end = list_end;
    l->rbegin = list_rbegin;
    l->rend = list_rend;

    return l;
}

static _ListPrivate *new_list_private(void *vals, int num, size_t val_size)
{
    _ListPrivate *lp = malloc(sizeof(_ListPrivate));

    lp->num = num;
    lp->dummy_node = new_list_node(NULL, NULL, NULL, val_size);
    lp->val_size = val_size;

    ListNode *cur_node = lp->dummy_node;
    for (int i = 0; i < num; i++) {
        void *ptr = &((void **)vals)[i * val_size / sizeof(void *)];
        cur_node->next = new_list_node(ptr, cur_node, NULL, val_size);
        cur_node = cur_node->next;
    }

    lp->final_node = cur_node;
    lp->final_node->next = lp->dummy_node;
    lp->dummy_node->prev = lp->final_node;

    return lp;
}

static ListIterator *new_list_iterator(ListNode *node)
{
    ListIterator *li = malloc(sizeof(ListIterator));

    li->_private = new_list_iterator_private(node);
    li->pp = list_iterator_pp;
    li->mm = list_iterator_mm;
    li->get_val = list_iterator_get_val;

    return li;
}

static _ListIteratorPrivate *new_list_iterator_private(ListNode *node)
{
    _ListIteratorPrivate *lip = malloc(sizeof(_ListIteratorPrivate));

    lip->node = node;

    return lip;
}

ListNode *new_list_node(void *val, ListNode *prev, ListNode *next, size_t val_size)
{
    ListNode *node = malloc(sizeof(ListNode));

    node->val = malloc(val_size);
    if (!val)
        memset(node->val, 0, val_size);
    else
        memcpy(node->val, val, val_size);
    node->prev = prev;
    node->next = next;

    return node;
}

void delete_list_node(ListNode *node)
{
    free(node->val);
    node->val = NULL;
    node->next = NULL;
    node->prev = NULL;
    free(node);
}

static size_t list_size(List *l)
{
    _ListPrivate *lp = l->_private;

    return lp->num;
}

static bool list_empty(List *l)
{
    _ListPrivate *lp = l->_private;

    return lp->num == 0;
}

static void list_pop_front(List *l)
{
    _ListPrivate *lp = l->_private;

    if (lp->num == 0)
        return;

    ListNode *tmp = lp->dummy_node->next->next;
    delete_list_node(lp->dummy_node->next);
    lp->dummy_node->next = tmp;
    lp->num--;
}

static void list_pop_back(List *l)
{
    _ListPrivate *lp = l->_private;

    if (lp->num == 0)
        return;

    ListNode *tmp = lp->final_node->prev;
    delete_list_node(lp->final_node);
    lp->final_node = tmp;
    lp->num--;
}

static void list_push_front(List *l, void *val)
{
    _ListPrivate *lp = l->_private;

    lp->dummy_node->next = new_list_node(val, lp->dummy_node, lp->dummy_node->next, lp->val_size);
    lp->num++;
} 

static void list_push_back(List *l, void *val)
{
    _ListPrivate *lp = l->_private;

    lp->final_node->next = new_list_node(val, lp->final_node, lp->dummy_node, lp->val_size);
    lp->final_node = lp->final_node->next;
    lp->num++;
} 

static void *list_front(List *l)
{
    _ListPrivate *lp = l->_private;

    return lp->dummy_node->next->val;
}

static void *list_back(List *l)
{
    _ListPrivate *lp = l->_private;

    return lp->final_node->val;
}

static ListIterator *list_erase(List *l, ListIterator *li)
{
    _ListPrivate *lp = l->_private;
    _ListIteratorPrivate *lip = li->_private;
    
    lip->node->prev->next = lip->node->next;
    lip->node = lip->node->next;
    delete_list_node(lip->node->prev);

    lp->num--;

    return li;
}

static ListIterator *list_begin(List *l)
{
    _ListPrivate *lp = l->_private;
    ListIterator *li = new_list_iterator(lp->dummy_node->next);

    return li;
}

static ListIterator *list_end(List *l)
{
    _ListPrivate *lp = l->_private;
    ListIterator *li = new_list_iterator(lp->dummy_node);

    return li;
}

static ListIterator *list_rbegin(List *l)
{
    _ListPrivate *lp = l->_private;
    ListIterator *li = new_list_iterator(lp->final_node);

    return li;
}

static ListIterator *list_rend(List *l)
{
    _ListPrivate *lp = l->_private;
    ListIterator *li = new_list_iterator(lp->dummy_node);

    return li;
}

static void list_iterator_pp(ListIterator *li)
{
    _ListIteratorPrivate *lip = li->_private;

    lip->node = lip->node->next;
}

static void list_iterator_mm(ListIterator *li)
{
    _ListIteratorPrivate *lip = li->_private;

    lip->node = lip->node->prev;
}

static void *list_iterator_get_val(ListIterator *li)
{
    _ListIteratorPrivate *lip = li->_private;

    return lip->node->val;
}

#ifdef debug
static void my_error(char *s)
{
    perror(s);
    exit(EXIT_FAILURE);
}
#endif