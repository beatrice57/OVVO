node: $ROOT

copy_corpus: t

query:     (IP-*|ECM-IP*|MOD-IP*|ORD-IP* iDoms {1}PP-*)
       AND (IP-*|ECM-IP*|MOD-IP*|ORD-IP* doms {2}PP-PRD*)
       AND (PP-PRD* iDoms \**)
       AND (PP-* sameIndex \**)

prepend_label{1}: MOVED-PRD-
prepend_label{2}: ZZZ-
