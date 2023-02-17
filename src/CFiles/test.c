#include <check.h>
#include "calculator.h"

START_TEST(number_test) {
  double result = 0;
  // test 1
  char string_1[255] = "12.3+4=";
  result = smart_calc(string_1, &result, 0);
  ck_assert_double_eq_tol(result, 16.3, 1e-7);
  // test 2
  char string_2[255] = "(12)=";
  result = smart_calc(string_2, &result, 0);
  ck_assert_double_eq_tol(result, 12, 1e-7);
  // test 3
  char string_3[255] = "(12.)=";
  result = smart_calc(string_3, &result, 0);
  // test 4
  char string_4[255] = ".12=";
  result = smart_calc(string_4, &result, 0);
  // test 5
  char string_5[255] = "1.12.=";
  result = smart_calc(string_5, &result, 0);
  // test 6
  char string_6[255] = "1.12.1=";
  result = smart_calc(string_6, &result, 0);
  // test 7
  char string_7[255] = "(1.12.)=";
  result = smart_calc(string_7, &result, 0);
  // test 8
  char string_8[255] = "x+1.1=";
  result = smart_calc(string_8, &result, 2.2);
  ck_assert_double_eq_tol(result, 3.3, 1e-7);
  // test 9
  char string_9[255] = "x=";
  result = smart_calc(string_9, &result, 2.2);
  ck_assert_double_eq_tol(result, 2.2, 1e-7);
  // test 10
  char string_10[255] = "-x=";
  result = smart_calc(string_10, &result, 2.2);
  ck_assert_double_eq_tol(result, -2.2, 1e-7);
  // test 11
  char string_11[255] = ".x+1=";
  result = smart_calc(string_11, &result, 2.2);
  // test 12
  char string_12[255] = "1.x+1=";
  result = smart_calc(string_12, &result, 2.2);
  // test 13
  char string_13[255] = "x.1+1=";
  result = smart_calc(string_13, &result, 2.2);
}

// plus test
START_TEST(plus_test) {
  double result = 0;
  // test 1
  char string_1[255] = "-12.3+4=";
  result = smart_calc(string_1, &result, 0);
  ck_assert_double_eq_tol(result, -8.3, 1e-7);
  // test 2
  char string_2[255] = "(12)+(-12.00006)=";
  result = smart_calc(string_2, &result, 0);
  ck_assert_double_eq_tol(result, -0.00006, 1e-7);
  // test 3
  char string_3[255] = "(12.02)++12.2=";
  result = smart_calc(string_3, &result, 0);
  // test 4
  char string_4[255] = "12+=";
  result = smart_calc(string_4, &result, 0);
  // test 5
  char string_5[255] = "+1.12=";
  result = smart_calc(string_5, &result, 0);
  ck_assert_double_eq_tol(result, 1.12, 1e-7);
  // test 6
  char string_6[255] = "+(+(+10))+(+(+10))=";
  result = smart_calc(string_6, &result, 0);
  ck_assert_double_eq_tol(result, 20, 1e-7);
  // test 7
  char string_7[255] = "++1.12=";
  result = smart_calc(string_7, &result, 0);
  // test 8
  char string_8[255] = "1.2+1.2+2.4+4.8=";
  result = smart_calc(string_8, &result, 2.2);
  ck_assert_double_eq_tol(result, 9.6, 1e-7);
}

// sub test
START_TEST(sub_test) {
  double result = 0;
  // test 1
  char string_1[255] = "-12.3-4=";
  result = smart_calc(string_1, &result, 0);
  ck_assert_double_eq_tol(result, -16.3, 1e-7);
  // test 2
  char string_2[255] = "(12)-(-12.00006)=";
  result = smart_calc(string_2, &result, 0);
  ck_assert_double_eq_tol(result, 24.00006, 1e-7);
  // test 3
  char string_3[255] = "(12.02)--12.2=";
  result = smart_calc(string_3, &result, 0);
  // test 4
  char string_4[255] = "12-=";
  result = smart_calc(string_4, &result, 0);
  // test 5
  char string_5[255] = "-1.12=";
  result = smart_calc(string_5, &result, 0);
  ck_assert_double_eq_tol(result, -1.12, 1e-7);
  // test 6
  char string_6[255] = "-(-(-10))-(-(-10))=";
  result = smart_calc(string_6, &result, 0);
  ck_assert_double_eq_tol(result, -20, 1e-7);
  // test 7
  char string_7[255] = "--1.12=";
  result = smart_calc(string_7, &result, 0);
  // test 8
  char string_8[255] = "-1.2-1.2-2.4-4.8=";
  result = smart_calc(string_8, &result, 2.2);
  ck_assert_double_eq_tol(result, -9.6, 1e-7);
}

