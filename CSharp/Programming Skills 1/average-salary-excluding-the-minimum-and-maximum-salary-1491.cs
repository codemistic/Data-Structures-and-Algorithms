public class Solution {
    public double Average(int[] salary) {
        Array.Sort(salary);
        int sum = 0;
        for (int i = 1; i < salary.Length - 1; i++) 
            sum += salary[i];
        double avgSalary = Convert.ToDouble(sum.ToString("N3")) / (salary.Length - 2);
        return Math.Floor(avgSalary * 100000) / 100000;
    }
}