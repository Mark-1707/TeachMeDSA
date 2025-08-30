// https://leetcode.com/problems/valid-sudoku/description

class Solution {
    fun isValidSudoku(board: Array<CharArray>): Boolean {
        val rows = Array(9) { HashSet<Char>() }
        val cols = Array(9) { HashSet<Char>() }
        val squares = Array(9) { HashSet<Char>() }

        for(r in 0..8) {
            for(c in 0..8) {
                val value = board[r][c]

                if(value == '.') continue

                val squaresIdx = (r / 3) * 3 + (c / 3)
                if(
                    value in rows[r] ||
                    value in cols[c] ||
                    value in squares[squaresIdx]
                ) return false

                rows[r].add(value)
                cols[c].add(value)
                squares[squaresIdx].add(value)
            }
        }
        return true
    }
}