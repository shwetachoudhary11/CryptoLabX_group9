# Monoalphabetic Cipher Cryptanalysis Decision Table

The following table records the observations, candidate substitutions, substitution tests, results and decisions made during the cryptanalysis.

| Step | Observation                                                                        | Possible Substitution          | Substitution Tested                   | Result                                                         | Decision            |
| ---- | ---------------------------------------------------------------------------------- | ------------------------------ | ------------------------------------- | -------------------------------------------------------------- | ------------------- |
| 1    | Most frequent ciphertext letter was identified from frequency analysis.            | `[X] → E`                      | `[X] → E`                             | Partial plaintext was examined for meaningful words.           | Accepted / Rejected |
| 2    | A one-letter ciphertext word was observed.                                         | `[X] → A/I`                    | `[X] → A` or `[X] → I`                | The resulting words were checked for consistency.              | Accepted / Rejected |
| 3    | A frequent two-letter ciphertext word was identified.                              | `[XY] → [possible word]`       | `[X] → [P]`, `[Y] → [Q]`              | Partial plaintext was compared with common English words.      | Accepted / Rejected |
| 4    | A repeated three-letter word was observed.                                         | `[XYZ] → THE/AND/etc.`         | `[X] → [P]`, `[Y] → [Q]`, `[Z] → [R]` | The substitution produced a more meaningful partial plaintext. | Accepted / Rejected |
| 5    | A repeated ciphertext word occurred several times.                                 | `[WORD] → [candidate]`         | `[mapping]`                           | The same substitution was consistent at all occurrences.       | Accepted / Rejected |
| 6    | A repeated-letter pattern was identified.                                          | `[PATTERN] → [candidate word]` | `[mapping]`                           | Pattern and substitution consistency were checked.             | Accepted / Rejected |
| 7    | A previously unknown ciphertext letter appeared in several meaningful words.       | `[X] → [P]`                    | `[X] → [P]`                           | Several partial words became recognizable.                     | Accepted / Rejected |
| 8    | A candidate substitution conflicted with an already accepted mapping.              | `[X] → [P]`                    | `[X] → [P]`                           | Existing plaintext mappings became inconsistent.               | Rejected            |
| 9    | Another candidate substitution was tested after rejecting the previous hypothesis. | `[X] → [P]`                    | `[X] → [P]`                           | The partial plaintext became more meaningful.                  | Accepted            |
| 10   | Remaining unknown letters were analyzed using word and pattern consistency.        | `[X] → [P]`                    | `[X] → [P]`                           | Additional plaintext words were recovered.                     | Accepted            |
| 11   | The resulting partial plaintext was compared with the expected English structure.  | `[X] → [P]`                    | `[X] → [P]`                           | The substitution remained consistent throughout the text.      | Accepted            |
| 12   | Final unknown substitutions were determined from the remaining word patterns.      | `[X] → [P]`                    | `[X] → [P]`                           | The plaintext became completely meaningful.                    | Accepted            |

---

## Detailed Cryptanalysis Record

### Step 1 — Frequency Analysis

**Observation:**
The ciphertext letters were counted and arranged according to their frequency.

**Possible substitution:**
The most frequent ciphertext letter was considered as a candidate for a frequently occurring plaintext letter such as `E`.

**Substitution tested:**
`[WRITE ACTUAL MAPPING]`

**Result:**
`[WRITE ACTUAL RESULT]`

**Decision:**
`Accepted / Rejected`

---

### Step 2 — One-Letter Word

**Observation:**
A one-letter ciphertext word was identified.

**Possible substitution:**
The word was considered as a possible `A` or `I`.

**Substitution tested:**
`[WRITE ACTUAL MAPPING]`

**Result:**
`[WRITE ACTUAL RESULT]`

**Decision:**
`Accepted / Rejected`

---

### Step 3 — Two-Letter Word

**Observation:**
A frequently occurring two-letter ciphertext word was found.

**Possible substitution:**
A common English two-letter word was considered.

**Substitution tested:**
`[WRITE ACTUAL MAPPING]`

**Result:**
`[WRITE ACTUAL RESULT]`

**Decision:**
`Accepted / Rejected`

---

### Step 4 — Three-Letter Word

**Observation:**
A repeated three-letter ciphertext word was identified.

**Possible substitution:**
A common English three-letter word was considered.

**Substitution tested:**
`[WRITE ACTUAL MAPPING]`

**Result:**
`[WRITE ACTUAL RESULT]`

**Decision:**
`Accepted / Rejected`

---

### Step 5 — Repeated Word

**Observation:**
A ciphertext word occurred multiple times in the text.

**Possible substitution:**
A repeated English word with the same structure was considered.

**Substitution tested:**
`[WRITE ACTUAL MAPPING]`

**Result:**
`[WRITE ACTUAL RESULT]`

**Decision:**
`Accepted / Rejected`

---

### Step 6 — Pattern Analysis

**Observation:**
A repeated-letter pattern was identified.

**Possible substitution:**
A plaintext word having the same pattern was considered.

**Substitution tested:**
`[WRITE ACTUAL MAPPING]`

**Result:**
`[WRITE ACTUAL RESULT]`

**Decision:**
`Accepted / Rejected`

---

### Step 7 — Partial Plaintext

**Observation:**
Several substitutions had already been accepted.

**Possible substitution:**
An unknown ciphertext letter was matched using the surrounding partial words.

**Substitution tested:**
`[WRITE ACTUAL MAPPING]`

**Result:**
The number of recognizable plaintext words increased.

**Decision:**
`Accepted / Rejected`

---

### Step 8 — Rejection of Incorrect Hypothesis

**Observation:**
A candidate substitution produced an inconsistent partial plaintext.

**Possible substitution:**
`[WRITE CANDIDATE]`

**Substitution tested:**
`[WRITE TEST]`

**Result:**
The resulting word structure was not consistent with the surrounding plaintext.

**Decision:**
**Rejected**

**Reason:**
The substitution conflicted with previously accepted mappings or produced an unlikely plaintext word structure.

---

### Step 9 — Alternative Hypothesis

**Observation:**
An alternative substitution was tested after rejecting the previous hypothesis.

**Possible substitution:**
`[WRITE CANDIDATE]`

**Substitution tested:**
`[WRITE TEST]`

**Result:**
The resulting partial plaintext was more meaningful and consistent.

**Decision:**
**Accepted**

---

### Step 10 — Final Recovery

**Observation:**
Most of the ciphertext had been mapped.

**Possible substitution:**
Remaining mappings were determined using the remaining word structures and consistency.

**Substitution tested:**
`[WRITE FINAL MAPPING]`

**Result:**
The complete plaintext became meaningful.

**Decision:**
**Accepted**

---

# Final Recovered Key

```text
Ciphertext : ABCDEFGHIJKLMNOPQRSTUVWXYZ
Plaintext  : [WRITE YOUR RECOVERED 26-LETTER KEY]
```

# Verification

The recovered plaintext was re-encrypted using the recovered key.

Original ciphertext:

`datasets/monoalphabetic/ciphertext.txt`

Generated ciphertext:

`[WRITE/REFERENCE GENERATED RESULT]`

Verification:

**[SUCCESS / FAILURE]**

A successful verification requires the generated ciphertext to match the original ciphertext exactly.
