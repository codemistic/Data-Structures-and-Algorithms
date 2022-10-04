public static List < Interval > mergeIntervals(Interval[] intervals) {
  int n = intervals.length;
  List < Interval > res = new ArrayList();
 
  boolean vis[] = new boolean[n];
 
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
 
    vis[i] = true;
    int minS = intervals[i].start;
    int maxE = intervals[i].finish;
 
    while (true) {
      int c = 0;
 
      for (int j = 0; j < n; j++) {
        if (!vis[j] && isOverlap(minS, maxE, intervals[j])) {
          vis[j] = true;
          minS = Math.min(minS, intervals[j].start);
          maxE = Math.max(maxE, intervals[j].finish);
          c++;
        }
      }
 
      if (c == 0) {
        break;
      }
    }
res.add(new Interval(minS, maxE));
  }
 
  Collections.sort(res, new Comparator < Interval > () {
 
    public int compare(Interval a, Interval b) {
      if (a.start == b.start) {
        return a.finish - b.finish;
      }
 
      return a.start - b.start;
    }
 
  });
 
  return res;
}
 
public static boolean isOverlap(int minS, int maxE, Interval i) {
  if (minS > i.finish || maxE < i.start) {
    return false;
  }
 
  return true;
}
