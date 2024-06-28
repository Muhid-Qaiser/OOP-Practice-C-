#include <iostream>
#include <cstring>
#include <cctype>

void SprinkleCommas(char *text)
{
    int textSize = strlen(text);
    bool commasAdded;

    do
    {
        commasAdded = false;

        // Step 1: Add commas before words preceded by a comma
        for (int i = 1; i < textSize - 1; i++)
        {
            if (text[i] == ' ' && text[i - 1] == ',')
            {
                if (text[i + 1] != ',' && text[i + 1] != '.' && text[i + 1] != ' ')
                {
                    // Find all occurrences of the word
                    for (int j = i + 1; j < textSize - 1; j++)
                    {
                        if (text[j] == ' ' || text[j] == ',' || text[j] == '.')
                        {
                            break;
                        }
                        if (tolower(text[j]) == tolower(text[i + 1]))
                        {
                            // Insert comma before each occurrence, except if it's the first word or already preceded by a comma
                            if (i != 1 && text[i - 2] != ',' && text[i - 2] != '.')
                            {
                                memmove(&text[i - 1], &text[i], textSize - i);
                                text[i - 1] = ',';
                                textSize++;
                                i++;
                                commasAdded = true;
                            }
                        }
                    }
                }
            }
        }

        // Step 2: Add commas after words succeeded by a comma
        for (int i = 1; i < textSize - 1; i++)
        {
            if (text[i] == ' ' && text[i + 1] == ',')
            {
                if (text[i - 1] != ',' && text[i - 1] != '.' && text[i - 1] != ' ')
                {
                    // Find all occurrences of the word
                    for (int j = i + 1; j < textSize - 1; j++)
                    {
                        if (text[j] == ' ' || text[j] == ',' || text[j] == '.')
                        {
                            break;
                        }
                        if (tolower(text[j]) == tolower(text[i - 1]))
                        {
                            // Insert comma after each occurrence, except if it's the last word or already succeeded by a comma
                            if (text[j + 1] != ',' && text[j + 1] != '.')
                            {
                                memmove(&text[j + 2], &text[j + 1], textSize - j - 1);
                                text[j + 1] = ',';
                                textSize++;
                                commasAdded = true;
                            }
                        }
                    }
                }
            }
        }

    } while (commasAdded);
}

int main()
{
    char text[] = "Please sit spot. Sit spot, sit. Spot here now here.";

    SprinkleCommas(text);

    std::cout << "Result: " << text << std::endl;

    return 0;
}
