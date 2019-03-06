#pragma once

#include <unordered_map>
#include <string>

#pragma pack(1)
// *info*.bin �ļ���ʽ
struct imgInfoHead
{
	unsigned int id;
	unsigned int addr;  // ��ͼ���ļ��е�ƫ��
	unsigned int len;	// ����
	long xOffset;		// ����Ϸ�ڵ�ƫ����x
	long yOffset;		// ����Ϸ�ڵ�ƫ����y
	unsigned int width;
	unsigned int height;
	unsigned char tileEast;	// ��ͼ�Ϻ��򼸸�
	unsigned char tileSouth;// ���򼸸�
	unsigned char flag;
	unsigned char unKnow[5];
	long tileId;			// �����ĵ�ͼtile��id
};

// ͼ��bin �ļ���ʽ
struct imgData
{
	unsigned char cName[2];
	unsigned char cVer;	// 1ѹ��
	unsigned char cUnknow;
	unsigned int width;
	unsigned int height;
	unsigned int len;	// ��������ͷ���ܳ��ȣ�������char����
	unsigned int cgpLen; // ��ɫ�峤��
}; // + char* len = size - 16

// ��ɫ�� *.cgp�ļ���ʽ��708�ֽڣ�236ɫ
// idx=1����ɫ��Ӧ��Ϸ�ڵı��Ϊ16��Ҳ����cgp�洢16-252ɫ
struct cgpData
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
};

#pragma pack()

// ͼƬ������ͼƬ��Ķ��ձ�
__declspec(selectany) std::unordered_map<std::string, std::string> g_ImgMap = {
 	{ "GraphicInfo_20.bin", "Graphic_20.bin" },			// ���˵Ŀ�����
// 	{ "GraphicInfo_Joy_22.bin", "Graphic_Joy_22.bin" },	// ��԰֮�� [TODO]
 	{ "GraphicInfoEx_4.bin", "GraphicEx_4.bin" },		// ��֮ɳʱ��
// 	{ "GraphicInfoV3_18.bin", "GraphicV3_18.bin" }, // ��԰֮�ѣ����飩 [TODO]
};