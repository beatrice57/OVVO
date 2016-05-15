node: ECM-IP-INF*

define: GTRC.def

// count clitics, neg, traces
ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF

coding_query:

// TEXT
1: {  
      besti_r: (1128-best* inID)
      gormo_r: (1130-gorm* inID)
      juise_r: (1138-Juis* inID)
      lapid_p: (1150-Lapi* inID)
      psorn_p: (1150-PsOr* inID)
      enea1_r: (1155-eneas1* inID)
      enea2_r: (1155-eneas2* inID)
      provs_p: (1165-Prov* inID)
      becke_r: (1173-beck* inID)
      bendu_p: (1174-BenD* inID)
      fanto_r: (1175-Fant* inID)
      mirnd_r: (1175-MirN* inID)
      adgar_r: (1183-adga* inID)
      cobe__r: (1185-cobe* inID)
      blond_r: (1190-Blon* inID)
      digr1_p: (1190-DialGreg1* inID)
      digr2_p: (1190-DialGreg2* inID)
      diame_p: (1200-DialA* inID)
      sermm_p: (1200-Serm* inID)
      stras_p: (*STRASB* inID)
      eulal_p: (*EULAL* inID)
      leger_v: (*LEGER* inID)
      passi_p: (*PASSION* inID)
      alexi_v: (*ALEXIS* inID)
      rolan_v: (*ROLAND* inID)
      lapid_r: (*LAPID* inID)
      brend_r: (*BRENDAN* inID)
      quatr_p: (*QUATRE* inID)
      marie_r: (*MARIE* inID)
      yvain_r: (*YVAIN* inID)
      berna_p: (*BERN* inID)
      boron_r: (*BORON-R* inID)
      clari_p: (*CLARI* inID)
      boron_p: (*BORON-P* inID)
      eustf_r: (*EUSTACE-FISHER-R* inID)
      quest_p: (*QUESTE* inID)
      agnes_p: (*AGNES* inID)
      aucas_p: (*AUCASSIN-*-P* inID)
      aucas_v: (*AUCASSIN-*-V* inID)
      eustp_r: (*EUSTACE-PETERSEN-R* inID)
      turpi_p: (*TURPIN* inID)
      eustm_p: (*EUSTACE-MURRAY-P* inID)
      somme_p: (*SOMME* inID)
      cassi_p: (*CASSIDORUS* inID)
      joinv_p: (*JOINVILLE* inID)
      perce_p: (*PERCEFOREST* inID)
      frois_p: (*FROISSART-P* inID)
      froi1_p: (*FROISSART-1* inID)
      froi2_p: (*FROISSART-2* inID)
      froi3_p: (*FROISSART-3* inID)
      froi4_p: (*FROISSART-4* inID)
      froi5_p: (*FROISSART-5* inID)
      froi6_p: (*FROISSART-6* inID)
      froi7_p: (*FROISSART-7* inID)
      froi8_p: (*FROISSART-8* inID)
      prise_r: (*PRISE* inID)
      xvjoi_p: (*XV-JOIES* inID)
      cnna__p: (*CNNA* inID)
      commy_p: (*COMMYNES* inID)
      newte_p: (*NEW-TEST* inID)
      bayar_p: (*BAYART* inID)
      valoi_p: (*VALOIS* inID)
      #1:     ELSE
}

// filled in by add-dates-french
2: { -: ELSE
}

// filled in by add-dates-french
3: { -: ELSE
}

// CLAUSE TYPE
4: { gap: (ECM-IP-INF*=* exists)
     -:   (ECM-IP-INF* iDoms CONJP)
     ecm: (ECM-IP-INF* exists)
     -: ELSE
}

// SUBJECT
// type of subject
5: { -:          (ECM-IP-INF* iDoms CONJP)
     -:          (ECM-IP* iDoms ZZZ-NP-ECM-SBJ*)
// overt subject
     s_cli:      (ECM-IP-INF* iDoms CL-NP-ECM-SBJ*)
     s_Pro:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO) AND (PRO iDoms weakSubjPronoun)
     s_Dem:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO) AND (PRO iDoms !weakSubjPronoun)
     s_Exp:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PROIMP)
     s_NP:       (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
     s_Frl:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
     s_CP:       (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
     s_IP:       (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
     s_Inf:      (ECM-IP-INF* iDoms *IP-INF-ECM*)
// silent subject
// traces (for parallelism with subordinate clauses)
     -:          (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
     s_scr:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*ICH\**)
     s_tra:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*T\**)
     s_arb:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*)
     s_exp:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*proimp\*)
     s_pro:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*pro\*)
     s_con:      (ECM-IP-INF* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*con\*)
     #5:         (ECM-IP-INF* iDoms *-ECM*)
     -: ELSE
}

