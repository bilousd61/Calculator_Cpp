#include <iostream>
#include <cmath>

int fact(int x)
{
    int r = 1;
    for (int i = x; i > 0; --i)
    {
        r *= i;
    }
    return r;
}

double inputNumber()
{
    while(1)
    {
        std::cout << "Input the number: ";
        double number;
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "INPUT CORRECT NUMBER. Please.\n";
        }
        else
        {
            std::cin.ignore(32767,'\n');
            return number;
        }
    }
}

char inputOperate()
{
    while(1)
    {
        std::cout << "Input operator (+, -, *, / or ^): ";
        char op;
        std::cin >> op;

        switch(op)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case 'q':
            return op;
        default:
            std::cout << "INPUT CORRECT OPERATOR. Please.\n";
        }
    }
}

double calculate(double f, char d, double s)
{
    // Перевіряємо яку саме дію треба виконати і даємо результат
    switch(d)
    {
    case '+':
        return f + s;
    case '-':
        return f - s;
    case '*':
        return f * s;
    case '/':
        return f / s;
    case '^':
        return pow(f, s);
    default:
        return -1;
    }

}

void printResult(double firstNumber, char op, double secondNumber)
{
    // Виконуємо дію
    double result = calculate(firstNumber, op, secondNumber);

    // Виводимо результат
    std::cout << "\n" << firstNumber << ' ';
    std::cout << op << ' ';
    std::cout << secondNumber << " = ";
    std::cout << result << "\n\n";
}

int main()
{
    std::cout << "Input -1 (on number) or q (on operator) to quit" << std::endl;
    while(1)
    {
        // Запитуємо першу цифру
        double firstNumber = inputNumber();
        if (firstNumber == -1)
            break;

        // Запитуємо дію 
        char op = inputOperate();
        if (op == 'q')
            break;

        // Запитуємо другу цифру
        double secondNumber = inputNumber();
        if (secondNumber == -1)
            break;

        // Виконуємо дію і виводимо результат на екран
        printResult(firstNumber, op, secondNumber);
    }
    return 0;
}