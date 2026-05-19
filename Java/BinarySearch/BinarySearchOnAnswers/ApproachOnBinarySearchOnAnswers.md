<h1>🌸 Minimum Number of Days to Make Bouquets</h1>

<h2> Problem Statement</h2>
<p align="center">
<img width="684" height="356" alt="Untitled Diagram drawio"  src="Java\BinarySearch\BinarySearchOnAnswers\photo_Animation_of_approach\image2.png" />
</p>

<p>You are given an integer array <b>bloomDay[]</b> where:</p>

<ul>
    <li><code>bloomDay[i]</code> represents the day the <i>i-th</i> flower blooms</li>
    <li>You must create <b>M bouquets</b></li>
    <li>Each bouquet requires <b>K consecutive flowers</b></li>
</ul>


<h3>Tasks</h3>
<ol>
    <li>Return the <b>minimum number of days</b> required to make <b>M</b> bouquets</li>
    <li>If it is <b>not possible</b>, return <code>-1</code></li>
</ol>

<hr>

<h2> Key Observations</h2>

<h3>1️) Feasibility Check (Fail Fast)</h3>

<p>To make <b>M</b> bouquets of <b>K</b> flowers each:</p>

<pre>
Total flowers required = M × K
</pre>

<p>If:</p>

<pre>
M × K &gt; bloomDay.length
</pre>

<p>It is <b>impossible</b> to form the bouquets, so return <code>-1</code>.</p>

<hr>
<p align="center">
<img width="806" height="531" alt="Untitled Diagram drawio (3)" src="Java\BinarySearch\BinarySearchOnAnswers\photo_Animation_of_approach\image1.png" />
</p>

<h3>2️) Why Binary Search Works</h3>

<p>This problem is <b>not</b> about searching indices.</p>
<p>It is about searchin<p>Define a function:</p>

<pre>
CanMakeBouquet(day)
</pre>

<ul>
    <li>If bouquets can be made on day <b>D</b></li>
    <li>They can also be made on any day <b>greater than D</b></li>
</ul>

<p>This creates a <b>monotonic pattern</b>:</p>

<pre>
F F F F F T T T T
</pre>

<p>Perfect use case for <b>Binary Search on Answer</b>.</p>

<hr>

<h2> Approach</h2>

<ul>
    <li>Search space: minimum bloom day → maximum bloom day</li>
    <li>Apply binary search on days</li>
    <li>Check if <b>M</b> bouquets can be formed using <b>K consecutive flowers</b></li>
    <li>Minimize the day</li>
</ul>

<hr>


<h2> Java Implementation</h2>

<pre>

<code>
class Solution {
    public int minDays(int[] bloomDay, int m, int k) {

        if ((long) m * k > bloomDay.length) return -1;

        int low = Integer.MAX_VALUE, high = Integer.MIN_VALUE;
        for (int day : bloomDay) {
            low = Math.min(low, day);
            high = Math.max(high, day);
        }

        int ans = -1;
        while (low &lt;= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquet(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    private boolean canMakeBouquet(int[] bloomDay, int m, int k, int days) {
        int count = 0;

        for (int day : bloomDay) {
            if (day &lt;= days) {
                count++;
                if (count == k) {
                    m--;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return m &lt;= 0;
    }
}
</code>

</pre>

<hr>

<h2>⏱ Complexity Analysis</h2>

<ul>
    <li><b>Time Complexity:</b> O(n log(maxDay))</li>
    <li><b>Space Complexity:</b> O(1)</li>
</ul>

<hr>

<p>
Binary Search is <b>not only for sorted arrays</b>.<br>
It can be applied whenever the answer space is <b>monotonic</b>.
</p>



<hr>


</body>
</html>
