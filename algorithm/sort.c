#include "sort.h"

void sort(Vector *v, SORT_TYPE st)
{
    switch (st) {
        case ST_BUBBLE: sort_bubble(v); break;
        case ST_SELECT: sort_select(v); break;
        case ST_INSERTION: sort_insertion(v); break;
        case ST_QUICK: sort_quick(v); break;
    }
}

void print_vector(Vector *v)
{
    for (int i = 0; i < v->size(v); i++) {
        printf("%d ", *(int *)v->at(v, i));
        if (i % 4 == 3)
            printf("\n");
    }
    printf("\n");
}

void print_vector_vector(Vector *v)
{
    for (int i = 0; i < v->size(v); i++) {
        Vector *tmp = v->at(v, i);
        for (int j = 0; j < tmp->size(tmp); j++) {
            printf("%d ", *(int *)tmp->at(tmp, j));
        }
        printf("\n");
    }
}

// 比较相邻两个元素，值大的放在右边, O(n ^ 2)
static void sort_bubble(Vector *v)
{
    for (int i = 0; i < v->size(v); i++) {
        for (int j = 0; j < v->size(v) - 1 - i; j++) {
            int a = *(int *)v->at(v, j);
            int b = *(int *)v->at(v, j + 1);
            if (a > b)
                swap_by_index(v, j, j + 1);
        }
    }
}

// 每次从i到结尾遍历，将最小值提到前面, O(n ^ 2)
static void sort_select(Vector *v)
{
    for (int i = 0; i < v->size(v); i++) {
        int min = INT_MAX;
        int index = 0;
        for (int j = i; j < v->size(v); j++) {
            int *a = v->at(v, j);
            if (*a < min) {
                min = *a;
                index = j;
            }
        }
        swap_by_index(v, i, index);
    }
}

// 每次将一个数插入前面已经排好的序列中
static void sort_insertion(Vector *v)
{
    for (int i = 1; i < v->size(v); i++) {
        for (int j = i; j > 0; j--) {
            int *a = v->at(v, j);
            int *b = v->at(v, j - 1);
            if (*a < *b)
                swap_by_index(v, j - 1, j);
            else
                break;
        }
    }
}

// 分治法，平均O(n * log(n))， 最坏O(n * n)
static void sort_quick(Vector *v)
{
    sort_quick_helper(v, 0, v->size(v) - 1);
}

static void swap_by_index(Vector *v, int i, int j)
{
    int *a = v->at(v, i);
    int *b = v->at(v, j);
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 开辟堆内存应该效率低
static void swap_by_pointer(void *i, void *j, size_t size)
{
    void *tmp = malloc(sizeof(size));

    memcpy(tmp, i, size);
    memcpy(i, j, size);
    memcpy(j, tmp, size);

    free(tmp);
}

// 是不是不会出现left > right的情况？即left != right时就退出while结束了
// 结论：若将所有关于left和right之间的判断改为是否相等，而不是left大于right，会出现错误
// 由于vector实现问题，需要多次rptr = v->at(v, right)这种动作，不过问题不大。
static void sort_quick_helper(Vector *v, int left, int right)
{
    if (left >= right)
        return;

    int save_left = left;
    int save_right = right;

    int pivot = *(int *)v->at(v, left);

    int *lptr, *rptr;
    while (left < right) {
        lptr = v->at(v, left);
        rptr = v->at(v, right);
        while (left < right && *rptr > pivot) {
            right--;
            rptr = v->at(v, right);
        }
        if (left < right)
            *lptr = *rptr;
        while (left < right && *lptr < pivot) {
            left++;
            lptr = v->at(v, left);
        }
        if (left < right)
            *rptr = *lptr;
        if (left >= right)
            *lptr = pivot;            
    }

    // left == right
    sort_quick_helper(v, save_left, left - 1);
    sort_quick_helper(v, right + 1, save_right);
}


//
//

Vector *full_permutation(Vector *v)
{
    Vector *rst = new_vector(NULL, 0, sizeof(Vector));
    Vector *tmp = new_vector(NULL, 0, sizeof(int));

    full_permutation_helper(v, tmp, rst);

    return rst;
}

static void full_permutation_helper(Vector *v, Vector *tmp, Vector *rst)
{
    if (tmp->size(tmp) == v->size(v)) {
        rst->push_back_vector(rst, tmp);
        return;
    }
    
    for (int i = 0; i < v->size(v); i++) {
        int *val = v->at(v, i);
        int tmp_val = *val;
        if (*val == INT_MIN)
            continue;
        
        tmp->push_back(tmp, val);
        *val = INT_MIN;

        full_permutation_helper(v, tmp, rst);

        *val = tmp_val;
        tmp->pop_back(tmp);
    }
}
