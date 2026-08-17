//Complete and categorized list of commonly used string functions in C++:


//String concatenation
//1. Using + Operator
// string a = "Hello";
// string b = "World";
// string c = a + " " + b;

//Output:Hello World

//2. Using += Operator (what you used)
// string result = "";
// result += 'a';
// result += "bc";

//Output:abc

//3. Using append() Function
// string s = "Hello";
// s.append(" World");

//Output:Hello World



// 1. Constructors
// string s1;                  // empty
// string s2("hello");         // from literal
// string s3(s2);              // copy
// string s4(5, 'a');          // "aaaaa"


// 2. Size & Capacity
// s.length()        // number of characters
// s.size()          // same as length()  //size() and length() are identical.
// s.max_size()      // max possible size
// s.capacity()      // current allocated capacity
// s.resize(n)       // resize string
// s.empty()         // check if empty


// 3. Element Access
// s[i]              // access character
// s.at(i)           // safe access (throws error if out of range)  //at() is safer than []
// s.front()         // first character
// s.back()          // last character


// 4. Modifiers
// s.append("abc")        // add at end
// s += "abc"             // append
// s.push_back('x')       // add one char
// s.pop_back()           // remove last char

// s.insert(pos, "text")  // insert at position
// s.erase(pos, len)      // delete part
// s.clear()              // remove all characters

// s.replace(pos, len, "new") // replace part
// s.swap(s2)             // swap with another string


// 5. String Operations
// s.substr(pos, len)     // substring


// 6. Searching Functions
// s.find("abc")          // first occurrence
// s.rfind("abc")         // last occurrence

// s.find_first_of("aeiou")     // first vowel
// s.find_last_of("aeiou")      // last vowel

// s.find_first_not_of("abc")   // first char NOT in set
// s.find_last_not_of("abc")    // last char NOT in set


// 7. Comparison
// s.compare(s2)   // returns 0 if equal


// 8. C-Style Conversion
// s.c_str()       // convert to C-string (const char*)
// s.data()        // pointer to internal array


// 9. Iterators
// s.begin()
// s.end()
// s.rbegin()
// s.rend()


// 10. Copying
// s.copy(char_array, len, pos)


// 11. Input / Output
// cin >> s        // input (no spaces)
// getline(cin, s) // input with spaces
// cout << s       // output


// 12. Useful Extra Functions (C++11+)
// stoi(s)     // string → int
// stol(s)     // string → long
// stof(s)     // string → float
// stod(s)     // string → double

// to_string(x)  // number → string





//From Here-
// These functions work on char, not directly on string
// Use loops or transform() for full strings



// 1. Case Conversion Functions

// These work on single characters:

// #include <cctype>

// toupper(ch)   // convert to uppercase
// tolower(ch)   // convert to lowercase

// Example:
// char ch = 'a';
// cout << (char)toupper(ch);   // Output: A



// 2. Check Character Type
// isupper(ch)   // checks uppercase letter
// islower(ch)   // checks lowercase letter
// isalpha(ch)   // checks alphabet (A-Z, a-z)
// isdigit(ch)   // checks digit (0-9)
// isalnum(ch)   // checks alphabet or digit
// isspace(ch)   // checks space

// Example:
// if (isupper('A')) cout << "Uppercase";



// 3. Convert Entire String to Uppercase
// #include <algorithm>
// #include <cctype>

// string s = "hello";

// for (int i = 0; i < s.length(); i++) {
//     s[i] = toupper(s[i]);
// }

// cout << s;   // HELLO



// 4. Convert Entire String to Lowercase
// for (int i = 0; i < s.length(); i++) {
//     s[i] = tolower(s[i]);
// }


//Transform function
//Syntax-
//transform(input_begin, input_end, output_begin, function);
// 5. Using transform() (Best Method)
// #include <algorithm>

// transform(s.begin(), s.end(), s.begin(), ::toupper);
// transform(s.begin(), s.end(), s.begin(), ::tolower);



// 6. Toggle Case (Upper ↔ Lower)
// for (int i = 0; i < s.length(); i++) {
//     if (isupper(s[i]))
//         s[i] = tolower(s[i]);
//     else if (islower(s[i]))
//         s[i] = toupper(s[i]);
// }



// 7. Capitalize First Letter
// s[0] = toupper(s[0]);



// 8. Capitalize Each Word
// for (int i = 0; i < s.length(); i++) {
//     if (i == 0 || s[i-1] == ' ') {
//         s[i] = toupper(s[i]);
//     }
// }



// Summary Table
// Function	    Purpose
// toupper()	to uppercase
// tolower()	to lowercase
// isupper()	check uppercase
// islower()	check lowercase
// isalpha()	check letter
// isdigit()	check number
// isalnum()	letter or number
// isspace()	check space













// 1. Complete Character Functions (<cctype>)

// These work on char.

// ✅ Case Conversion

// toupper(ch)

// tolower(ch)

// ✅ Checking Functions

// isupper(ch)

// islower(ch)

// isalpha(ch)

// isdigit(ch)

// isalnum(ch)

// isspace(ch)

// isblank(ch)

// iscntrl(ch)

// isprint(ch)

// ispunct(ch)

// isxdigit(ch)

// isgraph(ch)


// 🔵 2. Complete std::string Functions

// (from C++ Standard Library)

// ✅ A. Size & Capacity

// size()

// length()

// max_size()

// capacity()

// resize()

// empty()

// reserve()

// shrink_to_fit()

// ✅ B. Element Access

// operator[]

// at()

// front()

// back()

// data()

// c_str()

// ✅ C. Modifiers

// append()

// push_back()

// pop_back()

// insert()

// erase()

// replace()

// clear()

// swap()

// ✅ D. String Operations

// substr()

// copy()

// ✅ E. Searching

// find()

// rfind()

// find_first_of()

// find_last_of()

// find_first_not_of()

// find_last_not_of()

// ✅ F. Comparison

// compare()

// ✅ G. Iterators

// begin(), end()

// rbegin(), rend()

// cbegin(), cend()

// crbegin(), crend()

// ✅ H. Non-Member Functions (Important)

// getline()

// swap()

// 🔵 3. Conversion Functions (Very Important)

// stoi()

// stol()

// stoll()

// stof()

// stod()

// stold()

// to_string()

// 🔴 Important Truth (Exam Point)

// 👉 C++ does NOT provide built-in string functions for:

// Uppercase whole string ❌

// Lowercase whole string ❌

// Reverse string ❌

// ✔ You must use:

// loops

// or transform()

// or reverse() (from <algorithm>)