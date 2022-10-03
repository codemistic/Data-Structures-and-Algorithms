def solution():
    result =[]
    scores_list = []
    for _ in range(int(input("Number of students?? "))):
            name = str(input("Students' name? ").strip())
            score = float(input("{}'s Marks ".format(name)))
            result+=[[name,score]]
            scores_list+=[score]

    b = sorted(list(set(scores_list)))[1] 

    for a,c in sorted(result):
        if c==b:
            print(a)

if __name__ == '__main__':
    solution()