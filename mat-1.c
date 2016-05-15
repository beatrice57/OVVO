node: IP-MAT*

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
4: { Gap: (IP-MAT*=* exists)
     Mat: (IP-MAT* exists)
     -: ELSE
}

// SUBJECT
// type of subject
5: {
// overt subject
     #5:         (IP-MAT* iDoms CL-NP-SBJ*)
     s_Pro:      (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms PRO) AND (PRO iDoms weakSubjPronoun)
     s_Dem:      (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms PRO) AND (PRO iDoms !weakSubjPronoun)
     s_Exp:      (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms PROIMP)
     s_NP:       (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDomsMod NP fullNP)
     s_Frl:      (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDomsFirst CP-FRL*)
     s_CP:       (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDomsOnly CP*)
     s_IP:       (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
     s_Inf:      (IP-MAT* iDoms *IP-INF-SBJ*)
// silent subject
// traces (for parallelism with subordinate clauses)
     #5:         (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*ICH\**)
     #5:         (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*T\**)
     s_exp:      (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*proimp\*)
// clearly pro
     s_pro:      (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*pro\*)
// clearly pro
     s_pro:      (IP-MAT* iDoms conjCoord)
             AND (conjCoord iDoms [cCkK]ar|que)
             AND (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*con\*)
// pro because LFD incompatible with conjunction analysis
     s_pro:      (IP-MAT* iDomsNum 1 conjCoord)
             AND (IP-MAT* iDomsNum 2 *-LFD)
             AND (IP-MAT* iDomsNum 4 NP-SBJ*) 
             AND (NP-SBJ* iDoms \*con\*)
             AND (IP-MAT* iDomsNum 5 finiteAll)
// ambiguous between (1) topicalization (= pro) and (2) left-adjoined adverb or OV (= con)
// PPs currently all treated as left-adjoined although some are clearly arguments
     s_amb1:     (IP-MAT* iDomsNum 1 conjCoord)
             AND (IP-MAT* iDomsNum 3 NP-SBJ*) 
     	     AND (NP-SBJ* iDoms \*con\*)
             AND (IP-MAT* iDomsNum 4 finiteAll)
// clearly conjoined
     s_con:      (IP-MAT* iDomsNum 1 conjCoord)
             AND (IP-MAT* iDomsNum 2 NP-SBJ*) 
             AND (NP-SBJ* iDoms \*con\*)
             AND (IP-MAT* iDomsNum 3 finiteAll)
// remaining *con* with conjunction
     s_con:      (IP-MAT* iDoms conjCoord)
             AND (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*con\*)
// treated as unambiguously *pro* even though some are conjuncts with silent conjunctions
// these will need to be fixed by adding (CONJ *) and will then collapse with \2
     s_amb2:     (IP-MAT* iDoms !conjCoord)
             AND (IP-MAT* iDomsNum 2 NP-SBJ*) 
	     AND (NP-SBJ* iDoms \*con\*)
             AND (IP-MAT* iDomsNum 3 finiteAll)
// same as \4
     s_amb3:     (IP-MAT* iDoms !conjCoord)
             AND (IP-MAT* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \*con\*)
     #5:         (IP-MAT* iDoms *-SBJ*)
     -: ELSE
}

// FINITE (= HIGHEST) VERB
// type
6:  { coord:        (IP-MAT* iDoms finiteAll) AND (finiteAll iDoms CONJ[OP])
      aux-avoir:    (IP-MAT* iDoms AJ)
      aux-etre:     (IP-MAT* iDoms EJ)
      mod-dev:      (IP-MAT* iDoms MDJ) AND (MDJ iDoms [dD].*)
      mod-pouv:     (IP-MAT* iDoms MDJ) AND (MDJ iDoms [pP].*|rep*)
      mod-voul:     (IP-MAT* iDoms MDJ) AND (MDJ iDoms [uUvVwW].*|bee)
      mod:          (IP-MAT* iDoms MDJ)
      avoir-sc-vpp: (IP-MAT* iDoms VJ) AND (VJ iDoms avoir) AND (IP-MAT* iDomsMod ECM-IP-SMC* VPP*)
      main-sc-vpp:  (IP-MAT* iDoms VJ) AND (IP-MAT* iDomsMod ECM-IP-SMC* VPP*)
      main-sc:      (IP-MAT* iDoms VJ) AND (IP-MAT* iDoms ECM-IP-SMC*)
      main-ecm:     (IP-MAT* iDoms VJ) AND (IP-MAT* iDoms ECM-IP-INF*)
      main-etre:    (IP-MAT* iDoms VJ) AND (VJ iDoms etre)
      main-avoir:   (IP-MAT* iDoms VJ) AND (VJ iDoms avoir)
      main:         (IP-MAT* iDoms VJ)
      -: ELSE
}

// ORDER
// subject and finite verb
// 7: { in mat-2.c
// }

// subject and nonfinite verb
8: { 
// ordinary
     s-non:     (IP-MAT* iDoms VPP*|PARTP*) AND (IP-MAT* iDoms !movedPart) AND (IP-MAT* iDoms *-SBJ*) AND (*-SBJ* precedes VPP*|PARTP*)
     non-s:     (IP-MAT* iDoms VPP*|PARTP*) AND (IP-MAT* iDoms !movedPart) AND (IP-MAT* iDoms *-SBJ*) AND (VPP*|PARTP* precedes *-SBJ*)
// infinitive in situ
     s-non:     (IP-MAT* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (IP-MAT* iDoms !movedInf) AND (IP-MAT* iDoms *-SBJ*) AND (*-SBJ* precedes MOD-IP-INF*|ECM-IP-INF*)
     non-s:     (IP-MAT* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (IP-MAT* iDoms !movedInf) AND (IP-MAT* iDoms *-SBJ*) AND (MOD-IP-INF*|ECM-IP-INF* precedes *-SBJ*)
// infinitive or participle moved
     s-non:     (IP-MAT* iDoms movedInf|movedPart) AND (IP-MAT* iDoms *-SBJ*) AND (*-SBJ* precedes movedInf|movedPart)
     non-s:     (IP-MAT* iDoms movedInf|movedPart) AND (IP-MAT* iDoms *-SBJ*) AND (movedInf|movedPart precedes *-SBJ*)
     -:	ELSE
}

// finite and nonfinite verb
9: { no-aux:    (IP-MAT* iDoms !AJ|EJ|MDJ)
// ordinary
     fin-non:   (IP-MAT* iDomsMod PARTP* VPP*) AND (IP-MAT* iDoms !movedPart) AND (IP-MAT* iDoms [AE]J) AND ([AE]J precedes VPP*)
     non-fin:   (IP-MAT* iDomsMod PARTP* VPP*) AND (IP-MAT* iDoms !movedPart) AND (IP-MAT* iDoms [AE]J) AND (VPP* precedes [AE]J)
// infinitive in situ
     fin-non:   (IP-MAT* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (IP-MAT* iDoms !movedInf) AND (IP-MAT* iDoms MDJ|VJ) AND (MDJ|VJ precedes MOD-IP-INF*|ECM-IP-INF*)
     non-fin:   (IP-MAT* iDoms MOD-IP-INF*|ECM-IP-INF*) AND (IP-MAT* iDoms !movedInf) AND (IP-MAT* iDoms MDJ|VJ) AND (MOD-IP-INF*|ECM-IP-INF* precedes MDJ|VJ)
// infinitive or participle moved
     fin-non:   (IP-MAT* iDoms movedInf|movedPart) AND (IP-MAT* iDoms [AEV]J|MDJ) AND ([AEV]J|MDJ precedes movedInf|movedPart)
     non-fin:   (IP-MAT* iDoms movedInf|movedPart) AND (IP-MAT* iDoms [AEV]J|MDJ) AND (movedInf|movedPart precedes [AEV]J|MDJ)
     -:	ELSE
}

// DIRECT OBJECT
// type
10: { 
// exclude dative subjects in ECM contexts
      -:         (IP-MAT* iDoms ECM-IP-INF*) AND (ECM-IP-INF* iDomsMod NP-ECM-SBJ*|NP DAT)
// exclude raised passive subjects in ECM contexts
      -:         (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDoms EJ|EPP) 
             AND (IP-MAT* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \**) AND (*-SBJ* sameIndex \**)
// exclude *arb*, *pro*, *proimp* in ECM contexts
      -:         (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*|\*pro\*|\*proimp\*)
// exclude plain *
      -:         (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms \*)
      -:         (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
// trace
      #10:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms \*T*)
      #10:       (IP-MAT* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*RSP*)
      o_res:     (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* CL-NP-ACC*RSP*)
      o_cli:     (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* CL-NP-ACC*)
      o_np:      (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsMod NP fullNP)
      o_pro:     (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDoms PRO)
      o_frl:     (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsFirst CP-FRL*)
      o_cp:      (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsOnly CP*)
      o_ip:      (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*) AND (NP-ACC* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms !movedAcc|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-ACC*)
// // prd
//      p_Res:     (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*RSP*)
//      p_res:     (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* CL-NP-PRD*RSP*)
      p_cli:     (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* CL-NP-PRD*)
      p_np:      (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsMod NP fullNP)
//      p_pro:     (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDoms PRO)
//      p_frl:     (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsFirst CP-FRL*)
//      p_cp:      (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsOnly CP*)
//      p_ip:      (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*) AND (NP-PRD* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms !movedPrd|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-PRD*)
// ECM case without movement
      O_Res:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)
      O_res:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)
      O_cli:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)
      O_np:      (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
      O_pro:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)
      O_frl:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
      O_ip:      (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*)
// modal - infinitive moved, object moved
      o_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ACC-MOVED*)    AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-NP-ACC-RSP*)
      o_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-ACC-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-NP-ACC-RSP*)
      o_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-ACC-MOVED*)
      o_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsMod NP fullNP)
      o_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDoms PRO)
      o_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly CP*)
      o_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ACC-MOVED*)
