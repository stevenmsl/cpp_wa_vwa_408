#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol408;

/* Example 1:
Given s = "internationalization", abbr = "i12iz4n":
Return true.
*/
tuple<string, string, bool>
testFixture1()
{
  return make_tuple("internationalization", "i12iz4n", true);
}

/* Example 2:
Given s = "apple", abbr = "a2e":
Return false.
*/
tuple<string, string, bool>
testFixture2()
{
  return make_tuple("apple", "a2e", false);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << get<2>(f) << endl;
  auto result = Solution::isValid(get<0>(f), get<1>(f));
  cout << "result: " << result << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << get<2>(f) << endl;
  auto result = Solution::isValid(get<0>(f), get<1>(f));
  cout << "result: " << result << endl;
}

void testCharDigitToInt()
{
  auto one = '1' - '0';
  auto two = '2' - '0';
  cout << one << two << endl;
}

main()
{
  test1();
  test2();
  // testCharDigitToInt();
  return 0;
}