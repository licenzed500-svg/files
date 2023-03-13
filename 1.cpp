//Вариант6 задача 2b

#include <iostream>
#include <fstream>
#include <string>


void print_singerName(char *singer_name, const short* NAME_SIZE)
{
    std::cout << "\nSinger name is: "; 
    for (short i = 0; i < *NAME_SIZE; i++)
    {
        std::cout << singer_name[i];
    }
    std::cout << "\n";
}


void read_singerName(char *buffer, const short *NAME_SIZE,const short *BIAS, char *singer_name)
{
    for (short i = 0; i < *NAME_SIZE; i++)
    {
        singer_name[i] = buffer[i + *BIAS];
    }
}


int main()
{
    const short NAME_SIZE = 30;
    const short BUFFER_SIZE = 128;
    const short BIAS = 33;

    char singer_name[NAME_SIZE];
    char buffer[BUFFER_SIZE];

    std::ifstream file("1.mp3", std::ios::in || std::ios::binary);
    if (file.is_open())
    {
       std::cout << "\nfile is open\n\n";
       file.seekg(-128, std::ios::end);
       file.read(buffer,128);
       read_singerName(buffer, &NAME_SIZE, &BIAS, singer_name);
       print_singerName(singer_name, &NAME_SIZE);
    }
}

