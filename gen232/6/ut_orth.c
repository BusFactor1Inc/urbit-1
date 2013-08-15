/* j/6/orth.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

  static u2_flag
  _orth_in(u2_wire wir_r,
           u2_noun van,
           u2_noun sut, 
           u2_noun ref,
           u2_noun bix)
  {
    u2_noun p_sut, q_sut, r_sut;
    u2_noun p_ref, q_ref;

    if ( u2_no == u2_dust(sut) ) switch ( sut ) {
      default: goto fail;

      case c3__noun: {
        if ( c3__noun == ref ) {
          return u2_no;
        }
        else {
          return j2_mcy(Pt6, ut, nest)(wir_r, van, c3__void, u2_no, ref);
        }
      }
      case c3__void: {
        return u2_yes;
      }
    } 
    else switch ( u2_h(sut) ) {
      default: fail: return u2_bl_bail(wir_r, c3__fail);

      case c3__atom: {
        if ( u2_no == u2_dust(ref) ) {
          flip: return _orth_in(wir_r, van, ref, sut, bix);
        } 
        else switch ( u2_h(ref) ) {
          default: goto flip;
          
          case c3__atom: return u2_no;
          case c3__cell: return u2_yes;
        }
      }
      case c3__cell: {
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          if ( (u2_yes == u2_dust(ref)) && 
               (c3__cell == u2_h(ref)) &&
               (u2_yes == u2_as_cell(u2_t(ref), &p_ref, &q_ref)) )
          {
            return u2_or(_orth_in(wir_r, van, p_sut, p_ref, bix),
                         _orth_in(wir_r, van, q_sut, q_ref, bix));
          }
          else goto flip;
        }
      }
      case c3__core: {
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          u2_noun faz = u2_bt(wir_r, c3__cell, u2_rx(wir_r, p_sut), c3__noun);
          u2_flag ret = _orth_in(wir_r, van, faz, ref, bix);

          u2_rl_lose(wir_r, faz);
          return ret;
        }
      }
      case c3__cube: { 
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          return j2_mcy(Pt6, ut, firm)(wir_r, van, ref, p_sut);
        }
      }
      case c3__face: {
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          return _orth_in(wir_r, van, q_sut, ref, bix);
        }
      }
      case c3__fine: {
        if ( u2_no == u2_as_trel(u2_t(sut), &p_sut, &q_sut, &r_sut) ) {
          goto fail;
        } else {
          return _orth_in(wir_r, van, r_sut, ref, bix);
        }
      }
      case c3__fork: {
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          return u2_and(_orth_in(wir_r, van, p_sut, ref, bix),
                        _orth_in(wir_r, van, q_sut, ref, bix));
        }
      }
      case c3__hold: p_sut = u2_t(sut);
      {
        u2_noun tor = u2_bc(wir_r, u2_rx(wir_r, ref), 
                                   u2_rx(wir_r, sut));

        if ( (u2_yes == j2_mcc(Pt4, in, has)(wir_r, bix, tor)) ) {
          u2_rl_lose(wir_r, tor);
          return u2_yes;
        } 
        else {
          u2_noun zoc = j2_mcc(Pt4, in, put)(wir_r, bix, tor);
          u2_type fop = j2_mcy(Pt6, ut, rest)(wir_r, van, sut, p_sut);
          u2_noun ret = _orth_in(wir_r, van, fop, ref, zoc);

          u2_rl_lose(wir_r, fop);
          u2_rl_lose(wir_r, zoc);
          u2_rl_lose(wir_r, tor);

          return ret;
        }
      }
    } 
  }
  u2_flag                                                         //  transfer
  j2_mcx(Pt6, ut, orth)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun ref)                              //  retain
  {
    u2_flag ret;
    
    ret = _orth_in(wir_r, van, sut, ref, u2_nul);
    return ret;
  }
  
/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pt6, ut, orth)[];

  u2_noun                                                         //  transfer
  j2_mc(Pt6, ut, orth)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, ref, van;

    if ( (u2_no == u2_mean(cor, u2_cw_con, &van, u2_cw_sam, &ref, 0)) ||
         (u2_none == (sut = u2_frag(u2_cw_sam, van))) )
    {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      return j2_mcx(Pt6, ut, orth)(wir_r, van, sut, ref);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pt6, ut, orth)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun ref)                              //  retain
  {
    u2_weak hoc = u2_ds_look(wir_r, van, "orth");

    if ( u2_none == hoc ) {
      c3_assert(!"register orth");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cw_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cw_sam, u2_rx(wir_r, ref), 0);

      if ( (u2_none == j2_mcj(Pt6, ut, orth)[0].xip) ) {
        u2_noun xip = u2_ds_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pt6, ut, orth)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pt6, ut, orth)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun ref)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pt6, ut, orth)[0];

    if ( (jet_j->sat_s & u2_jet_live) && !(jet_j->sat_s & u2_jet_test) ) {
      if ( !(jet_j->sat_s & u2_jet_memo) ) {
        return j2_mcx(Pt6, ut, orth)(wir_r, van, sut, ref);
      }
      else {
        c3_m    fun_m = u2_jet_fun_m(jet_j);
        u2_noun pro   = u2_rl_find_cell(wir_r, fun_m, sut, ref);

        if ( u2_none != pro ) {
          return pro;
        }
        else {
          pro = j2_mcx(Pt6, ut, orth)(wir_r, van, sut, ref);

          return u2_rl_save_cell(wir_r, fun_m, sut, ref, pro);
        }
      }
    }
    else {
      u2_noun cor, fol, pro;

      cor = j2_mci(Pt6, ut, orth)(wir_r, van, sut, ref);
      fol = u2_t(cor);

      pro = u2_ho_use(wir_r, jet_j, cor, fol);
      if ( u2_none == pro ) return u2_bl_bail(wir_r, c3__fail);

      u2_rz(wir_r, cor);
      u2_rz(wir_r, fol);

      return pro;
    }
  }

  u2_weak
  j2_mck(Pt6, ut, orth)(u2_wire wir_r,
                        u2_noun cor)
  {
    u2_noun sut, ref, van;

    if ( (u2_no == u2_mean(cor, u2_cw_con, &van, u2_cw_sam, &ref, 0)) ||
         (u2_none == (sut = u2_frag(u2_cw_sam, van))) )
    {
      return u2_none;
    } else {
      return u2_rc(wir_r, u2_rx(wir_r, sut), u2_rx(wir_r, ref));
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pt6, ut, orth)[] = {
    { ".3", c3__hevy, 
        j2_mc(Pt6, ut, orth), 
        Tier6_b_memo,
        u2_none, u2_none,
        j2_mck(Pt6, ut, orth)
    },
    { }
  };
