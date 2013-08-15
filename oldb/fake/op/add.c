/* fake/op/add.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* u4_op_add(): 
**
**   Produce the sum of (a) and (b).
*/
u4_atom
u4_op_add(u4_lane lane,
          u4_atom a,
          u4_atom b)
{
  mpz_t mp_a, mp_b;

  u4_a_gmp(a, mp_a);
  u4_a_gmp(b, mp_b);

  mpz_add(mp_a, mp_a, mp_b);
  mpz_clear(mp_b);

  return u4_k_atom_gmp(lane, mp_a);
}
