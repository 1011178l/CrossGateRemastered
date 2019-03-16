/**
 * һЩͨ�õĺ�����װ
 */

#pragma once

#include <windows.h>
#include <stdio.h>
#include <iostream>

#define SAFE_DELETE(p) { if (p) {delete p; p = nullptr; }}
#define SAFE_DELETE_A(p) { if (p) {delete[] p; p = nullptr; }}

// ֻ�Ǽ���־���ͷ��������
enum eLogLevel
{
	LOG_NORMAL = 0,
	LOG_INFO,
	LOG_ERROR
};

__declspec(selectany) eLogLevel g_logLevel = LOG_ERROR;

namespace Utils
{
	// ȥ��֮���'\\'
	inline std::string extractFileDir(const std::string& strFullPath)
	{
		std::string strDir;
		int nPos = (int)strFullPath.rfind('\\');
		if (nPos != -1)
			strDir = strFullPath.substr(0, nPos);

		return std::move(strDir);
	}

	// ���Ŀ¼�Ƿ����
	inline bool dirExists(LPCSTR szDir)
	{
		DWORD dwRet = GetFileAttributesA(szDir);
		return ((dwRet != 0xFFFFFFFF) && ((FILE_ATTRIBUTE_DIRECTORY & dwRet) != 0));
	}

	// ȷ���ļ��д��ڣ�û���򴴽�
	inline void makeSureDirExsits(const std::string& strDir)
	{
		if (Utils::dirExists(strDir.c_str()))
			return;

		// �ݹ鴦��
		Utils::makeSureDirExsits(extractFileDir(strDir));
		::CreateDirectoryA(strDir.c_str(), nullptr);
	}

	inline std::string getExePath()
	{
		// ��ȡ����·��
		char szFullPath[MAX_PATH] = { 0 };
		::GetModuleFileNameA(nullptr, szFullPath, MAX_PATH);
		std::string str = szFullPath;
		return Utils::extractFileDir(str);
	}

	// ����׺��
	inline std::string getFileName(const std::string &strName)
	{
		std::string strOut = strName;
		auto i = strName.find_last_of('\\');
		if (i != std::string::npos)
			strOut = strOut.substr(i + 1);
		
		return std::move(strOut);
	}

	// �޺�׺��
	inline std::string getFileNameNoExt(const std::string &strName)
	{
		std::string strOut = strName;
		auto i = strName.find_last_of('\\');
		if (i != std::string::npos)
			strOut = strOut.substr(i + 1);

		auto j = strName.find_last_of('.');
		if (j != std::string::npos)
			strOut = strOut.substr(0, j);

		return std::move(strOut);
	}

	// ���������Ϣ
	inline void saveError(eLogLevel logLevel, const std::string &strFile, const std::string &err)
	{
		if (logLevel < g_logLevel)
			return;

		std::string str;
		switch (logLevel)
		{
		case LOG_NORMAL: str = "@@@normal " + err; break;
		case LOG_INFO: str = "---info " + err; break;
		case LOG_ERROR: str = "!!!ERROR " + err; break;
		default:
			break;
		}

		FILE *pFile = nullptr;
		if (0 != fopen_s(&pFile, strFile.c_str(), "a"))
			return;

		str += "\n";
		fwrite(str.c_str(), 1, str.length(), pFile);
		fclose(pFile);
	}

	// խ�ַ�ת���ַ�
	inline std::wstring StrToWStr(const std::string& str, UINT dwCodePage = CP_THREAD_ACP)
	{
		std::wstring strDest;
		int nSize = ::MultiByteToWideChar(dwCodePage, 0, str.c_str(), -1, 0, 0);
		if (nSize > 0)
		{
			WCHAR* pwszDst = new WCHAR[nSize];
			::MultiByteToWideChar(dwCodePage, 0, str.c_str(), -1, pwszDst, nSize);
			strDest = pwszDst;
			SAFE_DELETE_A(pwszDst);
		}
		return strDest;
	}
};