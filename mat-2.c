node: IP-MAT*

define: GTRC.def

// ignore clitics and neg for position
// count traces
ignore_nodes: CL*|CODE|ID|ITJ*|LS|META|NEG|NP-VOC|PON*|REF

coding_query:

// ORDER
// subject and finite verb
7: { s-fin:   (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDoms finiteAll) AND (*-SBJ* iPrecedes finiteAll)
     s-x-fin: (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDoms finiteAll) AND (*-SBJ* precedes finiteAll)
     fin-s:   (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDoms finiteAll) AND (finiteAll precedes *-SBJ*)
     #7:      (IP-MAT* iDoms *-SBJ*) AND (IP-MAT* iDoms finiteAll)
     -:  ELSE
}


