#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#ifdef LIVE

static void tulostaInt(FILE *virta, const void *arvo)
{ /* Tulostaa osoittimen arvo osoittaman int-arvon tulostevirtaan virta. */
  const int *intOsoitin = arvo;
  fprintf(virta, "%d", *intOsoitin);
}

int main(void)
{
  int i = 0;
  int arvoja[5] = {2, 8, 1, 7, 4};
  Lista *ll = ll_luo(tulostaInt);
  for(i = 0; i < 5; ++i)
  { /* Välitetään arvot arvoja[i] osoittimien välityksellä. */
    ll_lisaaEteen(ll, &arvoja[i]);
  }
  ll_tulosta(ll, stdout);
  for(i = 0; i < 5; ++i)
  { /* Välitetään arvo i osoittimen välityksellä. */
    ll_lisaaEteen(ll, &i);
  }
  ll_tulosta(ll, stdout);
  ll_tuhoa(ll);
  return 0;
}

#endif

Solmu* s_luo(const void* data, Solmu *seur)
{
  Solmu *s = malloc(sizeof(Solmu));
  s->data = data;
  s->seur = seur;
  return s;
}

Lista * ll_luo(void (*tulostaArvo)(FILE *virta, const void *arvo))
{
  Lista *ll = malloc(sizeof(Lista));
  ll->n = 0;
  ll->paa = NULL;
  ll->tulostaArvo = tulostaArvo;

  return ll;
}

void ll_tuhoa(Lista *dl)
{
  while(dl->n > 0)
  {
    ll_poistaEdesta(dl);
  }
  free(dl);
}

Solmu* ll_lisaaEteen(Lista *dl, const void* arvo)
{
  dl->paa = s_luo(arvo, dl->paa);
  dl->n += 1;
  return dl->paa;
}

void* ll_poistaEdesta(Lista *dl)
{
  void* arvo = 0;
  if(dl->n > 0)
  {
    Solmu *vanhaPaa = dl->paa;
    arvo = dl->paa->data;
    dl->paa = dl->paa->seur;
    free(vanhaPaa);
    dl->n -= 1;
  }
  return arvo;
}

void ll_tulosta(const Lista *lista, FILE *virta)
{
  Solmu *s;

  if(lista->tulostaArvo == NULL)
  {
    return;
  }

  /*printf("Lista:");*/
  fprintf(virta, "Lista:");
  for(s = lista->paa; s != NULL; s = s->seur)
  {
    /*printf(" %.1f", s->data);*/
    fprintf(virta, " ");
    lista->tulostaArvo(virta, s->data);

  }
  /*printf("\n");*/
  fprintf(virta, "\n");
}
