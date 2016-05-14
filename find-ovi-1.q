node: $ROOT

query:     (CODING* column 16 o-fin)
       AND (CODING* column 17 non-o)
       AND (CODING* column 9 non-fin)
//       AND (CODING* column 10 o_np|o_pro)
       AND (CODING* column 10 !o_cl*)
