node: IP-PPL*

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
4: { gap: (IP-PPL*=* exists)
     ppl: (IP-PPL* exists)
     -: ELSE
}

// SUBJECT
// type of subject
5: {
// overt subject
     #5:         (IP-PPL* iDoms CL-NP-SBJ*)
     s_Pro:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDoms PRO) AND (PRO iDoms weakSubjPronoun)
     s_Dem:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDoms PRO) AND (PRO iDoms !weakSubjPronoun)
     s_Exp:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDoms PROIMP)
     s_NP:       (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDomsMod NP fullNP)
     s_Frl:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDomsFirst CP-FRL*)
     s_CP:       (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDomsOnly CP*)
     s_IP:       (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
     s_Inf:      (IP-PPL* iDoms *IP-INF-SBJ*)
// silent subject
// traces (for parallelism with subordinate clauses)
     s_scr:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*ICH\**)
     s_tra:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*T\**)
     s_exp:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*proimp\*)
     s_pro:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*pro\*)
     s_con:      (IP-PPL* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*con\*)
     #5:         (IP-PPL* iDoms *-SBJ*)
     -: ELSE
}

// FINITE VERB
// type
6:  { coord:        (IP-PPL* iDoms [AE]G|MDG|VG) AND ([AE]G|MDG|VG iDoms CONJ[OP])
      aux-avoir:    (IP-PPL* iDoms AG)
      aux-etre:     (IP-PPL* iDoms EG)
      mod-dev:      (IP-PPL* iDoms MDG) AND (MDG iDoms [dD].*)
      mod-pouv:     (IP-PPL* iDoms MDG) AND (MDG iDoms [pP].*|rep*)
      mod-voul:     (IP-PPL* iDoms MDG) AND (MDG iDoms [uUvVwW].*|bee)
      mod:          (IP-PPL* iDoms MDG)
      avoir-sc-vpp: (IP-PPL* iDoms VG) AND (VG iDoms [aA][iy]a*) AND (IP-PPL* iDomsMod ECM-IP-SMC* VPP*)
      main-sc-vpp:  (IP-PPL* iDoms VG) AND (IP-PPL* iDomsMod ECM-IP-SMC* VPP*)
      main-sc:      (IP-PPL* iDoms VG) AND (IP-PPL* iDoms ECM-IP-SMC*)
      main-ecm:     (IP-PPL* iDoms VG) AND (IP-PPL* iDoms ECM-IP-INF*)
      main-etre:    (IP-PPL* iDoms VG) AND (VG iDoms etre)
      main-avoir:   (IP-PPL* iDoms VG) AND (VG iDoms avoir)
      main:         (IP-PPL* iDoms VG)
      -: ELSE
}

// ORDER
// subject and finite verb
// 7: { in ppl-2.c

