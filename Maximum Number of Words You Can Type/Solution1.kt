// https://leetcode.com/problems/maximum-number-of-words-you-can-type/

class Solution {
    fun canBeTypedWords(text: String, brokenLetters: String): Int {
        val brokenSet = brokenLetters.toSet()

        return text.split(' ').count {
            word -> word.none { it in brokenSet }
        }
    }
}