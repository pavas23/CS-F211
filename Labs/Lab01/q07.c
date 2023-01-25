#include <stdio.h>

// finding sum of given freq_arr
int sumOfArray(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    // taking user input
    char sentence[1000];
    char word[1000];
    int i = 0;
    char ch = ' ';
    while (ch != '\n')
    {
        scanf("%c", &ch);
        sentence[i] = ch;
        i++;
    }
    ch = ' ';
    int lenOfSentence = i - 1;
    i = 0;
    while (ch != '\n')
    {
        scanf("%c", &ch);
        word[i] = ch;
        i++;
    }
    int lenOfWord = i - 1;

    // making frequency array for storing freq of each char in the given string
    int original_freq_arr[26];
    int new_freq_arr[26];
    for (int i = 0; i < 26; i++)
    {
        original_freq_arr[i] = 0;
        new_freq_arr[i] = 0;
    }
    for (int i = 0; i < lenOfWord; i++)
    {
        original_freq_arr[word[i] - 'a']++;
    }

    int startIndex = 0, endIndex = 0;
    int flag = 0;
    int sum_original = sumOfArray(original_freq_arr, 26);
    int sum = 0;
    int window_arr[1000][2];
    int k = 0;
    int start_count = 0;
    i = 0;

    while (startIndex < lenOfSentence && endIndex < lenOfSentence)
    {
        // if the char is not present in the word
        if (original_freq_arr[sentence[i] - 'a'] == 0)
        {
            if (sum != sum_original)
            {
                endIndex = i;
            }
            else
            {
                i--;
            }
        }
        else
        {
            if (start_count == 0)
            {
                startIndex = i;
                start_count++;
            }
            endIndex = i;
            new_freq_arr[sentence[i] - 'a']++;
            if (original_freq_arr[sentence[i] - 'a'] - new_freq_arr[sentence[i] - 'a'] >= 0)
            {
                sum++;
            }
        }
        if (sum == sum_original)
        {
            // if sum becomes equal to original sum that is substring is found then store the start and end index in 2D-array
            window_arr[k][0] = startIndex;
            window_arr[k][1] = endIndex;
            k++;
            flag = 1;
            endIndex = i;
            // now increment the startIndex and check whether the char at startIndex is present in given word or not and it should not be a space
            if (sentence[startIndex] != ' ' && original_freq_arr[sentence[startIndex] - 'a'] != 0)
            {
                // if present then decrement the frequency of that char
                new_freq_arr[sentence[startIndex] - 'a']--;
                if (new_freq_arr[sentence[startIndex] - 'a'] - original_freq_arr[sentence[startIndex] - 'a'] < 0)
                {
                    // if that char after decrementing also fullfils the condition then don't change sum otherwise decrement it
                    sum--;
                }
            }
            startIndex++;
        }
        i++;
    }

    // if no such window exists
    if (flag == 0)
    {
        printf("NO WINDOW\n");
        return 0;
    }

    // finding the smallest window size
    int min = __INT_MAX__;
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        if (window_arr[i][1] - window_arr[i][0] < min)
        {
            min = window_arr[i][1] - window_arr[i][0];
            index = i;
        }
    }

    // printing the output
    printf("%d %d\n", window_arr[index][0], window_arr[index][1]);
    for (int i = window_arr[index][0]; i <= window_arr[index][1]; i++)
    {
        printf("%c", sentence[i]);
    }
    printf("\n");

    return 0;
}