// // prd
//      p_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-PRD-MOVED*)    AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-NP-PRD-RSP*)
//      p_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-PRD-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-NP-PRD-RSP*)
      p_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-PRD-MOVED*)
      p_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsMod NP fullNP)
//      p_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDoms PRO)
//      p_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsFirst CP-FRL*)
//      p_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly CP*)
//      p_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-PRD-MOVED*)
// modal - infinitive moved, object in situ
      o_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-ACC-RSP*)
      o_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* CL-NP-ACC-RSP*)
      o_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* CL-NP-ACC*)
      o_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsMod NP fullNP)
      o_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDoms PRO)
      o_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsFirst CP-FRL*)
      o_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsOnly CP*)
      o_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-ACC*) AND (NP-ACC* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-ACC*)
// // prd
//      p_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-PRD-RSP*)
//      p_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* CL-NP-PRD-RSP*)
      p_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* CL-NP-PRD*)
      p_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsMod NP fullNP)
//      p_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDoms PRO)
//      p_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsFirst CP-FRL*)
//      p_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsOnly CP*)
//      p_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-PRD*) AND (NP-PRD* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-PRD*)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (IP-MAT* iDoms NP-ACC-MOVED*)    AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-ACC-RSP*)
      o_res:     (IP-MAT* iDoms CL-NP-ACC-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-ACC-RSP*)
      o_cli:     (IP-MAT* iDoms CL-NP-ACC-MOVED*)
      o_np:      (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsMod NP fullNP)
      o_pro:     (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDoms PRO)
      o_frl:     (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly CP*)
      o_ip:      (IP-MAT* iDoms NP-ACC-MOVED*)    AND (NP-ACC-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms NP-ACC-MOVED*)
