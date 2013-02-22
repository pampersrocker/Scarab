#pragma once

#include <string>

namespace zip
{
	typedef std::wstring String_t;

	namespace CompressionLevel
	{
		enum Enum
		{
			  NO_COMPRESSION         = 0
			, BEST_SPEED             = 1
			, BEST_COMPRESSION       = 9
			, DEFAULT_COMPRESSION    = -1
		};
	}

	class ZipArchiveOutput
	{
	public:
		ZipArchiveOutput( String_t const& archiveName, bool utf8fileNames, int compressionLevel );

		void WriteFile( String_t const& fileName, const void* pMemoryBlock, size_t size );
		void Close();

	private:
		String_t m_archiveName;
		bool m_utf8fileNames;
		
		int err;
		const char* password;
		int opt_compress_level;
		int errclose;

		typedef void* ZipFile_t;
		ZipFile_t zf;
	};
}
