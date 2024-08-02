#include "../incs/Serializer.hpp"

/* --- static_cast ---
compiler checks if the conversion is reasonable.
it's like having a friend look over your work before you submit it.
*/


/* --- reinterpret_cast ---
compiler doesn't check anything.
it's like submitting your work without proofreading. */


uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t new_data = reinterpret_cast<uintptr_t>(ptr);
    return (new_data);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *data = reinterpret_cast<Data*>(raw);
    return (data);
}
