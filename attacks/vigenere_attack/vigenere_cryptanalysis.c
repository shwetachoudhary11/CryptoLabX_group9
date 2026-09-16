#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 20000
#define MAX_PATTERNS 1000
#define MAX_PATTERN 20
#define MAX_KEY 100

void clean_ciphertext(char *input, char *output)
{
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)input[i]))
        {
            output[j++] = toupper((unsigned char)input[i]);
        }
    }

    output[j] = '\0';
}

int string_length(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

void find_repeated_patterns(char *text, int length)
{
    printf("\n====================================\n");
    printf("REPEATED PATTERNS\n");
    printf("====================================\n");

    int found = 0;

    for (int size = 3; size <= 5; size++)
    {
        for (int i = 0; i <= length - size; i++)
        {
            int repeated = 0;

            for (int j = i + 1; j <= length - size; j++)
            {
                int same = 1;

                for (int k = 0; k < size; k++)
                {
                    if (text[i + k] != text[j + k])
                    {
                        same = 0;
                        break;
                    }
                }

                if (same)
                {
                    printf("Pattern: ");

                    for (int k = 0; k < size; k++)
                        printf("%c", text[i + k]);

                    printf("   Positions: %d, %d\n", i, j);

                    repeated = 1;
                    found = 1;
                    break;
                }
            }

            if (repeated)
                continue;
        }
    }

    if (!found)
        printf("No repeated patterns found.\n");
}

void calculate_distances(char *text, int length)
{
    printf("\n====================================\n");
    printf("DISTANCES BETWEEN REPEATED PATTERNS\n");
    printf("====================================\n");

    int found = 0;

    for (int size = 3; size <= 5; size++)
    {
        for (int i = 0; i <= length - size; i++)
        {
            for (int j = i + 1; j <= length - size; j++)
            {
                int same = 1;

                for (int k = 0; k < size; k++)
                {
                    if (text[i + k] != text[j + k])
                    {
                        same = 0;
                        break;
                    }
                }

                if (same)
                {
                    printf("Pattern: ");

                    for (int k = 0; k < size; k++)
                        printf("%c", text[i + k]);

                    printf("   Distance: %d\n", j - i);

                    found = 1;
                }
            }
        }
    }

    if (!found)
        printf("No repeated pattern distances found.\n");
}

void find_factors(int number)
{
    printf("Distance %d factors: ", number);

    for (int i = 2; i <= number; i++)
    {
        if (number % i == 0)
            printf("%d ", i);
    }

    printf("\n");
}

void kasiski_analysis(char *text, int length)
{
    printf("\n====================================\n");
    printf("KASISKI ANALYSIS\n");
    printf("====================================\n");

    int distances[1000];
    int distance_count = 0;

    for (int size = 3; size <= 5; size++)
    {
        for (int i = 0; i <= length - size; i++)
        {
            for (int j = i + 1; j <= length - size; j++)
            {
                int same = 1;

                for (int k = 0; k < size; k++)
                {
                    if (text[i + k] != text[j + k])
                    {
                        same = 0;
                        break;
                    }
                }

                if (same)
                {
                    int distance = j - i;

                    if (distance_count < 1000)
                        distances[distance_count++] = distance;
                }
            }
        }
    }

    if (distance_count == 0)
    {
        printf("No repeated patterns were found.\n");
        return;
    }

    printf("Factors of repeated-pattern distances:\n");

    for (int i = 0; i < distance_count; i++)
        find_factors(distances[i]);

    printf("\nCandidate key lengths are suggested from common factors.\n");
}

double calculate_ic(char *text, int length)
{
    int freq[26] = {0};

    for (int i = 0; i < length; i++)
        freq[text[i] - 'A']++;

    if (length <= 1)
        return 0.0;

    double numerator = 0;

    for (int i = 0; i < 26; i++)
        numerator += freq[i] * (freq[i] - 1);

    return numerator / ((double)length * (length - 1));
}

void split_into_groups(char *text, int length, int key_length)
{
    printf("\n====================================\n");
    printf("CIPHERTEXT GROUPS\n");
    printf("====================================\n");

    for (int group = 0; group < key_length; group++)
    {
        printf("Group %d: ", group + 1);

        for (int i = group; i < length; i += key_length)
            printf("%c", text[i]);

        printf("\n");
    }
}

void frequency_analysis(char *text, int length, int key_length)
{
    printf("\n====================================\n");
    printf("FREQUENCY ANALYSIS OF GROUPS\n");
    printf("====================================\n");

    for (int group = 0; group < key_length; group++)
    {
        int freq[26] = {0};
        int count = 0;

        for (int i = group; i < length; i += key_length)
        {
            freq[text[i] - 'A']++;
            count++;
        }

        printf("\nGroup %d\n", group + 1);
        printf("Letter  Frequency  Percentage\n");

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                double percentage =
                    ((double)freq[i] / count) * 100;

                printf("%c       %d          %.2f%%\n",
                       'A' + i,
                       freq[i],
                       percentage);
            }
        }
    }
}

