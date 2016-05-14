node: CP*

define: GTRC.def

// count clitics, neg, traces
ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF

coding_query:

// subject and direct object
15: { 
      -:      (CODING-CP* column 5 -)
      -:      (CODING-CP* column 10 -|[oOp]_tra)
// monoclausal case without movement (including modal and PARTP cases)
      s-o:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedAcc|movedPrd) AND (IP-SUB* iDoms *-SBJ*) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (*-SBJ* precedes acc|prd)
      o-s:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedAcc|movedPrd) AND (IP-SUB* iDoms *-SBJ*) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd precedes *-SBJ*)
// object moved
      s-o:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (IP-SUB* iDoms *-SBJ*) AND (*-SBJ* precedes movedAcc|movedPrd)
      o-s:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (IP-SUB* iDoms *-SBJ*) AND (movedAcc|movedPrd precedes *-SBJ*)
// ecm subject in situ
      s-O:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj) AND (IP-SUB* iDoms *-SBJ*) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (*-SBJ* precedes ecmSbj)
      O-s:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj) AND (IP-SUB* iDoms *-SBJ*) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj precedes *-SBJ*)
// ecm subject moved
      s-O:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (IP-SUB* iDoms *-SBJ*) AND (*-SBJ* precedes movedEcmSbj)
      O-s:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (IP-SUB* iDoms *-SBJ*) AND (movedEcmSbj precedes *-SBJ*)
      -: ELSE
}

// finite verb and direct object
16: { 
      -:           (CODING-CP* column 10 -|[oOp]_tra)
// object in situ
      fin-o:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-SUB* iDoms !movedAcc|movedPrd) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes acc|prd)
      o-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-SUB* iDoms !movedAcc|movedPrd) AND (IP-SUB* iDoms finiteAll) AND (acc|prd precedes finiteAll)
// ecm subject in situ
      fin-O:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (IP-SUB* iDoms !movedEcmSbj) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes ecmSbj)
      O-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (IP-SUB* iDoms !movedEcmSbj) AND (IP-SUB* iDoms finiteAll) AND (ecmSbj precedes finiteAll)
// moved object
      fin-o:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes movedAcc|movedPrd)
      o-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (IP-SUB* iDoms finiteAll) AND (movedAcc|movedPrd precedes finiteAll)
// ecm subject moved
      fin-O:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes movedEcmSbj)
      O-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (IP-SUB* iDoms finiteAll) AND (movedEcmSbj precedes finiteAll)
      -: ELSE
}

// nonfinite verb and direct object
17: { 
      -:          (CODING-CP* column 10 -|[oOp]_tra)
// object in situ, nonfinite verb in situ
      non-o:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (VPP*|VX* precedes acc|prd)
      o-non:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (acc|prd precedes VPP*|VX*)
// object moved, nonfinite verb in situ
      non-o:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd)                     AND (IP-SUB* iDoms !movedInf|movedPart)       AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (VPP*|VX* precedes movedAcc|movedPrd)
      o-non:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd)                     AND (IP-SUB* iDoms !movedInf|movedPart)       AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (movedAcc|movedPrd precedes VPP*|VX*)
// object in situ, nonfinite verb moved
      non-o:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedAcc|movedPrd)                    AND (IP-SUB* iDoms movedInf|movedPart)        AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (movedInf|movedPart precedes acc|prd)
    o-non:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedAcc|movedPrd)                    AND (IP-SUB* iDoms movedInf|movedPart)        AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (acc|prd precedes movedInf|movedPart)
// object moved, nonfinite verb moved
      non-o:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd)                     AND (IP-SUB* iDoms movedInf|movedPart)                                                           AND (movedInf|movedPart precedes movedAcc|movedPrd)
      o-non:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd)                     AND (IP-SUB* iDoms movedInf|movedPart)                                                           AND (movedAcc|movedPrd precedes movedInf|movedPart)
// ecm subject in situ, nonfinite verb in situ
      non-O:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj|movedInf)  AND (IP-SUB* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                AND (VPP*|VX* precedes ecmSbj)
      O-non:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj|movedInf)  AND (IP-SUB* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                AND (ecmSbj precedes VPP*|VX*)
// ecm subject in situ, nonfinite verb moved
      non-O:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj)           AND (IP-SUB* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (IP-SUB* iDoms movedInf|movedPart)      AND (movedInf|movedPart precedes ecmSbj)
      O-non:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj)           AND (IP-SUB* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (IP-SUB* iDoms movedInf|movedPart)      AND (ecmSbj precedes movedInf|movedPart)
// ecm subject moved, nonfinite verb in situ
      non-O:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj)            AND (IP-SUB* iDoms !movedInf|movedPart)  AND (IP-SUB* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (VPP*|VX* precedes movedEcmSbj)
      O-non:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj)            AND (IP-SUB* iDoms !movedInf|movedPart)  AND (IP-SUB* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (movedEcmSbj precedes VPP*|VX*)
// ecm subject moved, nonfinite verb moved
      non-O:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj)            AND (IP-SUB* iDoms movedInf|movedPart)                                                             AND (movedInf|movedPart precedes movedEcmSbj)
      O-non:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj)            AND (IP-SUB* iDoms movedInf|movedPart)                                                             AND (movedEcmSbj precedes movedInf|movedPart)
