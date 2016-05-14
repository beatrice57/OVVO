node: IP-ABS*

define: GTRC.def

// count clitics, neg, traces
ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF

coding_query:

// subject and direct object
15: { -: ELSE
}

// finite verb and direct object
16: { -: ELSE
}

// nonfinite verb and subject (treated on a par with subject of ECM complement)
17: { 
      non-O:      (IP-ABS* iDoms sbj) AND (IP-ABS* iDoms VPP*) AND (VPP* precedes sbj)
      O-non:      (IP-ABS* iDoms sbj) AND (IP-ABS* iDoms VPP*) AND (sbj precedes VPP*)
      prd-O:      (IP-ABS* iDoms sbj) AND (IP-ABS* iDoms *-LOC*|*-PRD*|VG) AND (*-LOC*|*-PRD*|VG precedes sbj)
      O-prd:      (IP-ABS* iDoms sbj) AND (IP-ABS* iDoms *-LOC*|*-PRD*|VG) AND (sbj precedes *-LOC*|*-PRD*|VG)
      prd-O:      (IP-ABS* iDomsTotal 2) AND (IP-ABS* iDoms sbj) AND (IP-ABS* iDoms PP)  AND (PP precedes sbj)
      O-prd:      (IP-ABS* iDomsTotal 2) AND (IP-ABS* iDoms sbj) AND (IP-ABS* iDoms PP)  AND (sbj precedes PP)
      #17:        (IP-ABS* iDoms sbj)
      -: ELSE
}

// SUBJECT
// quantificational type
18: { 
      -:       (CODING-IP-ABS* column 10 -|O_sil)
      s:       (CODING-IP-ABS* column 10 O_frl|O_cp|O_ip)
      cli:     (CODING-IP-ABS* column 10 O_cli|O_res)
      def:     (CODING-IP-ABS* column 10 O_pro)
// monoclausal case without movement (including modal and PARTP cases)
      conj:    (IP-ABS* iDoms sbj) AND (sbj iDoms CONJP*)
      spl:     (IP-ABS* iDoms sbj) AND (sbj iDoms QP) AND (QP iDoms \*ICH*|\*T*)
      uni:     (IP-ABS* iDoms sbj) AND (sbj iDomsMod QP Q) AND (Q iDoms univQ)
      neg:     (IP-ABS* iDoms sbj) AND (sbj iDomsMod QP Q) AND (Q iDoms negQ)
      npi:     (IP-ABS* iDoms sbj) AND (sbj iDomsMod QP Q-NPI) AND (Q-NPI iDoms npi)
      exi2:    (IP-ABS* iDoms sbj) AND (sbj iDomsMod QP Q) AND (Q iDoms npi)
      exi:     (IP-ABS* iDoms sbj) AND (sbj iDomsMod QP Q|Q[RS])
      par:     (IP-ABS* iDoms sbj) AND (sbj iDoms DF)
      def:     (IP-ABS* iDoms sbj) AND (sbj iDoms defHead)
      def:     (IP-ABS* iDoms sbj) AND (sbj iDoms D) AND (D iDoms defDet)
      ind:     (IP-ABS* iDoms sbj) AND (sbj iDoms D) AND (D iDoms indefDet)
      ind:     (IP-ABS* iDoms sbj) AND (sbj iDoms !Q*|DF|defHead|D)
      #18:     (IP-ABS* iDoms *NP-SBJ*)
}

// SUBJECT
// length
19: { 
      -:       (CODING-IP-ABS* column 10 -|O_sil)
      \1:      (IP-ABS* iDoms sbj) AND (sbj domsWords 1)
      \2:      (IP-ABS* iDoms sbj) AND (sbj domsWords 2)
      \3:      (IP-ABS* iDoms sbj) AND (sbj domsWords 3)
      \4:      (IP-ABS* iDoms sbj) AND (sbj domsWords 4)
      \5:      (IP-ABS* iDoms sbj) AND (sbj domsWords> 4)
      #19:     (IP-ABS* iDoms *NP-SBJ*)
      -:       ELSE
}

// finite verb and indirect object
20: { -: ELSE
}

// finite verb and first PP
21: { -: ELSE
}

