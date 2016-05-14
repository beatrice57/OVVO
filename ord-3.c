node: ORD-IP*

define: GTRC.def

// count clitics, neg, traces
ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF

coding_query:

// subject and direct object
15: { -: ELSE
}

// finite verb and direct object
16: { 
      -:           (CODING-ORD-IP* column 10 -|[oO]_scr|[oOp]_tra)
// object in situ
      fin-o:       (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (ORD-IP* iDoms !movedAcc|movedPrd) AND (ORD-IP* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes acc|prd)
      o-fin:       (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (ORD-IP* iDoms !movedAcc|movedPrd) AND (ORD-IP* iDoms [AE]X|MDX) AND (acc|prd precedes [AE]X|MDX)
// ecm subject in situ
      fin-O:       (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ORD-IP* iDoms !movedEcmSbj) AND (ORD-IP* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes ecmSbj)
      O-fin:       (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ORD-IP* iDoms !movedEcmSbj) AND (ORD-IP* iDoms [AE]X|MDX) AND (ecmSbj precedes [AE]X|MDX)
// moved object
      fin-o:       (ORD-IP* iDoms movedAcc|movedPrd) AND (ORD-IP* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes movedAcc|movedPrd)
      o-fin:       (ORD-IP* iDoms movedAcc|movedPrd) AND (ORD-IP* iDoms [AE]X|MDX) AND (movedAcc|movedPrd precedes [AE]X|MDX)
// ecm subject moved
      fin-O:       (ORD-IP* iDoms movedEcmSbj) AND (ORD-IP* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes movedEcmSbj)
      O-fin:       (ORD-IP* iDoms movedEcmSbj) AND (ORD-IP* iDoms [AE]X|MDX) AND (movedEcmSbj precedes [AE]X|MDX)
      -: ELSE
}

// nonfinite verb and direct object
17: { 
      -:          (CODING-ORD-IP* column 10 -|[oO]_scr|[oOp]_tra)
// object in situ, nonfinite verb in situ
      non-o:      (ORD-IP* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (VPP*|VX* precedes acc|prd)
      o-non:      (ORD-IP* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (acc|prd precedes VPP*|VX*)
// object moved, nonfinite verb in situ
      non-o:      (ORD-IP* iDoms movedAcc|movedPrd)                     AND (ORD-IP* iDoms !movedInf|movedPart)       AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (VPP*|VX* precedes movedAcc|movedPrd)
      o-non:      (ORD-IP* iDoms movedAcc|movedPrd)                     AND (ORD-IP* iDoms !movedInf|movedPart)       AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (movedAcc|movedPrd precedes VPP*|VX*)
// object in situ, nonfinite verb moved
      non-o:      (ORD-IP* iDoms !movedAcc|movedPrd)                    AND (ORD-IP* iDoms movedInf|movedPart)        AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (movedInf|movedPart precedes acc|prd)
      o-non:      (ORD-IP* iDoms !movedAcc|movedPrd)                    AND (ORD-IP* iDoms movedInf|movedPart)        AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (acc|prd precedes movedInf|movedPart)
// object moved, nonfinite verb moved
      non-o:      (ORD-IP* iDoms movedAcc|movedPrd)                     AND (ORD-IP* iDoms movedInf|movedPart)                                                           AND (movedInf|movedPart precedes movedAcc|movedPrd)
      o-non:      (ORD-IP* iDoms movedAcc|movedPrd)                     AND (ORD-IP* iDoms movedInf|movedPart)                                                           AND (movedAcc|movedPrd precedes movedInf|movedPart)
// ecm subject in situ, nonfinite verb in situ
      non-O:      (ORD-IP* iDoms !movedEcmSbj|movedInf)  AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                AND (VPP*|VX* precedes ecmSbj)
      O-non:      (ORD-IP* iDoms !movedEcmSbj|movedInf)  AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                AND (ecmSbj precedes VPP*|VX*)
// ecm subject in situ, nonfinite verb moved
      non-O:      (ORD-IP* iDoms !movedEcmSbj)           AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ORD-IP* iDoms movedInf|movedPart)      AND (movedInf|movedPart precedes ecmSbj)
      O-non:      (ORD-IP* iDoms !movedEcmSbj)           AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ORD-IP* iDoms movedInf|movedPart)      AND (ecmSbj precedes movedInf|movedPart)
// ecm subject moved, nonfinite verb in situ
      non-O:      (ORD-IP* iDoms movedEcmSbj)            AND (ORD-IP* iDoms !movedInf|movedPart)  AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (VPP*|VX* precedes movedEcmSbj)
      O-non:      (ORD-IP* iDoms movedEcmSbj)            AND (ORD-IP* iDoms !movedInf|movedPart)  AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (movedEcmSbj precedes VPP*|VX*)
// ecm subject moved, nonfinite verb moved
      non-O:      (ORD-IP* iDoms movedEcmSbj)            AND (ORD-IP* iDoms movedInf|movedPart)                                                             AND (movedInf|movedPart precedes movedEcmSbj)
      O-non:      (ORD-IP* iDoms movedEcmSbj)            AND (ORD-IP* iDoms movedInf|movedPart)                                                             AND (movedEcmSbj precedes movedInf|movedPart)
// ecm subject in situ, predicate in situ
      prd-O:      (ORD-IP* iDoms !movedEcmSbj)           AND (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes ecmSbj)
      O-prd:      (ORD-IP* iDoms !movedEcmSbj)           AND (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (ecmSbj precedes *-PRD*|VG)
// ecm subject in situ, predicate moved
//
// ecm subject moved, predicate in situ
      prd-O:      (ORD-IP* iDoms movedEcmSbj)            AND (ORD-IP* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes movedEcmSbj)
      O-prd:      (ORD-IP* iDoms movedEcmSbj)            AND (ORD-IP* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (movedEcmSbj precedes *-PRD*|VG)
// ecm subject moved, predicate moved
//
      prd-O:      (ORD-IP* iDoms !movedEcmSbj)           AND (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (PP precedes ecmSbj)
      O-prd:      (ORD-IP* iDoms !movedEcmSbj)           AND (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (ecmSbj precedes PP)
// ecm complement contains no predicate
      #17:        (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
      -: ELSE
}

// DIRECT OBJECT 
// quantificational type
18: { 
      -:       (CODING-ORD-IP* column 10 -|[oO]_scr|[oOp]_tra)
      s:       (CODING-ORD-IP* column 10 [oO]_frl|[oO]_cp|[oO]_ip)
      cli:     (CODING-ORD-IP* column 10 [oO]_cli|[oO]_res)
      def:     (CODING-ORD-IP* column 10 [oO]_pro)
// monoclausal case without movement (including modal and PARTP cases)
      conj:    (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms DF)
      def:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms defHead)
      def:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      conj:    (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms DF)
      def:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj)
// modal - infinitive moved, object moved
      conj:    (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      conj:    (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms DF)
      def:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms defHead)
      def:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      conj:    (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (ORD-IP* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      conj:    (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      conj:    (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms DF)
      def:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj)
// small clause - infinitive in situ, subject moved
      conj:    (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (ORD-IP* iDoms movedEcmSbj)
      -:       ELSE
}

// DIRECT OBJECT 
// length
19: { 
      -:       (CODING-ORD-IP* column 10 -|[oO]_scr|[oOp]_tra)
// monoclausal case without movement (including modal and PARTP cases)
      \1:      (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 1)
      \2:      (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 2)
      \3:      (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 3)
      \4:      (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 4)
      \5:      (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (ORD-IP* iDoms !movedInf|movedAcc|movedPrd) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      \1:      (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (ORD-IP* iDoms !movedInf|movedEcmSbj) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj)
// modal - infinitive moved, object moved
      \1:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      \1:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 1)
      \2:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 2)
      \3:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 3)
      \4:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 4)
      \5:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      \1:      (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (ORD-IP* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (ORD-IP* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      \1:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      \1:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* ecmSbj)
// small clause - infinitive in situ, subject moved
      \1:      (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (ORD-IP* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (ORD-IP* iDoms movedEcmSbj)
      -:       ELSE
}

// finite verb and indirect object
20: { 
      -:           (CODING-ORD-IP* column 11 -)
// object in situ
      fin-o:       (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (ORD-IP* iDoms !movedDtv) AND (ORD-IP* iDoms finiteAll) AND (finiteAll precedes dtv)
      o-fin:       (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (ORD-IP* iDoms !movedDtv) AND (ORD-IP* iDoms finiteAll) AND (dtv precedes finiteAll)
// ecm subject in situ
      fin-O:       (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ORD-IP* iDoms !movedEcmSbj) AND (ORD-IP* iDoms finiteAll) AND (finiteAll precedes ecmSbj) AND (ecmSbj iDoms DAT)
      O-fin:       (ORD-IP* iDomsMod ECM-IP* ecmSbj) AND (ORD-IP* iDoms !movedEcmSbj) AND (ORD-IP* iDoms finiteAll) AND (ecmSbj precedes finiteAll) AND (ecmSbj iDoms DAT)
// moved object
      fin-o:       (ORD-IP* iDoms movedDtv) AND (ORD-IP* iDoms finiteAll) AND (finiteAll precedes movedDtv)
      o-fin:       (ORD-IP* iDoms movedDtv) AND (ORD-IP* iDoms finiteAll) AND (movedDtv precedes finiteAll)
// ecm subject moved
      fin-O:       (ORD-IP* iDoms movedEcmSbj) AND (ORD-IP* iDoms finiteAll) AND (finiteAll precedes movedEcmSbj) AND (movedEcmSbj iDoms DAT)
      O-fin:       (ORD-IP* iDoms movedEcmSbj) AND (ORD-IP* iDoms finiteAll) AND (movedEcmSbj precedes finiteAll) AND (movedEcmSbj iDoms DAT)
     -: ELSE
}

// finite verb and first PP
21: { 
      -:           (CODING-ORD-IP* column 12 -)
// PP in situ
      fin-o:       (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (ORD-IP* iDoms !movedFirstPP) AND (ORD-IP* iDoms finiteAll) AND (finiteAll precedes firstPP)
      o-fin:       (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (ORD-IP* iDoms !movedFirstPP) AND (ORD-IP* iDoms finiteAll) AND (firstPP precedes finiteAll)
// moved PP
      fin-o:       (ORD-IP* iDoms movedFirstPP) AND (ORD-IP* iDoms finiteAll) AND (finiteAll precedes movedFirstPP)
      o-fin:       (ORD-IP* iDoms movedFirstPP) AND (ORD-IP* iDoms finiteAll) AND (movedFirstPP precedes finiteAll)
     -: ELSE
}

// nonfinite verb raising
22: { 
      -:               (CODING-ORD-IP* column 10 -|[oO]_scr|[oOp]_tra)
// participle
      advp-part-o:     (ORD-IP* iDoms NP-ACC*) AND (ORD-IP* iDoms VPP*) AND (ORD-IP* iDoms ADVP*) AND (ADVP* iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      advp-o-part:     (ORD-IP* iDoms NP-ACC*) AND (ORD-IP* iDoms VPP*) AND (ORD-IP* iDoms ADVP*) AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-advp-o:     (ORD-IP* iDoms NP-ACC*) AND (ORD-IP* iDoms VPP*) AND (ORD-IP* iDoms ADVP*) AND (VPP* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-part-o:       (ORD-IP* iDoms NP-ACC*) AND (ORD-IP* iDoms VPP*) AND (ORD-IP* iDoms prepP) AND (prepP iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      pp-o-part:       (ORD-IP* iDoms NP-ACC*) AND (ORD-IP* iDoms VPP*) AND (ORD-IP* iDoms prepP) AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-pp-o:       (ORD-IP* iDoms NP-ACC*) AND (ORD-IP* iDoms VPP*) AND (ORD-IP* iDoms prepP) AND (VPP* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
// modal - infinitive in situ, object in situ
      advp-inf-o:      (ORD-IP* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      advp-o-inf:      (ORD-IP* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-advp-o:      (ORD-IP* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (VX* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-inf-o:        (ORD-IP* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      pp-o-inf:        (ORD-IP* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-pp-o:        (ORD-IP* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (VX* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
      -: ELSE
}

// tense of AVOIR
23: { -: ELSE
}

// gender of antecedent
24: { 
      coord: (ORD-IP* iDomsMod PARTP* CL-NP-ACC-C*|NP-ACC-C*)
      part:  (ORD-IP* iDomsMod PARTP* CL-NP-ACC-D*|NP-ACC-D*)
      f:     (ORD-IP* iDomsMod PARTP* CL-NP-ACC-F*|NP-ACC-F*)
      m:     (ORD-IP* iDomsMod PARTP* CL-NP-ACC-M[CDPSX]|CL-NP-ACC-M[CDPSX].*|NP-ACC-M[CDPSX]|NP-ACC-M[CDPSX].*)
      x:     (ORD-IP* iDomsMod PARTP* CL-NP-ACC-X*|NP-ACC-X*)
      coord: (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-C*|NP-ECM-SBJ-C*)
      part:  (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-D*|NP-ECM-SBJ-D*)
      f:     (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-F*|NP-ECM-SBJ-F*)
      m:     (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-M[CDPSX]|CL-NP-ECM-SBJ-M[CDPSX].*|NP-ECM-SBJ-M[CDPSX]|NP-ECM-SBJ-M[CDPSX].*)
      x:     (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-X*|NP-ECM-SBJ-X*)
      -: ELSE
}
          
// number of antecedent
25: { 
      coord: (ORD-IP* iDomsMod PARTP* CL-NP-ACC-[CDFMX]C*|NP-ACC-[CDFMX]C*)
      part:  (ORD-IP* iDomsMod PARTP* CL-NP-ACC-[CDFMX]D*|NP-ACC-[CDFMX]D*)
      pl:    (ORD-IP* iDomsMod PARTP* CL-NP-ACC-[CDFMX]P*|NP-ACC-[CDFMX]P*)
      sg:    (ORD-IP* iDomsMod PARTP* CL-NP-ACC-[CDFMX]S*|NP-ACC-[CDFMX]S*)
      x:     (ORD-IP* iDomsMod PARTP* CL-NP-ACC-[CDFMX]X*|NP-ACC-[CDFMX]X*)
      coord: (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]C*|NP-ECM-SBJ-[CDFMX]C*)
      part:  (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]D*|NP-ECM-SBJ-[CDFMX]D*)
      pl:    (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]P*|NP-ECM-SBJ-[CDFMX]P*)
      sg:    (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]S*|NP-ECM-SBJ-[CDFMX]S*)
      x:     (ORD-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]X*|NP-ECM-SBJ-[CDFMX]X*)
      -: ELSE
}

// gender of participle
26: { 
      coord: (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-C*)
      part:  (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-D*)
      f:     (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-F*)
      m:     (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-M*)
      x:     (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-X*)
      -: ELSE
}
          
// number of participle
27: { 
      coord: (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]C*)
      part:  (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]D*)
      pl:    (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]P*)
      sg:    (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]S*)
      x:     (ORD-IP* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]X*)
      -: ELSE
}

