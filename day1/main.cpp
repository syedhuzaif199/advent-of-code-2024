#include <iostream>
#include <fstream>
#include <queue>
#include <map>

int main()
{
    // read a file
    std::ifstream file("input.txt");
    if (!file.is_open())
    {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    // priority queues for part 1
    std::priority_queue<int> pq1;
    std::priority_queue<int> pq2;

    // hash map for part 2
    std::map<int, int> m;

    int num1,
        num2;
    while (file >> num1)
    {
        file >> num2;
        // part 1
        pq1.push(num1);
        pq2.push(num2);

        // part 2
        if (m.find(num2) == m.end())
        {
            m[num2] = num2;
        }
        else
        {
            m[num2] += num2;
        }
    }

    file.clear();
    file.seekg(0, std::ios::beg);

    int sum = 0;
    while (!pq1.empty())
    {
        sum += abs(pq2.top() - pq1.top());
        pq1.pop();
        pq2.pop();
    }

    std::cout << "Sum of differences: " << sum << std::endl;

    sum = 0;
    while (file >> num1)
    {
        file >> num2;
        if (m.find(num1) != m.end())
        {
            sum += m[num1];
        }
    }

    std::cout << "Similarity score: " << sum << std::endl;
}