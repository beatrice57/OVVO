node: $ROOT

copy_corpus: t

query:     ({1}IP-INF*|IP-SMC* iDoms ECM-IP*)
       AND (IP-INF*|IP-SMC* iDoms CONJP)
       AND (CONJP iDoms {2}IP-INF*=*|IP-SMC*=*)

prepend_label{1}: ECM-
prepend_label{2}: ECM-
