// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../include/kafkaclient-cpp.h"

#ifdef _WIN32
#include <iostream>
#include <io.h>
#include <cstring>
#include <Windows.h>
using namespace std;

void listFiles(const char * dir)
{
    using namespace std;
    HANDLE hFind;
    WIN32_FIND_DATA findData;
    LARGE_INTEGER size;
    hFind = FindFirstFile(dir, &findData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        cout << "Failed to find first file!\n";
        return;
    }
    do
    {
        // 忽略"."和".."两个结果 
        if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0)
            continue;
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)    // 是否是目录 
        {
            cout << findData.cFileName << "\t<dir>\n";
        }
        else
        {
            size.LowPart = findData.nFileSizeLow;
            size.HighPart = findData.nFileSizeHigh;
            cout << findData.cFileName << "\t" << size.QuadPart << " bytes\n";
        }
    } while (FindNextFile(hFind, &findData));
    cout << "Done!\n";
}

void gensourcefile(const char *file)
{
#define SOURCE \
"#include \"%s.h\"\n\n"   \
"%s::%s(std::string message)\n"   \
"    : ApiException(message.c_str())\n" \
"{\n\n" \
"}\n"
    char ff[128] = { 0 };
    strcpy(ff, file);
    ff[strlen(ff) - 4] = 0;
    char buffer[128] = { 0 };
    for (int i = 0; i < strlen(ff); i++)
        buffer[i] = toupper(ff[i]);
    char c[2048];
    sprintf(c, SOURCE, ff, ff, ff);

    char filename[1024] = { 0 };
    sprintf(filename, "D:/Windows/kafkaclient-cpp/src/common/exceptions/%s", file);
    FILE *f = fopen(filename, "wb");
    fprintf(f, "%s", c);
    fclose(f);
}

void genheaderfile(const char *file)
{
#define HEADER \
"#ifndef __KFK_%s_H__\n"  \
"#define __KFK_%s_H__\n\n"   \
"#pragma once\n"  \
"#include \"ApiException.h\"\n\n"   \
"class %s\n"  \
"    : public ApiException\n" \
"{\n" \
"public:\n"   \
"    %s() : ApiException(\"\") {}\n" \
"    %s(std::string message);\n"  \
"    virtual ~%s()\n" \
"    {\n\n" \
"    }\n" \
"    static %s* new0()\n"\
"    {\n"   \
"        return new %s();\n"   \
"    }\n"   \
"};\n\n"    \
"#endif // !__KFK_%s_H__\n"

    char ff[128] = { 0 };
    strcpy(ff, file);
    ff[strlen(ff) - 2] = 0;
    char buffer[128] = { 0 };
    for (int i = 0; i < strlen(ff); i++)
        buffer[i] = toupper(ff[i]);
    char c[2048];
    sprintf(c, HEADER, buffer, buffer, ff, ff, ff, ff, ff, ff, buffer);

    char filename[1024] = { 0 };
    sprintf(filename, "D:/Windows/kafkaclient-cpp/src/common/exceptions/%s", file);
    FILE *f = fopen(filename, "wb");
    fprintf(f, "%s", c);
    fclose(f);
}
    
int GetAllFilepathFromfolder(char*  Path)
{
    char szFind[MAX_PATH];
    WIN32_FIND_DATA FindFileData;
    strcpy(szFind, Path);
    strcat(szFind, "\\*.*");//再路劲后加"*.*"标识当前目录下的所有文件和目录
    HANDLE hFind = FindFirstFile(szFind, &FindFileData);
    if (INVALID_HANDLE_VALUE == hFind)
        return -1;

    do
    {
        if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//如果文件属性是目录
        {
            if (strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0)//过滤掉"."和".."目录
            {
                //发现子目录，递归之
                char szFile[MAX_PATH] = { 0 };
                strcpy(szFile, Path);
                strcat(szFile, "\\");
                strcat(szFile, FindFileData.cFileName);
                GetAllFilepathFromfolder(szFile);
            }
        }
        else
        {
            //如果是文件，则直接处理之
            std::string file = FindFileData.cFileName;
            if (strstr(file.c_str(), "ApiException") != NULL ||
                strstr(file.c_str(), "KafkaException") != NULL)
                continue;
            if (file.at(file.length() - 1) == 'h')
            {
                cout << FindFileData.cFileName << std::endl;
                static FILE *f = fopen("aa.txt", "wb");
                fprintf(f, "#include \"%s\"\n", file.c_str());
                fflush(f);
                genheaderfile(file.c_str());
            }
            else
            {
                gensourcefile(file.c_str());
            }
        }
    } while (FindNextFile(hFind, &FindFileData));

    FindClose(hFind);

    return 0;

}
#endif

int main()
{
    //GetAllFilepathFromfolder("D:/Windows/kafkaclient-cpp/src/common/exceptions");
    test();
    return 0;
}