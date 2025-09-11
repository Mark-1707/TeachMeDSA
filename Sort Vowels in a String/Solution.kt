// https://leetcode.com/problems/sort-vowels-in-a-string/description/

class Solution {
    fun sortVowels(s: String): String {
        val list = mutableListOf<Char>()
        val vowels = listOf('A', 'E', 'I', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u')
        for(i in s) {
            if(i in vowels) {
                list.add(i)
            }
        }

        list.sort()

        val t = StringBuilder()
        var i = 0
        for(ch in s) {
            if(ch in vowels) {
                t.append(list[i])
                i++
            } else {
                t.append(ch)
            }
        }
        return t.toString()
    }
}