// subject and nonfinite verb
8: { 
// ordinary
     s-non:     (IP-PPL* iDoms VG) AND (IP-PPL* iDoms *-SBJ*) AND (*-SBJ* precedes VG)
     non-s:     (IP-PPL* iDoms VG) AND (IP-PPL* iDoms *-SBJ*) AND (VG precedes *-SBJ*)
// perfect
     s-non:     (IP-PPL* iDoms AG) AND (IP-PPL* iDoms VPP*) AND (IP-PPL* iDoms *-SBJ*) AND (*-SBJ* precedes VPP*)
     non-s:     (IP-PPL* iDoms AG) AND (IP-PPL* iDoms VPP*) AND (IP-PPL* iDoms *-SBJ*) AND (VPP* precedes *-SBJ*)
// infinitive in situ
     s-non:     (IP-PPL* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (IP-PPL* iDoms !movedInf) AND (IP-PPL* iDoms *-SBJ*) AND (*-SBJ* precedes MOD-IP-INF*|ECM-IP-INF*)
     non-s:     (IP-PPL* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (IP-PPL* iDoms !movedInf) AND (IP-PPL* iDoms *-SBJ*) AND (MOD-IP-INF*|ECM-IP-INF* precedes *-SBJ*)
// infinitive or participle moved
     s-non:     (IP-PPL* iDoms movedInf|movedPart) AND (IP-PPL* iDoms *-SBJ*) AND (*-SBJ* precedes movedInf|movedPart)
     non-s:     (IP-PPL* iDoms movedInf|movedPart) AND (IP-PPL* iDoms *-SBJ*) AND (movedInf|movedPart precedes *-SBJ*)
     -:	ELSE
}

// finite and nonfinite verb
9: { no-aux:    (IP-PPL* iDoms ![AE]G|MDG)
// no ordinary case
// perfect
     fin-non:   (IP-PPL* iDomsMod PARTP* VPP*) AND (IP-PPL* iDoms !movedPart) AND (IP-PPL* iDoms [AE]G) AND ([AE]G precedes VPP*)
     non-fin:   (IP-PPL* iDomsMod PARTP* VPP*) AND (IP-PPL* iDoms !movedPart) AND (IP-PPL* iDoms [AE]G) AND (VPP* precedes [AE]G)
// infinitive in situ
     fin-non:   (IP-PPL* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (IP-PPL* iDoms !movedInf) AND (IP-PPL* iDoms MDG|VG) AND (MDG|VG precedes MOD-IP-INF*|ECM-IP-INF*)
     non-fin:   (IP-PPL* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (IP-PPL* iDoms !movedInf) AND (IP-PPL* iDoms MDG|VG) AND (MOD-IP-INF*|ECM-IP-INF* precedes MDG|VG)
// infinitive or participle moved
     fin-non:   (IP-PPL* iDoms movedInf|movedPart) AND (IP-PPL* iDoms [AE]G|MDG) AND ([AE]G|MDG precedes movedInf|movedPart)
     non-fin:   (IP-PPL* iDoms movedInf|movedPart) AND (IP-PPL* iDoms [AE]G|MDG) AND (movedInf|movedPart precedes [AE]G|MDG)
     -:	ELSE
}

// DIRECT OBJECT
// type
10: {
      -:         (IP-PPL* iDoms !acc|prd|movedAcc|movedPrd)
// exclude dative subjects in ECM contexts
      -:         (IP-PPL* iDoms ECM-IP-INF*)  AND (ECM-IP-INF* iDomsMod NP-ECM-SBJ*|NP DAT)
// exclude raised passive subjects in ECM contexts
      -:         (IP-PPL* iDoms *-SBJ*)  AND (IP-PPL* iDoms EG|EPP) 
             AND (IP-PPL* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \**) AND (*-SBJ* sameIndex \**)
// exclude *arb*, *pro*, *proimp* in ECM contexts
      -:         (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*|\*pro\*|\*proimp\*)
// exclude plain *
      -:         (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms \*)
      -:         (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
// trace
      o_tra:     (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms \*T*)
      O_tra:     (IP-PPL* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \*T*)
      p_tra:     (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*RSP*)
      o_res:     (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* CL-NP-ACC*RSP*)
      o_cli:     (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* CL-NP-ACC*)
      o_np:      (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsMod NP fullNP)
      o_pro:     (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms PRO)
      o_frl:     (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsFirst CP-FRL*)
      o_cp:      (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsOnly CP*)
      o_ip:      (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms !movedAcc|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*)
// // prd
//      p_Res:     (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*RSP*)
//      p_res:     (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* CL-NP-PRD*RSP*)
      p_cli:     (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* CL-NP-PRD*)
      p_np:      (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsMod NP fullNP)
//      p_pro:     (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDoms PRO)
//      p_frl:     (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsFirst CP-FRL*)
//      p_cp:      (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsOnly CP*)
//      p_ip:      (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms !movedPrd|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*)
// ECM case without movement
      O_Res:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)
      O_res:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)
      O_cli:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)
      O_np:      (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
      O_pro:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)
      O_frl:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
      O_ip:      (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*)
// modal - infinitive moved, object moved
      o_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ACC-MOVED*)    AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-NP-ACC-RSP*)
      o_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-ACC-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-NP-ACC-RSP*)
      o_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-ACC-MOVED*)
      o_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsMod NP fullNP)
      o_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDoms PRO)
      o_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly CP*)
      o_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ACC-MOVED*)
// // prd
//      p_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-PRD-MOVED*)    AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-NP-PRD-RSP*)
//      p_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-PRD-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-NP-PRD-RSP*)
      p_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-PRD-MOVED*)
      p_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsMod NP fullNP)
