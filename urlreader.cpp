#include "urlreader.h"
#include <fstream>

void Wchar_tToString(std::string& szDst,  wchar_t* wchar)
{
    wchar_t* wText = wchar;

    // WideCharToMultiByte的运用
    DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);

    // psText为char*的临时数组，作为赋值给std::string的中间变量
    char* psText; 
    psText = new char[dwNum];

    // WideCharToMultiByte的再次运用
    WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);
    szDst = psText;// std::string赋值
    delete[]psText;// psText的清除
}



int ReadLibraryUrl(std::vector<std::string>& libraryUrls, std::string fileName)
{
    std::string filePath;
    //指定路径为空则在程序运行路径查找
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

    //删除文件名，只获得路径 字串
    (_tcsrchr(szPath, _T('\\')))[1] = 0;
    
    std::string strPath;
    Wchar_tToString(strPath, szPath);

    return strPath;
}