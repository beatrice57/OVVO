node: CP*

define: GTRC.def

// ignore clitics and neg for position
// count traces
ignore_nodes: CL*|CODE|ID|ITJ*|LS|META|NEG|NP-VOC|PON*|REF

coding_query:

// ORDER
// subject and finite verb
7: { s-fin:   (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms *-SBJ*) AND (IP-SUB* iDoms finiteAll) AND (*-SBJ* iPrecedes finiteAll)
     s-x-fin: (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms *-SBJ*) AND (IP-SUB* iDoms finiteAll) AND (*-SBJ* precedes finiteAll)
     fin-s:   (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms *-SBJ*) AND (IP-SUB* iDoms finiteAll) AND (finiteAll precedes *-SBJ*)
     #7:      (CP* iDoms IP-SUB*) AND (IP-SUB* iDoms *-SBJ*) AND (IP-SUB* iDoms finiteAll)
     -:  ELSE
}


