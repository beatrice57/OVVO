node: IP-MAT*

define: GTRC.def

// count clitics, neg, traces
ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF

coding_query:

// subject and direct object
15: { 
      -:       (CODING-IP-MAT* column 5 -)
      -:       (CODING-IP-MAT* column 10 -)
// monoclausal case without movement (including modal and PARTP cases)
      s-o:     (IP-MAT* iDoms !movedAcc|movedPrd) AND (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (*-SBJ* precedes acc|prd)
      o-s:     (IP-MAT* iDoms !movedAcc|movedPrd) AND (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd precedes *-SBJ*)
// object moved
      s-o:     (IP-MAT* iDoms movedAcc|movedPrd) AND (IP-MAT* iDoms *-SBJ*) AND (*-SBJ* precedes movedAcc|movedPrd)
      o-s:     (IP-MAT* iDoms movedAcc|movedPrd) AND (IP-MAT* iDoms *-SBJ*) AND (movedAcc|movedPrd precedes *-SBJ*)
// ecm subject in situ
      s-O:     (IP-MAT* iDoms !movedEcmSbj) AND (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (*-SBJ* precedes ecmSbj)
      O-s:     (IP-MAT* iDoms !movedEcmSbj) AND (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj precedes *-SBJ*)
// ecm subject moved
      s-O:     (IP-MAT* iDoms movedEcmSbj) AND (IP-MAT* iDoms *-SBJ*) AND (*-SBJ* precedes movedEcmSbj)
      O-s:     (IP-MAT* iDoms movedEcmSbj) AND (IP-MAT* iDoms *-SBJ*) AND (movedEcmSbj precedes *-SBJ*)
      -: ELSE
}

// finite verb and direct object
16: { 
      -:           (CODING-IP-MAT* column 10 -)
// object in situ
      fin-o:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-MAT* iDoms !movedAcc|movedPrd) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes acc|prd)
      o-fin:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-MAT* iDoms !movedAcc|movedPrd) AND (IP-MAT* iDoms finiteAll) AND (acc|prd precedes finiteAll)
// ecm subject in situ
      fin-O:       (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (IP-MAT* iDoms !movedEcmSbj) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes ecmSbj)
      O-fin:       (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (IP-MAT* iDoms !movedEcmSbj) AND (IP-MAT* iDoms finiteAll) AND (ecmSbj precedes finiteAll)
// moved object
      fin-o:       (IP-MAT* iDoms movedAcc|movedPrd) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes movedAcc|movedPrd)
      o-fin:       (IP-MAT* iDoms movedAcc|movedPrd) AND (IP-MAT* iDoms finiteAll) AND (movedAcc|movedPrd precedes finiteAll)
// ecm subject moved
      fin-O:       (IP-MAT* iDoms movedEcmSbj) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes movedEcmSbj)
      O-fin:       (IP-MAT* iDoms movedEcmSbj) AND (IP-MAT* iDoms finiteAll) AND (movedEcmSbj precedes finiteAll)
     -: ELSE
}

