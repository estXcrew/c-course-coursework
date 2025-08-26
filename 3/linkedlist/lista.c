#include "lista.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef LIVE
int main() {
    DblLista *lista;
    double removed;
    size_t i;
    
    printf("=== Testing DblLista Implementation ===\n\n");
    
    /* Create a new list */
    lista = dl_luo();
    printf("Created empty list\n");
    dl_tulosta(lista);
    
    /* Test adding elements to front */
    printf("\n--- Testing dl_lisaaEteen ---\n");
    dl_lisaaEteen(lista, 1.5);
    dl_tulosta(lista);
    
    dl_lisaaEteen(lista, 2.7);
    dl_tulosta(lista);
    
    dl_lisaaEteen(lista, 3.9);
    dl_tulosta(lista);
    
    /* Test accessing elements by index */
    printf("\n--- Testing dl_alkio ---\n");
    for(i = 0; i < 5; i++) {
        printf("Element at index %u: %.1f\n", (unsigned int)i, dl_alkio(lista, i));
    }
    
    /* Test inserting at specific positions */
    printf("\n--- Testing dl_lisaa ---\n");
    printf("Inserting 4.2 at position 1:\n");
    dl_lisaa(lista, 1, 4.2);
    dl_tulosta(lista);
    
    printf("Inserting 5.8 at position 0:\n");
    dl_lisaa(lista, 0, 5.8);
    dl_tulosta(lista);
    
    printf("Inserting 6.1 at position 3:\n");
    dl_lisaa(lista, 3, 6.1);
    dl_tulosta(lista);
    
    printf("Inserting 7.3 at position 10 (beyond list):\n");
    dl_lisaa(lista, 10, 7.3);
    dl_tulosta(lista);
    
    /* Test removing from front */
    printf("\n--- Testing dl_poistaEdesta ---\n");
    removed = dl_poistaEdesta(lista);
    printf("Removed from front: %.1f\n", removed);
    dl_tulosta(lista);
    
    removed = dl_poistaEdesta(lista);
    printf("Removed from front: %.1f\n", removed);
    dl_tulosta(lista);
    
    /* Test removing from specific positions */
    printf("\n--- Testing dl_poista ---\n");
    removed = dl_poista(lista, 2);
    printf("Removed from position 2: %.1f\n", removed);
    dl_tulosta(lista);
    
    removed = dl_poista(lista, 0);
    printf("Removed from position 0: %.1f\n", removed);
    dl_tulosta(lista);
    
    removed = dl_poista(lista, 10);
    printf("Removed from position 10 (beyond list): %.1f\n", removed);
    dl_tulosta(lista);
    
    /* Test edge cases */
    printf("\n--- Testing edge cases ---\n");
    
    /* Empty the list */
    while(lista->n > 0) {
        removed = dl_poistaEdesta(lista);
        printf("Removed: %.1f, ", removed);
        dl_tulosta(lista);
    }
    
    /* Try operations on empty list */
    printf("Trying to remove from empty list:\n");
    removed = dl_poistaEdesta(lista);
    printf("Removed: %.1f\n", removed);
    
    printf("Trying to access element 0 in empty list: %.1f\n", dl_alkio(lista, 0));
    
    /* Add some elements back and test */
    printf("\nAdding elements back:\n");
    dl_lisaaEteen(lista, 10.1);
    dl_lisaaEteen(lista, 20.2);
    dl_lisaaEteen(lista, 30.3);
    dl_tulosta(lista);
    
    printf("Final list size: %u\n", (unsigned int)lista->n);
    
    /* Clean up */
    dl_tuhoa(lista);
    printf("\nList destroyed\n");
    
    return 0;
}

#endif

DblSolmu * ds_luo(double data, DblSolmu *seur) {
  DblSolmu *ds = malloc(sizeof(DblSolmu));
  ds->data = data;
  ds->seur = seur;
  return ds;
}

DblLista * dl_luo(void){
  DblLista *dl = malloc(sizeof(DblLista));
  dl->n = 0;
  dl->paa = NULL;
  return dl;
}

void dl_tuhoa(DblLista *dl) {
  while(dl->n > 0) {
    dl_poistaEdesta(dl);
  }
  free(dl);
}

DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo) {
  dl->paa = ds_luo(arvo, dl->paa);
  dl->n += 1;
  return dl->paa;
}

double dl_poistaEdesta(DblLista *dl) {
  double arvo = 0;
  if(dl->n > 0) {
    DblSolmu *vanhaPaa = dl->paa;
    arvo = dl->paa->data;
    dl->paa = dl->paa->seur;
    free(vanhaPaa);
    dl->n -= 1;
  }
  return arvo;
}

void dl_tulosta(const DblLista *lista) {
  DblSolmu *s;
  printf("Lista:");
  for(s = lista->paa; s != NULL; s = s->seur) {
    printf(" %.1f", s->data);
  }
  printf("\n");
}

double dl_alkio(const DblLista *lista, size_t i) {
    uint32_t j;
    DblSolmu* current;

    if(i>=(lista->n)) {
        printf("indexing past size in read\n");
        return 0;
    }

    current = lista->paa;
    for(j=0; j<i; j++){
        current = current->seur;
    }
    return current->data;
}

DblSolmu * dl_lisaa(DblLista *lista, size_t i, double arvo) {
    DblSolmu* new_item;
    DblSolmu* temp_item;
    DblSolmu* iter_item;
    uint32_t j, k;

    /* create new item */
    /* if i is bigger than list, add to position n in the end. Otherwise keep pos*/
    if(i >= (lista->n)) {
        j = lista->n;
    } else {
        j = i;
    }

    if(i == 0) {
        return dl_lisaaEteen(lista, arvo);
    }

    /* iterate through list until the target item is found */
    iter_item = lista->paa;
    for(k=1; k<j; k++) {
        iter_item = iter_item->seur;
    }
    /* create new item with nullptr next value */
    new_item = ds_luo(arvo, NULL);
    /* buffer old next item in temp buffer. Assign new next item. Assign temp buffer value (old next) as new next after new value */
    temp_item = iter_item->seur;
    iter_item->seur = new_item;
    new_item->seur = temp_item;
    lista->n++;

    return new_item;    
}

double dl_poista(DblLista *lista, size_t i) {
    DblSolmu* prev_item;
    DblSolmu* iter_item;
    uint32_t j, k;

    double deleted_data;

    /* create new item */
    /* if i is bigger than list, add to position n in the end. Otherwise keep pos*/
    if(i > (lista->n)) {
        j = lista->n;
    } else {
        j = i;
    }

    if(i == 0) {
        return dl_poistaEdesta(lista);
    }

    /* iterate through list until the target item is found */
    iter_item = lista->paa;
    prev_item = iter_item;
    for(k=1; k<(j+1); k++) {
        prev_item = iter_item;
        iter_item = iter_item->seur;
    }

    /*
    a->b
    b->c
    c->d

    del b: 
    a->c
    c->d 
    */

    prev_item->seur = iter_item->seur;
    deleted_data = iter_item->data;

    free(iter_item);

    lista->n--;

    return deleted_data;    
}
