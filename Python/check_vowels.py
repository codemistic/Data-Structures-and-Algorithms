t=input()
vowels = ['a','e','i','o','u','A','E','I','O','U']
vowels_in_string = []
for i in t:
    if i in vowels:
        vowels_in_string.append(i)
vowels_in_string = list(set(vowels_in_string))
vowels_in_string.sort()
vowels_in_string = [i.lower() for i in vowels_in_string]
if len(vowels_in_string) == 0:
    print('none')
else:
    print(''.join(vowels_in_string))