// mul test
START_TEST(mul_test) {
  double result = 0;
  // test 1
  char string_1[255] = "-1.3*4=";
  result = smart_calc(string_1, &result, 0);
  ck_assert_double_eq_tol(result, -5.2, 1e-7);
  // test 2
  char string_2[255] = "(12)*(-1.0006)=";
  result = smart_calc(string_2, &result, 0);
  ck_assert_double_eq_tol(result, -12.0072, 1e-7);
  // test 3
  char string_3[255] = "(12.02)**12.2=";
  result = smart_calc(string_3, &result, 0);
  // test 4
  char string_4[255] = "12*=";
  result = smart_calc(string_4, &result, 0);
  // test 5
  char string_5[255] = "*1.12=";
  result = smart_calc(string_5, &result, 0);
  // test 6
  char string_6[255] = "-(-(-10))*(-(-10))=";
  result = smart_calc(string_6, &result, 0);
  ck_assert_double_eq_tol(result, -100, 1e-7);
  // test 8
  char string_8[255] = "(+12*)13=";
  result = smart_calc(string_8, &result, 2.2);
}

// div test
START_TEST(div_test) {
  double result = 0;
  // test 1
  char string_1[255] = "-1.3/4=";
  result = smart_calc(string_1, &result, 0);
  ck_assert_double_eq_tol(result, -0.325, 1e-7);
  // test 2
  char string_2[255] = "(12)/(-1.0006)=";
  result = smart_calc(string_2, &result, 0);
  ck_assert_double_eq_tol(result, -11.9928043, 1e-7);
  // test 3
  char string_3[255] = "(12.02)//12.2=";
  result = smart_calc(string_3, &result, 0);
  // test 4
  char string_4[255] = "12/=";
  result = smart_calc(string_4, &result, 0);
  // test 5
  char string_5[255] = "/1.12=";
  result = smart_calc(string_5, &result, 0);
  // test 6
  char string_6[255] = "-(-(-10))/(-(-10))=";
  result = smart_calc(string_6, &result, 0);
  ck_assert_double_eq_tol(result, -1, 1e-7);
  // test 8
  char string_8[255] = "(+12/)13=";
  result = smart_calc(string_8, &result, 2.2);
}

// mod test
START_TEST(mod_test) {
  double result = 0;
  // test 1
  char string_1[255] = "-1.3mod4=";
  result = smart_calc(string_1, &result, 0);
  ck_assert_double_eq_tol(result, -1.3, 1e-7);
  // test 2
  char string_2[255] = "(12)mod(-1.0006)=";
  result = smart_calc(string_2, &result, 0);
  ck_assert_double_eq_tol(result, 0.9934000000000007, 1e-7);
  // test 3
  char string_3[255] = "(12.2)mod12.02=";
  result = smart_calc(string_3, &result, 0);
  ck_assert_double_eq_tol(result, 0.17999999999999972, 1e-7);
  // test 4
  char string_4[255] = "12mod=";
  result = smart_calc(string_4, &result, 0);
  // test 5
  char string_5[255] = "mod1.12=";
  result = smart_calc(string_5, &result, 0);
  // test 6
  char string_6[255] = "-(-(-10))mod(-(-10))=";
  result = smart_calc(string_6, &result, 0);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  // test 8
  char string_8[255] = "(+12mod)13=";
  result = smart_calc(string_8, &result, 2.2);
}

