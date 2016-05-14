node: $ROOT

copy_corpus: t

// ignoring clitics

query:     (IP-*|ECM-IP*|MOD-IP*|ORD-IP* iDoms {1}FIRST-PP*)
       AND (IP-*|ECM-IP*|MOD-IP*|ORD-IP* doms {2}PP*)
       AND (PP* iDoms \**)
       AND (FIRST-PP* sameIndex \**)

prepend_label{1}: MOVED-
prepend_label{2}: ZZZ-




