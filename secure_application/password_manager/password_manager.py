FILE_NAME = "passwords.txt"

ADMIN_USERNAME = "admin"
ADMIN_PASSWORD = "admin123"


def add_password():
    print("\n--- Add Password ---")

    website = input("Enter website name: ")
    username = input("Enter username: ")
    password = input("Enter password: ")

    with open(FILE_NAME, "a") as file:
        file.write(website + "|" + username + "|" + password + "\n")

    print("Password saved successfully.")




def view_passwords():
    print("\n--- Saved Passwords ---")

    try:
        with open(FILE_NAME, "r") as file:
            lines = file.readlines()

            if len(lines) == 0:
                print("No passwords saved.")
                return

            for line in lines:
                line = line.strip()

                if line == "":
                    continue

                data = line.split("|")

                website = data[0]
                username = data[1]
                password = data[2]

                print("------------------------------")
                print("Website :", website)
                print("Username:", username)
                print("Password:", password)
                print("------------------------------")
    
    except FileNotFoundError:
        print("No password file found.")




def search_password():
    print("\n--- Search Password ---")

    search_website = input("Enter website name: ")

    try:
        with open(FILE_NAME, "r") as file:

            found = False

            for line in file:
                line = line.strip()

                if line == "":
                    continue

                data = line.split("|")

                website = data[0]
                username = data[1]
                password = data[2]

                if website.lower() == search_website.lower():
                    print("\nPassword Found")
                    print("------------------------------")
                    print("Website :", website)
                    print("Username:", username)
                    print("Password:", password)
                    print("------------------------------")
                    found = True
                    break

            if not found:
                print("Website not found.")

    except FileNotFoundError:
        print("No password file found.")




def update_password():
    print("\n--- Update Password ---")

    website_to_update = input("Enter website name: ")
    new_password = input("Enter new password: ")

    try:
        with open(FILE_NAME, "r") as file:
            lines = file.readlines()

        updated = False

        with open(FILE_NAME, "w") as file:

            for line in lines:
                line = line.strip()

                if line == "":
                    continue

                data = line.split("|")

                website = data[0]
                username = data[1]
                password = data[2]




                if website.lower() == website_to_update.lower():
                    file.write(
                        website + "|" + username + "|" + new_password + "\n"
                    )
                    updated = True
                else:
                    file.write(
                        website + "|" + username + "|" + password + "\n"
                    )

        if updated:
            print("Password updated successfully.")
        else:
            print("Website not found.")

    except FileNotFoundError:
        print("No password file found.")




def delete_password():
    print("\n--- Delete Password ---")

    website_to_delete = input("Enter website name: ")

    try:
        with open(FILE_NAME, "r") as file:
            lines = file.readlines()

        deleted = False

        with open(FILE_NAME, "w") as file:

            for line in lines:
                line = line.strip()

                if line == "":
                    continue

                data = line.split("|")

                website = data[0]
                username = data[1]
                password = data[2]

                if website.lower() == website_to_delete.lower():
                    deleted = True
                    continue

                file.write(
                    website + "|" + username + "|" + password + "\n"
                )

        if deleted:
            print("Password deleted successfully.")
        else:
            print("Website not found.")

    except FileNotFoundError:
        print("No password file found.")


def main():
    while True:

        print("\n================================")
        print("        PASSWORD MANAGER")
        print("================================")

        print("1. Add Password")
        print("2. View Passwords")
        print("3. Search Password")
        print("4. Update Password")
        print("5. Delete Password")
        print("6. Exit")

        choice = input("\nEnter your choice: ")

        if choice == "1":
            add_password()

        elif choice == "2":
            view_passwords()

        elif choice == "3":
            search_password()

        elif choice == "4":
            update_password()

        elif choice == "5":
            delete_password()

        elif choice == "6":
            print("Exiting Password Manager...")
            break

        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()



