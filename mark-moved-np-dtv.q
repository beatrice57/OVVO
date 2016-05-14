node: $ROOT

copy_corpus: t

// including clitics

query:     (IP-*|ECM-IP*|MOD-IP*|ORD-IP* iDoms {1}CL-NP-*|NP-*)
       AND (IP-*|ECM-IP*|MOD-IP*|ORD-IP* doms {2}NP-DTV*)
       AND (NP-DTV* iDoms \**)
       AND (CL-NP-*|NP-* sameIndex \**)

prepend_label{1}: MOVED-DTV-
prepend_label{2}: ZZZ-