int find_shift(char *text, int length, int group, int key_length)
{
    int freq[26] = {0};
    int count = 0;

    for (int i = group; i < length; i += key_length)
    {
        freq[text[i] - 'A']++;
        count++;
    }

    double best_score = -1;
    int best_shift = 0;

    for (int shift = 0; shift < 26; shift++)
    {
        double score = 0;

        for (int i = 0; i < 26; i++)
        {
            int shifted = (i - shift + 26) % 26;

            if (shifted == 4)
                score += freq[i];
        }

        if (score > best_score)
        {
            best_score = score;
            best_shift = shift;
        }
    }

    return best_shift;
}

void find_key(char *text, int length, int key_length, char *key)
{
    for (int i = 0; i < key_length; i++)
    {
        int shift = find_shift(text, length, i, key_length);

        key[i] = 'A' + shift;
    }

    key[key_length] = '\0';

    printf("\n====================================\n");
    printf("RECOVERED KEY\n");
    printf("====================================\n");

    printf("Key: %s\n", key);
}

void vigenere_decrypt(char *ciphertext, char *key, char *plaintext)
{
    int key_length = string_length(key);
    int key_index = 0;

    for (int i = 0; ciphertext[i] != '\0'; i++)
    {
        int c = ciphertext[i] - 'A';
        int k = key[key_index % key_length] - 'A';

        plaintext[i] = 'A' + (c - k + 26) % 26;

        key_index++;
    }

    plaintext[key_index] = '\0';
}

void vigenere_encrypt(char *plaintext, char *key, char *ciphertext)
{
    int key_length = string_length(key);

    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        int p = plaintext[i] - 'A';
        int k = key[i % key_length] - 'A';

        ciphertext[i] = 'A' + (p + k) % 26;
    }

    ciphertext[string_length(plaintext)] = '\0';
}

int verify(char *original, char *generated)
{
    if (strcmp(original, generated) == 0)
        return 1;

    return 0;
}

int main()
{
    char input[MAX_TEXT];
    char ciphertext[MAX_TEXT];
    char plaintext[MAX_TEXT];
    char generated[MAX_TEXT];
    char key[MAX_KEY];

    FILE *file = fopen("datasets/vigenere/ciphertext.txt", "r");

    if (file == NULL)
    {
        printf("Error: ciphertext.txt could not be opened.\n");
        return 1;
    }

    int length = fread(input, 1, MAX_TEXT - 1, file);
    input[length] = '\0';

    fclose(file);

    clean_ciphertext(input, ciphertext);

    length = string_length(ciphertext);

    printf("====================================\n");
    printf("VIGENERE CIPHER CRYPTANALYSIS\n");
    printf("====================================\n");

    printf("\nClean ciphertext length: %d\n", length);

    find_repeated_patterns(ciphertext, length);

    calculate_distances(ciphertext, length);

    kasiski_analysis(ciphertext, length);

    printf("\nIndex of Coincidence of ciphertext: %.4f\n",
           calculate_ic(ciphertext, length));

    int key_length;

    printf("\nEnter estimated key length from Kasiski analysis: ");
    scanf("%d", &key_length);

    if (key_length <= 0 || key_length > 50)
    {
        printf("Invalid key length.\n");
        return 1;
    }

    split_into_groups(ciphertext, length, key_length);

    frequency_analysis(ciphertext, length, key_length);

    find_key(ciphertext, length, key_length, key);

    vigenere_decrypt(ciphertext, key, plaintext);

    printf("\n====================================\n");
    printf("RECOVERED PLAINTEXT\n");
    printf("====================================\n");

    printf("%s\n", plaintext);

    vigenere_encrypt(plaintext, key, generated);

    printf("\n====================================\n");
    printf("VERIFICATION\n");
    printf("====================================\n");

    if (verify(ciphertext, generated))
        printf("Verification successful: ciphertexts match.\n");
    else
        printf("Verification failed: ciphertexts do not match.\n");

    FILE *out = fopen("outputs/vigenere/recovered_plaintext.txt", "w");

    if (out != NULL)
    {
        fprintf(out, "Recovered Key: %s\n\n", key);
        fprintf(out, "Recovered Plaintext:\n%s\n", plaintext);
        fclose(out);
    }

    return 0;
}