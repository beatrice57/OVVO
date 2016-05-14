node: ECM-IP-INF*

define: GTRC.def

// count clitics, neg, traces
ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF

coding_query:

// subject and direct object
15: { 
      -:       (ECM-IP-INF* iDoms CONJP)
      -:       (CODING-ECM-IP-INF* column 5 -)
      -:       (CODING-ECM-IP-INF* column 10 -|[oO]_scr|[oOp]_tra)
// monoclausal case without movement (including modal and PARTP cases)
      s-o:     (ECM-IP-INF* iDoms !movedAcc|movedPrd) AND (ECM-IP-INF* iDoms *-SBJ*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (*-SBJ* precedes acc|prd)
      o-s:     (ECM-IP-INF* iDoms !movedAcc|movedPrd) AND (ECM-IP-INF* iDoms *-SBJ*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd precedes *-SBJ*)
// object moved
      s-o:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (ECM-IP-INF* iDoms *-SBJ*) AND (*-SBJ* precedes movedAcc|movedPrd)
      o-s:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (ECM-IP-INF* iDoms *-SBJ*) AND (movedAcc|movedPrd precedes *-SBJ*)
// ecm subject in situ
      s-O:     (ECM-IP-INF* iDoms !movedEcmSbj) AND (ECM-IP-INF* iDoms *-SBJ*) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (*-SBJ* precedes ecmSbj)
      O-s:     (ECM-IP-INF* iDoms !movedEcmSbj) AND (ECM-IP-INF* iDoms *-SBJ*) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj precedes *-SBJ*)
// ecm subject moved
      s-O:     (ECM-IP-INF* iDoms movedEcmSbj) AND (ECM-IP-INF* iDoms *-SBJ*) AND (*-SBJ* precedes movedEcmSbj)
      O-s:     (ECM-IP-INF* iDoms movedEcmSbj) AND (ECM-IP-INF* iDoms *-SBJ*) AND (movedEcmSbj precedes *-SBJ*)
      -: ELSE
}

// finite verb and direct object
16: { 
      -:           (ECM-IP-INF* iDoms CONJP)
      -:           (CODING-ECM-IP-INF* column 10 -|[oO]_scr|[oOp]_tra)
// object in situ
      fin-o:       (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (ECM-IP-INF* iDoms !movedAcc|movedPrd) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes acc|prd)
      o-fin:       (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (ECM-IP-INF* iDoms !movedAcc|movedPrd) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND (acc|prd precedes [AE]X|MDX)
// ecm subject in situ
      fin-O:       (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP-INF* iDoms !movedEcmSbj) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes ecmSbj)
      O-fin:       (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP-INF* iDoms !movedEcmSbj) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND (ecmSbj precedes [AE]X|MDX)
// moved object
      fin-o:       (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes movedAcc|movedPrd)
      o-fin:       (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND (movedAcc|movedPrd precedes [AE]X|MDX)
// ecm subject moved
      fin-O:       (ECM-IP-INF* iDoms movedEcmSbj) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes movedEcmSbj)
      O-fin:       (ECM-IP-INF* iDoms movedEcmSbj) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND (movedEcmSbj precedes [AE]X|MDX)
      -: ELSE
}

// nonfinite verb and direct object
17: { 
      -:          (ECM-IP-INF* iDoms CONJP)
      -:          (CODING-ECM-IP-INF* column 10 -|[oO]_scr|[oOp]_tra)
// object in situ, nonfinite verb in situ
      non-o:      (ECM-IP-INF* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (VPP*|VX* precedes acc|prd)
      o-non:      (ECM-IP-INF* iDoms !movedAcc|movedPrd|movedInf|movedPart) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (acc|prd precedes VPP*|VX*)
// object moved, nonfinite verb in situ
      non-o:      (ECM-IP-INF* iDoms movedAcc|movedPrd)                     AND (ECM-IP-INF* iDoms !movedInf|movedPart)       AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (VPP*|VX* precedes movedAcc|movedPrd)
      o-non:      (ECM-IP-INF* iDoms movedAcc|movedPrd)                     AND (ECM-IP-INF* iDoms !movedInf|movedPart)       AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* VPP*|VX*) AND (movedAcc|movedPrd precedes VPP*|VX*)
// object in situ, nonfinite verb moved
      non-o:      (ECM-IP-INF* iDoms !movedAcc|movedPrd)                    AND (ECM-IP-INF* iDoms movedInf|movedPart)        AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (movedInf|movedPart precedes acc|prd)
      o-non:      (ECM-IP-INF* iDoms !movedAcc|movedPrd)                    AND (ECM-IP-INF* iDoms movedInf|movedPart)        AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd)      AND (acc|prd precedes movedInf|movedPart)
