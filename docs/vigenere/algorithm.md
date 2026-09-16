# Vigenère Cipher Cryptanalysis Algorithm

## 1. Preprocessing

1. Read the given ciphertext.
2. Remove spaces, numbers and special characters.
3. Convert all alphabetic characters to uppercase.
4. Store the cleaned ciphertext.

## 2. Kasiski Examination

1. Search the ciphertext for repeated sequences of length 3 to 5.
2. Record the positions of repeated sequences.
3. Calculate the distance between repeated occurrences.
4. Find the factors of these distances.
5. Count common factors.
6. Use the common factors to suggest possible key lengths.

## 3. Index of Coincidence

1. Count the frequency of each alphabetic character.
2. Calculate the Index of Coincidence.
3. Use IC as additional evidence for estimating the key length.

## 4. Divide Ciphertext

1. Select a candidate key length.
2. Divide the ciphertext into groups according to character position.
3. Characters at positions having the same key position are placed in the same group.

## 5. Frequency Analysis

1. Calculate the frequency of A-Z in every group.
2. Compare the frequency distribution with normal English letter frequencies.
3. Treat each group as a Caesar cipher.
4. Determine the most probable Caesar shift.

## 6. Recover Key

1. Find the probable Caesar shift for every group.
2. Convert each shift into its corresponding alphabetic key character.
3. Combine the characters in their original order.
4. Obtain the probable Vigenère key.

## 7. Decryption

1. Read the ciphertext and recovered key.
2. Repeat the key over the complete ciphertext.
3. Subtract the key value from each ciphertext character.
4. Convert the resulting values back to letters.
5. Obtain the recovered plaintext.

## 8. Verification

1. Take the recovered plaintext.
2. Encrypt it again using the recovered Vigenère key.
3. Compare the generated ciphertext with the original cleaned ciphertext.
4. If both are identical, the recovered key and plaintext are verified.
5. Otherwise, revise the key-length or shift hypotheses.
