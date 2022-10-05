<h2><a href="https://leetcode.com/problems/range-sum-query-2d-immutable/">304. Range Sum Query 2D - Immutable</a></h2><h3>Medium</h3><hr><div><p>Given a 2D matrix <code>matrix</code>, handle multiple queries of the following type:</p>

<ul>
	<li>Calculate the <strong>sum</strong> of the elements of <code>matrix</code> inside the rectangle defined by its <strong>upper left corner</strong> <code>(row1, col1)</code> and <strong>lower right corner</strong> <code>(row2, col2)</code>.</li>
</ul>

<p>Implement the NumMatrix class:</p>

<ul>
	<li><code>NumMatrix(int[][] matrix)</code> Initializes the object with the integer matrix <code>matrix</code>.</li>
	<li><code>int sumRegion(int row1, int col1, int row2, int col2)</code> Returns the <strong>sum</strong> of the elements of <code>matrix</code> inside the rectangle defined by its <strong>upper left corner</strong> <code>(row1, col1)</code> and <strong>lower right corner</strong> <code>(row2, col2)</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/sum-grid.jpg" style="width: 415px; height: 415px;">
<pre><strong>Input</strong>
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
<strong>Output</strong>
[null, 8, 11, 12]

<strong>Explanation</strong>
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-10<sup>5</sup> &lt;= matrix[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= row1 &lt;= row2 &lt; m</code></li>
	<li><code>0 &lt;= col1 &lt;= col2 &lt; n</code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>sumRegion</code>.</li>
</ul>
</div>