// object moved, nonfinite verb moved
      non-o:      (ECM-IP-INF* iDoms movedAcc|movedPrd)                     AND (ECM-IP-INF* iDoms movedInf|movedPart)                                                               AND (movedInf|movedPart precedes movedAcc|movedPrd)
      o-non:      (ECM-IP-INF* iDoms movedAcc|movedPrd)                     AND (ECM-IP-INF* iDoms movedInf|movedPart)                                                               AND (movedAcc|movedPrd precedes movedInf|movedPart)
// ecm subject in situ, nonfinite verb in situ
      non-O:      (ECM-IP-INF* iDoms !movedEcmSbj|movedInf)  AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                    AND (VPP*|VX* precedes ecmSbj)
      O-non:      (ECM-IP-INF* iDoms !movedEcmSbj|movedInf)  AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP* iDoms VPP*|VX*)                    AND (ecmSbj precedes VPP*|VX*)
// ecm subject in situ, nonfinite verb moved
      non-O:      (ECM-IP-INF* iDoms !movedEcmSbj)           AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP-INF* iDoms movedInf|movedPart)      AND (movedInf|movedPart precedes ecmSbj)
      O-non:      (ECM-IP-INF* iDoms !movedEcmSbj)           AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ECM-IP-INF* iDoms movedInf|movedPart)      AND (ecmSbj precedes movedInf|movedPart)
// ecm subject moved, nonfinite verb in situ
      non-O:      (ECM-IP-INF* iDoms movedEcmSbj)            AND (ECM-IP-INF* iDoms !movedInf|movedPart)  AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (VPP*|VX* precedes movedEcmSbj)
      O-non:      (ECM-IP-INF* iDoms movedEcmSbj)            AND (ECM-IP-INF* iDoms !movedInf|movedPart)  AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms VPP*|VX*)  AND (movedEcmSbj precedes VPP*|VX*)
// ecm subject moved, nonfinite verb moved
      non-O:      (ECM-IP-INF* iDoms movedEcmSbj)            AND (ECM-IP-INF* iDoms movedInf|movedPart)                                                                 AND (movedInf|movedPart precedes movedEcmSbj)
      O-non:      (ECM-IP-INF* iDoms movedEcmSbj)            AND (ECM-IP-INF* iDoms movedInf|movedPart)                                                                 AND (movedEcmSbj precedes movedInf|movedPart)