//      p_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDoms PRO)
//      p_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsFirst CP-FRL*)
//      p_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly CP*)
//      p_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-PRD-MOVED*)
// modal - infinitive moved, object in situ
      o_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-ACC-RSP*)
      o_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* CL-NP-ACC-RSP*)
      o_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* CL-NP-ACC*)
      o_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsMod NP fullNP)
      o_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDoms PRO)
      o_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsFirst CP-FRL*)
      o_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsOnly CP*)
      o_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-ACC*)
// // prd
//      p_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-PRD-RSP*)
//      p_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* CL-NP-PRD-RSP*)
      p_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* CL-NP-PRD*)
      p_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsMod NP fullNP)
//      p_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDoms PRO)
//      p_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsFirst CP-FRL*)
//      p_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsOnly CP*)
//      p_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-PRD*)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (IP-PPL* iDoms NP-ACC-MOVED*)    AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-ACC-RSP*)
      o_res:     (IP-PPL* iDoms CL-NP-ACC-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-ACC-RSP*)
      o_cli:     (IP-PPL* iDoms CL-NP-ACC-MOVED*)
      o_np:      (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsMod NP fullNP)
      o_pro:     (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDoms PRO)
      o_frl:     (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly CP*)
      o_ip:      (IP-PPL* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms NP-ACC-MOVED*)
// // prd 
//      p_Res:     (IP-PPL* iDoms NP-PRD-MOVED*)    AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-PRD-RSP*)
//      p_res:     (IP-PPL* iDoms CL-NP-PRD-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-PRD-RSP*)
      p_cli:     (IP-PPL* iDoms CL-NP-PRD-MOVED*)
      p_np:      (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsMod NP fullNP)
//      p_pro:     (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDoms PRO)
//      p_frl:     (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsFirst CP-FRL*)
//      p_cp:      (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly CP*)
//      p_ip:      (IP-PPL* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms NP-PRD-MOVED*)
// small clause - infinitive moved, subject moved
      O_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*)    AND (IP-PPL* iDomsMod ECM-IP* ZZZ-NP-ECM-SBJ*RSP*)
      O_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-ECM-MOVED*) AND (IP-PPL* iDomsMod ECM-IP* ZZZ-CL-NP-ECM-SBJ*RSP*)
      O_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-ECM-MOVED*)
      O_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)
      O_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)
      O_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)
      O_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)
      O_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*)
// small clause - infinitive moved, subject in situ
      O_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)
      O_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)
      O_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)
      O_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
      O_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)
      O_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
      O_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*)
// small clause - infinitive in situ, subject moved
      O_Res:     (IP-PPL* iDoms NP-ECM-MOVED*)    AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)
      O_res:     (IP-PPL* iDoms CL-NP-ECM-MOVED*) AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)
      O_cli:     (IP-PPL* iDoms CL-NP-ECM-MOVED*)
      O_np:      (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)
      O_pro:     (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)
      O_frl:     (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)
      O_cp:      (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)
      O_ip:      (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-PPL* iDoms NP-ECM-MOVED*)
      -:         ELSE
}

// INDIRECT OBJECT
// type
11: {
      -:         (IP-PPL* iDoms !dtv|movedDtv)
// include dative subjects in ECM contexts (see below)
// exclude raised passive subjects in ECM contexts
      -:         (IP-PPL* iDoms *-SBJ*)  AND (IP-PPL* iDoms EG|EPP) 
             AND (IP-PPL* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \**) AND (*-SBJ* sameIndex \**)
// exclude *arb*, *pro*, *proimp* in ECM contexts
      -:         (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*|\*pro\*|\*proimp\*)
// exclude plain *
      -:         (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms \*)
      -:         (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
// trace
      o_tra:     (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms \*T*)
      O_tra:     (IP-PPL* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*RSP*)
      o_res:     (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* CL-NP-DTV*RSP*)
      o_cli:     (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* CL-NP-DTV*)
      o_np:      (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsMod NP fullNP)
      o_pro:     (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms PRO)
      o_frl:     (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsFirst CP-FRL*)
      o_cp:      (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsOnly CP*)
      o_ip:      (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (IP-PPL* iDoms !movedDtv|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*)
// ECM case without movement
      O_Res:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)                                           AND (NP-ECM-SBJ*RSP* iDoms DAT)
      O_res:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)                                        AND (CL-NP-ECM-SBJ*RSP* iDoms DAT)
      O_cli:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)                                            AND (CL-NP-ECM-SBJ* iDoms DAT)
      O_np:      (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)          AND (NP-ECM-SBJ* iDoms DAT)
      O_pro:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)                   AND (NP-ECM-SBJ* iDoms DAT)
      O_frl:     (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)          AND (NP-ECM-SBJ* iDoms DAT)
      O_cp:      (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)               AND (NP-ECM-SBJ* iDoms DAT)
      O_ip:      (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE) AND (NP-ECM-SBJ* iDoms DAT)
      #11:       (IP-PPL* iDoms !movedEcmSbj|movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*)                                               AND (NP-ECM-SBJ* iDoms DAT)
