node: CP*

define: GTRC.def

ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF|\**

coding_query:

28: { 
// simple case
      -:                   (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (acc iDomsMod QP \*ICH*)
      -:                   (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !nonfinVerbAct|MOD-IP-INF*)
      3-acc-dtv-pp-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms firstPP)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms dtv)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms dtv) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms dtv)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms acc)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms dtv)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAct) AND (IP-SUB* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP)

// modal case
      3-acc-dtv-pp-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
     		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* acc)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-SUB* iDomsMod MOD-IP-INF* firstPP)
      		       AND (nonfinVerbAct precedes firstPP)
      -: ELSE
}

29: {
       -:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !nonfinVerbAll|MOD-IP-INF*|ADVP*)
// simple case
       part-v:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAll) AND (IP-SUB* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAll) AND (IP-SUB* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAll) AND (IP-SUB* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms nonfinVerbAll) AND (IP-SUB* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
// modal case
       part-v:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
        -:        ELSE
}
