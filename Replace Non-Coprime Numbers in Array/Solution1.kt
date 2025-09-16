// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/

class Solution {
    fun replaceNonCoprimes(nums: IntArray): List<Int> {

        fun isNonCoprime(a: Int, b: Int): Int {
            var x = a
            var y = b
            while (y != 0) {
                val temp = y
                y = x % y
                x = temp
            }
            return x
        }

        fun lcm(a: Long, b: Long, gcd: Long): Long {
            return (a / gcd) * b
        }


        var i = 0
        val list = nums.toMutableList()

        while(i < list.size - 1) {
            val gcd = isNonCoprime(list[i], list[i + 1])
            if(gcd > 1) {
                val lcm = lcm(list[i].toLong(), list[i + 1].toLong(), gcd.toLong()).toInt()
                list.removeAt(i)
                list.removeAt(i)
                list.add(i, lcm)
                if(i > 0) i--
            } else {
                i++
            }
        }
        return list.toList()
    }
}