// // prd
//      p_Res:     (IP-MAT* iDoms NP-PRD-MOVED*)    AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-PRD-RSP*)
//      p_res:     (IP-MAT* iDoms CL-NP-PRD-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-PRD-RSP*)
      p_cli:     (IP-MAT* iDoms CL-NP-PRD-MOVED*)
      p_np:      (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsMod NP fullNP)
//      p_pro:     (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDoms PRO)
//      p_frl:     (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsFirst CP-FRL*)
//      p_cp:      (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly CP*)
//      p_ip:      (IP-MAT* iDoms NP-PRD-MOVED*)    AND (NP-PRD-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms NP-PRD-MOVED*)
// small clause - infinitive moved, subject moved
      O_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*)    AND (IP-MAT* iDomsMod ECM-IP* ZZZ-NP-ECM-SBJ*RSP*)
      O_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-ECM-MOVED*) AND (IP-MAT* iDomsMod ECM-IP* ZZZ-CL-NP-ECM-SBJ*RSP*)
      O_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-ECM-MOVED*)
      O_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)
      O_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)
      O_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)
      O_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)
      O_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*)
// small clause - infinitive moved, subject in situ
      O_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)
      O_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)
      O_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)
      O_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)
      O_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)
      O_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)
      O_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*)
// small clause - infinitive in situ, subject moved
      O_Res:     (IP-MAT* iDoms NP-ECM-MOVED*)    AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)
      O_res:     (IP-MAT* iDoms CL-NP-ECM-MOVED*) AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)
      O_cli:     (IP-MAT* iDoms CL-NP-ECM-MOVED*)
      O_np:      (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)
      O_pro:     (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)
      O_frl:     (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)
      O_cp:      (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)
      O_ip:      (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-MAT* iDoms NP-ECM-MOVED*)
      -:         ELSE
    }


