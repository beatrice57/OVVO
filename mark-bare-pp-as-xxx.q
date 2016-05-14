node: $ROOT

copy_corpus: t

ignore_nodes: \**

query:     (IP-*|*-IP-INF* iDomsMod PARTP {1}PP) AND (PP iDomsMod PP NP)

append_label{1}: -XXX
