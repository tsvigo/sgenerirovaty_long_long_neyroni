//#include <QCoreApplication>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}
//###########################################################################
#include <climits>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    const int NUM_VALUES = 205;
    std::vector<long long> values(NUM_VALUES);

    // Инициализация генератора случайных чисел
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long> dis(LLONG_MIN, LLONG_MAX);

    // Генерация случайных чисел
    for (int i = 0; i < NUM_VALUES; ++i) {
        values[i] = dis(gen);
    }

    // Запись чисел в бинарный файл
    std::ofstream
        outFile("/home/viktor/my_projects_qt_2/sgenerirovaty_long_long_neyroni/random_numbers.bin",
                std::ios::binary);
    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return 1;
    }

    outFile.write(reinterpret_cast<char *>(values.data()), values.size() * sizeof(long long));
    outFile.close();

    if (!outFile) {
        std::cerr << "Ошибка при записи в файл." << std::endl;
        return 1;
    }

    std::cout << "205 случайных чисел записаны в файл 'random_numbers.bin'." << std::endl;
    return 0;
}
