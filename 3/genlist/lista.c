#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "string.h"

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
  Lista *ll = ll_luo(sizeof(int), tulostaInt); /* Alkion koko: sizeof(int). */
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

Solmu * s_luo(const void* data, size_t dataKoko, Solmu *seur)
{
  Solmu *s = malloc(sizeof(Solmu));
  s->data = malloc(dataKoko);
  memcpy(s->data, data, dataKoko);
  s->seur = seur;
  return s;
}

Lista* ll_luo(size_t dataKoko, void (*tulostaArvo)(FILE *virta, const void *arvo))
{
  Lista *ll = malloc(sizeof(Lista));
  ll->n = 0;
  ll->paa = NULL;
  ll->tulostaArvo = tulostaArvo;
  ll->dataKoko = dataKoko;

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
  dl->paa = s_luo(arvo, dl->dataKoko, dl->paa);
  dl->n += 1;
  return dl->paa;
}

void ll_poistaEdesta(Lista *dl)
{
  if(dl->n > 0)
  {
    Solmu *vanhaPaa = dl->paa;
    free(vanhaPaa->data);
    dl->paa = dl->paa->seur;
    free(vanhaPaa);
    dl->n -= 1;
  }
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
  for(s = lista->paa; s != NULL; s = s->seur) {
    /*printf(" %.1f", s->data);*/
    fprintf(virta, " ");
    lista->tulostaArvo(virta, s->data);

  }
  /*printf("\n");*/
  fprintf(virta, "\n");
}
