#ifndef CmdExecutor_class
#define CmdExecutor_class

#include <iostream>

class CmdExecutor
{
public:
    CmdExecutor();
    ~CmdExecutor();

    size_t      get_result_file_size( ) const;
    std::string get_result_file_name( ) const;
    int         get_result_code( ) const;

    bool        capture_camera_oneshot( );
    bool        record_voice_mircophone( );
    bool        play_microphone_voice( int ch );
    bool        speaker_sound( int type );
    bool        tof_measure_distance( );

private:
    static void thread_func(std::string& srcfile);
    template<typename ... Args> 
    std::string stringFormat(const std::string& format, Args ... args) ;

private:
    int             m_retCode;
	std::string     m_resPath;
	size_t          m_fsize;
};

#endif