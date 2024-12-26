def rabin_karp(text, pattern, base=256, prime=101):
    """
    Rabin-Karp Algorithm for substring search.
    
    Parameters:
    text (str): The main text where the pattern is to be searched.
    pattern (str): The pattern to search for.
    base (int): The base used for hashing (default: 256).
    prime (int): A prime number used to reduce hash values (default: 101).
    
    Returns:
    list: Starting indices of all occurrences of the pattern in the text.
    """
    n, m = len(text), len(pattern)
    if m > n:
        return []

    pattern_hash = 0  # Hash value for pattern
    text_hash = 0     # Hash value for current window in text
    h = 1             # The value of base^(m-1)

    # Compute h = (base^(m-1)) % prime
    for _ in range(m - 1):
        h = (h * base) % prime

    # Compute initial hash values for pattern and first window of text
    for i in range(m):
        pattern_hash = (base * pattern_hash + ord(pattern[i])) % prime
        text_hash = (base * text_hash + ord(text[i])) % prime

    # List to store starting indices of pattern matches
    result = []

    # Slide the pattern over text one character at a time
    for i in range(n - m + 1):
        # Check if the hash values match
        if pattern_hash == text_hash:
            # If hash matches, check characters one by one for a real match
            if text[i:i + m] == pattern:
                result.append(i)

        # Compute hash for next window of text
        if i < n - m:
            text_hash = (base * (text_hash - ord(text[i]) * h) + ord(text[i + m])) % prime

            # Make sure text_hash is positive
            if text_hash < 0:
                text_hash += prime

    return result


# Example Usage
if __name__== "__main__":
    text = "abracadabra"
    pattern = "abra"
    matches = rabin_karp(text, pattern)
    print(f"Pattern '{pattern}' found at indices: {matches}")