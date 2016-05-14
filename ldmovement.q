node: $ROOT

query:     (WNP* hasSister [1]IP-SUB*)
       AND ([1]IP-SUB* iDoms AJ)
       AND ([1]IP-SUB* iDoms CP-THT*)
       AND (CP-THT* iDoms [2]IP-SUB*)
       AND ([2]IP-SUB* iDoms NP-ACC*)
       AND (NP-ACC* iDoms \**)
       AND (WNP* sameIndex \**)


