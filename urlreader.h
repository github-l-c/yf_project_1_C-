#include <iostream>
#include <vector>
#include <string>
#include<tchar.h>
#include <windows.h>

#define OpenFileError 1

//��ȡ�ļ�����ȡurl
int ReadLibraryUrl(std::vector<std::string>&, std::string fileName = "");
//��ȡ��������·��
std::string GetRuningPath();
//��wchar_t* ת��Ϊ string
void Wchar_tToString(std::string& szDst, wchar_t* wchar);