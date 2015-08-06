/*
 Definition: 1 is a Pure number; X is a Pure number if the sum of the squares of the digits of X is a Pure number.

 Example:
   13 => 1^2 + 3^2 = 1 + 9 = 10;
   10 => 1^2 + 0^2 = 1 + 0 = 1
   Therefore, both 13 and 10 are Pure.

 Note that if you reach a single digit number that's NOT 1, you keep going: 7 => 7^2 = 49, etc.
*/

// Returns true iff x is a Pure number. x is guaranteed to be a positive integer.

bool is_pure(unsigned int x) { // x == 13
  int digit, sum;
  map<int, bool> hash;
  hash[x] = true;

  while (true) {
    sum = 0;
    while (x > 0) {
      digit = x % 10;
      sum += digit * digit;
      x /= 10;
    }
    if (sum == 1)
      return true;
    if (hash.count(sum) > 1)
      return false;
    hash[sum] = true;
    x = sum;
  }
}