// deg test
START_TEST(deg_test) {
  double result = 0;
  // test 1
  char string_1[255] = "-1.3^4=";
  result = smart_calc(string_1, &result, 0);
  ck_assert_double_eq_tol(result, -2.8561, 1e-7);
  // test 2
  char string_2[255] = "(12)^(-1.0006)=";
  result = smart_calc(string_2, &result, 0);
  ck_assert_double_eq_tol(result, 0.08320918057, 1e-7);
  // test 3
  char string_3[255] = "(12.2)^2.02=";
  result = smart_calc(string_3, &result, 0);
  ck_assert_double_eq_tol(result, 156.475683751, 1e-7);
  // test 4
  char string_4[255] = "12^=";
  result = smart_calc(string_4, &result, 0);
  // test 5
  char string_5[255] = "^1.12=";
  result = smart_calc(string_5, &result, 0);
  // test 6
  char string_6[255] = "-(-(-10))^(-(-1))=";
  result = smart_calc(string_6, &result, 0);
  ck_assert_double_eq_tol(result, -10, 1e-7);
  // test 8
  char string_8[255] = "(+12^)13=";
  result = smart_calc(string_8, &result, 2.2);
  // test 9
  char string_9[255] = "2^2^3=";
  result = smart_calc(string_9, &result, 2.2);
  ck_assert_double_eq_tol(result, 256, 1e-7);
}

// sqrt test
START_TEST(sqrt_test) {
  double result = 0;
  // test 1
  char string_1[255] = "sqrt(4)=";
  result = smart_calc(string_1, &result, 0);
  ck_assert_double_eq_tol(result, 2, 1e-7);
  // test 2
  char string_2[255] = "sqrt(-4)=";
  result = smart_calc(string_2, &result, 0);
  ck_assert_double_nan(result);
  // test 3
  char string_3[255] = "-sqrt(4)=";
  result = smart_calc(string_3, &result, 0);
  ck_assert_double_eq_tol(result, -2, 1e-7);
  // test 4
  char string_4[255] = "sqrt()=";
  result = smart_calc(string_4, &result, 0);
  // test 5
  char string_5[255] = "sqrt=";
  result = smart_calc(string_5, &result, 0);
  // test 6
  char string_6[255] = "sqrt((((((4))))))=";
  result = smart_calc(string_6, &result, 0);
  ck_assert_double_eq_tol(result, 2, 1e-7);
  // test 7
  char string_7[255] = "sqrt(=";
  result = smart_calc(string_7, &result, 0);
  // test 8
  char string_8[255] = "sqrt)=";
  result = smart_calc(string_8, &result, 0);
  // test 9
  char string_9[255] = "sqrt(12=";
  result = smart_calc(string_9, &result, 0);
}

// sin test
START_TEST(sin_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "sin(3.14*2)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.00318530179, 1e-7);

  // test 2
  char string_2[255] = "sin(1)=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_eq_tol(result, 0.841470984807897, 1e-7);

  // test 3
  char string_3[255] = "-sin(1)=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.841470984807897, 1e-7);

  // test 4
  char string_4[255] = "sin()=";
  result = smart_calc(string_4, &result, 0);

  

  // test 5
  char string_5[255] = "sin=";
  result = smart_calc(string_5, &result, 0);

  

  // test 6
  char string_6[255] = "sin((((((4))))))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.7568024953, 1e-7);

  // test 7
  char string_7[255] = "sin(=";
  result = smart_calc(string_7, &result, 0);

  

  // test 8
  char string_8[255] = "sin)=";
  result = smart_calc(string_8, &result, 0);

  

  // test 9
  char string_9[255] = "sin(12=";
  result = smart_calc(string_9, &result, 0);

  
}

