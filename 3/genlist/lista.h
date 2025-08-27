#include <stddef.h>

struct Solmu
{
  void* data;
  struct Solmu *seur;
};

typedef struct Solmu Solmu;

Solmu* s_luo(const void* data, Solmu *seur);

struct Lista
{
  size_t n;
  Solmu *paa;
  void (*tulostaArvo)(FILE *virta, const void *arvo);
};

typedef struct Lista Lista;

Lista * ll_luo(void (*tulostaArvo)(FILE *virta, const void *arvo));

void ll_tuhoa(Lista *dl);

Solmu* ll_lisaaEteen(Lista *dl, const void* arvo);

void* ll_poistaEdesta(Lista *dl);

void ll_tulosta(const Lista *lista, FILE *virta);
