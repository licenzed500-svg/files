

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

void read_variable(std::ifstream *file, short *ch, short *step, short *start_point, short *final_point)
{
    *file >> *ch;
    *file >> *step;
    *file >> *start_point;
    *file >> *final_point;
}

void write_variables(std::ofstream *file, std::vector<int> &y_variables)
{
    for(auto i = 0; i<y_variables.size(); i++)
    {
        *file << "X" << i << " " << y_variables[i] << "\n";
    }
}

void tabulate_function(std::vector<int> &y_variables, short *ch, short *step, short *start_point, short *final_point)
{
    bool is_negative = true;
    
    int x = 0;
    for(short i = *start_point; i<*final_point; i+=*step)
    {
        x = *step*(*ch);
        y_variables.push_back(x);
    }
    for(auto i = 0; i<y_variables.size(); i++)
    {
        if(is_negative)
        {
            y_variables[i]-=y_variables[i+1];
            is_negative = false;
        }
        else
        {
            y_variables[i]+=y_variables[i+1];
            is_negative = true;
        }
    }
}

int main() {
    short ch = 0;
    short step = 0;
    short start_point = 0;
    short final_point = 0;
    
    std::vector<int> y_variables;
    
    std::ifstream input("in.txt");
    std::ofstream out("out.txt");
    if(input.is_open())
    {
        std::cout << "\nfile is open\n";
        read_variable(&input, &ch, &step, &start_point, &final_point);
        tabulate_function(y_variables, &ch, &step, &start_point, &final_point);
        write_variables(&out, y_variables);
    }
}
