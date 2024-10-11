#include <iostream>
#include <cctype> 
using namespace std;

/*int main() {
    char symbol;
    cout << "Введіть символ: ";
    cin >> symbol;

    if (isalpha(symbol)) {
        cout << "Це літера.\n";
    }
    else if (isdigit(symbol)) {
        cout << "Це цифра.\n";
    }
    else if (ispunct(symbol)) {
        cout << "Це знак пунктуації.\n";
    }
    else {
        cout << "Це інший символ.\n";
    }

    return 0;
}*/

/*int main() {
    double baseCost, finalCost;
    int fromOperator, toOperator;

    cout << "Введіть базову вартість розмови за хвилину (грн): ";
    cin >> baseCost;

    cout << "Виберіть оператора, з якого здійснюється дзвінок:\n";
    cout << "1 - Kyivstar\n";
    cout << "2 - Vodafone\n";
    cout << "3 - Lifecell\n";
    cout << "Ваш вибір: ";
    cin >> fromOperator;

    cout << "Виберіть оператора, на який здійснюється дзвінок:\n";
    cout << "1 - Kyivstar\n";
    cout << "2 - Vodafone\n";
    cout << "3 - Lifecell\n";
    cout << "Ваш вибір: ";
    cin >> toOperator;

    // Визначення вартості розмови в залежності від оператора
    if (fromOperator == toOperator) {
        finalCost = baseCost * 1.0;  // Внутрішньомережеві дзвінки за базовою вартістю
    }
    else if ((fromOperator == 1 && toOperator == 2) || (fromOperator == 2 && toOperator == 1)) {
        finalCost = baseCost * 1.2;  // Дзвінок між Kyivstar і Vodafone
    }
    else if ((fromOperator == 1 && toOperator == 3) || (fromOperator == 3 && toOperator == 1)) {
        finalCost = baseCost * 1.3;  // Дзвінок між Kyivstar і Lifecell
    }
    else if ((fromOperator == 2 && toOperator == 3) || (fromOperator == 3 && toOperator == 2)) {
        finalCost = baseCost * 1.25; // Дзвінок між Vodafone і Lifecell
    }
    else {
        cout << "Неправильний вибір оператора.\n";
        return 1;
    }

    cout << "Вартість розмови: " << finalCost << " грн за хвилину.\n";
    return 0;
}*/

int main() {
    int choice;
    double incomePer100Lines = 50.0;
    double latePenalty = 20.0;

    cout << "Меню:\n";
    cout << "1. Розрахувати, скільки рядків коду треба написати для досягнення бажаного доходу\n";
    cout << "2. Розрахувати, скільки разів можна запізнитися, щоб досягти бажаного доходу\n";
    cout << "3. Визначити, скільки грошей заплатять Васі та чи заплатять взагалі\n";
    cout << "Виберіть опцію (1, 2 або 3): ";
    cin >> choice;

    switch (choice) {
    case 1: {
        double desiredIncome;
        int lates;
        cout << "Введіть бажаний дохід (у $): ";
        cin >> desiredIncome;
        cout << "Введіть кількість запізнень: ";
        cin >> lates;
        double totalPenalty = (lates / 3) * latePenalty;
        int linesNeeded = (desiredIncome + totalPenalty) / incomePer100Lines * 100;
        cout << "Васі потрібно написати " << linesNeeded << " рядків коду, щоб досягти бажаного доходу.\n";
        break;
    }
    case 2: {
        int linesWritten;
        double desiredIncome;
        cout << "Введіть кількість рядків коду, написаних Васею: ";
        cin >> linesWritten;
        cout << "Введіть бажаний обсяг зарплати (у $): ";
        cin >> desiredIncome;
        double baseIncome = (linesWritten / 100) * incomePer100Lines;
        int maxLates = (baseIncome - desiredIncome) / latePenalty * 3;
        if (maxLates >= 0) {
            cout << "Вася може запізнитися максимум " << maxLates << " разів.\n";
        }
        else {
            cout << "Вася не може досягти бажаного обсягу зарплати з такою кількістю рядків коду.\n";
        }
        break;
    }
    case 3: {
        int linesWritten, lates;
        cout << "Введіть кількість рядків коду, написаних Васею: ";
        cin >> linesWritten;
        cout << "Введіть кількість запізнень: ";
        cin >> lates;
        double baseIncome = (linesWritten / 100) * incomePer100Lines;
        double totalPenalty = (lates / 3) * latePenalty;
        double finalIncome = baseIncome - totalPenalty;
        if (finalIncome > 0) {
            cout << "Васі заплатять " << finalIncome << " $.\n";
        }
        else {
            cout << "Васі нічого не заплатять через штрафи.\n";
        }
        break;
    }
    default:
        cout << "Неправильний вибір. Будь ласка, виберіть 1, 2 або 3.\n";
        break;
    }

    return 0;
}

