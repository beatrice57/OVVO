node: $ROOT

query:     (CODING* column 5 s_Dem|s_NP|s_Pro)
       AND (CODING=IP* column 6 !aux_etre)
       AND (CODING* column 9 fin-non)
       AND (CODING* column 11 o_np|o_pro)       AND (CODING* column 20 fin-o)
       AND (CODING* column 14 o_np|o_pro)       AND (CODING* column 21 fin-o)
       AND (CODING* column 28 2-pp-v-dtv)
