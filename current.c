node: IP-*|*-IP*|ORD-IP* 

define: GTRC.def

ignore_nodes: CODE|ID|ITJ*|LS|META|NP-VOC|PON*|REF|\**

coding_query:

30: { 
      ##p: (VPP*[123456789] exists)
      ##i: (VX*[123456789] exists)
      ##30: ELSE
}
