#include "ll.h"
#include <stdio.h>

ll_t *ll_make()
{
  ll_t *ll = malloc(sizeof(ll_t));
  ll->head = NULL;

  return ll;
}

static void ll_node_free(ll_node_t *node)
{
  if (node == NULL)
  {
    return;
  }

  ll_node_free(node->next);
  
  free(node);
}

void ll_free(ll_t *ll)
{
  ll_node_free(ll->head);

  free(ll);
  ll->size = 0;
  ll = NULL;
}

static ll_node_t *ll_node_make(char val)
{
  ll_node_t *node = malloc(sizeof(ll_node_t));
  node->val;

  return node;
}

void ll_add_node(ll_t *ll, char val)
{
  ll_node_t *current = ll->head;

  if (current == NULL)
  {
    ll->head = ll_node_make(val);
    ll->size++;

    return;
  }

  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = ll_node_make(val);
  ll->size++;
}

char ll_at(ll_t *ll, int index)
{
  ll_node_t *current = ll->head;

  for (int i = 0; i < index; i++)
  {
    if (current->next == NULL)
    {
      current->next = ll_node_make(0);
      ll->size++;
    }

    current = current->next;
  }

  return current->val;
}

void ll_set(ll_t *ll, int index, char val)
{
  ll_node_t *current = ll->head;

  for (int i = 0; i < index; i++)
  {
    if (current->next == NULL)
    {
      current->next = (ll_node_t *)ll_node_make(0);
      ll->size++;
    }

    current = (ll_node_t *)current->next;
  }

  current->val = val;
}

// TODO: Implementeeri
void ll_remove(ll_t *ll, int index)
{
  // Eemaldav kohal `index` olev element
  // Kui ta on kuskil vahel, võiks eelmise järglaseks panna järgmise
  // Vabasta viit
}

// TODO: Implementeeri
char ll_pop(ll_t *ll)
{
  // Tagasta viimase elemendi väärtus ja vabasta see viit
  // Säti eelviimase elemendi next väärtus NULL-ks
  return 0;
}
