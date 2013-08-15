/* j/6/cull.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  u2_noun
  j2_mcx(Pt6, ut, cull)(u2_wire, u2_noun, u2_noun, u2_atom, u2_noun);

  u2_noun                                                         //  transfer
  j2_mcx(Pt6, ut, cull)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_atom axe,
                        u2_noun ref)                              //  retain
  {
    u2_noun ret, p_sut, q_sut, r_sut;

    if ( _1 == axe ) {
      return j2_mcy(Pt6, ut, fuse)(wir_r, van, sut, ref);
    } else {
      u2_atom now = j2_mbc(Pt3, cap)(wir_r, axe);
      u2_atom lat = j2_mbc(Pt3, mas)(wir_r, axe);

      if ( u2_no == u2_dust(sut) ) switch ( sut ) {
        default: return u2_bl_bail(wir_r, c3__fail);

        case c3__noun: {
          u2_noun por = j2_mcy(Pt6, ut, repo)(wir_r, van, sut);
          u2_noun yot = j2_mcx(Pt6, ut, cull)(wir_r, van, por, axe, ref);
          
          if ( u2_yes == u2_sing(por, yot) ) {
            ret = u2_rx(wir_r, sut); 
          } else {
            ret = u2_rx(wir_r, yot);
          }
          u2_rl_lose(wir_r, por);
          u2_rl_lose(wir_r, yot);
          break;
        }
        case c3__void: {
          ret = c3__void;
        }
      }
      else switch ( u2_h(sut) ) {
        default: return u2_bl_bail(wir_r, c3__fail);

        case c3__atom: {
          ret = c3__void; 
          break;
        }
        case c3__cell: u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
        {
          u2_noun hub;

          if ( _2 == now ) {
            hub = j2_mcx(Pt6, ut, cull)(wir_r, van, p_sut, lat, ref);
            ret = j2_mby(Pt6, cell)(wir_r, hub, q_sut);
          } else {
            hub = j2_mcx(Pt6, ut, cull)(wir_r, van, q_sut, lat, ref);
            ret = j2_mby(Pt6, cell)(wir_r, p_sut, hub);
          }
          u2_rl_lose(wir_r, hub);
          break;
        }
        case c3__core: u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
        {
          if ( _2 != now ) {
            ret = u2_rx(wir_r, sut);
          } else {
            u2_noun hub = j2_mcx(Pt6, ut, cull)(wir_r, van, p_sut, lat, ref);

            ret = j2_mby(Pt6, core)(wir_r, hub, q_sut);

            u2_rl_lose(wir_r, hub);
          }
          break;
        }
        case c3__face: u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
        {
          u2_noun hic = j2_mcx(Pt6, ut, cull)(wir_r, van, q_sut, axe, ref);

          if ( u2_yes == u2_sing(hic, q_sut) ) {
            ret = u2_rx(wir_r, sut); 
          } else {
            ret = j2_mby(Pt6, face)(wir_r, p_sut, hic);
          }
          u2_rl_lose(wir_r, hic);

          break;
        }
        case c3__fine: u2_bi_trel(wir_r, u2_t(sut), &p_sut, &q_sut, &r_sut);
        {
          u2_noun hic = j2_mcx(Pt6, ut, cull)(wir_r, van, r_sut, axe, ref);

          if ( u2_yes == u2_sing(hic, r_sut) ) {
            ret = u2_rx(wir_r, sut); 
          } else {
            ret = j2_mby(Pt6, fine)(wir_r, p_sut, q_sut, hic);
          }
          u2_rl_lose(wir_r, hic);

          break;
        }
        case c3__fork: u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
        {
          u2_noun sin = j2_mcx(Pt6, ut, cull)(wir_r, van, p_sut, axe, ref);
          u2_noun dex = j2_mcx(Pt6, ut, cull)(wir_r, van, q_sut, axe, ref);

          ret = j2_mby(Pt6, fork)(wir_r, sin, dex);
          u2_rl_lose(wir_r, sin);
          u2_rl_lose(wir_r, dex);

          return ret;
        }
        case c3__cube: 
        case c3__hold: 
        {
          u2_noun por = j2_mcy(Pt6, ut, repo)(wir_r, van, sut);
          u2_noun yot = j2_mcx(Pt6, ut, cull)(wir_r, van, por, axe, ref);

          if ( u2_yes == u2_sing(por, yot) ) {
            ret = u2_rx(wir_r, sut); 
          } else {
            ret = u2_rx(wir_r, yot);
          }
          u2_rl_lose(wir_r, por);
          u2_rl_lose(wir_r, yot);
          break;
        }
      }
      u2_rl_lose(wir_r, lat);
      return ret;
    }
  }
 
/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pt6, ut, cull)[];

  u2_noun                                                         //  transfer
  j2_mc(Pt6, ut, cull)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, axe, ref, van;

    if ( (u2_no == u2_mean(cor, u2_cw_con, &van,
                                u2_cw_sam_2, &axe, 
                                u2_cw_sam_3, &ref, 0)) ||
         (u2_no == u2_stud(axe)) ||
         (u2_none == (sut = u2_frag(u2_cw_sam, van))) )
    {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      return j2_mcx(Pt6, ut, cull)(wir_r, van, sut, axe, ref);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pt6, ut, cull)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_atom axe,                              //  retain
                        u2_noun ref)                              //  retain
  {
    u2_weak hoc = u2_ds_look(wir_r, van, "cull");

    if ( u2_none == hoc ) {
      c3_assert(!"register cull");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cw_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, 
                                      u2_cw_sam_2, u2_rx(wir_r, axe), 
                                      u2_cw_sam_3, u2_rx(wir_r, ref), 
                                      0);

      if ( (u2_none == j2_mcj(Pt6, ut, cull)[0].xip) ) {
        u2_noun xip = u2_ds_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pt6, ut, cull)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pt6, ut, cull)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun axe,                              //  retain
                        u2_noun ref)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pt6, ut, cull)[0];

    if ( (jet_j->sat_s & u2_jet_live) && !(jet_j->sat_s & u2_jet_test) ) {
      if ( !(jet_j->sat_s & u2_jet_memo) ) {
        return j2_mcx(Pt6, ut, cull)(wir_r, van, sut, axe, ref);
      }
      else {
        c3_m    fun_m = u2_jet_fun_m(jet_j);
        u2_noun pro   = u2_rl_find_trel(wir_r, fun_m, sut, axe, ref);

        if ( u2_none != pro ) {
          return pro;
        }
        else {
          pro = j2_mcx(Pt6, ut, cull)(wir_r, van, sut, axe, ref);

          return u2_rl_save_trel(wir_r, fun_m, sut, axe, ref, pro);
        }
      }
    }
    else {
      u2_noun cor, fol, pro;

      cor = j2_mci(Pt6, ut, cull)(wir_r, van, sut, axe, ref);
      fol = u2_t(cor);

      pro = u2_ho_use(wir_r, jet_j, cor, fol);
      if ( u2_none == pro ) return u2_bl_bail(wir_r, c3__fail);

      u2_rz(wir_r, cor);
      u2_rz(wir_r, fol);

      return pro;
    }
  }

  u2_weak
  j2_mck(Pt6, ut, cull)(u2_wire wir_r,
                        u2_noun cor)
  {
    u2_noun sut, axe, ref, van;

    if ( (u2_no == u2_mean(cor, u2_cw_con, &van, 
                                u2_cw_sam_2, &axe, 
                                u2_cw_sam_3, &ref,
                                0)) ||
         (u2_none == (sut = u2_frag(u2_cw_sam, van))) )
    {
      return u2_none;
    } else {
      return u2_rt
        (wir_r, u2_rx(wir_r, sut), u2_rx(wir_r, axe), u2_rx(wir_r, ref));
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pt6, ut, cull)[] = {
    { ".3", c3__hevy, 
        j2_mc(Pt6, ut, cull), 
        Tier6_b_memo,
        u2_none, u2_none,
        j2_mck(Pt6, ut, cull)
    },
    { }
  };
