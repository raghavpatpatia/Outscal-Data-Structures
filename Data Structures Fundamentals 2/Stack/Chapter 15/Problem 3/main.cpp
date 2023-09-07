#include <iostream>
#include <stack>

class Solution
{
public:
    int Reverse(int num)
    {
        std::stack<int> stack;
        bool isNegative = false;
        if (num < 0)
        {
            isNegative = true;
            num = -num;
        }

        while (num != 0)
        {
            int digit = num % 10;
            stack.push(digit);
            num = num / 10;
        }
        int reversed = 0;
        int power = 1;
        while (!stack.empty())
        {
            reversed += stack.top() * power;
            stack.pop();
            power *= 10;
        }

        if (isNegative)
        {
            reversed = -reversed;
        }

        return reversed;
    }
};

int main()
{
    Solution solution;
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << "Reversed Number: " << solution.Reverse(num) << std::endl;
    return 0;
}