// nonfinite verb and direct object
17: { 
      -:          (CODING-IP-MAT* column 10 -)
// object in situ, nonfinite verb in situ
      non-o:      (IP-MAT* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (VPP*|VX* precedes acc|prd)
      o-non:      (IP-MAT* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (acc|prd precedes VPP*|VX*)
// object moved, nonfinite verb in situ
      non-o:      (IP-MAT* iDoms movedAcc|movedPrd)                     AND (IP-MAT* iDoms !movedInf|movedPart)       AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (VPP*|VX* precedes movedAcc|movedPrd)
      o-non:      (IP-MAT* iDoms movedAcc|movedPrd)                     AND (IP-MAT* iDoms !movedInf|movedPart)       AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (movedAcc|movedPrd precedes VPP*|VX*)
// object in situ, nonfinite verb moved
      non-o:      (IP-MAT* iDoms !movedAcc|movedPrd)                    AND (IP-MAT* iDoms movedInf|movedPart)        AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (movedInf|movedPart precedes acc|prd)
      o-non:      (IP-MAT* iDoms !movedAcc|movedPrd)                    AND (IP-MAT* iDoms movedInf|movedPart)        AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (acc|prd precedes movedInf|movedPart)
// object moved, nonfinite verb moved
      non-o:      (IP-MAT* iDoms movedAcc|movedPrd)                     AND (IP-MAT* iDoms movedInf|movedPart)                                                           AND (movedInf|movedPart precedes movedAcc|movedPrd)
      o-non:      (IP-MAT* iDoms movedAcc|movedPrd)                     AND (IP-MAT* iDoms movedInf|movedPart)                                                           AND (movedAcc|movedPrd precedes movedInf|movedPart)
// ecm subject in situ, nonfinite verb in situ
      non-O:      (IP-MAT* iDoms !movedEcmSbj|movedInf)  AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                AND (VPP*|VX* precedes ecmSbj)
      O-non:      (IP-MAT* iDoms !movedEcmSbj|movedInf)  AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                AND (ecmSbj precedes VPP*|VX*)
// ecm subject in situ, nonfinite verb moved
      non-O:      (IP-MAT* iDoms !movedEcmSbj)           AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (IP-MAT* iDoms movedInf|movedPart)      AND (movedInf|movedPart precedes ecmSbj)
      O-non:      (IP-MAT* iDoms !movedEcmSbj)           AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (IP-MAT* iDoms movedInf|movedPart)      AND (ecmSbj precedes movedInf|movedPart)
// ecm subject moved, nonfinite verb in situ
      non-O:      (IP-MAT* iDoms movedEcmSbj)            AND (IP-MAT* iDoms !movedInf|movedPart)  AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (VPP*|VX* precedes movedEcmSbj)
      O-non:      (IP-MAT* iDoms movedEcmSbj)            AND (IP-MAT* iDoms !movedInf|movedPart)  AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (movedEcmSbj precedes VPP*|VX*)
// ecm subject moved, nonfinite verb moved
      non-O:      (IP-MAT* iDoms movedEcmSbj)            AND (IP-MAT* iDoms movedInf|movedPart)                                                             AND (movedInf|movedPart precedes movedEcmSbj)
      O-non:      (IP-MAT* iDoms movedEcmSbj)            AND (IP-MAT* iDoms movedInf|movedPart)                                                             AND (movedEcmSbj precedes movedInf|movedPart)
// ecm subject in situ, predicate in situ
      prd-O:      (IP-MAT* iDoms !movedEcmSbj)           AND (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes ecmSbj)
      O-prd:      (IP-MAT* iDoms !movedEcmSbj)           AND (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (ecmSbj precedes *-PRD*|VG)
// ecm subject in situ, predicate moved
//
// ecm subject moved, predicate in situ
      prd-O:      (IP-MAT* iDoms movedEcmSbj)            AND (IP-MAT* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes movedEcmSbj)
      O-prd:      (IP-MAT* iDoms movedEcmSbj)            AND (IP-MAT* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (movedEcmSbj precedes *-PRD*|VG)
// ecm subject moved, predicate moved
//
      prd-O:      (IP-MAT* iDoms !movedEcmSbj)           AND (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (PP precedes ecmSbj)
      O-prd:      (IP-MAT* iDoms !movedEcmSbj)           AND (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (ecmSbj precedes PP)
// ecm complement contains no predicate
      #17:        (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
      -: ELSE
}

// DIRECT OBJECT 
// quantificational type
18: { 
      -:       (CODING-IP-MAT* column 10 -)
      s:       (CODING-IP-MAT* column 10 [oO]_frl|[oO]_cp|[oO]_ip)
      cli:     (CODING-IP-MAT* column 10 [oO]_cli|[oO]_res)
      def:     (CODING-IP-MAT* column 10 [oO]_pro)
// monoclausal case without movement (including modal and PARTP cases)
      conj:    (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*)
      uni:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms DF)
      def:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms defHead)
      def:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      conj:    (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*)
      uni:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms DF)
      def:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj)
// modal - infinitive moved, object moved
      conj:    (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*)
      uni:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      conj:    (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*)
      uni:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms DF)
      def:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms defHead)
      def:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      conj:    (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*)
      uni:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (IP-MAT* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      conj:    (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*)
      uni:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      conj:    (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*)
      uni:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms DF)
      def:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj)
// small clause - infinitive in situ, subject moved
      conj:    (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*)
      uni:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-MAT* iDoms movedEcmSbj)
      -:       ELSE
}

