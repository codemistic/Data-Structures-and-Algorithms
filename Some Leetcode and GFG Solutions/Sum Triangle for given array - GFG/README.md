# Sum Triangle for given array
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a array, write a program to construct a triangle where last row contains elements of given array, every element of second last row contains sum of below two elements and so on.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
A[] = {4, 7, 3, 6, 7};
<strong>Output:</strong>
81 40 41 21 19 22 11 10 9 13 4 7 3 6 7
<strong>Explanation:</strong>
       81
     40  41
   21  19  22
 11  10   9   13
4   7   3   6    7 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
A[] = {5, 8, 1, 2, 4, 3, 14}
<strong>Output:</strong>
200 98 102 55 43 59 34 21 22 37 22
12 9 13 24 13 9 3 6 7 17 5 8 1 2 4 3 14 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>getTriangle()</strong>&nbsp;which takes the array <strong>A[]</strong> and its size <strong>N</strong><strong> </strong>as inputs and returns the sum triangle.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N<sup>2</sup>)<br>
<strong>Expected Auxiliary Space:</strong> O(N<sup>2</sup>)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=1000<br>
1&lt;=Ai&lt;=1000<br>
Elements in the triangle will not exceed 10<sup>18</sup></span></p>
 <p></p>
            </div>