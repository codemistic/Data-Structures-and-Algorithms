from difflib import SequenceMatcher


def findSimilarity(f1, f2):
    with open(f1, errors="ignore") as file1, open(f2, errors="ignore") as file2:
        f1_content = file1.read()
        f2_content = file2.read()
        similarity = SequenceMatcher(None, f1_content, f2_content).ratio()
        print(f"The files are  {similarity*100}% similar")


if __name__ == '__main__':
    f1 = input("Enter path for first file:")
    f2 = input("Enter path for second file: ")
    findSimilarity(f1, f2)
