#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include "nlohmann/json.hpp"

#pragma pack(1)
struct tMapHead
{
	char cFlag[12];
	unsigned int w;
	unsigned int h;
}; // ��������w*h
#pragma pack()

enum eTiledDataType
{
	TILED_TYPE_TILE = 1,
	TILED_TYPE_OBJECT = 2,
};

class CGetCGMap
{
public:
	CGetCGMap();
	~CGetCGMap();

public:
	static CGetCGMap * getInstance()
	{
		static CGetCGMap a;
		return &a;
	}

	void mapProc();

private:
	void init();
	void readAllTile();
	void clearTempData();
	bool readCGMapData(const std::string &strPath, const std::string &strName);

	// ����ͼ��json
	void buildTiledData(std::map<int, int> &mapData, const std::string strName, int tileType);

	// ���ɵ�ͼjson
	void buildTileJson();
	void buildObjJson();
	void bulldBlockJson();
	void buildTiledMap();

private:
	std::string _strPath;
	std::string _strReadPath;
	std::string _strTiledMapPath;
	std::string _strErrFile;
	nlohmann::json _tiledFilesJson;

	tMapHead _mapHead;
	std::string _strMapOnlyName;

	std::string _strTileJsonName;	// tile json�����·��
	nlohmann::json _tileJsonData;	// tile json����
	std::vector<int> _vTileData;	// �ر���Ϣ
	std::map<int, int> _mapTileMap;	// �ر�����ӳ�䣬ӳ��Ϊtiled map��tile�����id

	std::string _strObjJsonName;	// obj json�����·��
	nlohmann::json _objJsonData;	// obj json����
	std::vector<int> _vObjectData; // ʵ�ʾ��ǵڶ���tiled��
	std::map<int, int> _mapObjectMap; // �������ӳ�䣬ӳ��Ϊtiled map��object�����id
};