// ecm subject in situ, predicate in situ
      prd-O:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj)           AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes ecmSbj)
      O-prd:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj)           AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (ecmSbj precedes *-PRD*|VG)
// ecm subject in situ, predicate moved
//
// ecm subject moved, predicate in situ
      prd-O:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj)            AND (IP-SUB* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes movedEcmSbj)
      O-prd:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj)            AND (IP-SUB* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (movedEcmSbj precedes *-PRD*|VG)
// ecm subject moved, predicate moved
//
      prd-O:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj)           AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (PP precedes ecmSbj)
      O-prd:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedEcmSbj)           AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (ecmSbj precedes PP)
// ecm complement contains no predicate
      #17:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
      -: ELSE
}

// DIRECT OBJECT 
// quantificational type
18: { 
      -:       (CODING-CP* column 10 -|[oOp]_tra)
      s:       (CODING-CP* column 10 [oO]_frl|[oO]_cp|[oO]_ip)
      cli:     (CODING-CP* column 10 [oO]_cli|[oO]_res)
      def:     (CODING-CP* column 10 [oO]_pro)
// monoclausal case without movement (including modal and PARTP cases)
      conj:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms DF)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms defHead)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      conj:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms DF)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj)
// modal - infinitive moved, object moved
      conj:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      conj:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms DF)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms defHead)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      conj:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      conj:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      conj:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms DF)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj)
// small clause - infinitive in situ, subject moved
      conj:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj)
      -:       ELSE
}

// DIRECT OBJECT 
// length
19: { 
      -:       (CODING-CP* column 10 -|[oOp]_tra)
// monoclausal case without movement (including modal and PARTP cases)
      \1:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 1)
      \2:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 2)
      \3:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 3)
      \4:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 4)
      \5:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedAcc|movedPrd) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      \1:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms !movedInf|movedEcmSbj) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj)
// modal - infinitive moved, object moved
      \1:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      \1:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 1)
      \2:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 2)
      \3:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 3)
      \4:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 4)
      \5:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      \1:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      \1:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      \1:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedInf) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj)
// small clause - infinitive in situ, subject moved
      \1:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj)
      -:       ELSE
}

// finite verb and indirect object
20: { 
      -:           (CODING-CP* column 11 -|[oOp]_tra)
// object in situ
      fin-o:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (IP-SUB* iDoms !movedDtv) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes dtv)
      o-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (IP-SUB* iDoms !movedDtv) AND (IP-SUB* iDoms finiteAll) AND (dtv precedes finiteAll)
// ecm subject in situ
      fin-O:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (IP-SUB* iDoms !movedEcmSbj) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes ecmSbj) AND (ecmSbj iDoms DAT)
      O-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod ECM-IP* ecmSbj) AND (IP-SUB* iDoms !movedEcmSbj) AND (IP-SUB* iDoms finiteAll) AND (ecmSbj precedes finiteAll) AND (ecmSbj iDoms DAT)
// moved object
      fin-o:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedDtv) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes movedDtv)
      o-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedDtv) AND (IP-SUB* iDoms finiteAll) AND (movedDtv precedes finiteAll)
// ecm subject moved
      fin-O:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes movedEcmSbj) AND (movedEcmSbj iDoms DAT)
      O-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedEcmSbj) AND (IP-SUB* iDoms finiteAll) AND (movedEcmSbj precedes finiteAll) AND (movedEcmSbj iDoms DAT)
     -: ELSE
}

// finite verb and first PP
21: { 
      -:           (CODING-CP* column 12 -)
// PP in situ
      fin-o:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (IP-SUB* iDoms !movedFirstPP) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes firstPP)
      o-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (IP-SUB* iDoms !movedFirstPP) AND (IP-SUB* iDoms finiteAll) AND (firstPP precedes finiteAll)
// moved PP
      fin-o:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedFirstPP) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes movedFirstPP)
      o-fin:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms movedFirstPP) AND (IP-SUB* iDoms finiteAll) AND (movedFirstPP precedes finiteAll)
     -: ELSE
}