// FINITE VERB
// type
6:  { -:            (ECM-IP-INF* iDoms CONJP)
      coord:        (ECM-IP-INF* iDoms [AE]X|MDX|VX) AND ([AE]X|MDX|VX iDoms CONJ[OP])
      aux-avoir:    (ECM-IP-INF* iDoms AX)
      aux-etre:     (ECM-IP-INF* iDoms EX)
      mod-dev:      (ECM-IP-INF* iDoms MDX) AND (MDX iDoms [dD].*)
      mod-pouv:     (ECM-IP-INF* iDoms MDX) AND (MDX iDoms [pP].*|rep*)
      mod-voul:     (ECM-IP-INF* iDoms MDX) AND (MDX iDoms [uUvVwW].*|bee)
      mod:          (ECM-IP-INF* iDoms MDX)
      avoir-sc-vpp: (ECM-IP-INF* iDoms VX) AND (VX iDoms [aA][uv][eo]ir) AND (ECM-IP-INF* iDomsMod ECM-IP-SMC* VPP*)
      main-sc-vpp:  (ECM-IP-INF* iDoms VX) AND (ECM-IP-INF* iDomsMod ECM-IP-SMC* VPP*)
      main-sc:      (ECM-IP-INF* iDoms VX) AND (ECM-IP-INF* iDoms ECM-IP-SMC*)
      main-ecm:     ([1]ECM-IP-INF* iDoms VX) AND ([1]ECM-IP-INF* iDoms [2]ECM-IP-INF*)
      main-etre:    (ECM-IP-INF* iDoms VX) AND (VX iDoms etre)
      main-avoir:   (ECM-IP-INF* iDoms VX) AND (VX iDoms avoir)
      main:         (ECM-IP-INF* iDoms VX)
      -: ELSE
}

// ORDER
// subject and finite verb
// 7: { in ecm-2.c

// subject and nonfinite verb
8: { -:	ELSE
}

