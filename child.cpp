#include <windows.h>
#include <cstdio>
#include <iostream>
#include <string>

DWORD recv(DWORD& err, HANDLE rd, char* b, DWORD k)
{
  DWORD r = 0;
  DWORD h = 0;
  while (r < k)
  {
    BOOL st = ReadFile(rd, b + r, k - r, &h, NULL);
    if (!st)
    {
      err = GetLastError();
      break;
    }
    if (h == 0)
    {
      break;
    }
    r += h;
  }
  return r;
}
