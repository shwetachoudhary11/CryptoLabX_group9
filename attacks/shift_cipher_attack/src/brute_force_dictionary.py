from shift_cipher import decrypt


def load_dictionary():
    words = set()

    with open("../dictionary/english_words.txt", "r") as file:
        for line in file:
            words.add(line.strip().lower())

    return words


def dictionary_attack(ciphertext, dictionary):
    best_key = 0
    best_score = -1
    best_text = ""

    for key in range(26):

        plaintext = decrypt(ciphertext, key)

        words = plaintext.lower().split()

        score = 0

        for word in words:
            word = word.strip(".,!?")

            if word in dictionary:
                score += 1

        print("Key:", key,
              "Score:", score,
              "Text:", plaintext)

        if score > best_score:
            best_score = score
            best_key = key
            best_text = plaintext

    return best_key, best_score, best_text