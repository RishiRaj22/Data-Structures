#define SIZE 10000
#define MAX_HEAP 1
#define MIN_HEAP 2
#define ERROR_HEAP -1
typedef struct _heap
{
        int val[SIZE];
        int len;
        int type; //Determines whether heap is min_heap or max_heap
} heap;
heap* initheap(int type);
void printheap(heap*);
int add_heap(heap*,int);
int get_heap(heap*);
void __swap(int*,int*);