// ecm subject in situ, predicate in situ
      prd-O:      (ECM-IP-INF* iDoms !movedEcmSbj)           AND (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes ecmSbj)
      O-prd:      (ECM-IP-INF* iDoms !movedEcmSbj)           AND (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (ecmSbj precedes *-PRD*|VG)
// ecm subject in situ, predicate moved
//
// ecm subject moved, predicate in situ
      prd-O:      (ECM-IP-INF* iDoms movedEcmSbj)            AND (ECM-IP-INF* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (*-PRD*|VG precedes movedEcmSbj)
      O-prd:      (ECM-IP-INF* iDoms movedEcmSbj)            AND (ECM-IP-INF* iDoms ECM-IP-SMC*)                                AND (ECM-IP-SMC* iDoms *-PRD*|VG)      AND (movedEcmSbj precedes *-PRD*|VG)
// ecm subject moved, predicate moved
//
      prd-O:      (ECM-IP* iDoms !movedEcmSbj)           AND (ECM-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (PP precedes ecmSbj)
      O-prd:      (ECM-IP* iDoms !movedEcmSbj)           AND (ECM-IP* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsTotal 2) AND (ECM-IP-SMC* iDoms ecmSbj) AND (ECM-IP-SMC* iDoms PP) AND (ecmSbj precedes PP)
      #17:        (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
      -: ELSE
}

// DIRECT OBJECT 
// quantificational type
18: { 
      -:       (ECM-IP-INF* iDoms CONJP)
      -:       (CODING-ECM-IP-INF* column 10 -|[oO]_scr|[oOp]_tra)
      s:       (CODING-ECM-IP-INF* column 10 [oO]_frl|[oO]_cp|[oO]_ip)
      cli:     (CODING-ECM-IP-INF* column 10 [oO]_cli|[oO]_res)
      def:     (CODING-ECM-IP-INF* column 10 [oO]_pro)
// monoclausal case without movement (including modal and PARTP cases)
      conj:    (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms DF)
      def:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms defHead)
      def:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      conj:    (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms DF)
      def:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
// modal - infinitive moved, object moved
      conj:    (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      conj:    (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms CONJP*)
      spl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDomsMod QP Q|Q[RS])
      par:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms DF)
      def:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms defHead)
      def:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms defDet)
      ind:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms D) AND (D iDoms indefDet)
      ind:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd iDoms !Q*|DF|defHead|D)
      #18:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      conj:    (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms CONJP*)
      spl:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDomsMod QP Q|Q[RS])
      par:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms DF)
      def:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms defHead)
      def:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms defDet)
      ind:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms D) AND (D iDoms indefDet)
      ind:     (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd iDoms !Q*|DF|defHead|D)
      #18:     (ECM-IP-INF* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      conj:    (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      conj:    (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms CONJP*)
      spl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDomsMod QP Q|Q[RS])
      par:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms DF)
      def:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms defHead)
      def:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms defDet)
      ind:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj iDoms !Q*|DF|defHead|D)
      #18:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
// small clause - infinitive in situ, subject moved
      conj:    (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms CONJP*)
      spl:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDomsMod QP Q|Q[RS])
      par:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms DF)
      def:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms defHead)
      def:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms defDet)
      ind:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms D) AND (D iDoms indefDet)
      ind:     (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj iDoms !Q*|DF|defHead|D)
      #18:     (ECM-IP-INF* iDoms movedEcmSbj)
      -:       ELSE
}

// DIRECT OBJECT 
// length
19: { 
      -:       (ECM-IP-INF* iDoms CONJP)
      -:       (CODING-ECM-IP-INF* column 10 -|[oO]_scr|[oOp]_tra)
// monoclausal case without movement (including modal and PARTP cases)
      \1:      (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 1)
      \2:      (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 2)
      \3:      (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 3)
      \4:      (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords 4)
      \5:      (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (ECM-IP-INF* iDoms !movedInf|movedAcc|movedPrd) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* acc|prd)
// ECM case without movement
      \1:      (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (ECM-IP-INF* iDoms !movedInf|movedEcmSbj) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
// modal - infinitive moved, object moved
      \1:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedAcc|movedPrd)
// modal - infinitive moved, object in situ
      \1:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 1)
      \2:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 2)
      \3:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 3)
      \4:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords 4)
      \5:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd) AND (acc|prd domsWords> 4)
      #19:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* acc|prd)
// modal - infinitive in situ, object moved; PARTP - object moved
      \1:      (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 1)
      \2:      (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 2)
      \3:      (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 3)
      \4:      (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords 4)
      \5:      (ECM-IP-INF* iDoms movedAcc|movedPrd) AND (movedAcc|movedPrd domsWords> 4)
      #19:     (ECM-IP-INF* iDoms movedAcc|movedPrd)
// small clause - infinitive moved, subject moved
      \1:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedEcmSbj)
// small clause - infinitive moved, subject in situ
      \1:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords 1)
      \2:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords 2)
      \3:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords 3)
      \4:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords 4)
      \5:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj) AND (ecmSbj domsWords> 4)
      #19:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ecmSbj)
// small clause - infinitive in situ, subject moved
      \1:      (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 1)
      \2:      (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 2)
      \3:      (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 3)
      \4:      (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords 4)
      \5:      (ECM-IP-INF* iDoms movedEcmSbj) AND (movedEcmSbj domsWords> 4)
      #19:     (ECM-IP-INF* iDoms movedEcmSbj)
      -:       ELSE
}

