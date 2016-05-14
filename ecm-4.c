node: ECM-IP-INF*

define: GTRC.def

ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF|\**

coding_query:

28: { 
// simple case
      -:                   (ECM-IP-INF* iDoms CONJP)
      -:                   (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (acc iDomsMod QP \*ICH*)
      -:                   (ECM-IP-INF* iDoms !nonfinVerbAct|MOD-IP-INF*)
      3-acc-dtv-pp-v:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms dtv)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms dtv) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms dtv)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms acc)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms dtv)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (ECM-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP)

// modal case
      3-acc-dtv-pp-v:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
     		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP)
      		       AND (nonfinVerbAct precedes firstPP)
      -: ELSE
}

29: {
       -:             (ECM-IP-INF* iDoms !nonfinVerbAll|MOD-IP-INF*|ADVP*)
// simple case
       part-v:        (ECM-IP-INF* iDoms nonfinVerbAll) AND (ECM-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (ECM-IP-INF* iDoms nonfinVerbAll) AND (ECM-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (ECM-IP-INF* iDoms nonfinVerbAll) AND (ECM-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (ECM-IP-INF* iDoms nonfinVerbAll) AND (ECM-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
// modal case
       part-v:        (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
        -:        ELSE
}