// nonfinite verb raising
22: { 
      -:               (CODING-CP* column 10 -|[oOp]_tra)
// participle
      advp-part-o:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms NP-ACC*) AND (IP-SUB* iDoms VPP*) AND (IP-SUB* iDoms ADVP*) AND (ADVP* iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      advp-o-part:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms NP-ACC*) AND (IP-SUB* iDoms VPP*) AND (IP-SUB* iDoms ADVP*) AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-advp-o:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms NP-ACC*) AND (IP-SUB* iDoms VPP*) AND (IP-SUB* iDoms ADVP*) AND (VPP* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-part-o:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms NP-ACC*) AND (IP-SUB* iDoms VPP*) AND (IP-SUB* iDoms prepP) AND (prepP iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      pp-o-part:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms NP-ACC*) AND (IP-SUB* iDoms VPP*) AND (IP-SUB* iDoms prepP) AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-pp-o:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms NP-ACC*) AND (IP-SUB* iDoms VPP*) AND (IP-SUB* iDoms prepP) AND (VPP* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
// modal - infinitive in situ, object in situ
      advp-inf-o:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      advp-o-inf:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-advp-o:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (VX* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-inf-o:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      pp-o-inf:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms PrepP)
                   AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-pp-o:        (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms PrepP)
                   AND (VX* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
      -: ELSE
}

// tense of AVOIR
23: { 
      imparfait:       (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms AJ) AND (AJ iDoms @av[ao][iy].*|[aAáÁ][uv][aeo][iy].*|[aAáÁ][uv]et|[aAáÁ][uv][iíïy].*|[rR]a[uv][aeo][iy].*|[rR]a[uv][iíïy].*)
      passe-simple:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms AJ) AND (AJ iDoms @eu*|@o*|[aA]u[dt]|[aA]urent|[aA]us*|[eE][uü]|[eE][uü].*|[hH]e[uü]|[hH]e[uü].*|[oO][ct]|[oO]ct|[oO]grent|[oO]i|[oO]rent|[oO]rrent|[oOóÓ][uüú].*|[oOóÓ][yz]|[rR]ot|[uUúÚ]issums|[uUúÚ]rent|[uUúÚ]s*)
      present:         (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms AJ) AND (AJ iDoms @a|@a*|[aA]|[aA]-t|[aAáÁ][diíjsty]|[aAáÁ][iy].*|[aAáÁ][uv][eé][sz]|[aAáÁ][uv][ou].*|[eEéÉ]|[eEéÉ]i|[eEéÉ]i.*|[hH]a|[hH][ae][is]|[oO]n|[oO]n.*|[rR]a|[rR]ad|[rR]ont|[uUúÚ]nt)
      futur:           (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms AJ) AND (AJ iDoms [aAáÁ]r*|[aAáÁ][uv]er*|[aAáÁ][uv]r*|[rR]a[r][aeo][iy].*)
      #23:             (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms AJ) AND (AJ iDoms !avoir|AJ)
      -: ELSE
}

// gender of antecedent
24: { 
      coord: (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-C*|NP-ACC-C*)
      part:  (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-D*|NP-ACC-D*)
      f:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-F*|NP-ACC-F*)
      m:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-M[CDPSX]|CL-NP-ACC-M[CDPSX].*|NP-ACC-M[CDPSX]|NP-ACC-M[CDPSX].*)
      x:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-X*|NP-ACC-X*)
      coord: (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-C*|NP-ECM-SBJ-C*)
      part:  (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-D*|NP-ECM-SBJ-D*)
      f:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-F*|NP-ECM-SBJ-F*)
      m:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-M[CDPSX]|CL-NP-ECM-SBJ-M[CDPSX].*|NP-ECM-SBJ-M[CDPSX]|NP-ECM-SBJ-M[CDPSX].*)
      x:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-X*|NP-ECM-SBJ-X*)
      -: ELSE
}
          
// number of antecedent
25: { 
      coord: (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-[CDFMX]C*|NP-ACC-[CDFMX]C*)
      part:  (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-[CDFMX]D*|NP-ACC-[CDFMX]D*)
      pl:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-[CDFMX]P*|NP-ACC-[CDFMX]P*)
      sg:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-[CDFMX]S*|NP-ACC-[CDFMX]S*)
      x:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP* CL-NP-ACC-[CDFMX]X*|NP-ACC-[CDFMX]X*)
      coord: (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]C*|NP-ECM-SBJ-[CDFMX]C*)
      part:  (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]D*|NP-ECM-SBJ-[CDFMX]D*)
      pl:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]P*|NP-ECM-SBJ-[CDFMX]P*)
      sg:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]S*|NP-ECM-SBJ-[CDFMX]S*)
      x:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]X*|NP-ECM-SBJ-[CDFMX]X*)
      -: ELSE
}

// gender of participle
26: { 
      coord: (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-C*)
      part:  (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-D*)
      f:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-F*)
      m:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-M*)
      x:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-X*)
      -: ELSE
}
          
// number of participle
27: { 
      coord: (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]C*)
      part:  (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]D*)
      pl:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]P*)
      sg:    (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]S*)
      x:     (CP* iDoms IP-SUB*) AND (IP-SUB* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]X*)
      -: ELSE
}