// finite verb and indirect object
20: { 
      -:           (ECM-IP-INF* iDoms CONJP)
      -:           (CODING-ECM-IP-INF* column 11 -)
// object in situ
      fin-o:       (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (ECM-IP-INF* iDoms !movedDtv) AND (ECM-IP-INF* iDoms finiteAll) AND (finiteAll precedes dtv)
      o-fin:       (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* dtv) AND (ECM-IP-INF* iDoms !movedDtv) AND (ECM-IP-INF* iDoms finiteAll) AND (dtv precedes finiteAll)
// ecm subject in situ
      fin-O:       (ECM-IP-INF* iDomsMod ECM-IP-INF* ecmSbj) AND (ECM-IP-INF* iDoms !movedEcmSbj) AND (ECM-IP-INF* iDoms finiteAll) AND (finiteAll precedes ecmSbj) AND (ecmSbj iDoms DAT)
      O-fin:       (ECM-IP-INF* iDomsMod ECM-IP-INF* ecmSbj) AND (ECM-IP-INF* iDoms !movedEcmSbj) AND (ECM-IP-INF* iDoms finiteAll) AND (ecmSbj precedes finiteAll) AND (ecmSbj iDoms DAT)
// moved object
      fin-o:       (ECM-IP-INF* iDoms movedDtv) AND (ECM-IP-INF* iDoms finiteAll) AND (finiteAll precedes movedDtv)
      o-fin:       (ECM-IP-INF* iDoms movedDtv) AND (ECM-IP-INF* iDoms finiteAll) AND (movedDtv precedes finiteAll)
// ecm subject moved
      fin-O:       (ECM-IP-INF* iDoms movedEcmSbj) AND (ECM-IP-INF* iDoms finiteAll) AND (finiteAll precedes movedEcmSbj) AND (movedEcmSbj iDoms DAT)
      O-fin:       (ECM-IP-INF* iDoms movedEcmSbj) AND (ECM-IP-INF* iDoms finiteAll) AND (movedEcmSbj precedes finiteAll) AND (movedEcmSbj iDoms DAT)
     -: ELSE
}

// finite verb and first PP
21: { 
      -:           (ECM-IP-INF* iDoms CONJP)
      -:           (CODING-ECM-IP-INF* column 12 -)
// PP in situ
      fin-o:       (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (ECM-IP-INF* iDoms !movedFirstPP) AND (ECM-IP-INF* iDoms finiteAll) AND (finiteAll precedes firstPP)
      o-fin:       (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (ECM-IP-INF* iDoms !movedFirstPP) AND (ECM-IP-INF* iDoms finiteAll) AND (firstPP precedes finiteAll)
// moved PP
      fin-o:       (ECM-IP-INF* iDoms movedFirstPP) AND (ECM-IP-INF* iDoms finiteAll) AND (finiteAll precedes movedFirstPP)
      o-fin:       (ECM-IP-INF* iDoms movedFirstPP) AND (ECM-IP-INF* iDoms finiteAll) AND (movedFirstPP precedes finiteAll)
     -: ELSE
}

// nonfinite verb raising
22: { 
      -:               (ECM-IP-INF* iDoms CONJP)
      -:               (CODING-ECM-IP-INF* column 10 -|[oO]_scr|[oOp]_tra)
// participle
      advp-part-o:     (ECM-IP-INF* iDoms NP-ACC*) AND (ECM-IP-INF* iDoms VPP*) AND (ECM-IP-INF* iDoms ADVP*) AND (ADVP* iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      advp-o-part:     (ECM-IP-INF* iDoms NP-ACC*) AND (ECM-IP-INF* iDoms VPP*) AND (ECM-IP-INF* iDoms ADVP*) AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-advp-o:     (ECM-IP-INF* iDoms NP-ACC*) AND (ECM-IP-INF* iDoms VPP*) AND (ECM-IP-INF* iDoms ADVP*) AND (VPP* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-part-o:       (ECM-IP-INF* iDoms NP-ACC*) AND (ECM-IP-INF* iDoms VPP*) AND (ECM-IP-INF* iDoms prepP) AND (prepP iPrecedes VPP*) AND (VPP* iPrecedes NP-ACC*)
      pp-o-part:       (ECM-IP-INF* iDoms NP-ACC*) AND (ECM-IP-INF* iDoms VPP*) AND (ECM-IP-INF* iDoms prepP) AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VPP*)
      part-pp-o:       (ECM-IP-INF* iDoms NP-ACC*) AND (ECM-IP-INF* iDoms VPP*) AND (ECM-IP-INF* iDoms prepP) AND (VPP* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
// modal - infinitive in situ, object in situ
      advp-inf-o:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      advp-o-inf:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (ADVP* iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-advp-o:      (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms ADVP*)
                   AND (VX* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-ACC*)
      pp-inf-o:        (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes VX*) AND (VX* iPrecedes NP-ACC*)
      pp-o-inf:        (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (prepP iPrecedes NP-ACC*) AND (NP-ACC* iPrecedes VX*)
      inf-pp-o:        (ECM-IP-INF* iDoms MOD-IP-INF*) AND (MOD-IP-INF* iDoms VX*) AND (MOD-IP-INF* iDoms NP-ACC*) AND (MOD-IP-INF* iDoms prepP)
                   AND (VX* iPrecedes prepP) AND (prepP iPrecedes NP-ACC*)
      -: ELSE
}

// tense of AVOIR
23: { -: ELSE
}

// gender of antecedent
24: { 
      -:     (ECM-IP-INF* iDoms CONJP)
      coord: (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-C*|NP-ACC-C*)
      part:  (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-D*|NP-ACC-D*)
      f:     (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-F*|NP-ACC-F*)
      m:     (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-M[CDPSX]|CL-NP-ACC-M[CDPSX].*|NP-ACC-M[CDPSX]|NP-ACC-M[CDPSX].*)
      x:     (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-X*|NP-ACC-X*)
      coord: (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-C*|NP-ECM-SBJ-C*)
      part:  (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-D*|NP-ECM-SBJ-D*)
      f:     (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-F*|NP-ECM-SBJ-F*)
      m:     (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-M[CDPSX]|CL-NP-ECM-SBJ-M[CDPSX].*|NP-ECM-SBJ-M[CDPSX]|NP-ECM-SBJ-M[CDPSX].*)
      x:     (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-X*|NP-ECM-SBJ-X*)
      -: ELSE
}
          
// number of antecedent
25: { 
      -:     (ECM-IP-INF* iDoms CONJP)
      coord: (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-[CDFMX]C*|NP-ACC-[CDFMX]C*)
      part:  (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-[CDFMX]D*|NP-ACC-[CDFMX]D*)
      pl:    (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-[CDFMX]P*|NP-ACC-[CDFMX]P*)
      sg:    (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-[CDFMX]S*|NP-ACC-[CDFMX]S*)
      x:     (ECM-IP-INF* iDomsMod PARTP* CL-NP-ACC-[CDFMX]X*|NP-ACC-[CDFMX]X*)
      coord: (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]C*|NP-ECM-SBJ-[CDFMX]C*)
      part:  (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]D*|NP-ECM-SBJ-[CDFMX]D*)
      pl:    (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]P*|NP-ECM-SBJ-[CDFMX]P*)
      sg:    (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]S*|NP-ECM-SBJ-[CDFMX]S*)
      x:     (ECM-IP-INF* iDoms ECM-IP-SMC*) AND (ECM-IP-SMC* iDomsMod ECM-IP-SM* CL-NP-ECM-SBJ-[CDFMX]X*|NP-ECM-SBJ-[CDFMX]X*)
      -: ELSE
}

// gender of participle
26: { 
      -:     (ECM-IP-INF* iDoms CONJP)
      coord: (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-C*)
      part:  (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-D*)
      f:     (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-F*)
      m:     (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-M*)
      x:     (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-X*)
      -: ELSE
}
          
// number of participle
27: { 
      -:     (ECM-IP-INF* iDoms CONJP)
      coord: (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]C*)
      part:  (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]D*)
      pl:    (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]P*)
      sg:    (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]S*)
      x:     (ECM-IP-INF* iDomsMod PARTP*|ECM-IP-SMC* VPP-[CDFMX]X*)
      -: ELSE
}

