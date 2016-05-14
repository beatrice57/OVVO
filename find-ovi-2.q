node: $ROOT

query:     (CODING* column 5 s_Dem|s_NP|s_Pro)
       AND (CODING* column 17 o-non)
       AND (CODING* column 9 non-fin)
       AND (CODING* column 10 o_np|o_pro)
