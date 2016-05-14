node: IP-ABS*

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
4: { gap: (IP-ABS*=* exists)
     abs: (IP-ABS* exists)
     -: ELSE
}

// SUBJECT
// type of subject
5: { -: ELSE
}

// FINITE VERB
// type
6: { -: ELSE
}

// ORDER
// subject and finite verb
// 7: { in abs-2.c

// subject and nonfinite verb
8: { -:	ELSE
}

// finite and nonfinite verb
9: { -:	ELSE
}

// SUBJECT (TREATED LIKE SUBJECT OF ECM COMPLEMENT)
// type
10: { O_sil:     (IP-ABS* iDoms NP-SBJ*) AND (NP-SBJ* iDoms \**)
      O_Res:     (IP-ABS* iDoms NP-SBJ*RSP*)
      O_res:     (IP-ABS* iDoms CL-NP-SBJ*RSP*)
      O_cli:     (IP-ABS* iDoms CL-NP-SBJ*)
      O_np:      (IP-ABS* iDoms NP-SBJ*) AND (NP-SBJ* iDomsMod NP fullNP)
      O_pro:     (IP-ABS* iDoms NP-SBJ*) AND (NP-SBJ* iDoms PRO)
      O_frl:     (IP-ABS* iDoms NP-SBJ*) AND (NP-SBJ* iDomsFirst CP-FRL*)
      O_cp:      (IP-ABS* iDoms NP-SBJ*) AND (NP-SBJ* iDomsOnly CP*)
      O_ip:      (IP-ABS* iDoms NP-SBJ*) AND (NP-SBJ* iDomsOnly IP-MAT|IP-MAT-SPE)
      #10:       (IP-ABS* iDoms *NP-SBJ*)
      -: ELSE
}

// INDIRECT OBJECT
// type
11: { -: ELSE
}

// FIRST PP
// type of PP
12: { -: ELSE
}

// FIRST PP
// preposition is A or not
13: { -: ELSE
}

// FIRST PP
// type of complement
14: { -: ELSE
}

