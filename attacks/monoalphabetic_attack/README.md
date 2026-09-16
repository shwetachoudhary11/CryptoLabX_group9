# Monoalphabetic Cipher Cryptanalysis

## Objective

This module performs cryptanalysis of a monoalphabetic substitution cipher.

## Cryptanalytic Techniques

The implementation uses:

- Letter-frequency analysis
- Frequency percentage calculation
- One-letter word analysis
- Two-letter word analysis
- Three-letter word analysis
- Repeated word analysis
- Repeated letter pattern analysis
- Candidate substitution
- Partial plaintext generation
- Iterative substitution
- Substitution key recovery
- Verification

## Required Functions

The program contains the following functions:

1. frequency_analysis()
2. word_frequency_analysis()
3. pattern_analysis()
4. apply_substitution()
5. display_partial_plaintext()
6. verify_solution()

## Input

The program reads ciphertext from:

datasets/monoalphabetic/ciphertext.txt

## Output

Analysis results are stored in:

outputs/monoalphabetic/

## Compilation

gcc monoalphabetic_cryptanalysis.c -o monoalphabetic_attack

## Execution

./monoalphabetic_attack

## Cryptanalysis Process

The ciphertext is first analyzed using letter and word frequencies.

Word patterns and repeated words are then examined to generate candidate substitutions.

Suspected substitutions are applied iteratively and the resulting partial plaintext is examined.

Incorrect hypotheses are rejected and useful substitutions are retained until meaningful plaintext is recovered.