// https://leetcode.com/problems/sort-matrix-by-diagonals/description

class Solution {
    fun sortMatrix(grid: Array<IntArray>): Array<IntArray> {
        val decreasing: MutableList<MutableList<Int>> = mutableListOf()
        val increasing: MutableList<MutableList<Int>> = mutableListOf()

        val s = grid.size

        for (i in 0 until s) {
            var r = i
            var c = 0
            val temp = mutableListOf<Int>()
            while (r < s && c < s) {
                temp.add(grid[r][c])
                r++
                c++
            }
            temp.sortDescending()
            decreasing.add(temp)
        }

        for (i in 1 until s) {
            var r = 0
            var c = i
            val temp = mutableListOf<Int>()
            while (r < s && c < s) {
                temp.add(grid[r][c])
                r++
                c++
            }
            temp.sort()
            increasing.add(temp)
        }

        val arr: Array<IntArray> = Array(s) { IntArray(s) }

        for (i in 0 until s) {
            var r = i
            var c = 0
            var idx = 0
            while (r < s && c < s) {
                arr[r][c] = decreasing[i][idx]
                r++
                c++
                idx++
            }
        }

        for (i in 1 until s) {
            var r = 0
            var c = i
            var idx = 0
            while (r < s && c < s) {
                arr[r][c] = increasing[i - 1][idx]
                r++
                c++
                idx++
            }
        }

        return arr
    }
}
