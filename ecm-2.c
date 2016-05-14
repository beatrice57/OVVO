node: ECM-IP-INF*

define: GTRC.def

// ignore clitics and neg for position
// count traces
ignore_nodes: CL*|CODE|ID|ITJ*|LS|META|NEG|NP-VOC|PON*|REF

coding_query:

// ORDER
// subject and finite verb
7: { 
     -:       (ECM-IP-INF* iDoms CONJP)
     -:       (ECM-IP-INF* iDoms ZZZ*-SBJ*)
     s-fin:   (ECM-IP-INF* iDoms *-SBJ*) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND (*-SBJ* iPrecedes [AE]X|MDX)
     s-x-fin: (ECM-IP-INF* iDoms *-SBJ*) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND (*-SBJ* precedes [AE]X|MDX)
     fin-s:   (ECM-IP-INF* iDoms *-SBJ*) AND (ECM-IP-INF* iDoms [AE]X|MDX) AND ([AE]X|MDX precedes *-SBJ*)
     #7:      (ECM-IP-INF* iDoms *-SBJ*) AND (ECM-IP-INF* iDoms [AE]X|MDX)
     -:  ELSE
}



