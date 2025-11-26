**NG 11/26/2025**
* class definition style & standards:  first, member vars  none per line and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions, except for static function,  should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
* To provide you with thorough feedback, your instructor reads your code line by line and runs it and quite often does it multiple times. Jumping from file to file is too time-consuming. Unless noted otherwise, place your class definitions above the main() and all function definitions below main(), all in one file. While the industry standard involves multi-source file programs, we will use a single file format for these labs unless instructed otherwise.
* Posted instructions are not optional; assignment description/requirements/specifications, and not following the instructions will result in a lower grade. It applies to all assignments in this course.

* 134 check spelling;  #139 what for?  consider return (rand() % 20) == 0?  getDamage()*2: getDamage();
* test runs not included -10
* rule of three -10
* DMA  handling; what of new fails – should deallocate all previously allocated memory and let the user know; deallocation should be handled by the class who made the allocation, army d’tor in this case, not main; 443 results in memory leak- releases array of pointers but not the creatures– 10 
* 461 results in a dangling pointer
* class(es) do(es) provide strong exception guarantee -5
*  should create consts for the default values; if it is not 1 or zero, make it const -5
* inline functions do not adhere to the best practices; an inline function may not be longer than one executable statement -5
* getter/accessor function(s) allow object state modification; const int foo() and int foo() const are not the same -5
* 44 if a class is a parent, to ensure proper object disposal, especially when DMA is involved, the destructor must be virtual -5
* 109 unnecessary function calls = unnecessary computation expense; make parents member vars protected -2
* 457 what if a user enters a non-number? -2

* 107 and like  – calls default parent c’tor; should call corresponding parent c’tor; corresponding parent c;tor already calls setCreature( newName,  newHealth, newStrength);-2
```text
 Elf(string newName, int newHealth, int newStrength): Creature( newName,  newHealth, newStrength) { } 
```
* 398 – should use switch  with enum -1
* poor Id(s)  and/or inconsistent naming convention; ids should be self-documenting and as short as possible; use verbs for functions and nouns for variables; use camel-casing for variables (errorMessage) enum & const should be in upper case with words separated by “_”, e.g., MAX_TERMS, PRINT_RECORDS; pointer variables should start with p( if single)  or pp( if double pointer); flags isValid ( clearly what true would mean); if copying – e.g rhsQueue or scrQueue ( rhs- right-hand side, src – source); do not use IDs and default values that are same as or very similar to C++  keywords and functions; no need to call an array “array”- it is obvious; vars should not be called value;  one char identifiers (e.g. j,k, i) are only suitable for loop counters; consider using prefix n -2
```text
        Creature** creatures;
```
* I will replace this lab’s score with your next lab score, as long as the next lab score is higher and all mistakes from this lab are corrected

