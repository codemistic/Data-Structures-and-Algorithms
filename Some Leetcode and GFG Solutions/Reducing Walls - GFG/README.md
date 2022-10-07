# Reducing Walls
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Ishaan is trapped in a city full of walls. To escape from there, it needs to climb N walls, one after the other. He can climb a wall if its height is atmost K.<br>
Ishaan also has a superpower. He can reduce the height of a wall H by K by using his superpower. Since he can't use this power many times, calculate the minimum number of times he has to use this power to go over all the walls.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[ ] = {5, 3, 2, 6, 8} and K = 5
<strong>Output :</strong> 2
<strong>Explanation:</strong>
Heights : 5 3 2 6 8 Ishaan can climb a 
wall with height atmost 5. So he climbs 
the first 3 walls easily. Now he has to 
use his power to reduce the height of the 
4th wall. After using his power, heights 
: 5 3 2&nbsp;<strong>1</strong>&nbsp;8, Now to climb the last wall, 
he again uses his power. Final heights 
: 5 3 2 1&nbsp;<strong>3</strong>
</span></pre>

<p><br>
<span style="font-size:18px"><strong>â€‹Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {2, 6, 4, 8, 1, 6} and K = 4 <strong>
Output :</strong>  3 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>ReducingWalls()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, an integer <strong>K</strong> and return the minimum number of times he has to use this power to go over all the walls The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints :</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ K ≤ 10<sup>5</sup><br>
1 ≤ Arr[i] ≤ 10<sup>9</sup></span></p>
 <p></p>
            </div>