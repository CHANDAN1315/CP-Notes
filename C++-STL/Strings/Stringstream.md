# stringstream in C++ and its Applications
```
-A stringstream associates a string object with a stream allowing you to read from the string 
as if it were a stream (like cin).
```

```cpp
int countWords(string str)
{
    // Breaking input into word
    // using string stream
   
    // Used for breaking words
    stringstream s(str);
   
    // To store individual words
    string word;
 
    int count = 0;
    while (s >> word)
        count++;
    return count;
}
```
# getline (string) in C++
```
The C++ getline() is a standard library function that is used to read a string or a
line from an input stream. It is a part of the <string> header.

Parameters: 
  
  1 Syntax : istream& getline(istream& is, string& str, char delim);
  
- is: It is an object of istream class and tells the function about the stream from where to read the input from.
- str: It is a string object, the input is stored in this object after being read from the stream.
- delim: It is the delimitation character which tells the function to stop reading further input after reaching this character.

2 Syntax : istream& getline (istream& is, string& str)

- is: It is an object of istream class and tells the function about the stream from where to read the input from.
- str: It is a string object, the input is stored in this object after being read from the stream.

```
```cpp
#include <iostream>
#include <string>
using namespace std;
  
int main()
{
    string str;
  
    cout << "Please enter your name: \n";
    getline(cin, str);
    cout << "Hello, " << str
         << " welcome to GfG !\n";
  
    return 0;
}

```
