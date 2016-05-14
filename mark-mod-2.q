node: $ROOT

copy_corpus: t

query:     (MOD-IP-INF* iDomsMod CONJP {1}IP-INF*)

prepend_label{1}: MOD-

//query:     (MOD-IP-INF* iDoms [1]{1}IP-INF*)
//       AND (MOD-IP-INF* iDoms CONJP)
//       AND (CONJP iDoms [2]{2}IP-INF*)
//       AND ([1]IP-INF* iDoms !*-SBJ*)
//       AND ([2]IP-INF* iDoms !*-SBJ*)

//prepend_label{1}: MOD-
//prepend_label{2}: MOD-
