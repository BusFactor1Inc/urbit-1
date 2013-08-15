/* mill/q/drol.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_drol():
*/
u4_noun
_mill_q_drol(u4_milr m, 
             u4_form nix,
             u4_form tep,
             u4_gene von)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_trop,
           _mill_lump(m, tep),
           u4_atom_load,
           u4_k_cell
            (lane, 
             u4_k_cell
              (lane, 
               u4_noun_0, 
               u4_k_trel(lane, u4_atom_cast, _mill_lump(m, nix), von)),
             u4_noun_0));
}
