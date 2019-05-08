#ifndef __KFK_H__
#define __KFK_H__

#ifdef _MSC_VER
#ifdef KFK_EXPORTS
#define KFK_API __declspec(dllexport)
#else
#define KFK_API __declspec(dllimport)
#endif
#else
#define KFK_API __attribute__ ((visibility("default")))
#endif//_MSC_VER

#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus

KFK_API void test();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif