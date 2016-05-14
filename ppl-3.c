node: IP-PPL*

define: GTRC.def

// count clitics, neg, traces
ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF

coding_query:

// subject and direct object
15: { 
      -:       (CODING-IP-PPL* column 5 -)
      -:       (CODING-IP-PPL* column 10 -|[oO]_scr|[oOp]_tra)
// monoclausal case without movement (including modal and PARTP cases)
      s-o:     (IP-PPL* iDoms !movedAcc|movedPrd) AND (IP-PPL* iDoms *-SBJ*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (*-SBJ* precedes acc|prd)
      o-s:     (IP-PPL* iDoms !movedAcc|movedPrd) AND (IP-PPL* iDoms *-SBJ*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd precedes *-SBJ*)
// object moved
      s-o:     (IP-PPL* iDoms movedAcc|movedPrd) AND (IP-PPL* iDoms *-SBJ*) AND (*-SBJ* precedes movedAcc|movedPrd)
      o-s:     (IP-PPL* iDoms movedAcc|movedPrd) AND (IP-PPL* iDoms *-SBJ*) AND (movedAcc|movedPrd precedes *-SBJ*)
// ecm subject in situ
      s-O:     (IP-PPL* iDoms !movedEcmSbj) AND (IP-PPL* iDoms *-SBJ*) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (*-SBJ* precedes ecmSbj)
      O-s:     (IP-PPL* iDoms !movedEcmSbj) AND (IP-PPL* iDoms *-SBJ*) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj precedes *-SBJ*)
// ecm subject moved
      s-O:     (IP-PPL* iDoms movedEcmSbj) AND (IP-PPL* iDoms *-SBJ*) AND (*-SBJ* precedes movedEcmSbj)
      O-s:     (IP-PPL* iDoms movedEcmSbj) AND (IP-PPL* iDoms *-SBJ*) AND (movedEcmSbj precedes *-SBJ*)
      -: ELSE
}

