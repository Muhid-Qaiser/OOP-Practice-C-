#include <iostream>

void rotateImage90(int **image, int n)
{
    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            std::swap(image[i][j], image[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            std::swap(image[i][j], image[i][n - 1 - j]);
        }
    }
}

int main()
{
    // Example usage
    const int n = 4;
    int **image = new int *[n];
    for (int i = 0; i < n; i++)
    {
        image[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            image[i][j] = i * n + j;
        }
    }

    std::cout << "Original Image:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << image[i][j] << " ";
        }
        std::cout << std::endl;
    }

    rotateImage90(image, n);

    std::cout << "Rotated Image:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << image[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        delete[] image[i];
    }
    delete[] image;

    return 0;
}
