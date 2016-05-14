node: $ROOT

copy_corpus: t

query:     ({1}IP-INF* iDomsMod CONJP [1]ORD-IP*)

prepend_label{1}: ORD-

//query:     ({1}IP-INF* iDoms [1]ORD-IP*)
//       AND (IP-INF* iDoms CONJP)
//       AND (CONJP iDoms [2]ORD-IP*|CP-THT*)

//prepend_label{1}: ORD-
