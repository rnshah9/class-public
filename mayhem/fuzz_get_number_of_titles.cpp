#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" int get_number_of_titles(char *titlestring);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    std::string str = provider.ConsumeRandomLengthString(1000);
    char* cstr = strdup(str.c_str());
    get_number_of_titles(cstr);
    free(cstr);
    return 0;
}