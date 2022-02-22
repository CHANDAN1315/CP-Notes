# Bitset and it's application

### important points

    - it is better in space complexity than vector of bool.
    - We can access each bit of bitset individually with
      help of array indexing operator [] that is bs[3].
    - Remember bitset starts its indexing backward that 
      is for 10110, 0 are at 0th and 3rd indices whereas 1 are at 1st 2nd and 4th indices.

### initilization
      const int M = 32;   
    - bitset<M> bset1   //  00000000000000000000000000000000
    - bitset<M> bset2(20)  // 00000000000000000000000000010100
    - bitset<M> bset3(string("1100"))  //00000000000000000000000000001100

### Operation
    1. General Operation
        - count , size, set ,reset, flip

    2. Bitwise Operation
        - &, |, ==, !=, <<,>>
          for more about operators : https://www.tutorialspoint.com/cpp_standard_library/bitset.htm
   
    3. functions
      - to_string()
          eg std::bitset<8> b(42);
                b.to_string()  //00101010
                b.to_string('*') //**1*1*1*
                b.to_string('O', 'X') //OOXOXOXO
      
      - unlong() // to convert bitset to long long
          eg. std::bitset<5> b(5);
                   b.to_ulong() // 5

