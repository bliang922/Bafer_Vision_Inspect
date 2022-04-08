#include "FileEncoder.h"
#include <fstream>      // std::ofstream

CFileEncoder::CFileEncoder(const wstring& fullfilepath)
{
	m_pathname = fullfilepath;
	size_t found = m_pathname.find_last_of(L'.');
	if(found != string::npos) {
		m_extension = m_pathname.substr(m_pathname.find_last_of('.') + 1);
		transform(m_extension.begin(), m_extension.end(), m_extension.begin(), ::tolower);
	}
	else
		m_extension = L"";
}

bool CFileEncoder::EncodeTextFile(const string& tempsequence)
{
	ofstream outfile(m_pathname);
	if(tempsequence.length() > 0)
		outfile << tempsequence;
	outfile.close();
	return outfile.good();
}

bool CFileEncoder::EncodeFastaFile(const string& tempsequence)
{
	ofstream outfile(m_pathname);
	outfile << '>';
	if (tempsequence.length() > 0)
		outfile << tempsequence;
	outfile << '\n';
	outfile.close();
	return outfile.good();
}

bool CFileEncoder::EncodeGenBankFile(const string& tempsequence)
{
	ofstream outfile(m_pathname);
	outfile << "ORIGIN";
	if (tempsequence.length() > 0)
		outfile << tempsequence;
	outfile << "//";
	outfile.close();
	return outfile.good();
}

bool CFileEncoder::EncodeGCGFile(const string& tempsequence)
{
	ofstream outfile(m_pathname);
	outfile << "..";
	if (tempsequence.length() > 0)
		outfile << tempsequence;
	outfile << '\0';
	outfile.close();
	return outfile.good();
}

bool CFileEncoder::EncodeDNAtoolsFile(const string& tempsequence, char type, char form, const string& comment, const string& applicationName, const string& version)
{
	// applicationInfo : "DNAssist;version beta 3"
	const char separator = ';';
	ofstream outfile(m_pathname);
	outfile << applicationName << separator;
	outfile << version << separator;
	outfile << type << separator;
	outfile << form << separator;
	outfile << comment << separator;
	if (tempsequence.length() > 0)
		outfile << tempsequence;
	return outfile.good();
}

unsigned char CFileEncoder::CompressCharactersIntoByte(const string& threebases)
{
	unsigned char currByte = 128; // Set bit 7;
	int bit;
	int shifted_bits;
	auto it = threebases.cbegin();

	int x = 0;
	while(it != threebases.cend()) {
		bit = EncodeDNAOrRNABase(*it);
		shifted_bits = bit<<(2*(threebases.length() - (x++) - 1));
		currByte = (unsigned char)(currByte | shifted_bits);
		++it;
	}

	if(threebases.length() < 3) {
		currByte = (unsigned char)(currByte | 64);
		if(threebases.length() < 2)
			currByte = (unsigned char)(currByte | 32);
	}

	return currByte;
}

int CFileEncoder::EncodeDNAOrRNABase(char base)
{
	switch(base)
	{
		case 'G' : return 0;
		case 'A' : return 1;
		case 'T' :
		case 'U' : return 2;
		case 'C' : return 3;
		default : return -1;
	}
}

bool CFileEncoder::WriteFile(const string& sequence, char type, char form, const string& comments, const string& applicationName, const string& version)
{
	if (m_extension == L"fas")
		return EncodeFastaFile(sequence);
	if (m_extension == L"gbk")
		return EncodeGenBankFile(sequence);
	if (m_extension == L"gcg")
		return EncodeGCGFile(sequence);
	if (m_extension == L"seq")
		return EncodeDNAtoolsFile(sequence, type, form, comments, applicationName, version);

	return EncodeTextFile(sequence);
}