// INDIRECT OBJECT
// type
11: {  
// include dative subjects in ECM contexts (see below)
// exclude raised passive subjects in ECM contexts
      -:         (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDoms EJ|EPP) 
             AND (IP-MAT* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \**) AND (*-SBJ* sameIndex \**)
// exclude *arb*, *pro*, *proimp* in ECM contexts
      -:         (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*arb\*|\*pro\*|\*proimp\*)
// exclude plain *
      -:         (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms \*)
      -:         (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms \*)
// trace
      #11:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms \*T*)
      #11:       (IP-MAT* iDomsMod ECM-IP* *NP-ECM-SBJ*) AND (*NP-ECM-SBJ* iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*RSP*)
      o_res:     (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* CL-NP-DTV*RSP*)
      o_cli:     (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* CL-NP-DTV*)
      o_np:      (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsMod NP fullNP)
      o_pro:     (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDoms PRO)
      o_frl:     (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsFirst CP-FRL*)
      o_cp:      (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsOnly CP*)
      o_ip:      (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*) AND (NP-DTV* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (IP-MAT* iDoms !movedDtv|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* NP-DTV*)
// ECM case without movement
      O_Res:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)                                           AND (NP-ECM-SBJ*RSP* iDoms DAT)
      O_res:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)                                        AND (CL-NP-ECM-SBJ*RSP* iDoms DAT)
      O_cli:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)                                            AND (CL-NP-ECM-SBJ* iDoms DAT)
      O_np:      (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)          AND (NP-ECM-SBJ* iDoms DAT)
      O_pro:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)                   AND (NP-ECM-SBJ* iDoms DAT)
      O_frl:     (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)          AND (NP-ECM-SBJ* iDoms DAT)
      O_cp:      (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)               AND (NP-ECM-SBJ* iDoms DAT)
      O_ip:      (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE) AND (NP-ECM-SBJ* iDoms DAT)
      #11:       (IP-MAT* iDoms !movedEcmSbj|movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*)                                               AND (NP-ECM-SBJ* iDoms DAT)
// modal - infinitive moved, object moved
      o_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-DTV-MOVED*)    AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-NP-DTV-RSP*)
      o_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-DTV-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-NP-DTV-RSP*)
      o_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-DTV-MOVED*)
      o_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsMod NP fullNP)
      o_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDoms PRO)
      o_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly CP*)
      o_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-DTV-MOVED*)
// modal - infinitive moved, object in situ
      o_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-DTV-RSP*)
      o_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* CL-NP-DTV-RSP*)
      o_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* CL-NP-DTV*)
      o_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsMod NP fullNP)
      o_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDoms PRO)
      o_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsFirst CP-FRL*)
      o_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsOnly CP*)
      o_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-DTV*) AND (NP-DTV* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* NP-DTV*)
// modal - infinitive in situ, object moved; PARTP - object moved
      o_Res:     (IP-MAT* iDoms NP-DTV-MOVED*)    AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-DTV-RSP*)
      o_res:     (IP-MAT* iDoms CL-NP-DTV-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-NP-DTV-RSP*)
      o_cli:     (IP-MAT* iDoms CL-NP-DTV-MOVED*)
      o_np:      (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsMod NP fullNP)
      o_pro:     (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDoms PRO)
      o_frl:     (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsFirst CP-FRL*)
      o_cp:      (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly CP*)
      o_ip:      (IP-MAT* iDoms NP-DTV-MOVED*)    AND (NP-DTV-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)
      #11:       (IP-MAT* iDoms NP-DTV-MOVED*)
