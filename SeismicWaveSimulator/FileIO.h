#pragma once
#include <SDL.h>
#include <string>
#include <json/json.h>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

enum FileMode { RES, DAT, EDIT };
enum FileType { CONFIG };

class FileIO {
public:
	//���� �ּ� ��ȯ �Լ�
	static std::string Location(FileMode f, std::string name, std::string pos = "");
	
	//Json ���� ����
	static Json::Value GetJsonFile(std::string location);

	static std::string OpenFile(FileType type);
};