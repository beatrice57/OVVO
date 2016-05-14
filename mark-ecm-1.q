node: $ROOT

copy_corpus: t

query:     ({1}IP-INF*|IP-SMC* iDoms CL-NP-SBJ*|NP-SBJ*)

prepend_label{1}: ECM-
