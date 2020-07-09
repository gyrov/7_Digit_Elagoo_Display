#ifndef 54A1S_h
#define 54A1S_h

#include <Arduino.h>

struct d_chars{
  int d_0[8];
  int d_1[8];
  int d_2[8];
  int d_3[8];
  int d_4[8];
  int d_5[8];
  int d_6[8];
  int d_7[8];
  int d_8[8];
  int d_9[8];
  int d_a[8];
  int d_b[8];
  int d_c[8];
  int d_d[8];
  int d_e[8];
  int d_f[8];
  int d_g[8];
  int d_h[8];
  int d_i[8];
  int d_j[8];
  int d_k[8];
  int d_l[8];
  int d_m[8];
  int d_n[8];
  int d_o[8];
  int d_p[8];
  int d_q[8];
  int d_r[8];
  int d_s[8];
  int d_t[8];
  int d_u[8];
  int d_v[8];
  int d_w[8];
  int d_x[8];
  int d_y[8];
  int d_z[8];
  int d_pt[8];
};

static void writechar(int segpins[8], int digit[8]);

class disp{
  public:
    disp(int segpins[8], int digpins[4]);
    void setdigit(int dig, int num);
    void disp_num(char[] input);
    int _segpins[8];
    int _digpins[4];
};
#endif
