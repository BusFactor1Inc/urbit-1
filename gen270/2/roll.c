/* j/2/roll.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pit, roll)(u2_wire wir_r, 
                    u2_noun a,                                    //  retain
                    u2_noun b)                                    //  retain
  {
    if ( _0 == a ) {
      return u2_frag(9, b);
    }
    else if ( u2_no == u2_dust(a) ) {
      return u2_none;
    }
    else {
      u2_weak gim = u2_rx(wir_r, u2_h(a));
      u2_weak zor = u2_rx(wir_r, u2_frag(9, b));
      u2_weak daz = u2_nk_mung(wir_r, b, u2_rc(wir_r, gim, zor));
      u2_weak vel = u2_rl_molt(wir_r, b, 9, daz, 0);

      if ( u2_none == vel ) {
        return u2_none;
      } else {
        u2_weak hox = j2_mbc(Pit, roll)(wir_r, u2_t(a), vel);

        u2_rl_lose(wir_r, vel);
        return hox;
      }
    }
  }
  u2_noun                                                         // transfer
  j2_mb(Pit, roll)(u2_wire wir_r, 
                   u2_noun cor)                                   // retain
  {
    u2_noun a, b;

    if ( u2_no == u2_mean(cor, 8, &a, 9, &b, 0) ) {
      return u2_none;
    } else {
      return j2_mbc(Pit, roll)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, roll)[] = {
    { ".3", c3__lite, j2_mb(Pit, roll), u2_no, u2_none, u2_none },
    { }
  };
