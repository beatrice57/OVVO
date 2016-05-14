node: ORD-IP*

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
4: { gap: (ORD-IP*=* exists)
     ord: (ORD-IP* exists)
     -: ELSE
}

// SUBJECT
// type of subject
5: { #5:    (ORD-IP* iDoms *-SBJ*)
     -:      ELSE
}

// FINITE VERB
// type
6:  { coord:        (ORD-IP* iDoms [AE]X|MDX|VX) AND ([AE]X|MDX|VX iDoms CONJ[OP])
      aux-avoir:    (ORD-IP* iDoms AX)
      aux-etre:     (ORD-IP* iDoms EX)
      mod-dev:      (ORD-IP* iDoms MDX) AND (MDX iDoms [dD].*)
      mod-pouv:     (ORD-IP* iDoms MDX) AND (MDX iDoms [pP].*|rep*)
      mod-voul:     (ORD-IP* iDoms MDX) AND (MDX iDoms [uUvVwW].*|bee)
      mod:          (ORD-IP* iDoms MDX)
      avoir-sc-vpp: (ORD-IP* iDoms VX) AND (VX iDoms [aA][uv][eo]ir) AND (ORD-IP* iDomsMod ECM-IP-SMC* VPP*)
      main-sc-vpp:  (ORD-IP* iDoms VX) AND (ORD-IP* iDomsMod ECM-IP-SMC* VPP*)
      main-sc:      (ORD-IP* iDoms VX) AND (ORD-IP* iDoms ECM-IP-SMC*)
      main-ecm:     (ORD-IP* iDoms VX) AND (ORD-IP* iDoms ECM-IP-INF*)
      main-etre:    (ORD-IP* iDoms VX) AND (VX iDoms etre)
      main-avoir:   (ORD-IP* iDoms VX) AND (VX iDoms avoir)
      main:         (ORD-IP* iDoms VX)
      -: ELSE
}

// ORDER
// subject and finite verb
// 7: { in ord-2.c

// subject and nonfinite verb
8: { -:	ELSE
}

// finite and nonfinite verb
9: { no-aux:    (ORD-IP* iDoms ![AE]X|MDX)
// no ordinary case
// perfect
     fin-non:   (ORD-IP* iDomsMod PARTP* VPP*) AND (ORD-IP* iDoms !movedPart) AND (ORD-IP* iDoms [AE]X) AND ([AE]X precedes VPP*)
     non-fin:   (ORD-IP* iDomsMod PARTP* VPP*) AND (ORD-IP* iDoms !movedPart) AND (ORD-IP* iDoms [AE]X) AND (VPP* precedes [AE]X)
// infinitive in situ
     fin-non:   (ORD-IP* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (ORD-IP* iDoms !movedInf) AND (ORD-IP* iDoms MDX|VX) AND (MDX|VX precedes MOD-IP-INF*|ECM-IP-INF*)
     non-fin:   (ORD-IP* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (ORD-IP* iDoms !movedInf) AND (ORD-IP* iDoms MDX|VX) AND (MOD-IP-INF*|ECM-IP-INF* precedes MDX|VX)
// infinitive or participle moved
     fin-non:   (ORD-IP* iDoms movedInf|movedPart) AND (ORD-IP* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes movedInf|movedPart)
     non-fin:   (ORD-IP* iDoms movedInf|movedPart) AND (ORD-IP* iDoms [AE]X|MDX) AND (movedInf|movedPart precedes [AE]X|MDX)
     -:	ELSE
}

// DIRECT OBJECT
// type
10: {  
      -:         (ORD-IP* iDoms !acc|prd|movedAcc|movedPrd)
// exclude dative subjects in ECM contexts
      -:         (ORD-IP* iDoms ECM-IP-INF*)  AND (ECM-IP-INF* iDomsMod NP-ECM-SBJ*|NP DAT)
// exclude raised passive subjects in ECM contexts
      -:         (ORD-IP* iDoms *-SBJ*)  AND (ORD-IP* iDoms EX|EPP) 
             AND (ORD-IP* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \**) AND (*-SBJ* sameIndex \**)
// exclude *arb*, *pro*, *proimp* in ECM contexts
      -:         (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*|\*pro\*|\*proimp\*)
// exclude plain *
      -:         (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms \*)
      -:         (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
// trace
      o_tra:     (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms \*T*)
      O_tra:     (ORD-IP* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \*T*)
      p_tra:     (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*RSP*)
      o_res:     (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* CL-NP-ACC*RSP*)
      o_cli:     (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* CL-NP-ACC*)
      o_np:      (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsMod NP fullNP)
      o_pro:     (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms PRO)
      o_frl:     (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsFirst CP-FRL*)
      o_cp:      (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsOnly CP*)
      o_ip:      (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms !movedAcc|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*)
// // prd
//      p_Res:     (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*RSP*)
//      p_res:     (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* CL-NP-PRD*RSP*)
      p_cli:     (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* CL-NP-PRD*)
      p_np:      (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsMod NP fullNP)
//      p_pro:     (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDoms PRO)
//      p_frl:     (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsFirst CP-FRL*)
//      p_cp:      (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsOnly CP*)
//      p_ip:      (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms !movedPrd|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*)
// ECM case without movement
      O_Res:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)
      O_res:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)
      O_cli:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)
      O_np:      (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
      O_pro:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)
      O_frl:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
      O_ip:      (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*)
// modal - infinitive moved, object moved
      o_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ACC-MOVED*)    AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-NP-ACC-RSP*)
      o_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-ACC-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-NP-ACC-RSP*)
      o_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-ACC-MOVED*)
      o_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsMod NP fullNP)
      o_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDoms PRO)
      o_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly CP*)
      o_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ACC-MOVED*)