// finite and nonfinite verb
9: { -:         (ECM-IP-INF* iDoms CONJP)
     no-aux:    (ECM-IP-INF* iDoms ![AE]X|MDX)
// no ordinary case
// perfect
     fin-non:   (ECM-IP-INF* iDomsMod PARTP* VPP*) AND (ECM-IP-INF* iDoms !movedPart) AND (ECM-IP-INF* iDoms [AE]X) AND ([AE]X precedes VPP*)
     non-fin:   (ECM-IP-INF* iDomsMod PARTP* VPP*) AND (ECM-IP-INF* iDoms !movedPart) AND (ECM-IP-INF* iDoms [AE]X) AND (VPP* precedes [AE]X)
// infinitive in situ
     fin-non:   (ECM-IP-INF* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (ECM-IP-INF* iDoms !movedInf) AND (ECM-IP-INF* iDoms MDX|VX) AND (MDX|VX precedes MOD-IP-INF*|ECM-IP-INF*)
     non-fin:   (ECM-IP-INF* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (ECM-IP-INF* iDoms !movedInf) AND (ECM-IP-INF* iDoms MDX|VX) AND (MOD-IP-INF*|ECM-IP-INF* precedes MDX|VX)
// infinitive or participle moved
     fin-non:   (ECM-IP-INF* iDoms movedInf|movedPart) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes movedInf|movedPart)
     non-fin:   (ECM-IP-INF* iDoms movedInf|movedPart) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND (movedInf|movedPart precedes [AE]X|MDX)
     -:	ELSE
}

// DIRECT OBJECT
// type
10: { 
      -:         (ECM-IP-INF* iDoms CONJP)
// exclude dative subjects in ECM contexts
      -:         ([1]ECM-IP-INF* iDoms [2]ECM-IP-INF*)  AND ([2]ECM-IP-INF* iDomsMod NP-ECM-SBJ*|NP DAT)
// exclude raised passive subjects in ECM contexts
      -:         (ECM-IP-INF* iDoms *-SBJ*)  AND (ECM-IP-INF* iDoms EX|EPP) 
             AND (ECM-IP-INF* iDoms ECM-IP-IN*) AND (ECM-IP-IN* iDoms *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \**) AND (*-SBJ* sameIndex \**)
// exclude *arb*, *pro*, *proimp* in ECM contexts
      -:         (ECM-IP-INF* iDoms ECM-IP-IN*) AND (ECM-IP-IN* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*|\*pro\*|\*proimp\*)
// exclude plain *
      -:         (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms \*)
      -:         (ECM-IP-INF* iDoms ECM-IP-IN*) AND (ECM-IP-IN* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
// trace
      o_tra:     (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms \*T*)
      O_tra:     (ECM-IP-INF* iDoms ECM-IP-IN*) AND (ECM-IP-IN* iDoms *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \*T*)
      p_tra:     (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*RSP*)
      o_res:     (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* CL-NP-ACC*RSP*)
      o_cli:     (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* CL-NP-ACC*)
      o_np:      (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsMod NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms PRO)
      o_frl:     (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsFirst CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsOnly CP*)
      o_ip:      (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms !movedAcc|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*)
// // prd
//      p_Res:     (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*RSP*)
//      p_res:     (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* CL-NP-PRD*RSP*)
      p_cli:     (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* CL-NP-PRD*)
      p_np:      (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsMod NP fullNP)
//      p_pro:     (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDoms PRO)
//      p_frl:     (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsFirst CP-FRL*)
//      p_cp:      (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsOnly CP*)
//      p_ip:      (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms !movedPrd|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*)
// ECM case without movement
      O_Res:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*RSP*)
      O_res:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms CL-NP-ECM-SBJ*RSP*)
      O_cli:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms CL-NP-ECM-SBJ*)
      O_np:      (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
      O_pro:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)
      O_frl:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
      O_ip:      (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*)
// modal - infinitive moved, object moved
      o_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (ECM-IP-INF* iDomsMod MOD-IP-INF* ZZZ-NP-ACC-RSP*)
      o_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-ACC-MOVED*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* ZZZ-NP-ACC-RSP*)
      o_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-ACC-MOVED*)
      o_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsMod NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDoms PRO)
      o_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly CP*)
      o_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ACC-MOVED*)
// // prd
//      p_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (ECM-IP-INF* iDomsMod MOD-IP-INF* ZZZ-NP-PRD-RSP*)
//      p_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-PRD-MOVED*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* ZZZ-NP-PRD-RSP*)
      p_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-PRD-MOVED*)
      p_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsMod NP fullNP)
//      p_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDoms PRO)
//      p_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsFirst CP-FRL*)
//      p_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly CP*)
//      p_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-PRD-MOVED*)
// modal - infinitive moved, object in situ
      o_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-ACC-RSP*)
      o_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* CL-NP-ACC-RSP*)
      o_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* CL-NP-ACC*)
      o_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsMod NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDoms PRO)
      o_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsFirst CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsOnly CP*)
      o_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-ACC*)
// // prd
//      p_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-PRD-RSP*)
//      p_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* CL-NP-PRD-RSP*)
      p_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* CL-NP-PRD*)
      p_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsMod NP fullNP)
//      p_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDoms PRO)
//      p_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsFirst CP-FRL*)
//      p_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsOnly CP*)
//      p_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-PRD*)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-ACC-RSP*)
      o_res:     (ECM-IP-INF* iDoms CL-NP-ACC-MOVED*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-ACC-RSP*)
      o_cli:     (ECM-IP-INF* iDoms CL-NP-ACC-MOVED*)
      o_np:      (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsMod NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDoms PRO)
      o_frl:     (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly CP*)
      o_ip:      (ECM-IP-INF* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms NP-ACC-MOVED*)
// // prd
//      p_Res:     (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-PRD-RSP*)
//      p_res:     (ECM-IP-INF* iDoms CL-NP-PRD-MOVED*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-PRD-RSP*)
      p_cli:     (ECM-IP-INF* iDoms CL-NP-PRD-MOVED*)
      p_np:      (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsMod NP fullNP)
