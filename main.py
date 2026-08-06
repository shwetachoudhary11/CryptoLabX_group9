

from collections import Counter

while True:
    print("\n========== CryptoLabX ==========")
    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Attack")
    print("4. Analyze")
    print("5. Exit")

    choice = input("Enter your choice (1-5): ")

    if choice == "1":
        print("\nEncrypt - Coming Soon!")

    elif choice == "2":
        print("\nDecrypt - Coming Soon!")

    elif choice == "3":
        print("\nAttack - Coming Soon!")

    elif choice == "4":
        filename = input("Enter the file name (example: sample1.txt): ")

        try:
            with open("datasets/" + filename, "r") as file:
                text = file.read()

            characters = len(text)
            words = len(text.split())
            lines = len(text.splitlines())
            unique_characters = len(set(text))

            print("\n----- File Analysis -----")
            print("Characters :", characters)
            print("Words      :", words)
            print("Lines      :", lines)
            print("Unique Characters :", unique_characters)

            letters = []

            for ch in text.lower():
                if ch.isalpha():
                    letters.append(ch)

            frequency = Counter(letters)

            print("\nLetter Frequency")
            for letter in sorted(frequency):
                print(letter, ":", frequency[letter])

        except FileNotFoundError:
            print("File not found!")

    elif choice == "5":
        print("Thank you for using CryptoLabX.")
        break

    else:
        print("Invalid choice!")