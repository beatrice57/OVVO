node: IP-MAT*

define: GTRC.def

ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF|\**

coding_query:

28: { 
// simple case
      -:                   (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (acc iDomsMod QP \*ICH*)
      -:                   (IP-MAT* iDoms !nonfinVerbAct|MOD-IP-INF*)
      3-acc-dtv-pp-v:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms firstPP)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms dtv)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms dtv) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms dtv)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms acc)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms dtv)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (IP-MAT* iDoms nonfinVerbAct) AND (IP-MAT* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP)

// modal case
      3-acc-dtv-pp-v:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
     		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* acc)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP)
      		       AND (nonfinVerbAct precedes firstPP)
      -: ELSE
}

29: {
       -:             (IP-MAT* iDoms !nonfinVerbAll|MOD-IP-INF*|ADVP*)
// simple case
       part-v:        (IP-MAT* iDoms nonfinVerbAll) AND (IP-MAT* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (IP-MAT* iDoms nonfinVerbAll) AND (IP-MAT* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (IP-MAT* iDoms nonfinVerbAll) AND (IP-MAT* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (IP-MAT* iDoms nonfinVerbAll) AND (IP-MAT* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
// modal case
       part-v:        (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
        -:        ELSE
}
