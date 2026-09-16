#include <stdio.h>
#include <ctype.h>

#define MAX_TEXT 20000
#define MAX_WORDS 3000
#define MAX_WORD_LEN 100

int my_strlen(char *s)
{
    int i = 0;

    while (s[i] != '\0')
        i++;

    return i;
}

int my_strcmp(char *a, char *b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return a[i] - b[i];

        i++;
    }

    return a[i] - b[i];
}

void copy_string(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

void frequency_analysis(char *text)
{
    int freq[26] = {0};
    int total = 0;
    int order[26];

    for (int i = 0; i < 26; i++)
        order[i] = i;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            char c = toupper((unsigned char)text[i]);
            freq[c - 'A']++;
            total++;
        }
    }

    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (freq[order[j]] > freq[order[i]])
            {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    printf("\n========================================\n");
    printf("LETTER FREQUENCY ANALYSIS\n");
    printf("========================================\n");

    printf("\nLetter   Count   Percentage\n");
    printf("---------------------------\n");

    for (int i = 0; i < 26; i++)
    {
        int index = order[i];

        if (freq[index] > 0)
        {
            double percentage = 0;

            if (total > 0)
                percentage = ((double)freq[index] / total) * 100;

            printf("%c        %d      %.2f%%\n",
                   'A' + index,
                   freq[index],
                   percentage);
        }
    }

    if (total > 0)
    {
        printf("\nMost frequent ciphertext letters:\n");

        for (int i = 0; i < 5 && i < 26; i++)
        {
            if (freq[order[i]] > 0)
                printf("%c ", 'A' + order[i]);
        }

        printf("\n");
    }
}

void word_frequency_analysis(char *text)
{
    char words[MAX_WORDS][MAX_WORD_LEN];
    int counts[MAX_WORDS] = {0};
    int word_count = 0;

    char current[MAX_WORD_LEN];
    int pos = 0;

    for (int i = 0;; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            if (pos < MAX_WORD_LEN - 1)
                current[pos++] = tolower((unsigned char)text[i]);
        }
        else
        {
            if (pos > 0)
            {
                current[pos] = '\0';

                int found = -1;

                for (int j = 0; j < word_count; j++)
                {
                    if (my_strcmp(words[j], current) == 0)
                    {
                        found = j;
                        break;
                    }
                }

                if (found == -1 && word_count < MAX_WORDS)
                {
                    copy_string(words[word_count], current);
                    counts[word_count] = 1;
                    word_count++;
                }
                else if (found != -1)
                {
                    counts[found]++;
                }

                pos = 0;
            }

            if (text[i] == '\0')
                break;
        }
    }

    printf("\n========================================\n");
    printf("WORD FREQUENCY ANALYSIS\n");
    printf("========================================\n");

    printf("\nOne-letter words:\n");

    for (int i = 0; i < word_count; i++)
    {
        if (my_strlen(words[i]) == 1)
            printf("%s : %d\n", words[i], counts[i]);
    }

    printf("\nTwo-letter words:\n");

    for (int i = 0; i < word_count; i++)
    {
        if (my_strlen(words[i]) == 2)
            printf("%s : %d\n", words[i], counts[i]);
    }

    printf("\nThree-letter words:\n");

    for (int i = 0; i < word_count; i++)
    {
        if (my_strlen(words[i]) == 3)
            printf("%s : %d\n", words[i], counts[i]);
    }

    printf("\nRepeated words:\n");

    for (int i = 0; i < word_count; i++)
    {
        if (counts[i] > 1)
            printf("%s : %d\n", words[i], counts[i]);
    }
}

void generate_pattern(char *word, char *pattern)
{
    int mapping[26];
    int next = 0;

    for (int i = 0; i < 26; i++)
        mapping[i] = -1;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (mapping[index] == -1)
        {
            mapping[index] = next;
            next++;
        }

        pattern[i] = 'A' + mapping[index];
    }

    pattern[my_strlen(word)] = '\0';
}

