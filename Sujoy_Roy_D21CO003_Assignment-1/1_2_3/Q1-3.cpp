#include <bits/stdc++.h>
#include <sys/time.h>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;
#define srand48 rand

std::unordered_set<int> duplicateElementSet;
std::unordered_map<int, int> numberCountMap;
vector<int> randomList;

void duplicateCount();
void removeDuplicate();

int main()
{
    long diff;
    struct timeval Start, end, now;
    long starttime, endtime;
    timeval t;

    int N = 1000000;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < N; i++)
    {
        randomList.push_back(rand());
    }

    auto start = std::chrono::high_resolution_clock::now();
    duplicateCount();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    auto defaultNano = (elapsed).count();
    cout << "Time taken by function to count Duplicates: " << defaultNano << " nanoseconds" << endl;
    // ------------------------------------------------------------------

    gettimeofday(&Start, NULL);
    start = std::chrono::high_resolution_clock::now();
    removeDuplicate();
    randomList.clear();
    for (auto i : numberCountMap)
    {
        randomList.push_back(i.first);
    }

    gettimeofday(&end, NULL);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    defaultNano = (elapsed).count();
    cout << "Time taken by function to remove Duplicates: " << defaultNano << " nanoseconds" << endl;
    diff = 1000000 * (end.tv_sec - Start.tv_sec) + end.tv_usec - Start.tv_usec;
    cout << "Time taken by function to remove Duplicates: " << diff << " microseconds" << endl;

    numberCountMap.clear();
    duplicateElementSet.clear();

    cout << "After removing Duplicates---\n";
    duplicateCount();

    ofstream output_file;
    output_file.open("randomList.txt");
    std::ostream_iterator<int> output_iterator(output_file, "\n");
    std::copy(randomList.begin(), randomList.end(), output_iterator);
    output_file.close();

    cout << "Program Ended!";
    return 0;
}

//Question---1
void duplicateCount()
{

    for (auto i : randomList)
    {
        if (numberCountMap.find(i) == numberCountMap.end())
        {
            numberCountMap[i] = 1;
        }
        else
        {
            numberCountMap[i]++;
            duplicateElementSet.insert(i);
        }
    }

    cout << "Duplicate Count:" << duplicateElementSet.size() << endl;
}

void removeDuplicate()
{

    for (auto i : duplicateElementSet)
    {
        while (numberCountMap[i] != 1)
        {
            for (int x = i - 1, j = i + 1;; x--, j++)
            {
                if (numberCountMap.find(x) == numberCountMap.end() && x >= 0)
                {
                    numberCountMap[x] = 1;
                    numberCountMap[i]--;
                    break;
                }
                else if (numberCountMap.find(j) == numberCountMap.end())
                {
                    numberCountMap[j] = 1;
                    numberCountMap[i]--;
                    break;
                }
            }
        }
    }
}
