node: PP*

copy_corpus: t

query:     (PP* iDomsFirst {1}NP-*)
       AND (PP* iDomsMod PP ORD-IP-INF*|IP-PPL*)
       AND (NP-* precedes ORD-IP-INF*|IP-PPL*)
       AND (ORD-IP-INF*|IP-PPL* iDoms {2}NP-ACC*)
       AND (NP-ACC* iDoms \**)
       AND (NP-* sameIndex \**)

prepend_label{1}: ZZZ-
prepend_label{2}: ZZZ-