// DIRECT OBJECT 
// length
19: { 
      -:       (CODING-IP-MAT* column 10 -)
// monoclausal case without movement (including modal and PARTP cases)
      \1:      (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 1)
      \2:      (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 2)
      \3:      (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 3)
      \4:      (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 4)
      \5:      (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (IP-MAT* iDoms !movedInf|movedAcc|movedPrd) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      \1:      (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (IP-MAT* iDoms !movedInf|movedEcmSbj) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj)
// modal - infinitive moved, object moved
      \1:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      \1:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 1)
      \2:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 2)
      \3:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 3)
      \4:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 4)
      \5:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      \1:      (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (IP-MAT* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (IP-MAT* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      \1:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      \1:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* ecmSbj)
// small clause - infinitive in situ, subject moved
      \1:      (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (IP-MAT* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (IP-MAT* iDoms movedEcmSbj)
      -:       ELSE
}

// finite verb and indirect object
20: { 
      -:           (CODING-IP-MAT* column 11 -)
// object in situ
      fin-o:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (IP-MAT* iDoms !movedDtv) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes dtv)
      o-fin:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (IP-MAT* iDoms !movedDtv) AND (IP-MAT* iDoms finiteAll) AND (dtv precedes finiteAll)
// ecm subject in situ
      fin-O:       (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (IP-MAT* iDoms !movedEcmSbj) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes ecmSbj) AND (ecmSbj iDoms DAT)
      O-fin:       (IP-MAT* iDomsMod ECM-IP* ecmSbj) AND (IP-MAT* iDoms !movedEcmSbj) AND (IP-MAT* iDoms finiteAll) AND (ecmSbj precedes finiteAll) AND (ecmSbj iDoms DAT)
// moved object
      fin-o:       (IP-MAT* iDoms movedDtv) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes movedDtv)
      o-fin:       (IP-MAT* iDoms movedDtv) AND (IP-MAT* iDoms finiteAll) AND (movedDtv precedes finiteAll)
// ecm subject moved
      fin-O:       (IP-MAT* iDoms movedEcmSbj) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes movedEcmSbj) AND (movedEcmSbj iDoms DAT)
      O-fin:       (IP-MAT* iDoms movedEcmSbj) AND (IP-MAT* iDoms finiteAll) AND (movedEcmSbj precedes finiteAll) AND (movedEcmSbj iDoms DAT)
     -: ELSE
}

// finite verb and first PP
21: { 
      -:           (CODING-IP-MAT* column 12 -)
// PP in situ
      fin-o:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (IP-MAT* iDoms !movedFirstPP) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes firstPP)
      o-fin:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (IP-MAT* iDoms !movedFirstPP) AND (IP-MAT* iDoms finiteAll) AND (firstPP precedes finiteAll)
// moved PP
      fin-o:       (IP-MAT* iDoms movedFirstPP) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes movedFirstPP)
      o-fin:       (IP-MAT* iDoms movedFirstPP) AND (IP-MAT* iDoms finiteAll) AND (movedFirstPP precedes finiteAll)
     -: ELSE
}

