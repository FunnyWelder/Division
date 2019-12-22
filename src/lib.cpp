#include "lib.h"
#include "cstring"
using namespace std;

void open_file(ifstream &fin, const string name_file)
{
    fin.open(name_file);
    if (!fin.is_open())
    {
        throw invalid_argument("File not found");
    }
}

int length(const char *input)
{
    int i = 0;
    while(input[i] != '\0')
    {
        i++;
    }
    return i;
}

bool CheckForNum(char *input)
{
    for(int i = 0; i < length(input); i++) {
        int c = input[i];
        if ((c == 13) && (i == 0)) {
            return false;
        } else {
            if ((c != 13) && (isdigit(input[i]) == 0)) {
                return false;
            }
        }
    }
    return true;
}

int division_nums(int num_1, int num_2)
{
    if (num_2 == 0)
    {
        throw domain_error("Error! Division by zero");
    }
    else return (num_1 / num_2);
}

int read_nums(ifstream &fin, int &num_1, int &num_2)
{
    int result = 0;
    string str_1;
    string str_2;

    getline(fin, str_1);
    getline(fin, str_2);
    if ((str_1.length() == 1) || (str_2 == "\0"))
    {
        throw runtime_error("Not enough variables");
    }
    else
    {
        char *chr_1 = new char[str_1.size() + 1];
        char *chr_2 = new char[str_2.size() + 1];
        strcpy(chr_1, str_1.c_str());
        strcpy(chr_2, str_2.c_str());
        if ((!CheckForNum(chr_1)) || (!CheckForNum(chr_2)))
        {
            throw invalid_argument("Some line does not contain a number");
        } else {
            num_1 = atoi(chr_1);
            num_2 = atoi(chr_2);
            if (num_2 == 0)
            {
                throw domain_error("Error! Division by zero");
            }
            else result = num_1 / num_2;
        }
    }
    return (result);
}