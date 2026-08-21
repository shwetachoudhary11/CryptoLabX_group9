from shift_cipher import encrypt

from brute_force_dictionary import load_dictionary, dictionary_attack

from chi_square_attack import chi_square_attack


print("===== SHIFT CIPHER CRYPTANALYSIS =====")

plaintext = input("Enter plaintext: ")

actual_key = int(input("Enter key: "))

ciphertext = encrypt(plaintext, actual_key)

print("\nCiphertext:", ciphertext)


dictionary = load_dictionary()


print("\n===== DICTIONARY ATTACK =====")

dictionary_key, dictionary_score, dictionary_text = dictionary_attack(
    ciphertext, dictionary
)

print("\nDictionary predicted key:", dictionary_key)

print("Dictionary plaintext:", dictionary_text)


print("\n===== CHI-SQUARE ATTACK =====")

chi_key, chi_score, chi_text = chi_square_attack(ciphertext)

print("\nChi-Square predicted key:", chi_key)

print("Chi-Square plaintext:", chi_text)


print("\n===== FINAL RESULT =====")

print("Actual key:", actual_key)

print("Dictionary key:", dictionary_key)

print("Chi-Square key:", chi_key)


if dictionary_key == actual_key:
    print("Dictionary: CORRECT")
else:
    print("Dictionary: WRONG")


if chi_key == actual_key:
    print("Chi-Square: CORRECT")
else:
    print("Chi-Square: WRONG")