// modal - infinitive moved, object moved
      o_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-DTV-MOVED*)    AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-NP-DTV-RSP*)
      o_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-DTV-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-NP-DTV-RSP*)
      o_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-DTV-MOVED*)
      o_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsMod NP fullNP)
      o_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDoms PRO)
      o_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly CP*)
      o_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-DTV-MOVED*)
// modal - infinitive moved, object in situ
      o_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-DTV-RSP*)
      o_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* CL-NP-DTV-RSP*)
      o_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* CL-NP-DTV*)
      o_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsMod NP fullNP)
      o_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDoms PRO)
      o_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsFirst CP-FRL*)
      o_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsOnly CP*)
      o_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* NP-DTV*)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (IP-PPL* iDoms NP-DTV-MOVED*)    AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-DTV-RSP*)
      o_res:     (IP-PPL* iDoms CL-NP-DTV-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-DTV-RSP*)
      o_cli:     (IP-PPL* iDoms CL-NP-DTV-MOVED*)
      o_np:      (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsMod NP fullNP)
      o_pro:     (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDoms PRO)
      o_frl:     (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly CP*)
      o_ip:      (IP-PPL* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (IP-PPL* iDoms NP-DTV-MOVED*)
// small clause - infinitive moved, subject moved
      O_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*)    AND (IP-PPL* iDomsMod ECM-IP* ZZZ-NP-ECM-SBJ*RSP*)    AND (NP-ECM-MOVED* iDoms DAT)
      O_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-ECM-MOVED*) AND (IP-PPL* iDomsMod ECM-IP* ZZZ-CL-NP-ECM-SBJ*RSP*) AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms CL-NP-ECM-MOVED*)                                                       AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)                   AND (NP-ECM-MOVED* iDoms DAT)
      O_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)                            AND (NP-ECM-MOVED* iDoms DAT)
      O_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)                   AND (NP-ECM-MOVED* iDoms DAT)
      O_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)                        AND (NP-ECM-MOVED* iDoms DAT)
      O_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)          AND (NP-ECM-MOVED* iDoms DAT)
      #11:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms NP-ECM-MOVED*)
// small clause - infinitive moved, subject in situ
      O_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)                                           AND (NP-ECM-SBJ*RSP* iDoms DAT)
      O_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)                                        AND (CL-NP-ECM-SBJ*RSP* iDoms DAT)
      O_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)                                            AND (CL-NP-ECM-SBJ* iDoms DAT)
      O_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)          AND (NP-ECM-SBJ* iDoms DAT)
      O_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)                   AND (NP-ECM-SBJ* iDoms DAT)
      O_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)          AND (NP-ECM-SBJ* iDoms DAT)
      O_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)               AND (NP-ECM-SBJ* iDoms DAT)
      O_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE) AND (NP-ECM-SBJ* iDoms DAT)
      #11:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod ECM-IP* NP-ECM-SBJ*)                                               AND (NP-ECM-SBJ* iDoms DAT)
// small clause - infinitive in situ, subject moved
      O_Res:     (IP-PPL* iDoms NP-ECM-MOVED*)    AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)       AND (NP-ECM-MOVED* iDoms DAT)
      O_res:     (IP-PPL* iDoms CL-NP-ECM-MOVED*) AND (IP-PPL* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)       AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_cli:     (IP-PPL* iDoms CL-NP-ECM-MOVED*)                                                                                  AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_np:      (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)                                              AND (NP-ECM-MOVED* iDoms DAT)
      O_pro:     (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)                                                       AND (NP-ECM-MOVED* iDoms DAT)
      O_frl:     (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)                                              AND (NP-ECM-MOVED* iDoms DAT)
      O_cp:      (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)                                                   AND (NP-ECM-MOVED* iDoms DAT)
      O_ip:      (IP-PPL* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)                                     AND (NP-ECM-MOVED* iDoms DAT)
      #11:       (IP-PPL* iDoms NP-ECM-MOVED*)                                                                                     AND (NP-ECM-MOVED* iDoms DAT)
      -:         ELSE
}

