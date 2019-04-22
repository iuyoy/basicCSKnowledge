/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Note:

name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.
*/

// Two pointers O(M)
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.back()!=name.back() ) return false;
        
        int i = 0, j = 0;
        while(j<typed.size()){
            if(i<name.size() && typed[j] == name[i])
                ++i; 
            else if(i == 0 || typed[j] != name[i-1])
                return false;
            ++j;
        }
        return true;
    }
};

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while(j<typed.size()){
            if(i<name.size() && typed[j] == name[i])
                ++i; 
            else if(i == 0 || typed[j] != name[i-1])
                return false;
            ++j;
        }
        return i == name.size();
    }
};