// small clause - infinitive moved, subject moved
      O_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*)    AND (IP-MAT* iDomsMod ECM-IP* ZZZ-NP-ECM-SBJ*RSP*)     AND (NP-ECM-MOVED* iDoms DAT)
      O_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-ECM-MOVED*) AND (IP-MAT* iDomsMod ECM-IP* ZZZ-CL-NP-ECM-SBJ*RSP*)  AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms CL-NP-ECM-MOVED*)                                                        AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)                    AND (NP-ECM-MOVED* iDoms DAT)
      O_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)                             AND (NP-ECM-MOVED* iDoms DAT)
      O_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)                    AND (NP-ECM-MOVED* iDoms DAT)
      O_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)                         AND (NP-ECM-MOVED* iDoms DAT)
      O_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)           AND (NP-ECM-MOVED* iDoms DAT)
      #11:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms NP-ECM-MOVED*)                                                           AND (NP-ECM-MOVED* iDoms DAT)
// small clause - infinitive moved, subject in situ
      O_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*RSP*)                                           AND (NP-ECM-SBJ*RSP* iDoms DAT)
      O_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* CL-NP-ECM-SBJ*RSP*)                                        AND (CL-NP-ECM-SBJ*RSP* iDoms DAT)
      O_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* CL-NP-ECM-SBJ*)                                            AND (CL-NP-ECM-SBJ* iDoms DAT)
      O_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsMod NP fullNP)          AND (NP-ECM-SBJ* iDoms DAT)
      O_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDoms PRO)                   AND (NP-ECM-SBJ* iDoms DAT)
      O_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsFirst CP-FRL*)          AND (NP-ECM-SBJ* iDoms DAT)
      O_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly CP*)               AND (NP-ECM-SBJ* iDoms DAT)
      O_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*) AND (NP-ECM-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE) AND (NP-ECM-SBJ* iDoms DAT)
      #11:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod ECM-IP* NP-ECM-SBJ*)                                               AND (NP-ECM-SBJ* iDoms DAT)
// small clause - infinitive in situ, subject moved
      O_Res:     (IP-MAT* iDoms NP-ECM-MOVED*)    AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)  AND (NP-ECM-MOVED* iDoms DAT)
      O_res:     (IP-MAT* iDoms CL-NP-ECM-MOVED*) AND (IP-MAT* iDoms ECM-IP*) AND (ECM-IP* iDomsMod ZZZ-NP-ECM-SBJ*RSP* \**)  AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_cli:     (IP-MAT* iDoms CL-NP-ECM-MOVED*)                                                                             AND (CL-NP-ECM-MOVED* iDoms DAT)
      O_np:      (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsMod NP fullNP)                                         AND (NP-ECM-MOVED* iDoms DAT)
      O_pro:     (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDoms PRO)                                                  AND (NP-ECM-MOVED* iDoms DAT)
      O_frl:     (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsFirst CP-FRL*)                                         AND (NP-ECM-MOVED* iDoms DAT)
      O_cp:      (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly CP*)                                              AND (NP-ECM-MOVED* iDoms DAT)
      O_ip:      (IP-MAT* iDoms NP-ECM-MOVED*) AND (NP-ECM-MOVED* iDomsOnly IP-MAT|IP-MAT-SPE)                                AND (NP-ECM-MOVED* iDoms DAT)
      #11:       (IP-MAT* iDoms NP-ECM-MOVED*)                                                                                AND (NP-ECM-MOVED* iDoms DAT)
      -:         ELSE
}

