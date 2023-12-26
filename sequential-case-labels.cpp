// Remember, execution begins at the first statement after a matching case
// label. Case labels aren’t statements (they’re labels), so they don’t count.

// The first statement after all of the case statements in the above program is
// return true, so if any case labels match, the function will return true.

// Thus, we can “stack” case labels to make all of those case labels share the
// same set of statements afterward. This is not considered fallthrough
// behavior, so use of comments or [[fallthrough]] is not needed here.
bool isVowel(char c) {
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    default:
        return false;
    }
}
