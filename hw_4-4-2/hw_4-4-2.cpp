#include <fstream>
#include <iostream>
#include <string>

class Address {

private:
    std::string city;
    std::string street;
    int building;
    int flat;

public:
    Address(std::string city, std::string street, int building, int flat) {
        this->city = city;
        this->street = street;
        this->building = building;
        this->flat = flat;
    }
    Address() {
        std::string city = "unknown";
        std::string street = "unknown";
        int building = 0;
        int flat = 0;
    }
    std::string get_output_address() {
        std::string build_str = std::to_string(building);
        std::string flat_str = std::to_string(flat);
        return city + ", " + street + ", " + build_str + ", " + flat_str + "\n";
    }

    static void sort(Address* adr_arr, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (adr_arr[i].get_output_address() < adr_arr[j].get_output_address()) {
                    std::swap(adr_arr[i], adr_arr[j]);
                }
            }
        }
    } 
};


int main() {
    std::string city = "unknown";
    std::string street = "unknown";
    int building = 0;
    int flat = 0;

    std::ifstream in("in.txt");
    std::ofstream out("out.txt");
    int size = 0;
    in >> size;
    out << size << std::endl;
    
    Address* adr_arr = new Address[size];
    for (int i = 0; i < size; i++) {
        in >> city >> street >> building >> flat;
        adr_arr[i] = Address(city, street, building, flat);
    }
    
    adr_arr->sort(adr_arr, size);

    for (int i = 0; i < size; i++) {
        out << adr_arr[i].get_output_address();
    }

    delete[] adr_arr;
    in.close();
    out.close();
}