// nonfinite verb raising
22: {
      -:               (CODING-IP-MAT* column 10 -)
// participle
      advp-part-o:     (IP-MAT* iDoms NP-ACC*) AND (IP-MAT* iDoms VPP*) AND (IP-MAT* iDoms ADVP*) AND (ADVP* iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      advp-o-part:     (IP-MAT* iDoms NP-ACC*) AND (IP-MAT* iDoms VPP*) AND (IP-MAT* iDoms ADVP*) AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-advp-o:     (IP-MAT* iDoms NP-ACC*) AND (IP-MAT* iDoms VPP*) AND (IP-MAT* iDoms ADVP*) AND (VPP* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-part-o:       (IP-MAT* iDoms NP-ACC*) AND (IP-MAT* iDoms VPP*) AND (IP-MAT* iDoms prepP) AND (prepP iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      pp-o-part:       (IP-MAT* iDoms NP-ACC*) AND (IP-MAT* iDoms VPP*) AND (IP-MAT* iDoms prepP) AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-pp-o:       (IP-MAT* iDoms NP-ACC*) AND (IP-MAT* iDoms VPP*) AND (IP-MAT* iDoms prepP) AND (VPP* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
// modal - infinitive in situ, object in situ
      advp-inf-o:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      advp-o-inf:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-advp-o:      (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (VX* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-inf-o:        (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      pp-o-inf:        (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-pp-o:        (IP-MAT* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (VX* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
      -: ELSE
}

// tense of AVOIR
23: { 
      imparfait:       (IP-MAT* iDoms AJ) AND (AJ iDoms @av[ao][iy].*|[aAáÁ][uv][aeo][iy].*|[aAáÁ][uv]et|[aAáÁ][uv][iíïy].*|[rR]a[uv][aeo][iy].*|[rR]a[uv][iíïy].*)
      passe-simple:    (IP-MAT* iDoms AJ) AND (AJ iDoms @eu*|@o*|[aA]u[dt]|[aA]urent|[aA]us*|[eE][uü]|[eE][uü].*|[hH]e[uü]|[hH]e[uü].*|[oO][ct]|[oO]ct|[oO]grent|[oO]i|[oO]rent|[oO]rrent|[oOóÓ][uüú].*|[oOóÓ][yz]|[rR]ot|[uUúÚ]issums|[uUúÚ]rent|[uUúÚ]s*)
      present:         (IP-MAT* iDoms AJ) AND (AJ iDoms @a|@a*|[aA]|[aA]-t|[aAáÁ][diíjsty]|[aAáÁ][iy].*|[aAáÁ][uv][eé][sz]|[aAáÁ][uv][ou].*|[eEéÉ]|[eEéÉ]i|[eEéÉ]i.*|[hH]a|[hH][ae][is]|[oO]n|[oO]n.*|[rR]a|[rR]ad|[rR]ont|[uUúÚ]nt)
      futur:           (IP-MAT* iDoms AJ) AND (AJ iDoms [aAáÁ]r*|[aAáÁ][uv]er*|[aAáÁ][uv]r*|[rR]a[r][aeo][iy].*)
      #23:             (IP-MAT* iDoms AJ) AND (AJ iDoms !avoir|AJ)
      -: ELSE
}

// gender of antecedent
24: { 
      coord: (IP-MAT* iDomsMod PARTP* CL-NP-ACC-C*|NP-ACC-C*)
      part:  (IP-MAT* iDomsMod PARTP* CL-NP-ACC-D*|NP-ACC-D*)
      f:     (IP-MAT* iDomsMod PARTP* CL-NP-ACC-F*|NP-ACC-F*)
      m:     (IP-MAT* iDomsMod PARTP* CL-NP-ACC-M[CDPSX]|CL-NP-ACC-M[CDPSX].*|NP-ACC-M[CDPSX]|NP-ACC-M[CDPSX].*)
      x:     (IP-MAT* iDomsMod PARTP* CL-NP-ACC-X*|NP-ACC-X*)
      coord: (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-C*|NP-ECM-SBJ-C*)
      part:  (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-D*|NP-ECM-SBJ-D*)
      f:     (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-F*|NP-ECM-SBJ-F*)
      m:     (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-M[CDPSX]|CL-NP-ECM-SBJ-M[CDPSX].*|NP-ECM-SBJ-M[CDPSX]|NP-ECM-SBJ-M[CDPSX].*)
      x:     (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-X*|NP-ECM-SBJ-X*)
      -: ELSE
}
          
// number of antecedent
25: { 
      coord: (IP-MAT* iDomsMod PARTP* CL-NP-ACC-[CDFMX]C*|NP-ACC-[CDFMX]C*)
      part:  (IP-MAT* iDomsMod PARTP* CL-NP-ACC-[CDFMX]D*|NP-ACC-[CDFMX]D*)
      pl:    (IP-MAT* iDomsMod PARTP* CL-NP-ACC-[CDFMX]P*|NP-ACC-[CDFMX]P*)
      sg:    (IP-MAT* iDomsMod PARTP* CL-NP-ACC-[CDFMX]S*|NP-ACC-[CDFMX]S*)
      x:     (IP-MAT* iDomsMod PARTP* CL-NP-ACC-[CDFMX]X*|NP-ACC-[CDFMX]X*)
      coord: (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]C*|NP-ECM-SBJ-[CDFMX]C*)
      part:  (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]D*|NP-ECM-SBJ-[CDFMX]D*)
      pl:    (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]P*|NP-ECM-SBJ-[CDFMX]P*)
      sg:    (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]S*|NP-ECM-SBJ-[CDFMX]S*)
      x:     (IP-MAT* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]X*|NP-ECM-SBJ-[CDFMX]X*)
      -: ELSE
}

// gender of participle
26: { 
      coord: (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-C*)
      part:  (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-D*)
      f:     (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-F*)
      m:     (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-M*)
      x:     (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-X*)
      -: ELSE
}
          
// number of participle
27: { 
      coord: (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]C*)
      part:  (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]D*)
      pl:    (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]P*)
      sg:    (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]S*)
      x:     (IP-MAT* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]X*)
      -: ELSE
}


