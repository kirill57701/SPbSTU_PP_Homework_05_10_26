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

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    return 1;
  }

  HANDLE rd{ reinterpret_cast<HANDLE>(std::stoull(argv[1])) };
  char msg[256] = {};

  DWORD err = 0, k = 255;
  if (recv(err, rd, msg, k) != k)
  {
    std::cerr << err << '\n';
    CloseHandle(rd);
    return 1;
  }
  CloseHandle(rd);
  printf("%s", msg);
  return 0;
}
