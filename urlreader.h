#include <iostream>
#include <vector>
#include <string>
#include<tchar.h>
#include <windows.h>

#define OpenFileError 1

//读取文件，获取url
int ReadLibraryUrl(std::vector<std::string>&, std::string fileName = "");
//获取程序运行路径
std::string GetRuningPath();
//将wchar_t* 转换为 string
void Wchar_tToString(std::string& szDst, wchar_t* wchar);