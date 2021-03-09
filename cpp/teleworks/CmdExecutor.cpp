#include "BuildPlatform.h"
#include "CmdExecutor.h"
#include "utils.h"
#include <sys/stat.h>
#include <thread>


CmdExecutor::CmdExecutor()
{
    m_retCode = 0;
    m_resPath = "";
    m_fsize = 0;
}

CmdExecutor::~CmdExecutor()
{

}

size_t CmdExecutor::get_result_file_size() const
{
    return m_fsize;
}

std::string CmdExecutor::get_result_file_name() const
{
    return m_resPath;
}

int CmdExecutor::get_result_code() const
{
    return m_retCode;
}

bool CmdExecutor::capture_camera_oneshot()
{
	struct stat file_info;
	char buf[PATH_MAX];
    bool result = false;

#if defined (DQ1_MACHINE)
	std::string path = getApplicationDirectory();
	path += "/mod_test_app";
	std::cout << "camera path= " << path << std::endl;
	int ret = system(path.c_str());
#else
	int ret = system("streamer -f jpeg -s 640x480 -o /tmp/testimg.jpeg");
	system("ls -al /tmp/testimg.jpeg");
#endif
	if (ret != -1)
	{
#if defined (DQ1_MACHINE)
		path = getApplicationDirectory();
		path += "/tmp.jpeg";
		sprintf(buf, "%s", path.c_str());
#else
		sprintf(buf, "/tmp/testimg.jpeg");
#endif
		m_resPath = buf;
		if (-1 == stat(buf, &file_info))
		{
			std::cout << "fail to get file size " << m_resPath << std::endl;
			m_fsize = 0;
			m_retCode = 10;
		}
		else
		{
			std::cout << " -> image file name : " << m_resPath << std::endl;
			m_fsize = file_info.st_size;
			std::cout << " -> image file size  = " << m_fsize << " bytes" << std::endl;
			m_retCode = 11;

            result = true;
		}
	}
	else
	{
		std::cout << "fail to execute camera function" << std::endl;
		m_resPath = "";
		m_fsize = 0;
		m_retCode = 10;
	}

	return result;
}

bool CmdExecutor::record_voice_mircophone()
{
    struct stat file_info;
    bool result = false;
	int ret;
    
#if defined (DQ1_MACHINE)
	ret = system("arecord -t wav -r 16000 -f S16_LE -c 4 -d 5 -D plughw:0,2 /tmp/a1234.wav");
#else
	ret = system("arecord -t wav -r 16000 -f S16_LE -c 4 -d 5 -D plughw:0,0 /tmp/a1234.wav");
#endif
	if (ret != -1)
	{
		m_resPath = "/tmp/a1234.wav";
		if (-1 == stat(m_resPath.c_str(), &file_info))
		{
			std::cout << "fail to get file size a1234.wav" << std::endl;
			m_fsize = 0;
			m_retCode = 20;
		}
		else
		{
			m_fsize = file_info.st_size;
			std::cout << " -> audio file size (" << m_resPath << ") = " << m_fsize << " bytes" << std::endl;
			m_retCode = 21;

			// Let's separate the channels from mic recorded file.
			std::thread thr(CmdExecutor::thread_func, std::ref(m_resPath));
			thr.join();

            result = true;
		}
	}
	else
    {
		m_resPath = "";
        std::cout << "No supported service or fail to execute" << std::endl;
		m_retCode = 20;
	}

    return result;
}

bool CmdExecutor::play_microphone_voice( int ch )
{
	struct stat file_info;
	bool result = false;
	int ret;
	char cmdline[128];
	std::string voicefname;

#if defined (DQ1_MACHINE)
	//ret = system("aplay -t raw -r 16000 -f S16_LE -c 1 -B 1 -D plughw:0,0 /tmp/12345.pcm");
	if (ch > 0 && ch <= 4) {
		voicefname = stringFormat("-t raw -r 16000 -f S16_LE -c 1 -B 1 -D plughw:0,0 /tmp/a1234.%d.wav", ch);
	}
	else {
		voicefname = "/tmp/a1234.wav";
	}
	m_resPath = voicefname;
	sprintf(cmdline, "aplay %s", voicefname.c_str());
	ret = system(cmdline);
#else
    voicefname = "/tmp/a1234.wav";
    m_resPath = voicefname;
	sprintf(cmdline, "aplay %s", voicefname.c_str());
	ret = system(cmdline);
#endif
	if (ret != -1)
	{
		if (-1 == stat(m_resPath.c_str(), &file_info))
		{
			std::cout << "fail to get file size " << m_resPath << std::endl;
			m_fsize = 0;
			m_retCode = 20;
		}
		else
		{
			m_fsize = file_info.st_size;
			std::cout << " -> audio file size = " << m_fsize << " bytes" << std::endl;
			m_retCode = 22;

            result = true;
		}
	}
	else
	{
        std::cout << "No supported service or fail to execute" << std::endl;
		m_retCode = 20;
	}

	return result;
}

