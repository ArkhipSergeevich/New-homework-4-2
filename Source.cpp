#include <iostream>
#include <fstream>
#include <string>

class addresses
{
private:
    std::string city, street;
    int building, flat;
public:
    addresses()
    {
        this->city = city;
        this->street = street;
        this->building = building;
        this->flat = flat;
    }
    void set_city(std::string city_) { city = city_; }
    void set_street(std::string street_) { street = street_; }
    void set_building(int building_) { building = building_; }
    void set_flat(int flat_) { flat = flat_; }
    std::string get_city() { return city; }
    std::string get_street() { return street; }
    int get_building() { return building; }
    int get_flat() { return flat; }
};

int main()
{
    std::ifstream infile("in.txt");
    if (infile.is_open() == 1)
    {
        std::string cty, strt;
        int adr_num, build, fl;
        infile >> adr_num;
        addresses* array = new addresses[adr_num];
        for (int i = 0; i < adr_num; i++)
        {
            infile >> cty >> strt >> build >> fl;
            array[i].set_city(cty);
            array[i].set_street(strt);
            array[i].set_building(build);
            array[i].set_flat(fl);
        }
        for (int i = 0; i < adr_num; i++)
        {
            for (int j = 0; j < adr_num - 1; j++)
            {
                if (array[j].get_city() > array[j + 1].get_city())
                {
                    addresses buff;
                    buff = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = buff;
                }
            }
        }
        std::ofstream outfile("out.txt");
        if (outfile.is_open() == 1)
        {
            outfile << "Количество адресов: " << adr_num << "\n";
            for (int i = 0; i < adr_num; i++)
            {
                outfile << array[i].get_city() << ", ";
                outfile << array[i].get_street() << ", ";
                outfile << array[i].get_building() << ", ";
                outfile << array[i].get_flat() << " \n";
            }
        }
        else
        {
            std::cout << " Файл не открыт!";
        }
        delete[] array;
    }
    else
    {
        std::cout << " Файл не открыт!";
    }
}