// nonfinite verb raising
22: { 
// participle
      advp-part-o:     (IP-ABS* iDoms NP-SBJ*) AND (IP-ABS* iDoms VPP*) AND (IP-ABS* iDoms ADVP*) AND (ADVP* iPrecedes VPP*) AND (VPP* iPrecedes NP-SBJ*)
      advp-o-part:     (IP-ABS* iDoms NP-SBJ*) AND (IP-ABS* iDoms VPP*) AND (IP-ABS* iDoms ADVP*) AND (ADVP* iPrecedes NP-SBJ*) AND (NP-SBJ* iPrecedes VPP*)
      part-advp-o:     (IP-ABS* iDoms NP-SBJ*) AND (IP-ABS* iDoms VPP*) AND (IP-ABS* iDoms ADVP*) AND (VPP* iPrecedes ADVP*) AND (ADVP* iPrecedes NP-SBJ*)
      pp-part-o:       (IP-ABS* iDoms NP-SBJ*) AND (IP-ABS* iDoms VPP*) AND (IP-ABS* iDoms prepP) AND (prepP iPrecedes VPP*) AND (VPP* iPrecedes NP-SBJ*)
      pp-o-part:       (IP-ABS* iDoms NP-SBJ*) AND (IP-ABS* iDoms VPP*) AND (IP-ABS* iDoms prepP) AND (prepP iPrecedes NP-SBJ*) AND (NP-SBJ* iPrecedes VPP*)
      part-pp-o:       (IP-ABS* iDoms NP-SBJ*) AND (IP-ABS* iDoms VPP*) AND (IP-ABS* iDoms prepP) AND (VPP* iPrecedes prepP) AND (prepP iPrecedes NP-SBJ*)
      -: ELSE
}

// tense of AVOIR
23: { -: ELSE
}

// gender of antecedent
24: { 
      coord: (IP-ABS* iDoms CL-NP-SBJ-C*|NP-SBJ-C*)
      part:  (IP-ABS* iDoms CL-NP-SBJ-D*|NP-SBJ-D*)
      f:     (IP-ABS* iDoms CL-NP-SBJ-F*|NP-SBJ-F*)
      m:     (IP-ABS* iDoms CL-NP-SBJ-M[CDPSX]|CL-NP-SBJ-M[CDPSX].*|NP-SBJ-M[CDPSX]|NP-SBJ-M[CDPSX].*)
      x:     (IP-ABS* iDoms CL-NP-SBJ-X*|NP-SBJ-X*)
      -: ELSE
}
          
// number of antecedent
25: { 
      coord: (IP-ABS* iDoms CL-NP-SBJ-[CDFMX]C*|NP-SBJ-[CDFMX]C*)
      part:  (IP-ABS* iDoms CL-NP-SBJ-[CDFMX]D*|NP-SBJ-[CDFMX]D*)
      pl:    (IP-ABS* iDoms CL-NP-SBJ-[CDFMX]P*|NP-SBJ-[CDFMX]P*)
      sg:    (IP-ABS* iDoms CL-NP-SBJ-[CDFMX]S*|NP-SBJ-[CDFMX]S*)
      x:     (IP-ABS* iDoms CL-NP-SBJ-[CDFMX]X*|NP-SBJ-[CDFMX]X*)
      -: ELSE
}

// gender of participle
26: { 
      coord: (IP-ABS* iDoms VPP-C*)
      part:  (IP-ABS* iDoms VPP-D*)
      f:     (IP-ABS* iDoms VPP-F*)
      m:     (IP-ABS* iDoms VPP-M*)
      x:     (IP-ABS* iDoms VPP-X*)
      #26:   (IP-ABS* iDoms VPP*)
      -: ELSE
}
          
// number of participle
27: { 
      coord: (IP-ABS* iDoms VPP-[CDFMX]C*)
      part:  (IP-ABS* iDoms VPP-[CDFMX]D*)
      pl:    (IP-ABS* iDoms VPP-[CDFMX]P*)
      sg:    (IP-ABS* iDoms VPP-[CDFMX]S*)
      x:     (IP-ABS* iDoms VPP-[CDFMX]X*)
      #27:   (IP-ABS* iDoms VPP*)
      -: ELSE
}
