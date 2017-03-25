#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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

heap* initheap(int type)
{
        heap* h;
        h=(heap*)(malloc(sizeof(heap)));
        h->type=type;
        h->len=0;
        return h;
}


int add_heap(heap* h, int val)
{
        /* arr- Pointer to the begining of array
           t1- current node
           t2- parent to current node
         */
        int *arr,*t1,*t2;
        int i;
        arr=h->val;
        *(arr+h->len)=val; //Setting the value of last element to the new element
        i=h->len; //Used to store current iteration values
        if(h->type == MAX_HEAP)
        {
                while(i>0 && *(t1=(arr+i)) > *(t2=arr+(i-1)/2))
                {
                        __swap(t1,t2);
                        i=(i-1)/2;
                }
        }
        else if(h->type == MIN_HEAP)
        {
                while(i>0 && *(t1=(arr+i)) < *(t2=arr+(i-1)/2))
                {
                        __swap(t1,t2);
                        i=(i-1)/2;
                }
        }
        else{
                printf("Error: Make sure you have initialised heap using initheap()");
                return -1;
        }
        h->len++;
        return 0;
}

int get_heap(heap* h)
{
        int* arr,* tmp; // arr- begining of array, tmp- current node
        int* t1,* t2; // t1-left child, t2-right child of the current node
        int i,ret,len;// i- current iteration, ret-value at top of heap
        arr=h->val;
        len=h->len;
        if(len<1)
        {
          printf("Empty heap: Cannot perform get operation.");
          return ERROR_HEAP;
        }
        ret=*(arr);
        *arr=*(arr+(h->len)-1);
        tmp=arr;
        i=0;
        if(h->type==MIN_HEAP)
        {
                while(1==1)
                {
                        tmp=arr+i;
                        t1=arr+2*i+1;
                        t2=arr+2*i+2;
                        if(2*i+1>=len-1) //(t1==NULL)
                          break;
                        else if(2*i+2>=len-1) //(t2==NULL)
                        {
                          if(*tmp > *t1)
                                __swap(tmp,t1);
                          break;
                        }
                        else if(*t1 < *t2)
                        {
                                if(*tmp > *t1)
                                {
                                        __swap(tmp,t1);
                                        i=2*i+1;
                                }
                                else break;
                        }
                        else
                        {
                                if(*tmp > *t2)
                                {
                                        __swap(tmp,t2);
                                        i=2*i+2;
                                }
                                else break;
                        }
                }
        }
        else if(h->type==MAX_HEAP)
        {
                while(1==1)
                {
                        tmp=arr+i;
                        t1=arr+2*i+1;
                        t2=arr+2*i+2;
                        if(2*i+1>=len-1) //(t1==NULL)
                          break;
                        else if(2*i+2>=len-1) //(t2==NULL)
                        {
                          if(*tmp < *t1)
                                  __swap(tmp,t1);
                          break;
                        }
                        else if(*t1 > *t2)
                        {
                                if(*tmp < *t1)
                                {
                                        __swap(tmp,t1);
                                        i=2*i+1;
                                }
                                else break;
                        }
                        else
                        {
                                if(*tmp < *t2)
                                {
                                        __swap(tmp,t2);
                                        i=2*i+2;
                                }
                                else break;
                        }
                }
        }
        else
        {
                printf("ERROR \nInitialise the heap using initheap()");
                return -1;
        }
        h->len--;
        return ret;
}
void printheap(heap* h)
{
        int i,power,l,*arr;
        printf("Heap:\n");
        l=1;
        power=2;
        for(i=0; i<h->len; i++)
        {
                arr=h->val;
                printf("%d ",*(arr+i));
                if(power-2==i)
                {
                        l++;
                        power=pow(2,l);
                        printf("\n");
                }
        }
        printf("\n");
}
void __swap(int* t1,int* t2)
{
        *t1 = *t1 + *t2;
        *t2 = *t1 - *t2;
        *t1 = *t1 - *t2;
}