//      p_pro:     (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDoms PRO)
//      p_frl:     (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsFirst CP-FRL*)
//      p_cp:      (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly CP*)
//      p_ip:      (ECM-IP-INF* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms NP-PRD-MOVED*)
// small clause - infinitive moved, subject moved
      O_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*)    AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ZZZ-NP-ECM-SBJ*RSP*)
      O_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-ECM-MOVED*) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms ZZZ-CL-NP-ECM-SBJ*RSP*)
      O_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-ECM-MOVED*)
      O_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)
      O_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)
      O_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)
      O_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)
      O_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*)
// small clause - infinitive moved, subject in situ
      O_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*RSP*)
      O_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms CL-NP-ECM-SBJ*RSP*)
      O_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms CL-NP-ECM-SBJ*)
      O_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
      O_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)
      O_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
      O_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*)
// small clause - infinitive in situ, subject moved
      O_Res:     (ECM-IP-INF* iDoms NP-ECM-MOVED*)    AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)
      O_res:     (ECM-IP-INF* iDoms CL-NP-ECM-MOVED*) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)
      O_cli:     (ECM-IP-INF* iDoms CL-NP-ECM-MOVED*)
      O_np:      (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)
      O_pro:     (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)
      O_frl:     (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)
      O_cp:      (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)
      O_ip:      (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ECM-IP-INF* iDoms NP-ECM-MOVED*)
      -:         ELSE
}

// INDIRECT OBJECT
// type
11: {  
      -:         (ECM-IP-INF* iDoms CONJP)
// include dative subjects in ECM contexts (see below)
// exclude raised passive subjects in ECM contexts
      -:         (ECM-IP-INF* iDoms *-SBJ*)  AND (ECM-IP-INF* iDoms EX|EPP) 
             AND (ECM-IP-INF* iDoms ECM-IP-IN*) AND (ECM-IP-IN* iDoms *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \**) AND (*-SBJ* sameIndex \**)
// exclude *arb*, *pro*, *proimp* in ECM contexts
      -:         (ECM-IP-INF* iDoms ECM-IP-IN*) AND (ECM-IP-IN* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*|\*pro\*|\*proimp\*)
// exclude plain *
      -:         (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms \*)
      -:         (ECM-IP-INF* iDoms ECM-IP-IN*) AND (ECM-IP-IN* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
// trace
      o_tra:     (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms \*T*)
      O_tra:     (ECM-IP-INF* iDoms ECM-IP-IN*) AND (ECM-IP-IN* iDoms *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*RSP*)
      o_res:     (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* CL-NP-DTV*RSP*)
      o_cli:     (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* CL-NP-DTV*)
      o_np:      (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsMod NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms PRO)
      o_frl:     (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsFirst CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsOnly CP*)
      o_ip:      (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (ECM-IP-INF* iDoms !movedDtv|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*)
// ECM case without movement
      O_Res:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*RSP*)                                           AND (NP-ECM-SBJ*RSP* iDoms DAT)
      O_res:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms CL-NP-ECM-SBJ*RSP*)                                        AND (CL-NP-ECM-SBJ*RSP* iDoms DAT)
      O_cli:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms CL-NP-ECM-SBJ*)                                            AND (CL-NP-ECM-SBJ* iDoms DAT)
      O_np:      (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)          AND (NP-ECM-SBJ* iDoms DAT)
      O_pro:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)                   AND (NP-ECM-SBJ* iDoms DAT)
      O_frl:     (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)          AND (NP-ECM-SBJ* iDoms DAT)
      O_cp:      (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)               AND (NP-ECM-SBJ* iDoms DAT)
      O_ip:      (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE) AND (NP-ECM-SBJ* iDoms DAT)
      #11:       (ECM-IP-INF* iDoms !movedEcmSbj|movedInf) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDoms NP-ECM-SBJ*)                                               AND (NP-ECM-SBJ* iDoms DAT) 
// modal - infinitive moved, object moved
      o_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (ECM-IP-INF* iDomsMod MOD-IP-INF* ZZZ-NP-DTV-RSP*)
      o_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-DTV-MOVED*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* ZZZ-NP-DTV-RSP*)
      o_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-DTV-MOVED*)
      o_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsMod NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDoms PRO)
      o_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly CP*)
      o_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-DTV-MOVED*)