// finite verb and direct object
16: { 
      -:           (CODING-IP-PPL* column 10 -|[oO]_scr|[oOp]_tra)
// object in situ
      fin-o:       (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-PPL* iDoms !movedAcc|movedPrd) AND (IP-PPL* iDoms [AE]G|MDG) AND ([AE]G|MDG precedes acc|prd)
      o-fin:       (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-PPL* iDoms !movedAcc|movedPrd) AND (IP-PPL* iDoms [AE]G|MDG) AND (acc|prd precedes [AE]G|MDG)
// ecm subject in situ
      fin-O:       (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (IP-PPL* iDoms !movedEcmSbj) AND (IP-PPL* iDoms [AE]G|MDG) AND ([AE]G|MDG precedes ecmSbj)
      O-fin:       (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (IP-PPL* iDoms !movedEcmSbj) AND (IP-PPL* iDoms [AE]G|MDG) AND (ecmSbj precedes [AE]G|MDG)
// moved object
      fin-o:       (IP-PPL* iDoms movedAcc|movedPrd) AND (IP-PPL* iDoms [AE]G|MDG) AND ([AE]G|MDG precedes movedAcc|movedPrd)
      o-fin:       (IP-PPL* iDoms movedAcc|movedPrd) AND (IP-PPL* iDoms [AE]G|MDG) AND (movedAcc|movedPrd precedes [AE]G|MDG)
// ecm subject moved
      fin-O:       (IP-PPL* iDoms movedEcmSbj) AND (IP-PPL* iDoms [AE]G|MDG) AND ([AE]G|MDG precedes movedEcmSbj)
      O-fin:       (IP-PPL* iDoms movedEcmSbj) AND (IP-PPL* iDoms [AE]G|MDG) AND (movedEcmSbj precedes [AE]G|MDG)
     -: ELSE
}

// nonfinite verb and direct object
17: { 
      -:          (CODING-IP-PPL* column 10 -|[oO]_scr|[oOp]_tra)
// object in situ, nonfinite verb in situ
      non-o:      (IP-PPL* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* VG*|VPP*) AND (VG*|VPP* precedes acc|prd)
      o-non:      (IP-PPL* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* VG*|VPP*) AND (acc|prd precedes VG*|VPP*)
// object moved, nonfinite verb in situ
      non-o:      (IP-PPL* iDoms movedAcc|movedPrd)                     AND (IP-PPL* iDoms !movedInf|movedPart)       AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* VG*|VPP*) AND (VG*|VPP* precedes movedAcc|movedPrd)
      o-non:      (IP-PPL* iDoms movedAcc|movedPrd)                     AND (IP-PPL* iDoms !movedInf|movedPart)       AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* VG*|VPP*) AND (movedAcc|movedPrd precedes VG*|VPP*)
// object in situ, nonfinite verb moved
      non-o:      (IP-PPL* iDoms !movedAcc|movedPrd)                    AND (IP-PPL* iDoms movedInf|movedPart)        AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (movedInf|movedPart precedes acc|prd)
      o-non:      (IP-PPL* iDoms !movedAcc|movedPrd)                    AND (IP-PPL* iDoms movedInf|movedPart)        AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (acc|prd precedes movedInf|movedPart)
// object moved, nonfinite verb moved
      non-o:      (IP-PPL* iDoms movedAcc|movedPrd)                     AND (IP-PPL* iDoms movedInf|movedPart)                                                           AND (movedInf|movedPart precedes movedAcc|movedPrd)
      o-non:      (IP-PPL* iDoms movedAcc|movedPrd)                     AND (IP-PPL* iDoms movedInf|movedPart)                                                           AND (movedAcc|movedPrd precedes movedInf|movedPart)
// ecm subject in situ, nonfinite verb in situ
      non-O:      (IP-PPL* iDoms !movedEcmSbj|movedInf)  AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                AND (VPP*|VX* precedes ecmSbj)
      O-non:      (IP-PPL* iDoms !movedEcmSbj|movedInf)  AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                AND (ecmSbj precedes VPP*|VX*)
// ecm subject in situ, nonfinite verb moved
      non-O:      (IP-PPL* iDoms !movedEcmSbj)           AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (IP-PPL* iDoms movedInf|movedPart)      AND (movedInf|movedPart precedes ecmSbj)
      O-non:      (IP-PPL* iDoms !movedEcmSbj)           AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (IP-PPL* iDoms movedInf|movedPart)      AND (ecmSbj precedes movedInf|movedPart)
// ecm subject moved, nonfinite verb in situ
      non-O:      (IP-PPL* iDoms movedEcmSbj)            AND (IP-PPL* iDoms !movedInf|movedPart)  AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (VPP*|VX* precedes movedEcmSbj)
      O-non:      (IP-PPL* iDoms movedEcmSbj)            AND (IP-PPL* iDoms !movedInf|movedPart)  AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (movedEcmSbj precedes VPP*|VX*)
// ecm subject moved, nonfinite verb moved
      non-O:      (IP-PPL* iDoms movedEcmSbj)            AND (IP-PPL* iDoms movedInf|movedPart)                                                             AND (movedInf|movedPart precedes movedEcmSbj)
      O-non:      (IP-PPL* iDoms movedEcmSbj)            AND (IP-PPL* iDoms movedInf|movedPart)                                                             AND (movedEcmSbj precedes movedInf|movedPart)
// ecm subject in situ, predicate in situ
      prd-O:      (IP-PPL* iDoms !movedEcmSbj)           AND (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes ecmSbj)
      O-prd:      (IP-PPL* iDoms !movedEcmSbj)           AND (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (ecmSbj precedes *-PRD*|VG)
// ecm subject in situ, predicate moved
//
// ecm subject moved, predicate in situ
      prd-O:      (IP-PPL* iDoms movedEcmSbj)            AND (IP-PPL* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes movedEcmSbj)
      O-prd:      (IP-PPL* iDoms movedEcmSbj)            AND (IP-PPL* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (movedEcmSbj precedes *-PRD*|VG)
// ecm subject moved, predicate moved
//
      prd-O:      (IP-PPL* iDoms !movedEcmSbj)           AND (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (PP precedes ecmSbj)
      O-prd:      (IP-PPL* iDoms !movedEcmSbj)           AND (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (ecmSbj precedes PP)
// ecm complement contains no predicate
      #17:        (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
      -: ELSE
}

// DIRECT OBJECT 
// quantificational type
18: { 
      -:       (CODING-IP-PPL* column 10 -|[oO]_scr|[oOp]_tra)
      s:       (CODING-IP-PPL* column 10 [oO]_frl|[oO]_cp|[oO]_ip)
      cli:     (CODING-IP-PPL* column 10 [oO]_cli|[oO]_res)
      def:     (CODING-IP-PPL* column 10 [oO]_pro)
// monoclausal case without movement (including modal and PARTP cases)
      conj:    (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms DF)
      def:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms defHead)
      def:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      conj:    (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms DF)
      def:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj)
// modal - infinitive moved, object moved
      conj:    (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      conj:    (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms DF)
      def:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms defHead)
      def:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      conj:    (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (IP-PPL* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      conj:    (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      conj:    (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms DF)
      def:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj)
// small clause - infinitive in situ, subject moved
      conj:    (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-PPL* iDoms movedEcmSbj)
      -:       ELSE
}

// DIRECT OBJECT 
// length
19: { 
      -:       (CODING-IP-PPL* column 10 -|[oO]_scr|[oOp]_tra)
// monoclausal case without movement (including modal and PARTP cases)
      \1:      (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 1)
      \2:      (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 2)
      \3:      (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 3)
      \4:      (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 4)
      \5:      (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (IP-PPL* iDoms !movedInf|movedAcc|movedPrd) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      \1:      (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (IP-PPL* iDoms !movedInf|movedEcmSbj) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj)
// modal - infinitive moved, object moved
      \1:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      \1:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 1)
      \2:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 2)
      \3:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 3)
      \4:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 4)
      \5:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      \1:      (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (IP-PPL* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (IP-PPL* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      \1:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      \1:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* ecmSbj)
// small clause - infinitive in situ, subject moved
      \1:      (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (IP-PPL* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (IP-PPL* iDoms movedEcmSbj)
      -:       ELSE
}

// finite verb and indirect object
20: { 
      -:           (CODING-IP-PPL* column 11 -)
// object in situ
      fin-o:       (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (IP-PPL* iDoms !movedDtv) AND (IP-PPL* iDoms finiteAll) AND (finiteAll precedes dtv)
      o-fin:       (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (IP-PPL* iDoms !movedDtv) AND (IP-PPL* iDoms finiteAll) AND (dtv precedes finiteAll)
// ecm subject in situ
      fin-O:       (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (IP-PPL* iDoms !movedEcmSbj) AND (IP-PPL* iDoms finiteAll) AND (finiteAll precedes ecmSbj) AND (ecmSbj iDoms DAT)
      O-fin:       (IP-PPL* iDomsMod ECM-IP* ecmSbj) AND (IP-PPL* iDoms !movedEcmSbj) AND (IP-PPL* iDoms finiteAll) AND (ecmSbj precedes finiteAll) AND (ecmSbj iDoms DAT)
// moved object
      fin-o:       (IP-PPL* iDoms movedDtv) AND (IP-PPL* iDoms finiteAll) AND (finiteAll precedes movedDtv)
      o-fin:       (IP-PPL* iDoms movedDtv) AND (IP-PPL* iDoms finiteAll) AND (movedDtv precedes finiteAll)
// ecm subject moved
      fin-O:       (IP-PPL* iDoms movedEcmSbj) AND (IP-PPL* iDoms finiteAll) AND (finiteAll precedes movedEcmSbj) AND (movedEcmSbj iDoms DAT)
      O-fin:       (IP-PPL* iDoms movedEcmSbj) AND (IP-PPL* iDoms finiteAll) AND (movedEcmSbj precedes finiteAll) AND (movedEcmSbj iDoms DAT)
     -: ELSE
}

// finite verb and first PP
21: { 
      -:           (CODING-IP-PPL* column 12 -)
// PP in situ
      fin-o:       (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (IP-PPL* iDoms !movedFirstPP) AND (IP-PPL* iDoms finiteAll) AND (finiteAll precedes firstPP)
      o-fin:       (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (IP-PPL* iDoms !movedFirstPP) AND (IP-PPL* iDoms finiteAll) AND (firstPP precedes finiteAll)
// moved PP
      fin-o:       (IP-PPL* iDoms movedFirstPP) AND (IP-PPL* iDoms finiteAll) AND (finiteAll precedes movedFirstPP)
      o-fin:       (IP-PPL* iDoms movedFirstPP) AND (IP-PPL* iDoms finiteAll) AND (movedFirstPP precedes finiteAll)
     -: ELSE
}
// nonfinite verb raising
22: { 
      -:               (CODING-IP-PPL* column 10 -|[oO]_scr|[oOp]_tra)
// gerund
      advp-ger-o:      (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VG) AND (IP-PPL* iDoms ADVP*) AND (ADVP* iPrecedes VG) AND (VG iPrecedes NP-ACC*)
      advp-o-ger:      (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VG) AND (IP-PPL* iDoms ADVP*) AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VG)
      ger-advp-o:      (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VG) AND (IP-PPL* iDoms ADVP*) AND (VG iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-ger-o:        (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VG) AND (IP-PPL* iDoms prepP) AND (prepP iPrecedes VG) AND (VG iPrecedes NP-ACC*)
      pp-o-ger:        (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VG) AND (IP-PPL* iDoms prepP) AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VG)
      ger-pp-o:        (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VG) AND (IP-PPL* iDoms prepP) AND (VG iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
// participle - ordinary
      advp-part-o:     (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VPP*) AND (IP-PPL* iDoms ADVP*) AND (ADVP* iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      advp-o-part:     (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VPP*) AND (IP-PPL* iDoms ADVP*) AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-advp-o:     (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VPP*) AND (IP-PPL* iDoms ADVP*) AND (VPP* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-part-o:       (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VPP*) AND (IP-PPL* iDoms prepP) AND (prepP iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      pp-o-part:       (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VPP*) AND (IP-PPL* iDoms prepP) AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-pp-o:       (IP-PPL* iDoms NP-ACC*) AND (IP-PPL* iDoms VPP*) AND (IP-PPL* iDoms prepP) AND (VPP* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
// modal - infinitive in situ, object in situ
      advp-inf-o:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      advp-o-inf:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-advp-o:      (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (VX* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-inf-o:        (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      pp-o-inf:        (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-pp-o:        (IP-PPL* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (VX* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
      -: ELSE
}

// tense of AVOIR
23: { -: ELSE
}

// gender of antecedent
24: { 
      coord: (IP-PPL* iDomsMod PARTP* CL-NP-ACC-C*|NP-ACC-C*)
      part:  (IP-PPL* iDomsMod PARTP* CL-NP-ACC-D*|NP-ACC-D*)
      f:     (IP-PPL* iDomsMod PARTP* CL-NP-ACC-F*|NP-ACC-F*)
      m:     (IP-PPL* iDomsMod PARTP* CL-NP-ACC-M[CDPSX]|CL-NP-ACC-M[CDPSX].*|NP-ACC-M[CDPSX]|NP-ACC-M[CDPSX].*)
      x:     (IP-PPL* iDomsMod PARTP* CL-NP-ACC-X*|NP-ACC-X*)
      coord: (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-C*|NP-ECM-SBJ-C*)
      part:  (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-D*|NP-ECM-SBJ-D*)
      f:     (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-F*|NP-ECM-SBJ-F*)
      m:     (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-M[CDPSX]|CL-NP-ECM-SBJ-M[CDPSX].*|NP-ECM-SBJ-M[CDPSX]|NP-ECM-SBJ-M[CDPSX].*)
      x:     (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-X*|NP-ECM-SBJ-X*)
      -: ELSE
}
          
// number of antecedent
25: { 
      coord: (IP-PPL* iDomsMod PARTP* CL-NP-ACC-[CDFMX]C*|NP-ACC-[CDFMX]C*)
      part:  (IP-PPL* iDomsMod PARTP* CL-NP-ACC-[CDFMX]D*|NP-ACC-[CDFMX]D*)
      pl:    (IP-PPL* iDomsMod PARTP* CL-NP-ACC-[CDFMX]P*|NP-ACC-[CDFMX]P*)
      sg:    (IP-PPL* iDomsMod PARTP* CL-NP-ACC-[CDFMX]S*|NP-ACC-[CDFMX]S*)
      x:     (IP-PPL* iDomsMod PARTP* CL-NP-ACC-[CDFMX]X*|NP-ACC-[CDFMX]X*)
      coord: (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]C*|NP-ECM-SBJ-[CDFMX]C*)
      part:  (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]D*|NP-ECM-SBJ-[CDFMX]D*)
      pl:    (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]P*|NP-ECM-SBJ-[CDFMX]P*)
      sg:    (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]S*|NP-ECM-SBJ-[CDFMX]S*)
      x:     (IP-PPL* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]X*|NP-ECM-SBJ-[CDFMX]X*)
      -: ELSE
}

// gender of participle
26: { 
      coord: (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-C*)
      part:  (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-D*)
      f:     (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-F*)
      m:     (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-M*)
      x:     (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-X*)
      -: ELSE
}
          
// number of participle
27: { 
      coord: (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]C*)
      part:  (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]D*)
      pl:    (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]P*)
      sg:    (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]S*)
      x:     (IP-PPL* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]X*)
      -: ELSE
}

