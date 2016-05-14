node: $ROOT

copy_corpus: t

ignore_nodes: \**

query:     (IP-*|*-IP-INF* iDomsMod PARTP [1]{1}PP*) AND (IP-*|*-IP-INF* iDomsMod PARTP !FIRST-PP*) AND ([1]PP* iDomsMod PP NP)
       AND (IP-*|*-IP-INF* iDomsMod PARTP [2]PP*) AND ([1]PP* precedes [2]PP*)

prepend_label{1}: FIRST-