// FIRST PP
// type of PP
12: {  
      -:       (IP-PPL* iDoms !firstPP|movedFirstPP)
// trace
      #12:     (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      xxx:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-XXX*)
      arg:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-ARG*)
      dir:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-DIR*)
      loc:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-LOC*)
      mod:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-MOD*)
      msr:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-MSR*)
      prd:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-PRD*)
      tmp:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-TMP*)
      #12:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, PP moved
      xxx:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-PP-XXX-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      arg:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-PP-ARG-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      dir:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-PP-DIR-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      loc:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-PP-LOC-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      mod:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-PP-MOD-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      msr:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-PP-MSR-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      prd:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-PP-PRD-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      tmp:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-PP-TMP-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      #12:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP)        AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP-*)
// modal - infinitive moved, PP in situ
      xxx:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP-XXX*)
      arg:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP-ARG*)
      dir:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP-DIR*)
      loc:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP-LOC*)
      mod:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP-MOD*)
      msr:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP-MSR*)
      prd:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP-PRD*)
      tmp:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP-TMP*)
      #12:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, PP moved; PARTP - PP moved
      xxx:     (IP-PPL* iDoms FIRST-PP-XXX-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      arg:     (IP-PPL* iDoms FIRST-PP-ARG-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      dir:     (IP-PPL* iDoms FIRST-PP-DIR-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      loc:     (IP-PPL* iDoms FIRST-PP-LOC-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      mod:     (IP-PPL* iDoms FIRST-PP-MOD-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      msr:     (IP-PPL* iDoms FIRST-PP-MSR-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      prd:     (IP-PPL* iDoms FIRST-PP-PRD-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      tmp:     (IP-PPL* iDoms FIRST-PP-TMP-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      #12:     (IP-PPL* iDoms movedFirstPP)        AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      -:         ELSE
}

// FIRST PP
// preposition is A or not
13: {  
      -:       (IP-PPL* iDoms !firstPP|movedFirstPP)
// trace
      #13:     (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      y:       (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|P datPrep)
      n:       (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, object moved
      y:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*) AND (movedFirstPP iDomsMod PP|P datPrep)
      n:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
// modal - infinitive moved, object in situ
      y:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|P datPrep)
      n:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, object moved; PARTP - object moved
      y:       (IP-PPL* iDoms movedFirstPP)    AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*) AND (movedFirstPP iDomsMod PP|P datPrep)
      n:       (IP-PPL* iDoms movedFirstPP)    AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
      -:        ELSE
}

// FIRST PP
// type of complement
14: {
      -:         (IP-PPL* iDoms !firstPP|movedFirstPP)
// trace
      #14:       (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-CL-PP*RSP*)
//      o_cli:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* FIRST-CL-PP*)
      o_np:      (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP fullNP)
      o_pro:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP PRO)
      o_frl:     (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP CP*)
      o_ip:      (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (IP-PPL* iDoms !movedFirstPP|movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, object moved
      o_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP)    AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-CL-PP-*-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
//      o_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms FIRST-CL-PP-*-MOVED*)
      o_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP fullNP)
      o_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP PRO)
      o_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP*)
      o_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDoms movedFirstPP)
// modal - infinitive moved, object in situ
      o_Res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-CL-PP*RSP*)
//      o_cli:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* FIRST-CL-PP*)
      o_np:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP fullNP)
      o_pro:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP PRO)
      o_frl:     (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP CP*)
      o_ip:      (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (IP-PPL* iDoms movedInf) AND (IP-PPL* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (IP-PPL* iDoms movedFirstPP)    AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (IP-PPL* iDoms FIRST-CL-PP-*-MOVED*) AND (IP-PPL* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
//      o_cli:     (IP-PPL* iDoms FIRST-CL-PP-*-MOVED*)
      o_np:      (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP fullNP)
      o_pro:     (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP PRO)
      o_frl:     (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP*)
      o_ip:      (IP-PPL* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (IP-PPL* iDoms movedFirstPP)
      -:         ELSE
}