// cos test
START_TEST(cos_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "cos(3.14*2)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_eq_tol(result, 0.99999492691, 1e-7);

  // test 2
  char string_2[255] = "cos(1)=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_eq_tol(result, 0.54030230586, 1e-7);

  // test 3
  char string_3[255] = "-cos(1)=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.54030230586, 1e-7);

  // test 4
  char string_4[255] = "cos()=";
  result = smart_calc(string_4, &result, 0);

  

  // test 5
  char string_5[255] = "cos=";
  result = smart_calc(string_5, &result, 0);

  

  // test 6
  char string_6[255] = "cos((((((4))))))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.65364362086, 1e-7);

  // test 7
  char string_7[255] = "cos(=";
  result = smart_calc(string_7, &result, 0);

  

  // test 8
  char string_8[255] = "cos)=";
  result = smart_calc(string_8, &result, 0);

  

  // test 9
  char string_9[255] = "cos(12=";
  result = smart_calc(string_9, &result, 0);

  
}

// tan test
START_TEST(tan_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "tan(3.14*2)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.00318531795, 1e-7);

  // test 2
  char string_2[255] = "tan(1)=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_eq_tol(result, 1.55740772465, 1e-7);

  // test 3
  char string_3[255] = "-tan(1)=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, -1.55740772465, 1e-7);

  // test 4
  char string_4[255] = "tan()=";
  result = smart_calc(string_4, &result, 0);

  

  // test 5
  char string_5[255] = "tan=";
  result = smart_calc(string_5, &result, 0);

  

  // test 6
  char string_6[255] = "tan((((((4))))))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_eq_tol(result, 1.15782128235, 1e-7);

  // test 7
  char string_7[255] = "tan(=";
  result = smart_calc(string_7, &result, 0);

  

  // test 8
  char string_8[255] = "tan)=";
  result = smart_calc(string_8, &result, 0);

  

  // test 9
  char string_9[255] = "tan(12=";
  result = smart_calc(string_9, &result, 0);

  
}

// asin test
START_TEST(asin_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "asin(3.14*2)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_nan(result);

  // test 2
  char string_2[255] = "asin(0.9)=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_eq_tol(result, 1.11977, 1e-6);

  // test 3
  char string_3[255] = "-asin(0.9)=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, -1.119770, 1e-6);

  // test 4
  char string_4[255] = "asin()=";
  result = smart_calc(string_4, &result, 0);

  

  // test 5
  char string_5[255] = "asin=";
  result = smart_calc(string_5, &result, 0);

  

  // test 6
  char string_6[255] = "asin((((((-0.0001))))))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.000100, 1e-6);

  // test 7
  char string_7[255] = "asin(=";
  result = smart_calc(string_7, &result, 0);

  

  // test 8
  char string_8[255] = "asin)=";
  result = smart_calc(string_8, &result, 0);

  

  // test 9
  char string_9[255] = "asin(12=";
  result = smart_calc(string_9, &result, 0);

  
}

// acos test
START_TEST(acos_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "acos(3.14*2)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_nan(result);

  // test 2
  char string_2[255] = "acos(0.9)=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_eq_tol(result, 0.451027, 1e-6);

  // test 3
  char string_3[255] = "-acos(0.9)=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.451027, 1e-6);

  // test 4
  char string_4[255] = "acos()=";
  result = smart_calc(string_4, &result, 0);

  

  // test 5
  char string_5[255] = "acos=";
  result = smart_calc(string_5, &result, 0);

  

  // test 6
  char string_6[255] = "acos((((((-0.0001))))))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_eq_tol(result, 1.570896, 1e-6);

  // test 7
  char string_7[255] = "acos(=";
  result = smart_calc(string_7, &result, 0);

  

  // test 8
  char string_8[255] = "acos)=";
  result = smart_calc(string_8, &result, 0);

  

  // test 9
  char string_9[255] = "acos(12=";
  result = smart_calc(string_9, &result, 0);

  
}

