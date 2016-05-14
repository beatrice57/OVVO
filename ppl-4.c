node: IP-PPL*

define: GTRC.def

ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF|\**

coding_query:

28: { 
// simple case
      -:                   (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (acc iDomsMod QP \*ICH*)
      -:                   (IP-PPL* iDoms !nonfinVerbAct|MOD-IP-INF*)
      3-acc-dtv-pp-v:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms firstPP)
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms firstPP)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms dtv)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms dtv) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms dtv)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms firstPP)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms acc)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms dtv)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (IP-PPL* iDoms nonfinVerbAct) AND (IP-PPL* iDoms firstPP)
      		       AND (nonfinVerbAct precedes firstPP)

// modal case
      3-acc-dtv-pp-v:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP)
                       AND (acc precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-acc-dtv-v-pp:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP)
                       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-acc-pp-dtv-v:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP)
		       AND (acc precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-acc-pp-v-dtv:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
     		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-acc-v-dtv-pp:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      3-acc-v-pp-dtv:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      3-dtv-acc-pp-v:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes acc) AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      3-dtv-acc-v-pp:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      3-dtv-pp-acc-v:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      3-dtv-pp-v-acc:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-dtv-v-acc-pp:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      3-dtv-v-pp-acc:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      3-pp-acc-dtv-v:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      3-pp-acc-v-dtv:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      3-pp-dtv-acc-v:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      3-pp-dtv-v-acc:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      3-pp-v-acc-dtv:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      3-pp-v-dtv-acc:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      3-v-acc-dtv-pp:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv) AND (dtv precedes firstPP)

      3-v-acc-pp-dtv:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP) AND (firstPP precedes dtv)

      3-v-dtv-acc-pp:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc) AND (acc precedes firstPP)

      3-v-dtv-pp-acc:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP) AND (firstPP precedes acc)

      3-v-pp-acc-dtv:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc) AND (acc precedes dtv)

      3-v-pp-dtv-acc:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv) AND (dtv precedes acc)

      2-acc-dtv-v:         (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv)
      		       AND (acc precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-acc-pp-v:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-acc-v-dtv:         (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv)
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-acc-v-pp:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (acc precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-dtv-acc-v:         (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes acc) AND (acc precedes nonfinVerbAct)

      2-dtv-pp-v:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes firstPP) AND (firstPP precedes nonfinVerbAct)

      2-dtv-v-acc:         (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-dtv-v-pp:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (dtv precedes nonfinVerbAct) AND (nonfinVerbAct precedes firstPP)

      2-pp-acc-v:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes acc) AND (acc precedes nonfinVerbAct)

      2-pp-dtv-v:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes dtv) AND (dtv precedes nonfinVerbAct)

      2-pp-v-acc:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes acc)

      2-pp-v-dtv:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (firstPP precedes nonfinVerbAct) AND (nonfinVerbAct precedes dtv)

      2-v-acc-dtv:         (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes dtv)

      2-v-acc-pp:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes acc) AND (acc precedes firstPP)

      2-v-dtv-acc:         (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes acc)

      2-v-dtv-pp:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes dtv) AND (dtv precedes firstPP)

      2-v-pp-acc:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes acc)

      2-v-pp-dtv:          (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) 
      		       AND (nonfinVerbAct precedes firstPP) AND (firstPP precedes dtv)

      1-acc-v:             (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc)
      		       AND (acc precedes nonfinVerbAct)

      1-dtv-v:             (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv)
      		       AND (dtv precedes nonfinVerbAct)

      1-pp-v:              (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP)
      		       AND (firstPP precedes nonfinVerbAct)

      1-v-acc:             (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* acc)
      		       AND (nonfinVerbAct precedes acc)

      1-v-dtv:             (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* dtv)
      		       AND (nonfinVerbAct precedes dtv)

      1-v-pp:              (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAct) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP)
      		       AND (nonfinVerbAct precedes firstPP)
      -: ELSE
}

29: {
       -:             (IP-PPL* iDoms !nonfinVerbAll|MOD-IP-INF*|ADVP*)
// simple case
       part-v:        (IP-PPL* iDoms nonfinVerbAll) AND (IP-PPL* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (IP-PPL* iDoms nonfinVerbAll) AND (IP-PPL* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (IP-PPL* iDoms nonfinVerbAll) AND (IP-PPL* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (IP-PPL* iDoms nonfinVerbAll) AND (IP-PPL* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
// modal case
       part-v:        (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle iPrecedes nonfinVerbAll)
       part-x-v:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (particle precedes nonfinVerbAll)
       v-part:        (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll iPrecedes particle)
       v-x-part:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms nonfinVerbAll) AND (MOD-IP-INF* iDoms ADVP*)
                  AND (ADVP* iDoms ADV) AND (ADV iDoms particle)
                  AND (nonfinVerbAll precedes particle)
        -:        ELSE
}