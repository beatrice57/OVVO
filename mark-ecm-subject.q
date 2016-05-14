node: $ROOT

copy_corpus: t

// including clitics

query: (ECM-IP* iDoms {1}CL-NP-SBJ*|NP-SBJ*)

prepend_label{1}: ECM-