void pattern_analysis(char *text)
{
    char words[MAX_WORDS][MAX_WORD_LEN];
    char patterns[MAX_WORDS][MAX_WORD_LEN];

    int word_count = 0;

    char current[MAX_WORD_LEN];
    int pos = 0;

    for (int i = 0;; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            if (pos < MAX_WORD_LEN - 1)
                current[pos++] = tolower((unsigned char)text[i]);
        }
        else
        {
            if (pos > 0)
            {
                current[pos] = '\0';

                int found = 0;

                for (int j = 0; j < word_count; j++)
                {
                    if (my_strcmp(words[j], current) == 0)
                    {
                        found = 1;
                        break;
                    }
                }

                if (!found && word_count < MAX_WORDS)
                {
                    copy_string(words[word_count], current);
                    generate_pattern(current, patterns[word_count]);
                    word_count++;
                }

                pos = 0;
            }

            if (text[i] == '\0')
                break;
        }
    }

    printf("\n========================================\n");
    printf("WORD PATTERN ANALYSIS\n");
    printf("========================================\n");

    printf("\nWord                 Pattern\n");
    printf("-----------------------------\n");

    for (int i = 0; i < word_count; i++)
        printf("%-20s %s\n", words[i], patterns[i]);
}

void apply_substitution(char *ciphertext, char *mapping, char *result)
{
    int i = 0;

    while (ciphertext[i] != '\0')
    {
        char c = ciphertext[i];

        if (c >= 'A' && c <= 'Z')
        {
            if (mapping[c - 'A'] != '?')
                result[i] = mapping[c - 'A'];
            else
                result[i] = '?';
        }
        else if (c >= 'a' && c <= 'z')
        {
            if (mapping[c - 'a'] != '?')
                result[i] = tolower((unsigned char)mapping[c - 'a']);
            else
                result[i] = '?';
        }
        else
        {
            result[i] = c;
        }

        i++;
    }

    result[i] = '\0';
}

void display_partial_plaintext(char *ciphertext, char *mapping)
{
    char result[MAX_TEXT];

    apply_substitution(ciphertext, mapping, result);

    printf("\n========================================\n");
    printf("PARTIAL PLAINTEXT\n");
    printf("========================================\n");

    printf("%s\n", result);
}

int verify_solution(char *plaintext, char *key, char *ciphertext)
{
    char encrypted[MAX_TEXT];

    apply_substitution(plaintext, key, encrypted);

    if (my_strcmp(encrypted, ciphertext) == 0)
        return 1;

    return 0;
}

int main()
{
    char ciphertext[MAX_TEXT];

    FILE *file;

    file = fopen("datasets/monoalphabetic/ciphertext.txt", "r");

    if (file == NULL)
    {
        printf("Error: ciphertext.txt could not be opened.\n");
        printf("Check the file path.\n");
        return 1;
    }

    int length = fread(ciphertext, 1, MAX_TEXT - 1, file);

    ciphertext[length] = '\0';

    fclose(file);

    printf("========================================\n");
    printf("MONOALPHABETIC CIPHER CRYPTANALYSIS\n");
    printf("========================================\n");

    frequency_analysis(ciphertext);

    word_frequency_analysis(ciphertext);

    pattern_analysis(ciphertext);

    char mapping[26];

    for (int i = 0; i < 26; i++)
        mapping[i] = '?';

    printf("\nInitial substitution mapping:\n");

    printf("Ciphertext : ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("Plaintext  : ??????????????????????????\n");

    display_partial_plaintext(ciphertext, mapping);

    printf("\n========================================\n");
    printf("ITERATIVE SUBSTITUTION\n");
    printf("========================================\n");

    char cipher_letter;
    char plain_letter;

    while (1)
    {
        printf("\nEnter ciphertext letter to substitute (0 to stop): ");

        scanf(" %c", &cipher_letter);

        if (cipher_letter == '0')
            break;

        cipher_letter = toupper((unsigned char)cipher_letter);

        if (cipher_letter < 'A' || cipher_letter > 'Z')
        {
            printf("Invalid ciphertext letter.\n");
            continue;
        }

        printf("Enter suspected plaintext letter: ");

        scanf(" %c", &plain_letter);

        plain_letter = toupper((unsigned char)plain_letter);

        if (plain_letter < 'A' || plain_letter > 'Z')
        {
            printf("Invalid plaintext letter.\n");
            continue;
        }

        mapping[cipher_letter - 'A'] = plain_letter;

        printf("\nSubstitution tested: %c -> %c\n",
               cipher_letter,
               plain_letter);

        display_partial_plaintext(ciphertext, mapping);
    }

    printf("\nFinal substitution mapping:\n");

    printf("Ciphertext : ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("Plaintext  : ");

    for (int i = 0; i < 26; i++)
        printf("%c", mapping[i]);

    printf("\n");

    printf("\nCryptanalysis session completed.\n");

    return 0;
}