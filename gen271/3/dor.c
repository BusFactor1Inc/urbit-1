/* j/3/dor.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pit, dor)(u2_wire wir_r, 
                   u2_atom a,                                     //  retain
                   u2_atom b)                                     //  retain
  {
    if ( u2_yes == u2_sing(a, b) ) {
      return u2_yes;
    }
    else {
      if ( u2_yes == u2_stud(a) ) {
        if ( u2_yes == u2_stud(b) ) {
          return j2_mbc(Pit, lth)(wir_r, a, b);
        }
        else {
          return u2_yes;
        }
      }
      else {
        if ( u2_yes == u2_stud(b) ) {
          return u2_no;
        }
        else {
          if ( u2_sing(u2_h(a), u2_h(b)) ) {
            return j2_mbc(Pit, dor)(wir_r, u2_t(a), u2_t(b));
          }
          else return j2_mbc(Pit, dor)(wir_r, u2_h(a), u2_h(b));
        }
      }
    }
  }
  u2_weak                                                         //  transfer
  j2_mb(Pit, dor)(u2_wire wir_r, 
                  u2_noun cor)                                    //  retain
  {
    u2_noun a, b;

    if ( u2_no == u2_mean(cor, 8, &a, 9, &b, 0) ) {
      return u2_none;
    } else {
      return j2_mbc(Pit, dor)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, dor)[] = {
    { ".3", c3__lite, j2_mb(Pit, dor), u2_no, u2_none, u2_none },
    { }
  };
