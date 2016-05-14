node: IP-MAT*|IP-SUB*

define: GTRC.def

ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF|\**

coding_query:

// tense of AVOIR - comes out as fg 21
1: { 
//     imparfait:     (AJ iDoms @av[ao][iy].*|[aAáÁ][uv][aeo][iy].*|[aAáÁ][uv]et|[aAáÁ][uv][iíïy].*|[rR]a[uv][aeo][iy].*|[rR]a[uv][iíïy].*)
//     passe_simple:  (AJ iDoms @eu*|@o*|[aA]u[dt]|[aA]urent|[aA]us*|[eE][uü]|[eE][uü].*|[hH]e[uü]|[hH]e[uü].*|[oO][ct]|[oO]ct|[oO]grent|[oO]i|[oO]rent|[oO]rrent|[oOóÓ][uüú].*|[oOóÓ][yz]|[rR]ot|[uUúÚ]issums|[uUúÚ]rent|[uUúÚ]s*)
//     futur:         (AJ iDoms [aAáÁ]r*|[aAáÁ][uv]er*|[aAáÁ][uv]r*|[rR]a[r][aeo][iy].*)
//     present:       (AJ iDoms @a|@a*|[aA]|[aA]-t|[aAáÁ][diíjsty]|[aAáÁ][iy].*|[aAáÁ][uv][eé][sz]|[aAáÁ][uv][ou].*|[eEéÉ]|[eEéÉ]i|[eEéÉ]i.*|[hH]a|[hH][ae][is]|[oO]n|[oO]n.*|[rR]a|[rR]ad|[rR]ont|[uUúÚ]nt)
     ZZZ:          (AJ iDoms !avoir|AJ)
     -: ELSE
}
