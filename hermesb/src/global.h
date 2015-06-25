#ifndef GLOBAL_DEFINITIONS
#define GLOBAL_DEFINITIONS

#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <glog/logging.h>


#define BOOST_ALL_DYN_LINK

#if defined _WIN32 || defined __CYGWIN__
	#ifdef HERMESB_EXPORTS
		#ifndef __GNUC__
			#define HERMESB_API __declspec(dllexport)
		#else
			#define HERMESB_API __attribute__ ((dllexport))
		#endif
	#else
		#ifndef __GNUC__
			#define HERMESB_API __declspec(dllimport)
		#else
			#define HERMESB_API __attribute__ ((dllimport))
		#endif
	#endif

	typedef __int64 int64_t;

#else
	#include <inttypes.h>
	#ifdef HERMESB_EXPORTS
		#if __GNUC__ >= 4
			#define HERMESB_API __attribute__ ((visibility ("default")))
		#else
			#define HERMESB_API
		#endif
	#else
		#define HERMESB_API
	#endif
#endif


#endif
