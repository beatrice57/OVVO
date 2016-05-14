node: $ROOT

query:     (CODING* column 5 s_Dem|s_NP|s_Pro)
       AND (CODING* column 9 fin-non)
       AND (CODING* column 10 o_np|o_pro)       AND (CODING* column 16 fin-o)
//       AND (CODING* column 18 def)
       AND (CODING* column 11 o_np|o_pro)       AND (CODING* column 20 fin-o)
       AND (CODING* column 28 2-v-dtv-acc)
