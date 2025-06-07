#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Function to load DNA sequence from file
std::string loadDNAFromFile(const std::string &filePath)
{
    std::ifstream file(filePath); // Open the file
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return "";
    }

    std::string dnaSequence;
    std::string line;

    // Read each line of the file and append to the DNA sequence string
    while (std::getline(file, line))
    {
        dnaSequence += line; // Append the line to the dnaSequence
    }

    file.close(); // Close the file
    return dnaSequence;
}

// Helper function to check if a nucleotide is not 'G'
bool isNotG(char nucleotide)
{
    return nucleotide == 'A' || nucleotide == 'T' || nucleotide == 'C';
}

// Function to find G-quadruplex regions
std::vector<std::pair<int, int>> findGQuadruplex(const std::string &dna)
{
    std::vector<std::pair<int, int>> regions;
    int n = dna.length();

    for (int i = 0; i < n; ++i)
    {
        // Look for a run of G's (3 to 4 in length)
        if (dna[i] == 'G')
        {
            int run1 = 0;
            // Count the length of the first run of G's
            while (i < n && dna[i] == 'G' && run1 < 4)
            {
                ++run1;
                ++i;
            }

            // Check if the run length is valid
            if (run1 >= 3 && run1 <= 4)
            {
                // Now find the loop (1 to 7 nucleotides, excluding 'G')
                int loop1 = 0;
                while (i < n && isNotG(dna[i]) && loop1 < 7)
                {
                    ++loop1;
                    ++i;
                }

                // Second run of G's (3 to 4 in length)
                int run2 = 0;
                while (i < n && dna[i] == 'G' && run2 < 4)
                {
                    ++run2;
                    ++i;
                }

                if (run2 >= 3 && run2 <= 4)
                {
                    // Second loop (1 to 7 nucleotides)
                    int loop2 = 0;
                    while (i < n && isNotG(dna[i]) && loop2 < 7)
                    {
                        ++loop2;
                        ++i;
                    }

                    // Third run of G's
                    int run3 = 0;
                    while (i < n && dna[i] == 'G' && run3 < 4)
                    {
                        ++run3;
                        ++i;
                    }

                    if (run3 >= 3 && run3 <= 4)
                    {
                        // Third loop (1 to 7 nucleotides)
                        int loop3 = 0;
                        while (i < n && isNotG(dna[i]) && loop3 < 7)
                        {
                            ++loop3;
                            ++i;
                        }

                        // Fourth run of G's
                        int run4 = 0;
                        while (i < n && dna[i] == 'G' && run4 < 4)
                        {
                            ++run4;
                            ++i;
                        }

                        if (run4 >= 3 && run4 <= 4)
                        {
                            // G-quadruplex identified, store start and end position
                            int endPos = i - 1;
                            int startPos = endPos - (run1 + run2 + run3 + run4 + loop1 + loop2 + loop3);
                            regions.push_back({startPos, endPos});
                        }
                    }
                }
            }
        }
    }

    return regions;
}

int main()
{

    std::string filePath = "genome.txt";

    // Load the DNA sequence from the file
    std::string dnaSequence = loadDNAFromFile(filePath);

    if (dnaSequence.empty())
    {
        std::cerr << "DNA sequence could not be loaded!" << std::endl;
        return 1;
    }

    // Output the size of the loaded DNA sequence
    std::cout << "DNA sequence length: " << dnaSequence.length() << " nucleotides" << std::endl;

    // Traverse and process the DNA sequence (e.g., find G-quadruplex regions)
    for (size_t i = 0; i < dnaSequence.length(); ++i)
    {
        // Example: Print only the first 100 nucleotides to avoid flooding the console
        if (i < 100)
        {
            std::cout << dnaSequence[i];
        }
    }

    std::cout << std::endl;

    ////////////////////////second part of code done

    std::string dna = "GGGTTAGGGTTAGGGTTAGGG";

    std::vector<std::pair<int, int>> regions = findGQuadruplex(dnaSequence);

    if (!regions.empty())
    {
        for (const auto &region : regions)
        {
            std::cout << "G-quadruplex found from position " << region.first
                      << " to " << region.second << std::endl;
            for (int i = region.first; i < region.second; i++)
            {
                std::cout << dnaSequence[i];
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "No G-quadruplex found." << std::endl;
    }

    return 0;
}
