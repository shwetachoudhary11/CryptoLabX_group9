# Monoalphabetic Cipher Cryptanalysis Notes

## Objective

The objective is to recover the plaintext of a monoalphabetic substitution cipher using frequency analysis, word frequency analysis, repeated words, word patterns and iterative substitution.

## Initial Observation

The ciphertext was first analyzed using letter-frequency analysis.

The most frequent ciphertext letters were:



## Candidate Substitutions

Substitutions were proposed based on:

- Letter frequency
- One-letter words
- Two-letter words
- Three-letter words
- Repeated words
- Repeated letter patterns

## Iterative Recovery

At each step, a suspected ciphertext-to-plaintext substitution was tested.

The resulting partial plaintext was examined for meaningful English words and consistency with previously accepted substitutions.

Incorrect substitutions were rejected and alternative substitutions were tested.

## Recovered Key

Ciphertext alphabet:

ABCDEFGHIJKLMNOPQRSTUVWXYZ

Plaintext alphabet:


## Verification

The recovered plaintext was re-encrypted using the recovered substitution key.

The generated ciphertext was compared with the original ciphertext.

Verification result:SUCCESS

