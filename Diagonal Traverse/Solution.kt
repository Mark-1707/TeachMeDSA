// https://leetcode.com/problems/diagonal-traverse/

class Solution {
    fun findDiagonalOrder(mat: Array<IntArray>): IntArray {
        var d = true
        // true -> up
        // false -> down

        val rows = mat.size
        val cols = mat[0].size

        var m = 0
        var n = 0

        val ans = mutableListOf<Int>()

        while (ans.size < rows * cols) {   // stop once all elements are visited
            ans.add(mat[m][n])
            
            if (d) {
                if (n == cols - 1) {        // right edge
                    m++
                    d = false
                } else if (m == 0) {        // top edge
                    n++
                    d = false
                } else {                    // move up-right
                    m--
                    n++
                }
            } else {
                if (m == rows - 1) {        // bottom edge
                    n++
                    d = true
                } else if (n == 0) {        // left edge
                    m++
                    d = true
                } else {                    // move down-left
                    m++
                    n--
                }
            }
        }

        return ans.toIntArray()
    }
}
