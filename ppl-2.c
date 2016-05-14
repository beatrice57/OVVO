node: IP-PPL*

define: GTRC.def

// ignore clitics and neg for position
// count traces
ignore_nodes: CL*|CODE|ID|ITJ*|LS|META|NEG|NP-VOC|PON*|REF

coding_query:

// ORDER
// subject and finite verb
7: { s-fin:   (IP-PPL* iDoms *-SBJ*) AND (IP-PPL* iDoms [AE]G|MDG) AND (*-SBJ* iPrecedes [AE]G|MDG)
     s-x-fin: (IP-PPL* iDoms *-SBJ*) AND (IP-PPL* iDoms [AE]G|MDG) AND (*-SBJ* precedes [AE]G|MDG)
     fin-s:   (IP-PPL* iDoms *-SBJ*) AND (IP-PPL* iDoms [AE]G|MDG) AND ([AE]G|MDG precedes *-SBJ*)
     #7:      (IP-PPL* iDoms *-SBJ*) AND (IP-PPL* iDoms [AE]G|MDG)
     -:  ELSE
}


