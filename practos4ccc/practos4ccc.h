#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

wstring reverse(const std::wstring& word) {
    wstring reversed = word;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

wstring removeVowels(const std::wstring& word) {
    wstring result = word;
    result.erase(std::remove_if(result.begin(), result.end(), [](wchar_t c) {
        static const std::wstring vowels = L"aeiou";
        return std::wstring::npos != vowels.find(c);
        }), result.end());
    return result;
}

wstring removeConsonants(const std::wstring& word) {
    wstring result = word;
    result.erase(std::remove_if(result.begin(), result.end(), [](wchar_t c) {
        static const std::wstring consonants = L"bcdfghjklmnpqrstvwxyz";
        return std::wstring::npos != consonants.find(c);
        }), result.end());
    return result;
}

wstring shuffle(const std::wstring& word) {
    wstring shuffled = word;
    random_device rd;
    mt19937 g(rd());
    shuffle(shuffled.begin(), shuffled.end(), g);
    return shuffled;
}

int main() {
    setlocale(LC_ALL, "");

    wstring word;

    wcout << L"������� �����: ";
    wcin >> word;

    int choice;
    wcout << L"�������� ��������:\n"
        << L"1. ����������� �����\n"
        << L"2. ������� �������\n"
        << L"3. ������� ���������\n"
        << L"4. ���������� �����\n";
    wcin >> choice;

    wstring result;
    switch (choice) {
    case 1:
        result = reverse(word);
        break;
    case 2:
        result = removeVowels(word);
        break;
    case 3:
        result = removeConsonants(word);
        break;
    case 4:
        result = shuffle(word);
        break;
    default:
        wcout << L"�������� �����\n";
        return 1;
    }

    wcout << L"���������: " << result << endl;

    return 0;
}
