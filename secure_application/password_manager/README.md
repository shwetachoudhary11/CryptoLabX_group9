# Password Manager

## 1. Introduction

The Password Manager is a simple command-line application developed as part of the Cryptography Laboratory semester project.

The purpose of this application is to allow a user to store and manage website login credentials such as website name, username, and password.

The application currently uses a text file named `passwords.txt` to store the saved credentials. The project is intentionally implemented as a basic application so that security vulnerabilities can be studied, analyzed using SAST tools, and fixed in later stages of the laboratory.

---

## 2. Objectives

The main objectives of this application are:

* To develop a basic password management application.
* To implement file-based storage of credentials.
* To provide basic password management operations.
* To understand security weaknesses in password storage.
* To identify vulnerabilities using Static Application Security Testing (SAST) tools.
* To fix the identified vulnerabilities using secure coding and cryptographic techniques.

---

## 3. Features

The Password Manager provides the following five main functions:

### 3.1 Add Password

The `add_password()` function allows the user to add a new website credential.

The user enters:

* Website name
* Username
* Password

The information is then stored in `passwords.txt`.

---

### 3.2 View Passwords

The `view_passwords()` function reads all saved credentials from `passwords.txt` and displays them on the screen.

It displays:

* Website
* Username
* Password

If the password file does not exist or contains no credentials, an appropriate message is displayed.

---

### 3.3 Search Password

The `search_password()` function allows the user to search for a saved password using the website name.

The search is case-insensitive. For example, searching for `Google` can also find an entry stored as `google`.

If the website is found, its username and password are displayed.

---

### 3.4 Update Password

The `update_password()` function allows the user to change the password associated with an existing website.

The user provides:

1. Website name
2. New password

The application reads the existing file, updates the matching entry, and writes the updated information back to the file.

---

### 3.5 Delete Password

The `delete_password()` function allows the user to delete a saved website credential.

The user enters the website name. If a matching entry is found, it is removed from the password file.

---

## 4. Application Menu

When the application starts, the following menu is displayed:

```text
================================
        PASSWORD MANAGER
================================

1. Add Password
2. View Passwords
3. Search Password
4. Update Password
5. Delete Password
6. Exit
```

The user selects an option by entering the corresponding number.

---

## 5. File Storage

The application uses:

```text
passwords.txt
```

to store the credentials.

Each record is stored in the following format:

```text
website|username|password
```

For example:

```text
google|student@gmail.com|mypassword123
github|student|githubpass456
```

The `|` symbol is used as a separator between the website, username, and password.


## 6. Technologies Used

* **Programming Language:** Python
* **Storage:** Text file
* **Interface:** Command-line interface (CLI)
* **Version Control:** Git and GitHub
* **Security Analysis:** SAST tools will be used in later stages


## 7. Current Security Limitations

This is the initial/basic version of the Password Manager. It is **not yet a secure password manager**.

The current implementation has several security limitations that will be studied during the laboratory.

Some important limitations include:

* Passwords are stored in plain text.
* Passwords are displayed directly on the screen.
* Credentials are stored in a normal text file.
* There is no encryption of stored passwords.
* There is no secure authentication mechanism.
* Sensitive information is directly handled as normal strings.
* The application does not currently use cryptographic protection for stored credentials.

These limitations are intentional parts of the initial application and will be analyzed during the vulnerability and secure-coding stages of the laboratory.

---



## 8. Learning Outcomes

Through this project, the following concepts will be studied:

* Password management
* File handling in Python
* Secure coding practices
* Common software vulnerabilities
* Static Application Security Testing (SAST)
* Password protection
* Cryptographic techniques
* Vulnerability analysis
* Vulnerability remediation
* Git and GitHub version control

---

## 9. Project Status

**Current Stage:** Basic Password Manager Application

The basic five password management operations have been implemented:

* Add
* View
* Search
* Update
* Delete

Security analysis, vulnerability identification, SAST testing, and cryptographic improvements will be performed in subsequent stages of the semester project.
