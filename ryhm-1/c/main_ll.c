#include "ll.h"

int main()
{
  ll_t *ll = ll_make();
  ll_add_node(ll, 'c');
  ll_add_node(ll, 'b');
  ll_free(ll);
}
