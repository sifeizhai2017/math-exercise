/*现代C++数学练习程序*/
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
    // 使用现代C++的随机数生成器
    std::random_device rd;
    std::mt19937 gen;

    // 成员变量使用更好的命名和类型
    int randomDigits = 10;
    int questionNumber = 5;
    int totalScore = 100;
    int correctAnswers = 0;

    // 使用vector代替C风格数组
    std::vector<std::string> mathProblems;

    enum class Operation
    {
        ADD = 0,
        SUBTRACT = 1,
        MULTIPLY = 2,
        DIVIDE = 3
    };

    // 生成随机数的辅助函数
    int generateRandomNumber()
    {
        std::uniform_int_distribution<> dis(1, randomDigits - 1);
        return dis(gen);
    }

    // 获取操作符字符串
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

    // 计算结果
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

    // 显示单个题目结果
    void showQuestionResult(int userAnswer, int correctAnswer, bool isCorrect)
    {
        if (isCorrect)
        {
            std::cout << "回答正确！\n";
        }
        else
        {
            std::cout << "回答错误！\n";
        }
        std::cout << "正确答案：" << correctAnswer << "\n\n";
    }

    // 显示练习总结
    void showExerciseSummary()
    {
        std::cout << "==============================================\n";
        std::cout << "正确题数：" << correctAnswers << "\n";
        std::cout << "总答题数：" << questionNumber << "\n";

        double correctnessRate = static_cast<double>(correctAnswers) / questionNumber;
        std::cout << "正确率：" << std::fixed << std::setprecision(2) << correctnessRate << "\n";
        std::cout << "==============================================\n";
    }

    // 显示考试结果
    void showTestResults()
    {
        std::cout << "==============================================\n";
        std::cout << "参考答案：\n";
        for (const auto &problem : mathProblems)
        {
            std::cout << problem << "\n";
        }
        std::cout << "题目总数：" << questionNumber << "\n";
        std::cout << "正确题数：" << correctAnswers << "\n";
        std::cout << "错误题数：" << questionNumber - correctAnswers << "\n";

        int finalScore = totalScore - (totalScore / questionNumber) * (questionNumber - correctAnswers);
        std::cout << "本次测试的成绩：" << finalScore << "\n";
        std::cout << "==============================================\n";
    }

public:
    // 构造函数使用初始化列表
    MathExerciseSystem() : gen(rd())
    {
        mathProblems.reserve(1000); // 预分配空间
    }

    // 数学练习模式
    void mathExercise()
    {
        correctAnswers = 0;
        mathProblems.clear();

        std::cout << "开始数学练习！\n\n";

        for (int i = 0; i < questionNumber; ++i)
        {
            int firstNumber = generateRandomNumber();
            int secondNumber = generateRandomNumber();

            // 确保除法时除数不为0
            if (secondNumber == 0)
            {
                secondNumber = generateRandomNumber();
            }

            std::uniform_int_distribution<> opDis(0, 3);
            Operation op = static_cast<Operation>(opDis(gen));

            int correctResult = calculateResult(firstNumber, secondNumber, op);

            std::cout << "第" << (i + 1) << "题：";
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
        std::cout << "按回车键继续...";
        std::cin.get();
    }

    // 数学考试模式
    void mathTest()
    {
        correctAnswers = 0;
        mathProblems.clear();
        mathProblems.resize(questionNumber);

        std::cout << "开始数学考试！\n\n";

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

            // 构建题目字符串
            mathProblems[i] = std::to_string(firstNumber) +
                              getOperatorString(op) +
                              std::to_string(secondNumber) +
                              " = " +
                              std::to_string(correctResult);

            std::cout << "第" << (i + 1) << "题：";
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
        std::cout << "按回车键继续...";
        std::cin.get();
    }

    // 测试设置
    void testSettings()
    {
        std::cout << "请选择几位数内的运算：";
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
            std::cout << "输入错误，使用默认值\n";
            randomDigits = 10;
            break;
        }

        std::cout << "请设置题目数量：";
        std::cin >> questionNumber;

        if (questionNumber <= 0)
        {
            questionNumber = 5;
            std::cout << "题目数量设置错误，使用默认值5\n";
        }

        std::cout << "请设置总分：";
        std::cin >> totalScore;

        if (totalScore <= 0)
        {
            totalScore = 100;
            std::cout << "总分设置错误，使用默认值100\n";
        }

        std::cout << "设置完成！\n";
        std::cin.ignore();
        std::cout << "按回车键继续...";
        std::cin.get();
    }

    // 保存成绩
    void saveScore()
    {
        try
        {
            std::cout << "请输入您的姓名：";
            std::cin.ignore();

            std::string userName;
            std::getline(std::cin, userName);

            std::ofstream file("Score.txt");
            if (!file.is_open())
            {
                throw std::runtime_error("无法创建成绩文件");
            }

            file << "姓名：" << userName << "\n";
            file << "参考答案：\n";

            for (const auto &problem : mathProblems)
            {
                file << problem << "\n";
            }

            file << "正确题数：" << correctAnswers << "\n";
            file << "错误题数：" << questionNumber - correctAnswers << "\n";

            int finalScore = totalScore - (totalScore / questionNumber) * (questionNumber - correctAnswers);
            file << "成绩：" << finalScore << "\n";

            file.close();
            std::cout << "成绩已保存到 Score.txt 文件中！\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << "保存成绩时出错：" << e.what() << "\n";
        }

        std::cout << "按回车键继续...";
        std::cin.get();
    }

    // 主菜单循环
    void run()
    {
        bool running = true;

        while (running)
        {
            // 清屏（跨平台）
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            std::cout << "数学练习系统\n";
            std::cout << "1. 练习\n";
            std::cout << "2. 测试\n";
            std::cout << "3. 设置\n";
            std::cout << "4. 查看保存成绩\n";
            std::cout << "0. 退出\n";
            std::cout << "请输入您的选择：";

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
                std::cout << "感谢使用数学练习系统！\n";
                break;
            default:
                std::cout << "无效选择，请重新输入！\n";
                std::cin.ignore();
                std::cout << "按回车键继续...";
                std::cin.get();
                break;
            }
        }
    }
};

// 主函数
int main()
{
    try
    {
        auto exerciseSystem = std::make_unique<MathExerciseSystem>();
        exerciseSystem->run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "程序运行出错：" << e.what() << "\n";
        return 1;
    }

    return 0;
}