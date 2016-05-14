node: $ROOT

copy_corpus: t

query:     ({1}IP-INF* iDoms !NP-SBJ*|CL-NP-SBJ*|CONJP)

prepend_label{1}: ORD-
