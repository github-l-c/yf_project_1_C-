#include "urlreader.h"
#include <fstream>

void Wchar_tToString(std::string& szDst,  wchar_t* wchar)
{
    wchar_t* wText = wchar;

    // WideCharToMultiByte������
    DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);

    // psTextΪchar*����ʱ���飬��Ϊ��ֵ��std::string���м����
    char* psText; 
    psText = new char[dwNum];

    // WideCharToMultiByte���ٴ�����
    WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);
    szDst = psText;// std::string��ֵ
    delete[]psText;// psText�����
}



int ReadLibraryUrl(std::vector<std::string>& libraryUrls, std::string fileName)
{
    std::string filePath;
    //ָ��·��Ϊ�����ڳ�������·������
    if (fileName.length() == 0)
    {
        filePath = GetRuningPath() +"\\UrlConfig.ini";
    }
    else
    {
        filePath = fileName;
    }

    std::ifstream file;
    file.open(filePath, std::ios::in);

    if (!file.is_open())
        return OpenFileError;

    std::string strLine;
    while (getline(file, strLine))
    {
        if (strLine.empty())
            continue;
        libraryUrls.push_back(strLine);
    }
    return 0;
}
std::string GetRuningPath()
{
    wchar_t szPath[MAX_PATH + 1] = { 0 };
    GetModuleFileName(NULL, szPath, MAX_PATH);

    //ɾ���ļ�����ֻ���·�� �ִ�
    (_tcsrchr(szPath, _T('\\')))[1] = 0;
    
    std::string strPath;
    Wchar_tToString(strPath, szPath);

    return strPath;
}