
test_str = "GeeksForGeeks"
 
# Removing char at pos 3
new_str = ""
 
for i in range(len(test_str)):
    if i != 2:
        new_str = new_str + test_str[i]
 
# Printing string after removal
print ("The string after removal of i'th character : " + new_str)