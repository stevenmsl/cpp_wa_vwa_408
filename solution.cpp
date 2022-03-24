#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>
using namespace sol408;
using namespace std;

/*takeways
  - use s = "internationalization", abbr = "i12iz4n" as an example
    - i points at 'i' and j points at 'i' (v) we are good here
    - j encounters a number 12. produce the number 12, and point j
      at 'i' char after the "..12"(i)
    - i needs skip ahead for 12 chars, and it will point at the 'i'
      char after "...onal"(i)
    - continue the process until we reach the end of word and abbr

  - use two-pointers here
    - i is pointing at word, and j is pointing at abbr
    - if j is not pointing at a digit char (0-9), then both
      i and j will move to the next char
    - if j is pointing at a digit char, extract all the digit
      chars after that position and convert them into a number
      - i will skip ahead for that number of chars
*/
bool Solution::isValid(string word, string abbr)
{
  int i = 0, j = 0, m = word.size(), n = abbr.size();
  auto isDigit = [](char c)
  {
    return c >= '0' && c <= '9';
  };

  while (i < m && j < n)
  {
    if (isDigit(abbr[j]))
    {
      /* a number can't start with a leading zero */
      if (abbr[j] == '0')
        return false;
      /*how many chars we need to skip on "word" */
      int skip = 0;
      /* produce the number */
      while (j < n && isDigit(abbr[j]))
      {
        /*compse the number
          - '1'-'0' = 1
        */
        skip = skip * 10 + (abbr[j++] - '0');
      }
      /* move i ahead of "skip" chars */
      i += skip;
    }
    /* both i and j needs to point to the same char
       if j is not pointing at a digit char
    */
    else if (word[i++] != abbr[j++])
      return false;
  }

  return i == m && j == n;
}