// FIRST PP
// type of PP
12: {  
// no ECM contexts
// trace
      #12:      (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      xxx:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-XXX*)
      arg:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-ARG*)
      dir:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-DIR*)
      loc:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-LOC*)
      mod:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-MOD*)
      msr:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-MSR*)
      prd:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-PRD*)
      tmp:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP-TMP*)
      #12:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, PP moved
      xxx:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-PP-XXX-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      arg:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-PP-ARG-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      dir:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-PP-DIR-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      loc:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-PP-LOC-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      mod:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-PP-MOD-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      msr:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-PP-MSR-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      prd:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-PP-PRD-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      tmp:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-PP-TMP-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
      #12:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP)        AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP-*)
// modal - infinitive moved, PP in situ
      xxx:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP-XXX*)
      arg:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP-ARG*)
      dir:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP-DIR*)
      loc:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP-LOC*)
      mod:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP-MOD*)
      msr:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP-MSR*)
      prd:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP-PRD*)
      tmp:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP-TMP*)
      #12:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, PP moved; PARTP - PP moved
      xxx:     (IP-MAT* iDoms FIRST-PP-XXX-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      arg:     (IP-MAT* iDoms FIRST-PP-ARG-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      dir:     (IP-MAT* iDoms FIRST-PP-DIR-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      loc:     (IP-MAT* iDoms FIRST-PP-LOC-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      mod:     (IP-MAT* iDoms FIRST-PP-MOD-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      msr:     (IP-MAT* iDoms FIRST-PP-MSR-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      prd:     (IP-MAT* iDoms FIRST-PP-PRD-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      tmp:     (IP-MAT* iDoms FIRST-PP-TMP-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      #12:     (IP-MAT* iDoms movedFirstPP)        AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP-*)
      -:        ELSE
}

// FIRST PP
// preposition is A or not
13: {  
// trace
      #13:     (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      y:       (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|P datPrep)
      n:       (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, object moved
      y:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*) AND (movedFirstPP iDomsMod PP|P datPrep)
      n:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
// modal - infinitive moved, object in situ
      y:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|P datPrep)
      n:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, object moved; PARTP - object moved
      y:       (IP-MAT* iDoms movedFirstPP)    AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*) AND (movedFirstPP iDomsMod PP|P datPrep)
      n:       (IP-MAT* iDoms movedFirstPP)    AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
      -:        ELSE
}

// FIRST PP
// type of complement
14: {  
// trace
      #14:       (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDoms \*T*)
// monoclausal case without movement (including modal and PARTP cases)
      o_Res:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-CL-PP*RSP*)
//      o_cli:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* FIRST-CL-PP*)
      o_np:      (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP fullNP)
      o_pro:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP PRO)
      o_frl:     (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP CP*)
      o_ip:      (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP) AND (firstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (IP-MAT* iDoms !movedFirstPP|movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* firstPP)
// modal - infinitive moved, PP moved
      o_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP)         AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-CL-PP-*-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF* ZZZ-PP*RSP*)
//      o_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms FIRST-CL-PP-*-MOVED*)
      o_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP fullNP)
      o_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP PRO)
      o_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP CP*)
      o_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDoms movedFirstPP)
// modal - infinitive moved, PP in situ
      o_Res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-CL-PP*RSP*)
//      o_cli:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* FIRST-CL-PP*)
      o_np:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP fullNP)
      o_pro:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP PRO)
      o_frl:     (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP CP*)
      o_ip:      (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP) AND (firstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (IP-MAT* iDoms movedInf) AND (IP-MAT* iDomsMod MOD-IP-INF* firstPP)
// modal - infinitive in situ, PP moved; PARTP - PP moved
      o_Res:     (IP-MAT* iDoms movedFirstPP)         AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
// clitic PPs aren't marked as FIRST-PP
//      o_res:     (IP-MAT* iDoms FIRST-CL-PP-*-MOVED*) AND (IP-MAT* iDomsMod MOD-IP-INF*|PARTP* ZZZ-PP*RSP*)
//      o_cli:     (IP-MAT* iDoms FIRST-CL-PP-*-MOVED*)
      o_np:      (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP fullNP)
      o_pro:     (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP PRO)
      o_frl:     (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP CP-FRL*)
      o_cp:      (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP CP*)
      o_ip:      (IP-MAT* iDoms movedFirstPP)         AND (movedFirstPP iDomsMod PP|NP IP-MAT|IP-MAT-SPE)
      #14:       (IP-MAT* iDoms movedFirstPP)
      -:         ELSE
}

