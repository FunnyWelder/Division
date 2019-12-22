#include <iostream>
#include "cstring"
#include "lib.h"

using namespace std;

int main()
{
    int num_1 = 0;
    int num_2 = 0;
    int result;
    ifstream inFile;

    try {
        open_file(inFile, "../quest.txt");
        read_nums(inFile, num_1, num_2);

        result = division_nums(num_1, num_2);
        cout << "Result: " << result;
    } catch (invalid_argument &er) {
        cout << "ERR1: "<< er.what();
        return 1;
    } catch (runtime_error &er) {
        cout << "ERR2: "<< er.what();
        return 2;
    } catch (domain_error &er) {
        cout << "ERR3: "<< er.what();
        return 3;
    }
    inFile.close();
    return 0;
}