// atan test
START_TEST(atan_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "atan(3.14*2)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_eq_tol(result, 1.412886, 1e-6);

  // test 2
  char string_2[255] = "atan(0.9)=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_eq_tol(result, 0.732815, 1e-6);

  // test 3
  char string_3[255] = "-atan(0.9)=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.732815, 1e-6);

  // test 4
  char string_4[255] = "atan()=";
  result = smart_calc(string_4, &result, 0);

  

  // test 5
  char string_5[255] = "atan=";
  result = smart_calc(string_5, &result, 0);

  

  // test 6
  char string_6[255] = "atan((((((-0.0001))))))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.000100, 1e-6);

  // test 7
  char string_7[255] = "atan(=";
  result = smart_calc(string_7, &result, 0);

  

  // test 8
  char string_8[255] = "atan)=";
  result = smart_calc(string_8, &result, 0);

  

  // test 9
  char string_9[255] = "atan(12=";
  result = smart_calc(string_9, &result, 0);

  
}

// ln test
START_TEST(ln_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "ln(3.14*2)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_eq_tol(result, 1.837370, 1e-6);

  // test 2
  char string_2[255] = "ln(0.9)=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.105361, 1e-6);

  // test 3
  char string_3[255] = "-ln(0.9)=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, 0.105361, 1e-6);

  // test 4
  char string_4[255] = "ln()=";
  result = smart_calc(string_4, &result, 0);

  

  // test 5
  char string_5[255] = "ln=";
  result = smart_calc(string_5, &result, 0);

  

  // test 6
  char string_6[255] = "ln((((((-0.0001))))))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_nan(result);

  // test 7
  char string_7[255] = "ln(=";
  result = smart_calc(string_7, &result, 0);

  

  // test 8
  char string_8[255] = "ln)=";
  result = smart_calc(string_8, &result, 0);

  

  // test 9
  char string_9[255] = "ln(12=";
  result = smart_calc(string_9, &result, 0);

  
}

// log test
START_TEST(log_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "log(3.14*2)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_eq_tol(result, 0.797960, 1e-6);

  // test 2
  char string_2[255] = "log(0.9)=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.045757, 1e-6);

  // test 3
  char string_3[255] = "-log(0.9)=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, 0.045757, 1e-6);

  // test 4
  char string_4[255] = "log()=";
  result = smart_calc(string_4, &result, 0);

  

  // test 5
  char string_5[255] = "log=";
  result = smart_calc(string_5, &result, 0);

  

  // test 6
  char string_6[255] = "log((((((-0.0001))))))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_nan(result);

  // test 7
  char string_7[255] = "log(=";
  result = smart_calc(string_7, &result, 0);

  

  // test 8
  char string_8[255] = "log)=";
  result = smart_calc(string_8, &result, 0);

  

  // test 9
  char string_9[255] = "log(12=";
  result = smart_calc(string_9, &result, 0);

  
}

//  test
START_TEST(algebraic_equation_test) {
  double result = 0;
  

  // test 1
  char string_1[255] = "sin(1.0009-12.53)*cos(1.25*2^3)=";
  result = smart_calc(string_1, &result, 0);

  
  ck_assert_double_eq_tol(result, -0.722457, 1e-6);

  // test 2
  char string_2[255] = "log(15.3)*log(-10)+15-1*15/14=";
  result = smart_calc(string_2, &result, 0);

  
  ck_assert_double_nan(result);

  // test 3
  char string_3[255] = "2^2^3*3^2^3=";
  result = smart_calc(string_3, &result, 0);

  
  ck_assert_double_eq_tol(result, 1679616.000000, 1e-6);

  // test 4
  char string_4[255] = "1/0=";
  result = smart_calc(string_4, &result, 0);

  
  ck_assert_double_infinite(result);

  // test 5
  char string_5[255] = "0/0=";
  result = smart_calc(string_5, &result, 0);

  
  ck_assert_double_nan(result);

  // test 6
  char string_6[255] =
      "sin(30)+cos(30)*tan(30)/acos(0.15)^asin(0.15)+(-atan(0.15))=";
  result = smart_calc(string_6, &result, 0);

  
  ck_assert_double_eq_tol(result, -2.074118, 1e-6);

  // test 7
  char string_7[255] = "17mod13mod5=";
  result = smart_calc(string_7, &result, 0);

  
  ck_assert_double_eq_tol(result, 4, 1e-6);
}

