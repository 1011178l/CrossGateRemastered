#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "define.h"

class CGetCGImage
{
public:
	CGetCGImage();
	~CGetCGImage();

public:
	void doRun();

private:
	void clearData();
	void readCgp();
	void readInfo(const std::string &strInfo);
	void readAndSaveImg(const std::string &strName);

private:
	int decodeImgData(unsigned char *p, int len, int cgpLen, std::vector<unsigned char>& v, int realLen);
	void saveImgData(const std::string &cgpName, std::vector<int>* pCgpData, const std::string &strPath, const imgInfoHead &tHead, const std::vector<unsigned char> &vPixes);

	bool isNewFormat(const std::string &strName)
	{
		if (strName == "Graphic_20.bin" || strName == "GraphicEx_4.bin")
			return false;

		return true;
	}

private:
	std::string _strPath;	// ����·��
	std::unordered_map<std::string, std::vector<int>> _uMapCgp; // ��ɫ��
	std::vector<imgInfoHead> _vecImginfo; // ͼƬ����
};