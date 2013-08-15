/* j/3/cap.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pit, cap)(u2_wire wir_r, 
                   u2_atom a)                                     //  retain
  {
    c3_w met_w = u2_met(0, a);

    if ( met_w < 2 ) {
      return u2_none;
    }
    else if ( (1 == u2_bit((met_w - 2), a)) ) {
      return _3;
    } else {
      return _2;
    }
  }
  u2_weak                                                         //  transfer
  j2_mb(Pit, cap)(u2_wire wir_r, 
                  u2_noun cor)                                    //  retain
  {
    u2_noun a;

    if ( (u2_none == (a = u2_frag(4, cor))) ||
         (u2_no == u2_stud(a)) )
    {
      return u2_none;
    } else {
      return j2_mbc(Pit, cap)(wir_r, a);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, cap)[] = {
    { ".3", c3__lite, j2_mb(Pit, cap), Tier3, u2_none, u2_none },
    { }
  };
