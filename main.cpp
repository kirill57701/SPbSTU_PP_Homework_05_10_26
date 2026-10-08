#include <windows.h>
#include <iostream>
#include <string>

const char msg[256] = "user data\n";

DWORD send(DWORD& err, HANDLE wr, const char* b, DWORD k)
{
  DWORD r = 0;
  DWORD h = 0;
  while (r < k)
  {
    BOOL st = WriteFile(wr, b + r, k - r, &h, NULL);
    if (!st)
    {
      err = GetLastError();
      break;
    }
    r += h;
  }
  return r;
}
