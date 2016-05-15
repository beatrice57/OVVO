node: ORD-IP-*

define: GTRC.def

ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF|\**

coding_query:

28: { 
// simple case
      -:                   (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (acc iDomsMod QP \*ICH*)
      -:                   (ORD-IP-INF* iDoms !nonfinVerbAct|MOD-IP-INF*)
      3-acc-dtv-pp-v:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms dtv) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms dtv)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms acc)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms dtv)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (ORD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDoms firstPP)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP)

// modal case
      3-acc-dtv-pp-v:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
     		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* acc)
                       AND (CODING-ORD-IP-INF* column 10 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* dtv)
                       AND (CODING-ORD-IP-INF* column 11 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ORD-IP-INF* iDomsMod MOD-IP-INF* firstPP)
                       AND (CODING-ORD-IP-INF* column 14 [oO]_Res|[oO]_np|[oO]_pro)
      		       AND (nonfinVerbAct precedes firstPP)
      -: ELSE
}

29: {
       -:             (ORD-IP-INF* iDoms !nonfinVerbAll|MOD-IP-INF*|ADVP*)
// simple case
       part-v:        (ORD-IP-INF* iDoms nonfinVerbAll) AND (ORD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (ORD-IP-INF* iDoms nonfinVerbAll) AND (ORD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (ORD-IP-INF* iDoms nonfinVerbAll) AND (ORD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (ORD-IP-INF* iDoms nonfinVerbAll) AND (ORD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
// modal case
       part-v:        (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (ORD-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
        -:        ELSE
}