// // prd
//      p_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-PRD-MOVED*)    AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-NP-PRD-RSP*)
//      p_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-PRD-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-NP-PRD-RSP*)
      p_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-PRD-MOVED*)
      p_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsMod NP fullNP)
//      p_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDoms PRO)
//      p_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsFirst CP-FRL*)
//      p_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly CP*)
//      p_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-PRD-MOVED*)
// modal - infinitive moved, object in situ
      o_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-ACC-RSP*)
      o_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* CL-NP-ACC-RSP*)
      o_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* CL-NP-ACC*)
      o_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsMod NP fullNP)
      o_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDoms PRO)
      o_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsFirst CP-FRL*)
      o_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsOnly CP*)
      o_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-ACC*)
// // prd
//      p_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-PRD-RSP*)
//      p_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* CL-NP-PRD-RSP*)
      p_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* CL-NP-PRD*)
      p_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsMod NP fullNP)
//      p_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDoms PRO)
//      p_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsFirst CP-FRL*)
//      p_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsOnly CP*)
//      p_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-PRD*)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (ORD-IP* iDoms NP-ACC-MOVED*)    AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-ACC-RSP*)
      o_res:     (ORD-IP* iDoms CL-NP-ACC-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-ACC-RSP*)
      o_cli:     (ORD-IP* iDoms CL-NP-ACC-MOVED*)
      o_np:      (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsMod NP fullNP)
      o_pro:     (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDoms PRO)
      o_frl:     (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly CP*)
      o_ip:      (ORD-IP* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms NP-ACC-MOVED*)
// // prd
//      p_Res:     (ORD-IP* iDoms NP-PRD-MOVED*)    AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-PRD-RSP*)
//      p_res:     (ORD-IP* iDoms CL-NP-PRD-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-PRD-RSP*)
      p_cli:     (ORD-IP* iDoms CL-NP-PRD-MOVED*)
      p_np:      (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsMod NP fullNP)
//      p_pro:     (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDoms PRO)
//      p_frl:     (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsFirst CP-FRL*)
//      p_cp:      (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly CP*)
//      p_ip:      (ORD-IP* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms NP-PRD-MOVED*)
// small clause - infinitive moved, subject moved
      O_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*)    AND (ORD-IP* iDomsMod ECM-IP* ZZZ-NP-ECM-SBJ*RSP*)
      O_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-ECM-MOVED*) AND (ORD-IP* iDomsMod ECM-IP* ZZZ-CL-NP-ECM-SBJ*RSP*)
      O_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-ECM-MOVED*)
      O_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)
      O_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)
      O_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)
      O_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)
      O_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*)
// small clause - infinitive moved, subject in situ
      O_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)
      O_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)
      O_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)
      O_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
      O_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)
      O_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
      O_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*)
// small clause - infinitive in situ, subject moved
      O_Res:     (ORD-IP* iDoms NP-ECM-MOVED*)    AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)
      O_res:     (ORD-IP* iDoms CL-NP-ECM-MOVED*) AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)
      O_cli:     (ORD-IP* iDoms CL-NP-ECM-MOVED*)
      O_np:      (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)
      O_pro:     (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)
      O_frl:     (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)
      O_cp:      (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)
      O_ip:      (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (ORD-IP* iDoms NP-ECM-MOVED*)
      -:         ELSE
}