// credit_calc test
START_TEST(credit_calc_test) {
  // test 1
  double total_sum = 2400000;
  int time = 20;
  double procent_rate = 9.5;
  int type = 1;
  double month_pay_1[10] = {0};
  double overpay = 0;
  double total_pay = 0;

  int result = credit_calc(total_sum, time, procent_rate, type, month_pay_1,
                           &overpay, &total_pay);

  
  ck_assert_double_eq_tol(month_pay_1[0], 130223.98, 1e-2);
  ck_assert_double_eq_tol(overpay, 204479.60, 1e-2);
  ck_assert_double_eq_tol(total_pay, 2604479.60, 1e-2);

  // test 2
  total_sum = 2400000;
  time = -5;
  procent_rate = 9.5;
  type = 1;
  double month_pay_2[10] = {0};
  overpay = 0;
  total_pay = 0;

  result = credit_calc(total_sum, time, procent_rate, type, month_pay_2,
                       &overpay, &total_pay);

  

  // test 3
  total_sum = 2400000;
  time = 25;
  procent_rate = -5;
  type = 1;
  double month_pay_3[10] = {0};
  overpay = 0;
  total_pay = 0;

  result = credit_calc(total_sum, time, procent_rate, type, month_pay_3,
                       &overpay, &total_pay);

  

  // test 4
  total_sum = -2400000;
  time = 25;
  procent_rate = 5;
  type = 1;
  double month_pay_4[10] = {0};
  overpay = 0;
  total_pay = 0;

  result = credit_calc(total_sum, time, procent_rate, type, month_pay_4,
                       &overpay, &total_pay);

  

  // test 5
  total_sum = 2400000;
  time = 25;
  procent_rate = 5;
  type = 3;
  double month_pay_5[10] = {0};
  overpay = 0;
  total_pay = 0;

  result = credit_calc(total_sum, time, procent_rate, type, month_pay_5,
                       &overpay, &total_pay);

  

  // test 6
  total_sum = 240000;
  time = 7;
  procent_rate = 9.5;
  type = 2;
  double month_pay_6[10] = {0};
  overpay = 0;
  total_pay = 0;

  result = credit_calc(total_sum, time, procent_rate, type, month_pay_6,
                       &overpay, &total_pay);

  
  ck_assert_double_eq_tol(month_pay_6[0], 36185.71, 1e-2);
  ck_assert_double_eq_tol(month_pay_6[1], 35914.29, 1e-2);
  ck_assert_double_eq_tol(month_pay_6[2], 35642.86, 1e-2);
  ck_assert_double_eq_tol(month_pay_6[3], 35371.43, 1e-2);
  ck_assert_double_eq_tol(month_pay_6[4], 35100.00, 1e-2);
  ck_assert_double_eq_tol(month_pay_6[5], 34828.57, 1e-2);
  ck_assert_double_eq_tol(month_pay_6[6], 34557.14, 1e-2);
  ck_assert_double_eq_tol(overpay, 7600, 1e-2);
  ck_assert_double_eq_tol(total_pay, 247600, 1e-2);
}

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  int failed = 0;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, number_test);
  tcase_add_test(tc1_1, plus_test);
  tcase_add_test(tc1_1, sub_test);
  tcase_add_test(tc1_1, mul_test);
  tcase_add_test(tc1_1, div_test);
  tcase_add_test(tc1_1, mod_test);
  tcase_add_test(tc1_1, deg_test);
  tcase_add_test(tc1_1, sqrt_test);
  tcase_add_test(tc1_1, sin_test);
  tcase_add_test(tc1_1, cos_test);
  tcase_add_test(tc1_1, tan_test);
  tcase_add_test(tc1_1, asin_test);
  tcase_add_test(tc1_1, acos_test);
  tcase_add_test(tc1_1, atan_test);
  tcase_add_test(tc1_1, ln_test);
  tcase_add_test(tc1_1, log_test);
  tcase_add_test(tc1_1, algebraic_equation_test);
  tcase_add_test(tc1_1, credit_calc_test);

  srunner_run_all(sr, CK_ENV);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
