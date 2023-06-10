#include <bits/stdc++.h>
using namespace std;
/*
<aside>
💡 **Question 1**

Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.

An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.

</aside>
*/
 bool isPowerOfThree(int n) {
        if(n>0)
        {
            if(n%3==0)
                return isPowerOfThree(n/3);
            //else return false;
            if(n==1)
                return true;
        }
        return false;
}






/*
<aside>
💡 **Question 2**

You have a list `arr` of all integers in the range `[1, n]` sorted in a strictly increasing order. Apply the following algorithm on `arr`:

- Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
- Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
- Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
</aside>
*/

 int lastRemaining(int n) {
        if(n==1){
            return n;
        }
        return 2 * (1 + n/2 - lastRemaining(n/2));
}





/*
<aside>
💡 **Question 3**

****Given a set represented as a string, write a recursive code to print all subsets of it. The subsets can be printed in any order.

**Example 1:**

Input :  set = “abc”

Output : { “”, “a”, “b”, “c”, “ab”, “ac”, “bc”, “abc”}

**Example 2:**

Input : set = “abcd”

Output : { “”, “a” ,”ab” ,”abc” ,”abcd”, “abd” ,”ac” ,”acd”, “ad” ,”b”, “bc” ,”bcd” ,”bd” ,”c” ,”cd” ,”d” }

</aside>
*/
void powerSet(string str, int index = 0, string curr = "")
{
	int n = str.length();

	if (index == n) {
		cout << curr << endl;
		return;
	}
	powerSet(str, index + 1, curr + str[index]);
	powerSet(str, index + 1, curr);
}





/*
<aside>
💡 **Question 4**

Given a string calculate length of the string using recursion.

**Examples:**

</aside>
*/
 int sizeofString(char* str){
    if(*str=='\0'){
        return 0;
    }
    return 1+sizeofString(str+1);
 }






 /*
 <aside>
**Question 5**

We are given a string S, we need to find count of all contiguous substrings starting and ending with same character.

**Examples :**
Input  : S = "abcab"
Output : 7
There are 15 substrings of "abcab"
a, ab, abc, abca, abcab, b, bc, bca
bcab, c, ca, cab, a, ab, b
Out of the above substrings, there
are 7 substrings : a, abca, b, bcab,
c, a and b.

Input  : S = "aba"
Output : 4
The substrings are a, b, a and aba

</aside>
 */

int countSubstringWithEqualEnds(string s)
{
    int result = 0;
    int n = s.length();
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
            if (s[i] == s[j])
                result++;
 
    return result;
}


/*

Question 6 The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.

*/

void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}



/*
<aside>
💡 **Question 7**

Given a string **str**, the task is to print all the permutations of **str**. A **permutation** is an arrangement of all or part of a set of objects, with regard to the order of the arrangement. For instance, the words ‘bat’ and ‘tab’ represents two distinct permutation (or arrangements) of a similar three letter word.

**Examples:**

> Input: str = “cd”
> 
> 
> **Output:** cd dc
> 
> **Input:** str = “abb”
> 
> **Output:** abb abb bab bba bab bba
> 
</aside>
*/

void printPermutations(string input,string output=""){

    if(input=="")
    {
        cout<<output<<endl;
        return;
    }
    for(int i=0;i<input.size();i++)
    {
        printPermutations(input.substr(1),output+input[0]);
        rotate(input.begin(),input.begin()+1,input.end());
    }
}

/*
<aside>
💡 **Question 8**

Given a string, count total number of consonants in it. A consonant is an English alphabet character that is not vowel (a, e, i, o and u). Examples of constants are b, c, d, f, and g.

</aside>
*/

bool isConsonant(char ch)
{
    ch = toupper(ch);
  
    return !(ch == 'A' || ch == 'E' || 
            ch == 'I' || ch == 'O' || 
            ch == 'U') && ch >= 65 && ch <= 90;
}

int totalConsonants(string str, int n)
{
    if (n == 1)
        return isConsonant(str[0]);
  
    return totalConsonants(str, n - 1) + 
           isConsonant(str[n-1]);
}
