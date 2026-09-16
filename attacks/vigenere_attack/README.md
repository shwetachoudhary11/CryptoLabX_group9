# Vigenère Cipher Cryptanalysis

## Objective

This module performs cryptanalysis of a Vigenère cipher using Kasiski examination, Index of Coincidence and frequency analysis.

## Input

The ciphertext is stored in:

`datasets/vigenere/ciphertext.txt`

The cleaned ciphertext contains **395 characters**.

## Techniques Used

* Ciphertext preprocessing
* Repeated pattern detection
* Distance calculation
* Factor calculation
* Kasiski examination
* Index of Coincidence
* Ciphertext grouping
* Frequency analysis
* Caesar shift estimation
* Key recovery
* Vigenère decryption
* Vigenère encryption
* Verification

## Required Functions

The program contains the following user-defined functions:

* `clean_ciphertext()`
* `find_repeated_patterns()`
* `calculate_distances()`
* `find_factors()`
* `kasiski_analysis()`
* `calculate_ic()`
* `split_into_groups()`
* `frequency_analysis()`
* `find_shift()`
* `find_key()`
* `vigenere_decrypt()`
* `vigenere_encrypt()`
* `verify()`

## Cryptanalysis Result

Kasiski examination identified repeated-pattern distances having several common factors.

Factor **14** occurred repeatedly and was selected as the estimated key length.

The ciphertext was divided into 14 groups and frequency analysis was performed on each group.

### Recovered Key

```text
AMBROISETHOMAS
```

### Key Length

```text
14
```

### Verification

The recovered plaintext was re-encrypted using the recovered key.

The generated ciphertext matched the original cleaned ciphertext.

**Verification: SUCCESS**

## Compilation

```bash
gcc attacks/vigenere_attack/vigenere_cryptanalysis.c -o vigenere_attack
```

## Execution

```bash
./vigenere_attack
```

## Dataset

```text
datasets/vigenere/ciphertext.txt
```

## Output

```text
outputs/vigenere/
```
