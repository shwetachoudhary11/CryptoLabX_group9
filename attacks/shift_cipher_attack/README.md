# Shift Cipher Cryptanalysis

## 1. Purpose

This project implements cryptanalysis of a Shift Cipher using:

1. Brute-Force Attack
2. Dictionary Scoring
3. Chi-Square Analysis

The purpose is to recover the encryption key from ciphertext and compare the keys predicted by Dictionary Scoring and Chi-Square Analysis.

---

## 2. Shift Cipher

A Shift Cipher is a classical substitution cipher in which every alphabet is shifted by a fixed number of positions.

For example, with key `3`:

```text
Plaintext:  HELLO
Ciphertext: KHOOR
```

The encryption process shifts each letter forward by 3 positions.

Since there are only 26 possible keys (`0` to `25`), a Shift Cipher can be attacked by trying all possible keys.

---

## 3. Cryptanalysis Methods

### 3.1 Brute-Force Dictionary Scoring

The dictionary attack tries all possible keys from `0` to `25`.

For every key:

1. Decrypt the ciphertext.
2. Split the decrypted text into words.
3. Compare the words with an English dictionary.
4. Calculate the number of matching English words.
5. Select the key with the highest dictionary score.

```text
Highest Dictionary Score = Predicted Key
```

### 3.2 Chi-Square Analysis

Chi-Square analysis uses the frequency of English letters.

For every possible key:

1. Decrypt the ciphertext.
2. Count the frequency of each letter.
3. Compare the observed frequencies with standard English frequencies.
4. Calculate the Chi-Square value.
5. Select the key with the lowest Chi-Square value.

```text
Lowest Chi-Square Value = Predicted Key
```

---

## 4. Project Structure

```text
shift_cipher_attack/
│
├── src/
│   ├── shift_cipher.py
│   ├── brute_force_dictionary.py
│   ├── chi_square_attack.py
│   └── main.py
│
├── dictionary/
│   └── english_words.txt
│
├── testcases/
│
├── outputs/
│
├── screenshots/
│
├── reports/
│   └── Assignment_4_Report.pdf
│
└── README.md
```

---

## 5. File Description

### `shift_cipher.py`

Contains the Shift Cipher encryption and decryption functions.

### `brute_force_dictionary.py`

Contains:

* Dictionary loading
* Dictionary scoring
* Brute-force key testing

### `chi_square_attack.py`

Contains:

* English letter-frequency data
* Chi-Square calculation
* Chi-Square cryptanalysis

### `main.py`

Controls the complete experiment.

It:

1. Reads plaintext and actual key.
2. Generates ciphertext.
3. Runs Dictionary Scoring.
4. Runs Chi-Square Analysis.
5. Compares the predicted keys with the actual key.

### `english_words.txt`

Contains English words used for dictionary scoring.

### `testcases/`

Contains test cases used to evaluate the attacks.

### `screenshots/`

Contains screenshots of experimental results.

### `reports/`

Contains the final assignment report.

---

## 6. How to Run

Open a terminal and go to the `src` directory:

```bash
cd attacks/shift_cipher_attack/src
```

Run the main program:

```bash
python3 main.py
```

The program asks for:

```text
Enter plaintext:
Enter key:
```

For example:

```text
Enter plaintext: this is a secret message
Enter key: 3
```

The program then generates the ciphertext and performs both cryptanalysis attacks.

---

## 7. Example Workflow

```text
Plaintext
    |
    | Shift Cipher + Actual Key
    ↓
Ciphertext
    |
    +----------------------+
    |                      |
    ↓                      ↓
Dictionary Attack    Chi-Square Attack
    |                      |
Try keys 0-25         Try keys 0-25
    |                      |
English word score    Letter frequency
    |                      |
Highest score         Lowest Chi-Square
    |                      |
Predicted Key         Predicted Key
    +----------+-----------+
               |
               ↓
       Compare with Actual Key
```

---

## 8. Result Comparison

The experimental results are recorded using the following format:

| Test Case | Actual Key | Dictionary Key | Chi-Square Key | Dictionary Correct? | Chi-Square Correct? |
| --------- | ---------: | -------------: | -------------: | ------------------- | ------------------- |
| Test 1    |          - |              - |              - | -                   | -                   |
| Test 2    |          - |              - |              - | -                   | -                   |
| Test 3    |          - |              - |              - | -                   | -                   |
| Test 4    |          - |              - |              - | -                   | -                   |
| Test 5    |          - |              - |              - | -                   | -                   |

The table should be filled using the actual results obtained during experimentation.

---

## 9. Failure Analysis

Dictionary Scoring may fail when the ciphertext is short or contains uncommon words that are not present in the dictionary. Its accuracy can be improved by using a larger English dictionary or an n-gram language model.

Chi-Square Analysis may fail when the ciphertext is very short because the observed letter frequencies may not accurately represent normal English frequencies. Its performance can be improved by using longer ciphertexts or combining frequency analysis with dictionary or n-gram scoring.

---

## 10. Observations

The following observations are made during the experiment:

* A Shift Cipher has only 26 possible keys.
* Brute-force testing can therefore examine every possible key.
* Dictionary Scoring works by identifying recognizable English words.
* Chi-Square Analysis works by comparing letter-frequency distributions.
* Dictionary Scoring selects the key with the highest score.
* Chi-Square Analysis selects the key with the lowest score.
* The performance of both attacks depends on the length and nature of the plaintext.
* Short ciphertexts can make statistical cryptanalysis less reliable.

---

## 11. Git Commit History

The project is maintained using meaningful Git commits.

### Commit 1

```text
Implemented Shift Cipher
```

### Commit 2

```text
Added brute-force and dictionary scoring
```

### Commit 3

```text
Added Chi-Square cryptanalysis
```

Additional commits may be used for:

* Testing
* Bug fixes
* Screenshots
* Documentation
* Report updates

---

## 12. Conclusion

This experiment demonstrates the cryptanalysis of a Shift Cipher using Brute-Force Dictionary Scoring and Chi-Square Analysis. Since a Shift Cipher has only 26 possible keys, all possible keys can be tested. Dictionary Scoring uses English words to identify the most likely plaintext, while Chi-Square Analysis uses English letter-frequency statistics. Comparing both predicted keys with the actual key helps evaluate the effectiveness and limitations of the two cryptanalysis techniques.
