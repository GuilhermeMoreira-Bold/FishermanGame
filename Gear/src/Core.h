#pragma once
#ifdef GEAR_EXPORTS
#define GEAR_API __declspec(dllexport)
#else
#define GEAR_API __declspec(dllimport)
#endif