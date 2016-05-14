node: $ROOT

copy_corpus: t

query:     ({1}IP-INF*|IP-SMC* iDoms ECM-IP*)
       AND (ECM-IP* iDoms CONJP)

prepend_label{1}: ECM-
