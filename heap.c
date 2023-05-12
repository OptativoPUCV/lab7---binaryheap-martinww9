#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq) {
  if (pq->size == 0) {
    return NULL;
  }
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if (pq->size == pq->capac) {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = (heapElem*) realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    if (pq->heapArray == NULL) {
      printf("Error: no se pudo reservar memoria para el arreglo heapArray.\n");
      exit(1);
    }
  }
  
  int i = pq->size;
  pq->size++;
  
  while (i > 0 && priority > pq->heapArray[(i-1)/2].priority) {
    pq->heapArray[i] = pq->heapArray[(i-1)/2];
    i = (i-1)/2;
  }
  
  pq->heapArray[i].data = data;
  pq->heapArray[i].priority = priority;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  
  Heap* newHeap = (Heap*) malloc(sizeof(Heap));
  if (newHeap == NULL) {
    printf("Error: no se pudo reservar memoria para el Heap.\n");
    exit(1);
  }
  newHeap->heapArray = (heapElem*) malloc(3 * sizeof(heapElem));
  if (newHeap->heapArray == NULL) {
    printf("Error: no se pudo reservar memoria para el arreglo heapArray.\n");
    exit(1);
  }
  newHeap->size = 0;
  newHeap->capac = 3;
  
  return newHeap;
}
