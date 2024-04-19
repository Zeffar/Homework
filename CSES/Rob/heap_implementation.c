#include <stdio.h>
#define MAX_SIZE 25000
#define size a[0]
typedef struct
{
    int a[MAX_SIZE];
} heap;
// 2*i
// 2<<1

//2*i+1
//2<<1|1
// 2*i+2
// 2<<1 + 2
void swap(int *x, int *y)
{
    *x = *x ^ *y ^ (*y = *x);
}

void insert(heap *h, int x)
{
    if (h->size > MAX_SIZE)
    {
        printf("Heap is full\n");
        return;
    }
    
    h->size++;
    h->a[h->size] = x;

    int index = h->size;
    while (index > 1 && h->a[index] < h->a[index/2])
    {
        swap(&h->a[index], &h->a[index/2]);
        index/=2; 
    }
}

int pop(heap *h)
{
    if (!h->size)
    {
        printf("Heap is empty\n");
        return -1; 
    }

    int root = h->a[1];

    h->a[1] = h->a[h->size];
    h->size--;

    int index=1;
    while(1)
    {
        int left = index*2;   
        int right = index*2+1; 
        int smallest = index;
        if (left <= h->size && h->a[left] < h->a[smallest])
            smallest = left;

        if (right <= h->size && h->a[right] < h->a[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(&h->a[index], &h->a[smallest]);
            index = smallest;
        }

        else
            break; 
    }
    
    return root;
}

int main()
{
    int n;
    scanf("%d", &n);
    heap myHeap;
    int third_el = myHeap.a[3];

    int x;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        insert(&myHeap, x);
    }
    
    printf("Root of the heap: %d\n", myHeap.a[1]);
    printf("Size of the heap: %d\n", myHeap.size);

    int v[10000]={0};
    printf("The sorted vector is: ");
    for(int i=0; i<n; ++i) 
    {
        v[i] = pop(&myHeap);
        printf("%d ", v[i]);
    }
    printf("\n");

}
