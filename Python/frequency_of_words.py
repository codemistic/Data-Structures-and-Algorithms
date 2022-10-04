from collections import Counter
line_text = "As a part of text analytics, we frequently need to count words and assign weightage to them for processing in various algorithms, so in this article we will see how we can find the frequency of each word in a given sentence. We can do it with three approaches as shown below."
freq = Counter(line_text.split()).most_common()
[print(word, count) for word, count in freq]