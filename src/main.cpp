#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cstring>

#include "log.h"
#include "DtaOptions.h"
#include "DtaStructures.h"
#include "DtaAnnotatedDump.h"


sedutiloutput outputFormat = sedutilReadable;
static uint16_t loggingLevel = 3;


int main(int argc, char* argv[])
{
    CLog::Level() = CLog::FromInt(loggingLevel);
    RCLog::Level() = RCLog::FromInt(loggingLevel);

    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <file_name> <cmd>" << std::endl;
        std::cerr << "cmd options: IF_RECV, IF_SEND, IDENTIFY" << std::endl;
        return 1;
    }

    ATACOMMAND cmd;
    std::string cmdArg = argv[2];
    if (cmdArg == "IF_RECV") cmd = IF_RECV;
    else if (cmdArg == "IF_SEND") cmd = IF_SEND;
    else if (cmdArg == "IDENTIFY") cmd = IDENTIFY;
    else
    {
        std::cerr << "Error: Invalid cmd argument. Use IF_RECV, IF_SEND, or IDENTIFY." << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::vector<uint8_t> buffer;
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    if (size <= 0)
    {
        std::cerr << "Error: File is empty or invalid." << std::endl;
        return 1;
    }
    buffer.resize(static_cast<size_t>(size));
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
    {
        std::cerr << "Error: Could not read file contents." << std::endl;
        return 1;
    }
    file.close();

    uint8_t result = DtaAnnotatedDump(cmd, buffer.data(), static_cast<uint32_t>(buffer.size()));
    std::cout << "DtaAnnotatedDump result: " << static_cast<int>(result) << std::endl;
    return 0;
}
