
# Notes :

1. Binary Left and Right shift operator

-> Left shift(<<)
    note : used to multiply by power of 2.
    
    n = (n<<i) ->  n = (n)*2^i 

    eg : 5 <<1 :- 101 << 1 -> 1010 = (10)
         8 << 1 :- 1000 << 1 -> 10000 = (16)
         5 << 4 :- 101 << 4 -> 1010000 = (80)   
         ***note :( here left shif operator will push the Binary of that number i'th time Leftward.)

-> Right Shift(>>)
    note : used to divide by power of 2.
    
    n = (n>>i) ->  n = (n)/2^i

    eg : 10 >> 1 :- 1010>>1 -> 101 = (5)
         16 >> 1 :- 10000 >> 1 -> 1000 = (8)
         80 >> 4 :- 1010000 >>4 -> 101 = (5)
         ***note :( here Right shif operator will push the Binary of that number i'th time rightward    .)


2. Check the i'th bit is set or not.
    
        n = n & (1<<i)
        note : The integer having one set bit is power of 2.

3. set the i'th bit
    
        (n | (1<<i))


4. Unset the i'th bit

        (n & (~(1<<i)))

5. Toggle the i'th bit

        (n ^ (1<<i))

6. inverting every bit by one complement 

        ~(n)

7. To unset the right most set bit
    
        n = (n & (n-1))

8. lowest set bit

       ans = n & (-n)

9. Lower case to upper case // 

        char ch = 'a' //(01100001)
        char mask = '_'//(11011111) 
        char ans = (ch | mask) = 'A'
        
10. upper to lower case 
        
        ch = 'A' (01000001) 
        mask = '' (00100000) 
        ch | mask = 'a' (01100001) 

11) is power of 2

        x and !(x & (x-1))

12) Check the given number is power of (x) or not 
        
        ceil(logx(n)) == floor(logx(n))

13) To find the right most set bit

        n & ~(n-1)