// modal - infinitive moved, object in situ
      o_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-DTV-RSP*)
      o_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* CL-NP-DTV-RSP*)
      o_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* CL-NP-DTV*)
      o_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsMod NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDoms PRO)
      o_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsFirst CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsOnly CP*)
      o_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* NP-DTV*)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-DTV-RSP*)
      o_res:     (ECM-IP-INF* iDoms CL-NP-DTV-MOVED*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-DTV-RSP*)
      o_cli:     (ECM-IP-INF* iDoms CL-NP-DTV-MOVED*)
      o_np:      (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsMod NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDoms PRO)
      o_frl:     (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly CP*)
      o_ip:      (ECM-IP-INF* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (ECM-IP-INF* iDoms NP-DTV-MOVED*)
// small clause - infinitive moved, subject moved
      O_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*)    AND (ECM-IP-INF* iDomsMod ECM-IP* ZZZ-NP-ECM-SBJ*RSP*)    AND (NP-ECM-MOVED* iDoms DAT)
      O_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-ECM-MOVED*) AND (ECM-IP-INF* iDomsMod ECM-IP* ZZZ-CL-NP-ECM-SBJ*RSP*) AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms CL-NP-ECM-MOVED*)                                                       AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)                   AND (NP-ECM-MOVED* iDoms DAT)
      O_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)                            AND (NP-ECM-MOVED* iDoms DAT)
      O_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)                   AND (NP-ECM-MOVED* iDoms DAT)
      O_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)                        AND (NP-ECM-MOVED* iDoms DAT)
      O_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)          AND (NP-ECM-MOVED* iDoms DAT)
      #11:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms NP-ECM-MOVED*)
// small clause - infinitive moved, subject in situ
      O_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)                                           AND (NP-ECM-SBJ*RSP* iDoms DAT)
      O_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)                                        AND (CL-NP-ECM-SBJ*RSP* iDoms DAT)
      O_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)                                            AND (CL-NP-ECM-SBJ* iDoms DAT)
      O_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)          AND (NP-ECM-SBJ* iDoms DAT)
      O_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)                   AND (NP-ECM-SBJ* iDoms DAT)
      O_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)          AND (NP-ECM-SBJ* iDoms DAT)
      O_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)               AND (NP-ECM-SBJ* iDoms DAT)
      O_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE) AND (NP-ECM-SBJ* iDoms DAT)
      #11:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod ECM-IP* NP-ECM-SBJ*)                                               AND (NP-ECM-SBJ* iDoms DAT)
// small clause - infinitive in situ, subject moved
      O_Res:     (ECM-IP-INF* iDoms NP-ECM-MOVED*)    AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)       AND (NP-ECM-MOVED* iDoms DAT)
      O_res:     (ECM-IP-INF* iDoms CL-NP-ECM-MOVED*) AND (ECM-IP-INF* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)       AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_cli:     (ECM-IP-INF* iDoms CL-NP-ECM-MOVED*)                                                                                  AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_np:      (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)                                              AND (NP-ECM-MOVED* iDoms DAT)
      O_pro:     (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)                                                       AND (NP-ECM-MOVED* iDoms DAT)
      O_frl:     (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)                                              AND (NP-ECM-MOVED* iDoms DAT)
      O_cp:      (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)                                                   AND (NP-ECM-MOVED* iDoms DAT)
      O_ip:      (ECM-IP-INF* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)                                     AND (NP-ECM-MOVED* iDoms DAT)
      #11:       (ECM-IP-INF* iDoms NP-ECM-MOVED*)                                                                                     AND (NP-ECM-MOVED* iDoms DAT)
      -:         ELSE
}

