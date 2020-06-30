#ifndef 54A1S_h
#define 54A1S_h

#include <Arduino.h>

struct d_numbers{
  int d0[8];
  int d1[8];
  int d2[8];
  int d3[8];
  int d4[8];
  int d5[8];
  int d6[8];
  int d7[8];
  int d8[8];
  int d9[8];
};

struct d_letters{
  int da[8];
  int db[8];
  int dc[8];
  int dd[8];
  int de[8];
  int df[8];
  int dg[8];
  int dh[8];
  int di[8];
  int dj[8];
  int dk[8];
  int dl[8];
  int dm[8];
  int dn[8];
  int dO[8];
  int dp[8];
  int dq[8];
  int dr[8];
  int ds[8];
  int dt[8];
  int du[8];
  int dv[8];
  int dw[8];
  int dx[8];
  int dy[8];
  int dz[8];
};

void writechar(int segpins[8], int digit[8]);

class disp{
  public:
    disp(int segpins[8], int digpins[4]);
    void setdigit(int dig, int num);
    void disp_num(long num);
    int _segpins[8];
    int _digpins[4];
};
#endif