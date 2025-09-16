// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/

class Solution {
    fun replaceNonCoprimes(nums: IntArray): List<Int> {

        fun gcd(a: Int, b: Int): Long {
            var x = a
            var y = b
            while (y != 0) {
                val temp = y
                y = x % y
                x = temp
            }
            return x.toLong()
        }

        fun lcm(a: Long, b: Long, gcd: Long): Long {
            return (a / gcd) * b
        }


        val stack = ArrayDeque<Long>()

        for (num in nums) {
            var cur = num.toLong()
            while (stack.isNotEmpty()) {
                val top = stack.last()
                val g = gcd(top.toInt(), cur.toInt())
                if (g > 1) {
                    stack.removeLast()
                    cur = lcm(top, cur, g).toLong()
                } else break
            }
            stack.addLast(cur)
        }

        return stack.map { it.toInt() }
    }
}