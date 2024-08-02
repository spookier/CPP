#include "../incs/Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Alex";
    
    uintptr_t serialized_res = Serializer::serialize(&data);
    Data *deserialized_res = Serializer::deserialize(serialized_res);

    std::cout << "Original data addr:       " << &data <<
        " | contains: " << data.id << " " << data.name << std::endl;


    std::cout << "Original data addr:       " << deserialized_res <<
        " | contains: " << deserialized_res->id << " " << deserialized_res->name << std::endl;
}