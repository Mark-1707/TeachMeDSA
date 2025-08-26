// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description

class Solution {
    fun areaOfMaxDiagonal(dimensions: Array<IntArray>): Int {
        var maxDia = 0.0
        var maxArea = 0

        for((l, w) in dimensions) {
            val di = sqrt((l * l + w * w).toDouble())
            val area = l * w

            when  {
                di > maxDia -> {
                    maxDia = di
                    maxArea = area
                }
                di == maxDia && area > maxArea -> {
                    maxArea = area
                }
            }
        }
        return maxArea
    }
}