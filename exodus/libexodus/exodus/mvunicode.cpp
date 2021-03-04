//#include <boost/algorithm/string.hpp>
//#include <wctype.h>

#if defined(_MSC_VER)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <string.h>
#endif

//#include <boost/scoped_array.hpp>
//#include <boost/algorithm/string.hpp>

#include <locale.h>
#ifdef __APPLE__
#include <xlocale.h>
//#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFString.h>
//#include <CoreFoundation/CFStringEncodingExt.h>
#endif

#include <exodus/mv.h>
#include <exodus/mvexceptions.h>

namespace exodus {

bool var::setxlocale() const {

#if defined(_MSC_VER) && defined(UNICODE)

	/* http://msdn.microsoft.com/en-us/library/dd374051%28v=VS.85%29.aspx
	//locale list
	//XP 2003 http://msdn.microsoft.com/en-us/goglobal/bb895996.aspx
	//http://msdn.microsoft.com/en-us/goglobal/bb964664.aspx
	BOOL SetThreadLocale(
		__in  LCID Locale
	);
	*/
	// GetSystemDefaultLCID()
	// GetUserDefaultLCID()
	// LCID locale_lcid=1031;//German Standard
	// LCID locale_lcid=1032;//Greek
	// LCID locale_lcid=1055;//Turkish

	return SetThreadLocale((*this).toInt()) != NULL;

#else
	THISIS("bool var::setxlocale() const")
	THISISSTRING()

	// make a thread local locale if not done already
	// TODO do this in thread creation
	// TODO destroy threalocale in thread destruction *OTHERWISE MEMORY LEAK
	// to avoid checking on every setxlocale
	if (uselocale(NULL) == uselocale(LC_GLOBAL_LOCALE))
		uselocale(duplocale(uselocale(LC_GLOBAL_LOCALE)));

	return setlocale(LC_ALL, (*this).toString().c_str()) != NULL;
	// return setlocale(LC_CTYPE,(*this).toString().c_str())!=NULL;

#endif
}

var& var::getxlocale() {
#if defined(_MSC_VER) && defined(UNICODE)
	*this = (int)GetThreadLocale();
	return *this;
#else
	// return "";
	*this = var(setlocale(LC_ALL, NULL));
	return *this;
#endif
}

} // namespace exodus
