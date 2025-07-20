/*�ִ�C++��ѧ��ϰ����*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <memory>
#include <stdexcept>

class MathExerciseSystem
{
private:
    // ʹ���ִ�C++�������������
    std::random_device rd;
    std::mt19937 gen;

    // ��Ա����ʹ�ø��õ�����������
    int randomDigits = 10;
    int questionNumber = 5;
    int totalScore = 100;
    int correctAnswers = 0;

    // ʹ��vector����C�������
    std::vector<std::string> mathProblems;

    enum class Operation
    {
        ADD = 0,
        SUBTRACT = 1,
        MULTIPLY = 2,
        DIVIDE = 3
    };

    // ����������ĸ�������
    int generateRandomNumber()
    {
        std::uniform_int_distribution<> dis(1, randomDigits - 1);
        return dis(gen);
    }

    // ��ȡ�������ַ���
    std::string getOperatorString(Operation op)
    {
        switch (op)
        {
        case Operation::ADD:
            return " + ";
        case Operation::SUBTRACT:
            return " - ";
        case Operation::MULTIPLY:
            return " * ";
        case Operation::DIVIDE:
            return " / ";
        default:
            return " ? ";
        }
    }

    // ������
    int calculateResult(int first, int second, Operation op)
    {
        switch (op)
        {
        case Operation::ADD:
            return first + second;
        case Operation::SUBTRACT:
            return first - second;
        case Operation::MULTIPLY:
            return first * second;
        case Operation::DIVIDE:
            return second != 0 ? first / second : 0;
        default:
            return 0;
        }
    }

    // ��ʾ������Ŀ���
    void showQuestionResult(int userAnswer, int correctAnswer, bool isCorrect)
    {
        if (isCorrect)
        {
            std::cout << "�ش���ȷ��\n";
        }
        else
        {
            std::cout << "�ش����\n";
        }
        std::cout << "��ȷ�𰸣�" << correctAnswer << "\n\n";
    }

    // ��ʾ��ϰ�ܽ�
    void showExerciseSummary()
    {
        std::cout << "==============================================\n";
        std::cout << "��ȷ������" << correctAnswers << "\n";
        std::cout << "�ܴ�������" << questionNumber << "\n";

        double correctnessRate = static_cast<double>(correctAnswers) / questionNumber;
        std::cout << "��ȷ�ʣ�" << std::fixed << std::setprecision(2) << correctnessRate << "\n";
        std::cout << "==============================================\n";
    }

    // ��ʾ���Խ��
    void showTestResults()
    {
        std::cout << "==============================================\n";
        std::cout << "�ο��𰸣�\n";
        for (const auto &problem : mathProblems)
        {
            std::cout << problem << "\n";
        }
        std::cout << "��Ŀ������" << questionNumber << "\n";
        std::cout << "��ȷ������" << correctAnswers << "\n";
        std::cout << "����������" << questionNumber - correctAnswers << "\n";

        int finalScore = totalScore - (totalScore / questionNumber) * (questionNumber - correctAnswers);
        std::cout << "���β��Եĳɼ���" << finalScore << "\n";
        std::cout << "==============================================\n";
    }

public:
    // ���캯��ʹ�ó�ʼ���б�
    MathExerciseSystem() : gen(rd())
    {
        mathProblems.reserve(1000); // Ԥ����ռ�
    }

    // ��ѧ��ϰģʽ
    void mathExercise()
    {
        correctAnswers = 0;
        mathProblems.clear();

        std::cout << "��ʼ��ѧ��ϰ��\n\n";

        for (int i = 0; i < questionNumber; ++i)
        {
            int firstNumber = generateRandomNumber();
            int secondNumber = generateRandomNumber();

            // ȷ������ʱ������Ϊ0
            if (secondNumber == 0)
            {
                secondNumber = generateRandomNumber();
            }

            std::uniform_int_distribution<> opDis(0, 3);
            Operation op = static_cast<Operation>(opDis(gen));

            int correctResult = calculateResult(firstNumber, secondNumber, op);

            std::cout << "��" << (i + 1) << "�⣺";
            std::cout << firstNumber << getOperatorString(op) << secondNumber << " = ";

            int userAnswer;
            std::cin >> userAnswer;

            bool isCorrect = (userAnswer == correctResult);
            if (isCorrect)
            {
                ++correctAnswers;
            }

            showQuestionResult(userAnswer, correctResult, isCorrect);
        }

        showExerciseSummary();
        std::cin.ignore();
        std::cout << "���س�������...";
        std::cin.get();
    }

    // ��ѧ����ģʽ
    void mathTest()
    {
        correctAnswers = 0;
        mathProblems.clear();
        mathProblems.resize(questionNumber);

        std::cout << "��ʼ��ѧ���ԣ�\n\n";

        for (int i = 0; i < questionNumber; ++i)
        {
            int firstNumber = generateRandomNumber();
            int secondNumber = generateRandomNumber();

            if (secondNumber == 0)
            {
                secondNumber = generateRandomNumber();
            }

            std::uniform_int_distribution<> opDis(0, 3);
            Operation op = static_cast<Operation>(opDis(gen));

            int correctResult = calculateResult(firstNumber, secondNumber, op);

            // ������Ŀ�ַ���
            mathProblems[i] = std::to_string(firstNumber) +
                              getOperatorString(op) +
                              std::to_string(secondNumber) +
                              " = " +
                              std::to_string(correctResult);

            std::cout << "��" << (i + 1) << "�⣺";
            std::cout << firstNumber << getOperatorString(op) << secondNumber << " = ";

            int userAnswer;
            std::cin >> userAnswer;

            if (userAnswer == correctResult)
            {
                ++correctAnswers;
            }
        }

        showTestResults();
        std::cin.ignore();
        std::cout << "���س�������...";
        std::cin.get();
    }

    // ��������
    void testSettings()
    {
        std::cout << "��ѡ��λ���ڵ����㣺";
        int digits;
        std::cin >> digits;

        switch (digits)
        {
        case 1:
            randomDigits = 10;
            break;
        case 2:
            randomDigits = 100;
            break;
        case 3:
            randomDigits = 1000;
            break;
        default:
            std::cout << "�������ʹ��Ĭ��ֵ\n";
            randomDigits = 10;
            break;
        }

        std::cout << "��������Ŀ������";
        std::cin >> questionNumber;

        if (questionNumber <= 0)
        {
            questionNumber = 5;
            std::cout << "��Ŀ�������ô���ʹ��Ĭ��ֵ5\n";
        }

        std::cout << "�������ܷ֣�";
        std::cin >> totalScore;

        if (totalScore <= 0)
        {
            totalScore = 100;
            std::cout << "�ܷ����ô���ʹ��Ĭ��ֵ100\n";
        }

        std::cout << "������ɣ�\n";
        std::cin.ignore();
        std::cout << "���س�������...";
        std::cin.get();
    }

    // ����ɼ�
    void saveScore()
    {
        try
        {
            std::cout << "����������������";
            std::cin.ignore();

            std::string userName;
            std::getline(std::cin, userName);

            std::ofstream file("Score.txt");
            if (!file.is_open())
            {
                throw std::runtime_error("�޷������ɼ��ļ�");
            }

            file << "������" << userName << "\n";
            file << "�ο��𰸣�\n";

            for (const auto &problem : mathProblems)
            {
                file << problem << "\n";
            }

            file << "��ȷ������" << correctAnswers << "\n";
            file << "����������" << questionNumber - correctAnswers << "\n";

            int finalScore = totalScore - (totalScore / questionNumber) * (questionNumber - correctAnswers);
            file << "�ɼ���" << finalScore << "\n";

            file.close();
            std::cout << "�ɼ��ѱ��浽 Score.txt �ļ��У�\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << "����ɼ�ʱ����" << e.what() << "\n";
        }

        std::cout << "���س�������...";
        std::cin.get();
    }

    // ���˵�ѭ��
    void run()
    {
        bool running = true;

        while (running)
        {
            // ��������ƽ̨��
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            std::cout << "��ѧ��ϰϵͳ\n";
            std::cout << "1. ��ϰ\n";
            std::cout << "2. ����\n";
            std::cout << "3. ����\n";
            std::cout << "4. �鿴����ɼ�\n";
            std::cout << "0. �˳�\n";
            std::cout << "����������ѡ��";

            int choice;
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                mathExercise();
                break;
            case 2:
                mathTest();
                break;
            case 3:
                testSettings();
                break;
            case 4:
                saveScore();
                break;
            case 0:
                running = false;
                std::cout << "��лʹ����ѧ��ϰϵͳ��\n";
                break;
            default:
                std::cout << "��Чѡ�����������룡\n";
                std::cin.ignore();
                std::cout << "���س�������...";
                std::cin.get();
                break;
            }
        }
    }
};

// ������
int main()
{
    try
    {
        auto exerciseSystem = std::make_unique<MathExerciseSystem>();
        exerciseSystem->run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "�������г���" << e.what() << "\n";
        return 1;
    }

    return 0;
}