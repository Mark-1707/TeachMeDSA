// https://leetcode.com/problems/vowel-spellchecker/description/

class Solution {
    fun spellchecker(wordlist: Array<String>, queries: Array<String>): Array<String> {
        val vowelSet = setOf('a', 'e', 'i', 'o', 'u')

        val wordSet = wordlist.toSet()

        val caseInsensitive = mutableMapOf<String, String>()

        val vowelInsensitive = mutableMapOf<String, String>()

        fun normalizeWord(word: String): String {
            return word.lowercase().map { if(it in vowelSet) '*' else it }.joinToString("")
        }

        for(word in wordlist) {
            val lowercase = word.lowercase()
            caseInsensitive.putIfAbsent(lowercase, word)
            vowelInsensitive.putIfAbsent(normalizeWord(word), word)
        }

        val ans = ArrayList<String>()

        for(q in queries) {
            when {
                q in wordSet -> ans.add(q)
                caseInsensitive.containsKey(q.lowercase()) -> ans.add(caseInsensitive[q.lowercase()]!!)
                vowelInsensitive.containsKey(normalizeWord(q)) -> ans.add(vowelInsensitive[normalizeWord(q)]!!)
                else -> ans.add("")
            }
        }
        return ans.toTypedArray()
    }
}

/*

1) find exact match
use set

2) find case insensitive equal word
use map 
key = lowercased
value = original word

3) find vowel insensitive equal word
use map 
key = vowel insensitive
value = original word

4) put ""

 */