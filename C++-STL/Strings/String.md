## String function and operations
**i - can be iterator, value**

#### Iterators:

       s.begin() : Return iterator to beginning (public member function 
       s.end() : Return iterator to end (public member function 

#### Capacity:

       s.size()   : Return length of string (public member function 
       s.length() :Return length of string (public member function 
       s.clear() :Clear string (public member function 
       s.empty() :Test if string is empty (public member function 
#### Element access:

       
       s.at(value) : Get character in string (public member function 
       s.back() :Access last character (public member function 
       s.front() :Access first character (public member function 
#### Modifer:

       s.push_back() :Append character to string (public member function )
       s.insert :Insert into string (public member function )
       s.erase(i) != s.end() :Erase characters from string (public member function )
       s.swap(j,j+1) :Swap string values (public member function )
       s.pop_back() :Delete last character (public member function )

#### operations

       note :- s.find(i) != s.end()
       find(i) : Find content in string (public member funct

       note :- a - initial position ; b - length of the substring.
       s.substr(a,b) Generate substring (public member function )

       string str;
       getline(cin, str) : Get line from stream into string (function )