// FIRST PP
// type of PP
12: {  
      -:       (ECM-IP-INF* iDoms CONJP)
// trace
      #12:     (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      xxx:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-XXX*)
      arg:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-ARG*)
      dir:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-DIR*)
      loc:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-LOC*)
      mod:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-MOD*)
      msr:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-MSR*)
      prd:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-PRD*)
      tmp:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-TMP*)
      #12:     (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, PP moved
      xxx:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms FIRST-PP-XXX-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      arg:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms FIRST-PP-ARG-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      dir:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms FIRST-PP-DIR-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      loc:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms FIRST-PP-LOC-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      mod:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms FIRST-PP-MOD-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      msr:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms FIRST-PP-MSR-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      prd:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms FIRST-PP-PRD-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      tmp:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms FIRST-PP-TMP-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      #12:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms movedFirstPP)        AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
// modal - infinitive moved, PP in situ
      xxx:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* FIRST-PP-XXX*)
      arg:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* FIRST-PP-ARG*)
      dir:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* FIRST-PP-DIR*)
      loc:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* FIRST-PP-LOC*)
      mod:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* FIRST-PP-MOD*)
      msr:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* FIRST-PP-MSR*)
      prd:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* FIRST-PP-PRD*)
      tmp:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* FIRST-PP-TMP*)
      #12:     (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, PP moved; PARTP - PP moved
      xxx:     (ECM-IP* iDoms FIRST-PP-XXX-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      arg:     (ECM-IP* iDoms FIRST-PP-ARG-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      dir:     (ECM-IP* iDoms FIRST-PP-DIR-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      loc:     (ECM-IP* iDoms FIRST-PP-LOC-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      mod:     (ECM-IP* iDoms FIRST-PP-MOD-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      msr:     (ECM-IP* iDoms FIRST-PP-MSR-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      prd:     (ECM-IP* iDoms FIRST-PP-PRD-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      tmp:     (ECM-IP* iDoms FIRST-PP-TMP-MOVED*) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      #12:     (ECM-IP* iDoms movedFirstPP)        AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      -:         ELSE
}

// FIRST PP
// preposition is A or not
13: {  
      -:       (ECM-IP-INF* iDoms CONJP)
// trace
      #13:     (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      y:       (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|P datPrep)
      n:       (ECM-IP* iDoms !movedFirstPP|movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, object moved
      y:       (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms movedFirstPP) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*) AND (movedFirstPP iDomsMod PP|P datPrep)
      n:       (ECM-IP* iDoms movedInf) AND (ECM-IP* iDoms movedFirstPP) AND (ECM-IP* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
// modal - infinitive moved, object in situ
      y:       (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|P datPrep)
      n:       (ECM-IP* iDoms movedInf) AND (ECM-IP* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, object moved; PARTP - object moved
      y:       (ECM-IP* iDoms movedFirstPP)    AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*) AND (movedFirstPP iDomsMod PP|P datPrep)
      n:       (ECM-IP* iDoms movedFirstPP)    AND (ECM-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
      -:        ELSE
}

// FIRST PP
// type of complement
14: { 
      -:         (ECM-IP-INF* iDoms CONJP)
// trace
      #14:       (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* FIRST-CL-PP*RSP*)
//      o_cli:     (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* FIRST-CL-PP*)
      o_np:      (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP PRO)
      o_frl:     (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP CP*)
      o_ip:      (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (ECM-IP-INF* iDoms !movedFirstPP|movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, object moved
      o_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedFirstPP)    AND (ECM-IP-INF* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms FIRST-CL-PP-*-MOVED*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
//      o_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms FIRST-CL-PP-*-MOVED*)
      o_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP PRO)
      o_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP*)
      o_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDoms movedFirstPP)
// modal - infinitive moved, object in situ
      o_Res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* FIRST-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* FIRST-CL-PP*RSP*)
//      o_cli:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* FIRST-CL-PP*)
      o_np:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP PRO)
      o_frl:     (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP CP*)
      o_ip:      (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (ECM-IP-INF* iDoms movedInf) AND (ECM-IP-INF* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (ECM-IP-INF* iDoms movedFirstPP)    AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (ECM-IP-INF* iDoms FIRST-CL-PP-*-MOVED*) AND (ECM-IP-INF* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
//      o_cli:     (ECM-IP-INF* iDoms FIRST-CL-PP-*-MOVED*)
      o_np:      (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP fullNP)
      o_pro:     (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP PRO)
      o_frl:     (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP*)
      o_ip:      (ECM-IP-INF* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (ECM-IP-INF* iDoms movedFirstPP)
      -:         ELSE
}

