#include <iostream>
#include <algorithm>

#include "List.h"
#include "Trapezoid.h"
#include "accessory.h"

using f_type = int;

int main() {
    std::string cmd;
    std::vector<std::string> out;
    std::stringstream buffer;
    List<Trapezoid<f_type>> list;
    help();
    while (true){
        getline(std::cin, cmd);
        std::vector<std::string> cmd_array = split(cmd,' ');
        if (cmd_array[0] == "exit"){
            break;
        }
        else if (cmd_array[0] == "help"){
            help();
        }
        else if (cmd_array[0] == "delete"){
            size_t index = string_to_int(cmd_array[1]);
            list.erase_by_index(index);
        }
        else if (cmd_array[0] == "show"){
            std::for_each(list.begin(), list.end(), [](Trapezoid<f_type>& T) { std::cout << T; });
        }
        else if (cmd_array[0] == "less"){
            double S = string_to_double(cmd_array[1]);
            std::cout <<
            std::count_if(list.begin(), list.end(), [=](Trapezoid<f_type>& T) { return T.get_square() < S; })
            << std::endl;
        }
        else {
            std::vector<std::string> array = split(cmd,' ');
            std::vector<std::pair<f_type,f_type>> numbers_double(EDGES_COUNT);
            int j = 0;
            for(size_t i = 0;i < numbers_double.size() * 2 ; i += 2){
                numbers_double[j] = {string_to_double(array[i]),string_to_double(array[i+1])};
                j++;
            }
            Trapezoid<f_type> tr(numbers_double);
            list.insert_by_index(list.length(),tr);
        }
    }
    return 0;
}
