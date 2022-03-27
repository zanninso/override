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