// INDIRECT OBJECT
// type
11: {  
      -:         (ORD-IP* iDoms !dtv|movedDtv)
// include dative subjects in ECM contexts (see below)
// exclude raised passive subjects in ECM contexts
      -:         (ORD-IP* iDoms *-SBJ*)  AND (ORD-IP* iDoms EX|EPP) 
             AND (ORD-IP* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \**) AND (*-SBJ* sameIndex \**)
// exclude *arb*, *pro*, *proimp* in ECM contexts
      -:         (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*|\*pro\*|\*proimp\*)
// exclude plain *
      -:         (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms \*)
      -:         (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
// trace
      o_tra:     (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms \*T*)
      O_tra:     (ORD-IP* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*RSP*)
      o_res:     (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* CL-NP-DTV*RSP*)
      o_cli:     (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* CL-NP-DTV*)
      o_np:      (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsMod NP fullNP)
      o_pro:     (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms PRO)
      o_frl:     (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsFirst CP-FRL*)
      o_cp:      (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsOnly CP*)
      o_ip:      (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (ORD-IP* iDoms !movedDtv|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*)
// ECM case without movement
      O_Res:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)                                           AND (NP-ECM-SBJ*RSP* iDoms DAT)
      O_res:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)                                        AND (CL-NP-ECM-SBJ*RSP* iDoms DAT)
      O_cli:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)                                            AND (CL-NP-ECM-SBJ* iDoms DAT)
      O_np:      (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)          AND (NP-ECM-SBJ* iDoms DAT)
      O_pro:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)                   AND (NP-ECM-SBJ* iDoms DAT)
      O_frl:     (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)          AND (NP-ECM-SBJ* iDoms DAT)
      O_cp:      (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)               AND (NP-ECM-SBJ* iDoms DAT)
      O_ip:      (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE) AND (NP-ECM-SBJ* iDoms DAT)
      #11:       (ORD-IP* iDoms !movedEcmSbj|movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*)                                               AND (NP-ECM-SBJ* iDoms DAT)
// modal - infinitive moved, object moved
      o_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-DTV-MOVED*)    AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-NP-DTV-RSP*)
      o_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-DTV-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-NP-DTV-RSP*)
      o_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-DTV-MOVED*)
      o_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsMod NP fullNP)
      o_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDoms PRO)
      o_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly CP*)
      o_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-DTV-MOVED*)
// modal - infinitive moved, object in situ
      o_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-DTV-RSP*)
      o_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* CL-NP-DTV-RSP*)
      o_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* CL-NP-DTV*)
      o_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsMod NP fullNP)
      o_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDoms PRO)
      o_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsFirst CP-FRL*)
      o_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsOnly CP*)
      o_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* NP-DTV*)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (ORD-IP* iDoms NP-DTV-MOVED*)    AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-DTV-RSP*)
      o_res:     (ORD-IP* iDoms CL-NP-DTV-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-DTV-RSP*)
      o_cli:     (ORD-IP* iDoms CL-NP-DTV-MOVED*)
      o_np:      (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsMod NP fullNP)
      o_pro:     (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDoms PRO)
      o_frl:     (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly CP*)
      o_ip:      (ORD-IP* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (ORD-IP* iDoms NP-DTV-MOVED*)
// small clause - infinitive moved, subject moved
      O_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*)    AND (ORD-IP* iDomsMod ECM-IP* ZZZ-NP-ECM-SBJ*RSP*)    AND (NP-ECM-MOVED* iDoms DAT)
      O_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-ECM-MOVED*) AND (ORD-IP* iDomsMod ECM-IP* ZZZ-CL-NP-ECM-SBJ*RSP*) AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms CL-NP-ECM-MOVED*)                                                       AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)                   AND (NP-ECM-MOVED* iDoms DAT)
      O_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)                            AND (NP-ECM-MOVED* iDoms DAT)
      O_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)                   AND (NP-ECM-MOVED* iDoms DAT)
      O_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)                        AND (NP-ECM-MOVED* iDoms DAT)
      O_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)          AND (NP-ECM-MOVED* iDoms DAT)
      #11:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms NP-ECM-MOVED*)
// small clause - infinitive moved, subject in situ
      O_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)                                           AND (NP-ECM-SBJ*RSP* iDoms DAT)
      O_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)                                        AND (CL-NP-ECM-SBJ*RSP* iDoms DAT)
      O_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)                                            AND (CL-NP-ECM-SBJ* iDoms DAT)
      O_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)          AND (NP-ECM-SBJ* iDoms DAT)
      O_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)                   AND (NP-ECM-SBJ* iDoms DAT)
      O_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)          AND (NP-ECM-SBJ* iDoms DAT)
      O_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)               AND (NP-ECM-SBJ* iDoms DAT)
      O_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE) AND (NP-ECM-SBJ* iDoms DAT)
      #11:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod ECM-IP* NP-ECM-SBJ*)                                               AND (NP-ECM-SBJ* iDoms DAT)
