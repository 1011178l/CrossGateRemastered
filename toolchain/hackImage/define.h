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
}; // + char* len = size - 16

#pragma pack()

#define MAX_IMG_SIZE (1024*1024)

#define DEFAULT_CPG_LEN 768		// ��ɫ���ļ�����256ɫ��ÿ����ɫ3���ֽڴ洢BGR
// ��Ϸָ���ĵ�ɫ��0-15 BGR
__declspec(selectany) unsigned char g_c0_15[] = {
	0x00, 0x00, 0x00,
	0x80, 0x00, 0x00,
	0x00, 0x80, 0x00,
	0x80, 0x80, 0x00,
	0x00, 0x00, 0x80,
	0x80, 0x00, 0x80,
	0x00, 0x80, 0x80,
	0xc0, 0xc0, 0xc0,
	0xc0, 0xdc, 0xc0,
	0xa6, 0xca, 0xf0,
	0xde, 0x00, 0x00,
	0xff, 0x5f, 0x00,
	0xff, 0xff, 0xa0,
	0x00, 0x5f, 0xd2,
	0x50, 0xd2, 0xff,
	0x28, 0xe1, 0x28,
};
// ��Ϸָ���ĵ�ɫ��240-255 BGR
__declspec(selectany) unsigned char g_c240_245[] = {
	0xf5, 0xc3, 0x96,
	0x1e, 0xa0, 0x5f,
	0xc3, 0x7d, 0x46,
	0x9b, 0x55, 0x1e,
	0x46, 0x41, 0x37,
	0x28, 0x23, 0x1e,
	0xff, 0xfb, 0xf0,
	0x3a, 0x6e, 0x5a,
	0x80, 0x80, 0x80,
	0xff, 0x00, 0x00,
	0x00, 0xff, 0x00,
	0xff, 0xff, 0x00,
	0x00, 0x00, 0xff,
	0xff, 0x80, 0xff,
	0x00, 0xff, 0xff,
	0xff, 0xff, 0xff,
};

// ͼƬ������ͼƬ��Ķ��ձ�
// �Ѿ���������ͼƬ��
// Anime��ͷ���൱����ָ�����¿�Ķ������൱���������ļ�������Ͳ������ˣ���Ҫ�Բ���
__declspec(selectany) std::unordered_map<std::string, std::string> g_ImgMap = {
	{ "GraphicInfo_20.bin", "Graphic_20.bin" },			// ���˵Ŀ�����
	{ "GraphicInfo_Joy_22.bin", "Graphic_Joy_22.bin" },	// ��԰֮��
	{ "GraphicInfoEx_4.bin", "GraphicEx_4.bin" },		// ��֮ɳʱ��
	{ "GraphicInfoV3_18.bin", "GraphicV3_18.bin" }, // ��԰֮�ѣ�����
	{ "Puk2\\GraphicInfo_PUK2_2.bin", "Puk2\\Graphic_PUK2_2.bin"},
	{ "Puk3\\GraphicInfo_PUK3_1.bin", "Puk3\\Graphic_PUK3_1.bin" },
};