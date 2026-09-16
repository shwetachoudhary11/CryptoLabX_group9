# Monoalphabetic Substitution Cipher and Cryptanalysis

## 1. Monoalphabetic Encryption Algorithm

1. Read the plaintext.
2. Define a 26-letter substitution key.
3. Read each character of the plaintext.
4. If the character is alphabetic, substitute it using the key.
5. Preserve spaces, numbers and punctuation.
6. Generate the ciphertext.
7. Store the generated ciphertext.

## 2. Frequency Analysis Algorithm

1. Read the ciphertext.
2. Count the occurrence of every alphabetic character.
3. Calculate the total number of alphabetic characters.
4. Calculate the percentage frequency of each character.
5. Sort the ciphertext letters according to frequency.
6. Display the letters in descending frequency order.
7. Identify the most frequent ciphertext letters.

## 3. Word Frequency Analysis Algorithm

1. Read the ciphertext.
2. Extract individual words.
3. Count one-letter words.
4. Count two-letter words.
5. Count three-letter words.
6. Count repeated words.
7. Display the word frequencies.

## 4. Pattern Analysis Algorithm

1. Extract words from the ciphertext.
2. Assign a pattern number to each new character in a word.
3. Generate the repeated-letter pattern of each word.
4. Display each word with its pattern.
5. Compare words having similar patterns.
6. Use repeated patterns to propose possible plaintext words.

## 5. Iterative Cryptanalysis Algorithm

1. Perform letter-frequency analysis.
2. Identify frequently occurring ciphertext letters.
3. Generate possible plaintext substitutions.
4. Examine one-letter, two-letter and three-letter words.
5. Examine repeated words.
6. Examine repeated letter patterns.
7. Select a candidate substitution.
8. Apply the substitution to the ciphertext.
9. Display the resulting partial plaintext.
10. Examine the partial plaintext.
11. Accept the substitution if it produces a consistent meaningful result.
12. Reject the substitution if it produces an inconsistent result.
13. Test another candidate substitution.
14. Repeat the process until meaningful plaintext is recovered.

## 6. Key Recovery Algorithm

1. Record all accepted ciphertext-to-plaintext substitutions.
2. Construct the complete substitution mapping.
3. Check that a plaintext letter is not assigned to multiple ciphertext letters.
4. Store the recovered substitution key.

## 7. Verification Algorithm

1. Take the recovered plaintext.
2. Construct the reverse encryption key from the recovered substitution key.
3. Encrypt the recovered plaintext.
4. Generate the new ciphertext.
5. Compare the generated ciphertext with the original ciphertext.
6. If both ciphertexts are identical, the recovered solution is verified.
7. Otherwise, re-examine the substitutions.