// small clause - infinitive in situ, subject moved
      O_Res:     (ORD-IP* iDoms NP-ECM-MOVED*)    AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)       AND (NP-ECM-MOVED* iDoms DAT)
      O_res:     (ORD-IP* iDoms CL-NP-ECM-MOVED*) AND (ORD-IP* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)       AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_cli:     (ORD-IP* iDoms CL-NP-ECM-MOVED*)                                                                                  AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_np:      (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)                                              AND (NP-ECM-MOVED* iDoms DAT)
      O_pro:     (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)                                                       AND (NP-ECM-MOVED* iDoms DAT)
      O_frl:     (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)                                              AND (NP-ECM-MOVED* iDoms DAT)
      O_cp:      (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)                                                   AND (NP-ECM-MOVED* iDoms DAT)
      O_ip:      (ORD-IP* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)                                     AND (NP-ECM-MOVED* iDoms DAT)
      #11:       (ORD-IP* iDoms NP-ECM-MOVED*)                                                                                     AND (NP-ECM-MOVED* iDoms DAT)
      -:         ELSE
}

// FIRST PP
// type of PP
12: {  
      -:       (ORD-IP* iDoms !firstPP|movedFirstPP)
// trace
      #12:     (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      xxx:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-XXX*)
      arg:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-ARG*)
      dir:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-DIR*)
      loc:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-LOC*)
      mod:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-MOD*)
      msr:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-MSR*)
      prd:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-PRD*)
      tmp:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-TMP*)
      #12:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, PP moved
      xxx:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-PP-XXX-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      arg:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-PP-ARG-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      dir:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-PP-DIR-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      loc:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-PP-LOC-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      mod:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-PP-MOD-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      msr:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-PP-MSR-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      prd:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-PP-PRD-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      tmp:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-PP-TMP-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      #12:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP)        AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP-*)
// modal - infinitive moved, PP in situ
      xxx:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP-XXX*)
      arg:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP-ARG*)
      dir:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP-DIR*)
      loc:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP-LOC*)
      mod:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP-MOD*)
      msr:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP-MSR*)
      prd:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP-PRD*)
      tmp:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP-TMP*)
      #12:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, PP moved; PARTP - PP moved
      xxx:     (ORD-IP* iDoms FIRST-PP-XXX-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      arg:     (ORD-IP* iDoms FIRST-PP-ARG-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      dir:     (ORD-IP* iDoms FIRST-PP-DIR-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      loc:     (ORD-IP* iDoms FIRST-PP-LOC-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      mod:     (ORD-IP* iDoms FIRST-PP-MOD-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      msr:     (ORD-IP* iDoms FIRST-PP-MSR-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      prd:     (ORD-IP* iDoms FIRST-PP-PRD-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      tmp:     (ORD-IP* iDoms FIRST-PP-TMP-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      #12:     (ORD-IP* iDoms movedFirstPP)        AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      -:         ELSE
}

// FIRST PP
// preposition is A or not
13: {  
      -:       (ORD-IP* iDoms !firstPP|movedFirstPP)
// trace
      #13:     (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      y:       (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|P datPrep)
      n:       (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, object moved
      y:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*) AND (movedFirstPP iDomsMod PP|P datPrep)
      n:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
// modal - infinitive moved, object in situ
      y:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|P datPrep)
      n:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, object moved; PARTP - object moved
      y:       (ORD-IP* iDoms movedFirstPP)    AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*) AND (movedFirstPP iDomsMod PP|P datPrep)
      n:       (ORD-IP* iDoms movedFirstPP)    AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
      -:        ELSE
}

// FIRST PP
// type of complement
14: {  
      -:         (ORD-IP* iDoms !firstPP|movedFirstPP)
// trace
      #14:       (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-CL-PP*RSP*)
//      o_cli:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* FIRST-CL-PP*)
      o_np:      (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP fullNP)
      o_pro:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP PRO)
      o_frl:     (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP CP*)
      o_ip:      (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (ORD-IP* iDoms !movedFirstPP|movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, object moved
      o_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP)    AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-CL-PP-*-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
//      o_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms FIRST-CL-PP-*-MOVED*)
      o_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP fullNP)
      o_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP PRO)
      o_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP*)
      o_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDoms movedFirstPP)
// modal - infinitive moved, object in situ
      o_Res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-CL-PP*RSP*)
//      o_cli:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* FIRST-CL-PP*)
      o_np:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP fullNP)
      o_pro:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP PRO)
      o_frl:     (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP CP*)
      o_ip:      (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (ORD-IP* iDoms movedInf) AND (ORD-IP* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (ORD-IP* iDoms movedFirstPP)    AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (ORD-IP* iDoms FIRST-CL-PP-*-MOVED*) AND (ORD-IP* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
//      o_cli:     (ORD-IP* iDoms FIRST-CL-PP-*-MOVED*)
      o_np:      (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP fullNP)
      o_pro:     (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP PRO)
      o_frl:     (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP CP*)
      o_ip:      (ORD-IP* iDoms movedFirstPP)    AND (movedFirstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (ORD-IP* iDoms movedFirstPP)
      -:         ELSE
}