bool CmdExecutor::speaker_sound(int type)
{
	struct stat file_info;
	bool result = false;
	char cmdline[128];

	std::string parent_path = getApplicationDirectory();
	std::vector<std::string> v_dirnames = tokenize_getline(parent_path, '/');

	std::string res_path, destFile;
	for (size_t i = 0; i < v_dirnames.size() - 1; i++)
	{
		res_path += v_dirnames[i];
		res_path += "/";
	}
	res_path += "res";
	std::cout << "  > res path=" << res_path << std::endl;

	switch (type)
	{
		case 1:	m_resPath = res_path + "/HalfwayHome-L.wav";	break;
		case 2: m_resPath = res_path + "/HalfwayHome-R.wav";	break;
		default: m_resPath.clear();								break;
	}

	if (m_resPath.size() > 0)
	{
#if defined (DQ1_MACHINE)
		sprintf(cmdline, "aplay -r 48000 -c 1 -B 1 -D plughw:0,0 %s", m_resPath.c_str());
#else
		sprintf(cmdline, "aplay %s", m_resPath.c_str());
#endif
		int r = system(cmdline);
		if (r != -1) {
			m_retCode = 31;
			if (stat(m_resPath.c_str(), &file_info) >= 0) {
				m_fsize = file_info.st_size;
                result = true;
			}
		}
	}
	else
	{
		std::cout << "[SPK sound] not supported.." << std::endl;
		m_retCode = 30;
		m_fsize = 0;
	}

	return result;
}

bool CmdExecutor::tof_measure_distance( )
{
	struct stat file_info;
	bool result = false;

	std::string path = getApplicationDirectory();
	path += "/tofCAPI";
	std::cout << "ToF exe file path= " << path << std::endl;
	int ret = system(path.c_str());

	if (ret != -1)
	{
		path.clear();
		path = "/tmp/depthZ.txt";

		m_resPath = path;
		if (-1 == stat(path.c_str(), &file_info))
		{
			std::cout << "fail to get file size " << m_resPath << std::endl;
			m_fsize = 0;
			m_retCode = 40;
		}
		else
		{
			std::cout << " -> distance file name : " << m_resPath << std::endl;
			m_fsize = file_info.st_size;
			std::cout << " -> file size  = " << m_fsize << " bytes" << std::endl;
			m_retCode = 41;

            result = true;
		}
	}
	else
	{
		std::cout << "fail to execute tof function" << std::endl;
		m_resPath = "";
		m_fsize = 0;
		m_retCode = 40;
	}

	return result;
}

template<typename ... Args> 
std::string CmdExecutor::stringFormat(const std::string& format, Args ... args) 
{
    size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0' 
    if (size <= 0) 
    { 
        throw std::runtime_error("Error during formatting.");
    }

    std::unique_ptr<char[]> buf(new char[size]); 
    snprintf(buf.get(), size, format.c_str(), args ...); 
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside }
}

void CmdExecutor::thread_func(std::string& srcfile)
{
	int result;
	char cmdline[128];
	if (!srcfile.empty())
	{
		std::cout << "audio file: " << srcfile << std::endl;
		std::vector<std::string> f_path = tokenize_getline(srcfile, '.');
		std::string fname = f_path.at(0);

		for (int i = 1; i <= 4; i++)
		{
			sprintf(cmdline, "sox %s %s.%d.wav remix %d", srcfile.c_str(), fname.c_str(), i, i);
			if ((result = system(cmdline)) != -1)
			{
				std::cout << "success to split voice file with channel " << i;
				std::cout << "  [ " << cmdline << " ]" << std::endl;
			}
		}
	}
	else{
		std::cout << "Error! wav file is not found (null)" << std::endl;
	}
}
