#pragma once
#include <string.h>
#include <fstream>

namespace cesaoEngine
{
    std::string readFile(const char* pFilePath)
    {
        FILE* lFile = fopen(pFilePath, "rt");

        fseek(lFile, 0, SEEK_END);

        unsigned long lLength = ftell(lFile);

        char* lData = new char[lLength + 1];

        memset(lData, 0, lLength + 1);

        fseek(lFile, 0, SEEK_SET);

        fread(lData,1,lLength, lFile);

        fclose(lFile);
        std::string lResult(lData);
        
        delete[] lData;

        return lResult;
    }
};