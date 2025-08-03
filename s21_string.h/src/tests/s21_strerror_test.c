#include <check.h>

#include "../s21_string.h"

#define GENERATE_STRERROR_TEST(num)                     \
  START_TEST(test_s21_strerror_##num) {                 \
    ck_assert_str_eq(s21_strerror(num), strerror(num)); \
  }                                                     \
  END_TEST

GENERATE_STRERROR_TEST(0)
GENERATE_STRERROR_TEST(1)
GENERATE_STRERROR_TEST(2)
GENERATE_STRERROR_TEST(3)
GENERATE_STRERROR_TEST(4)
GENERATE_STRERROR_TEST(5)
GENERATE_STRERROR_TEST(6)
GENERATE_STRERROR_TEST(7)
GENERATE_STRERROR_TEST(8)
GENERATE_STRERROR_TEST(9)
GENERATE_STRERROR_TEST(10)
GENERATE_STRERROR_TEST(11)
GENERATE_STRERROR_TEST(12)
GENERATE_STRERROR_TEST(13)
GENERATE_STRERROR_TEST(14)
GENERATE_STRERROR_TEST(15)
GENERATE_STRERROR_TEST(16)
GENERATE_STRERROR_TEST(17)
GENERATE_STRERROR_TEST(18)
GENERATE_STRERROR_TEST(19)
GENERATE_STRERROR_TEST(20)
GENERATE_STRERROR_TEST(21)
GENERATE_STRERROR_TEST(22)
GENERATE_STRERROR_TEST(23)
GENERATE_STRERROR_TEST(24)
GENERATE_STRERROR_TEST(25)
GENERATE_STRERROR_TEST(26)
GENERATE_STRERROR_TEST(27)
GENERATE_STRERROR_TEST(28)
GENERATE_STRERROR_TEST(29)
GENERATE_STRERROR_TEST(30)
GENERATE_STRERROR_TEST(31)
GENERATE_STRERROR_TEST(32)
GENERATE_STRERROR_TEST(33)
GENERATE_STRERROR_TEST(34)
GENERATE_STRERROR_TEST(35)
GENERATE_STRERROR_TEST(36)
GENERATE_STRERROR_TEST(37)
GENERATE_STRERROR_TEST(38)
GENERATE_STRERROR_TEST(39)
GENERATE_STRERROR_TEST(40)
GENERATE_STRERROR_TEST(41)
GENERATE_STRERROR_TEST(42)
GENERATE_STRERROR_TEST(43)
GENERATE_STRERROR_TEST(44)
GENERATE_STRERROR_TEST(45)
GENERATE_STRERROR_TEST(46)
GENERATE_STRERROR_TEST(47)
GENERATE_STRERROR_TEST(48)
GENERATE_STRERROR_TEST(49)
GENERATE_STRERROR_TEST(50)
GENERATE_STRERROR_TEST(51)
GENERATE_STRERROR_TEST(52)
GENERATE_STRERROR_TEST(53)
GENERATE_STRERROR_TEST(54)
GENERATE_STRERROR_TEST(55)
GENERATE_STRERROR_TEST(56)
GENERATE_STRERROR_TEST(57)
GENERATE_STRERROR_TEST(58)
GENERATE_STRERROR_TEST(59)
GENERATE_STRERROR_TEST(60)
GENERATE_STRERROR_TEST(61)
GENERATE_STRERROR_TEST(62)
GENERATE_STRERROR_TEST(63)
GENERATE_STRERROR_TEST(64)
GENERATE_STRERROR_TEST(65)
GENERATE_STRERROR_TEST(66)
GENERATE_STRERROR_TEST(67)
GENERATE_STRERROR_TEST(68)
GENERATE_STRERROR_TEST(69)
GENERATE_STRERROR_TEST(70)
GENERATE_STRERROR_TEST(71)
GENERATE_STRERROR_TEST(72)
GENERATE_STRERROR_TEST(73)
GENERATE_STRERROR_TEST(74)
GENERATE_STRERROR_TEST(75)
GENERATE_STRERROR_TEST(76)
GENERATE_STRERROR_TEST(77)
GENERATE_STRERROR_TEST(78)
GENERATE_STRERROR_TEST(79)
GENERATE_STRERROR_TEST(80)
GENERATE_STRERROR_TEST(81)
GENERATE_STRERROR_TEST(82)
GENERATE_STRERROR_TEST(83)
GENERATE_STRERROR_TEST(84)
GENERATE_STRERROR_TEST(85)
GENERATE_STRERROR_TEST(86)
GENERATE_STRERROR_TEST(87)
GENERATE_STRERROR_TEST(88)
GENERATE_STRERROR_TEST(89)
GENERATE_STRERROR_TEST(90)
GENERATE_STRERROR_TEST(91)
GENERATE_STRERROR_TEST(92)
GENERATE_STRERROR_TEST(93)
GENERATE_STRERROR_TEST(94)
GENERATE_STRERROR_TEST(95)
GENERATE_STRERROR_TEST(96)
GENERATE_STRERROR_TEST(97)
GENERATE_STRERROR_TEST(98)
GENERATE_STRERROR_TEST(99)
GENERATE_STRERROR_TEST(100)
GENERATE_STRERROR_TEST(101)
GENERATE_STRERROR_TEST(102)
GENERATE_STRERROR_TEST(103)
GENERATE_STRERROR_TEST(104)
GENERATE_STRERROR_TEST(105)
GENERATE_STRERROR_TEST(106)
GENERATE_STRERROR_TEST(107)
GENERATE_STRERROR_TEST(108)
GENERATE_STRERROR_TEST(109)
GENERATE_STRERROR_TEST(110)
GENERATE_STRERROR_TEST(111)
GENERATE_STRERROR_TEST(112)
GENERATE_STRERROR_TEST(113)
GENERATE_STRERROR_TEST(114)
GENERATE_STRERROR_TEST(115)
GENERATE_STRERROR_TEST(116)
GENERATE_STRERROR_TEST(117)
GENERATE_STRERROR_TEST(118)
GENERATE_STRERROR_TEST(119)
GENERATE_STRERROR_TEST(120)
GENERATE_STRERROR_TEST(121)
GENERATE_STRERROR_TEST(122)
GENERATE_STRERROR_TEST(123)
GENERATE_STRERROR_TEST(124)
GENERATE_STRERROR_TEST(125)
GENERATE_STRERROR_TEST(126)
GENERATE_STRERROR_TEST(127)
GENERATE_STRERROR_TEST(128)
GENERATE_STRERROR_TEST(129)
GENERATE_STRERROR_TEST(130)
GENERATE_STRERROR_TEST(131)
GENERATE_STRERROR_TEST(132)
GENERATE_STRERROR_TEST(133)
GENERATE_STRERROR_TEST(134)
GENERATE_STRERROR_TEST(135)
GENERATE_STRERROR_TEST(136)
GENERATE_STRERROR_TEST(137)
GENERATE_STRERROR_TEST(138)
GENERATE_STRERROR_TEST(139)
GENERATE_STRERROR_TEST(140)

Suite *s21_strerror_suite(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_strerror_0);
  tcase_add_test(tc, test_s21_strerror_1);
  tcase_add_test(tc, test_s21_strerror_2);
  tcase_add_test(tc, test_s21_strerror_3);
  tcase_add_test(tc, test_s21_strerror_4);
  tcase_add_test(tc, test_s21_strerror_5);
  tcase_add_test(tc, test_s21_strerror_6);
  tcase_add_test(tc, test_s21_strerror_7);
  tcase_add_test(tc, test_s21_strerror_8);
  tcase_add_test(tc, test_s21_strerror_9);
  tcase_add_test(tc, test_s21_strerror_10);
  tcase_add_test(tc, test_s21_strerror_11);
  tcase_add_test(tc, test_s21_strerror_12);
  tcase_add_test(tc, test_s21_strerror_13);
  tcase_add_test(tc, test_s21_strerror_14);
  tcase_add_test(tc, test_s21_strerror_15);
  tcase_add_test(tc, test_s21_strerror_16);
  tcase_add_test(tc, test_s21_strerror_17);
  tcase_add_test(tc, test_s21_strerror_18);
  tcase_add_test(tc, test_s21_strerror_19);
  tcase_add_test(tc, test_s21_strerror_20);
  tcase_add_test(tc, test_s21_strerror_21);
  tcase_add_test(tc, test_s21_strerror_22);
  tcase_add_test(tc, test_s21_strerror_23);
  tcase_add_test(tc, test_s21_strerror_24);
  tcase_add_test(tc, test_s21_strerror_25);
  tcase_add_test(tc, test_s21_strerror_26);
  tcase_add_test(tc, test_s21_strerror_27);
  tcase_add_test(tc, test_s21_strerror_28);
  tcase_add_test(tc, test_s21_strerror_29);
  tcase_add_test(tc, test_s21_strerror_30);
  tcase_add_test(tc, test_s21_strerror_31);
  tcase_add_test(tc, test_s21_strerror_32);
  tcase_add_test(tc, test_s21_strerror_33);
  tcase_add_test(tc, test_s21_strerror_34);
  tcase_add_test(tc, test_s21_strerror_35);
  tcase_add_test(tc, test_s21_strerror_36);
  tcase_add_test(tc, test_s21_strerror_37);
  tcase_add_test(tc, test_s21_strerror_38);
  tcase_add_test(tc, test_s21_strerror_39);
  tcase_add_test(tc, test_s21_strerror_40);
  tcase_add_test(tc, test_s21_strerror_41);
  tcase_add_test(tc, test_s21_strerror_42);
  tcase_add_test(tc, test_s21_strerror_43);
  tcase_add_test(tc, test_s21_strerror_44);
  tcase_add_test(tc, test_s21_strerror_45);
  tcase_add_test(tc, test_s21_strerror_46);
  tcase_add_test(tc, test_s21_strerror_47);
  tcase_add_test(tc, test_s21_strerror_48);
  tcase_add_test(tc, test_s21_strerror_49);
  tcase_add_test(tc, test_s21_strerror_50);
  tcase_add_test(tc, test_s21_strerror_51);
  tcase_add_test(tc, test_s21_strerror_52);
  tcase_add_test(tc, test_s21_strerror_53);
  tcase_add_test(tc, test_s21_strerror_54);
  tcase_add_test(tc, test_s21_strerror_55);
  tcase_add_test(tc, test_s21_strerror_56);
  tcase_add_test(tc, test_s21_strerror_57);
  tcase_add_test(tc, test_s21_strerror_58);
  tcase_add_test(tc, test_s21_strerror_59);
  tcase_add_test(tc, test_s21_strerror_60);
  tcase_add_test(tc, test_s21_strerror_61);
  tcase_add_test(tc, test_s21_strerror_62);
  tcase_add_test(tc, test_s21_strerror_63);
  tcase_add_test(tc, test_s21_strerror_64);
  tcase_add_test(tc, test_s21_strerror_65);
  tcase_add_test(tc, test_s21_strerror_66);
  tcase_add_test(tc, test_s21_strerror_67);
  tcase_add_test(tc, test_s21_strerror_68);
  tcase_add_test(tc, test_s21_strerror_69);
  tcase_add_test(tc, test_s21_strerror_70);
  tcase_add_test(tc, test_s21_strerror_71);
  tcase_add_test(tc, test_s21_strerror_72);
  tcase_add_test(tc, test_s21_strerror_73);
  tcase_add_test(tc, test_s21_strerror_74);
  tcase_add_test(tc, test_s21_strerror_75);
  tcase_add_test(tc, test_s21_strerror_76);
  tcase_add_test(tc, test_s21_strerror_77);
  tcase_add_test(tc, test_s21_strerror_78);
  tcase_add_test(tc, test_s21_strerror_79);
  tcase_add_test(tc, test_s21_strerror_80);
  tcase_add_test(tc, test_s21_strerror_81);
  tcase_add_test(tc, test_s21_strerror_82);
  tcase_add_test(tc, test_s21_strerror_83);
  tcase_add_test(tc, test_s21_strerror_84);
  tcase_add_test(tc, test_s21_strerror_85);
  tcase_add_test(tc, test_s21_strerror_86);
  tcase_add_test(tc, test_s21_strerror_87);
  tcase_add_test(tc, test_s21_strerror_88);
  tcase_add_test(tc, test_s21_strerror_89);
  tcase_add_test(tc, test_s21_strerror_90);
  tcase_add_test(tc, test_s21_strerror_91);
  tcase_add_test(tc, test_s21_strerror_92);
  tcase_add_test(tc, test_s21_strerror_93);
  tcase_add_test(tc, test_s21_strerror_94);
  tcase_add_test(tc, test_s21_strerror_95);
  tcase_add_test(tc, test_s21_strerror_96);
  tcase_add_test(tc, test_s21_strerror_97);
  tcase_add_test(tc, test_s21_strerror_98);
  tcase_add_test(tc, test_s21_strerror_99);
  tcase_add_test(tc, test_s21_strerror_100);
  tcase_add_test(tc, test_s21_strerror_101);
  tcase_add_test(tc, test_s21_strerror_102);
  tcase_add_test(tc, test_s21_strerror_103);
  tcase_add_test(tc, test_s21_strerror_104);
  tcase_add_test(tc, test_s21_strerror_105);
  tcase_add_test(tc, test_s21_strerror_106);
  tcase_add_test(tc, test_s21_strerror_107);
  tcase_add_test(tc, test_s21_strerror_108);
  tcase_add_test(tc, test_s21_strerror_109);
  tcase_add_test(tc, test_s21_strerror_110);
  tcase_add_test(tc, test_s21_strerror_111);
  tcase_add_test(tc, test_s21_strerror_112);
  tcase_add_test(tc, test_s21_strerror_113);
  tcase_add_test(tc, test_s21_strerror_114);
  tcase_add_test(tc, test_s21_strerror_115);
  tcase_add_test(tc, test_s21_strerror_116);
  tcase_add_test(tc, test_s21_strerror_117);
  tcase_add_test(tc, test_s21_strerror_118);
  tcase_add_test(tc, test_s21_strerror_119);
  tcase_add_test(tc, test_s21_strerror_120);
  tcase_add_test(tc, test_s21_strerror_121);
  tcase_add_test(tc, test_s21_strerror_122);
  tcase_add_test(tc, test_s21_strerror_123);
  tcase_add_test(tc, test_s21_strerror_124);
  tcase_add_test(tc, test_s21_strerror_125);
  tcase_add_test(tc, test_s21_strerror_126);
  tcase_add_test(tc, test_s21_strerror_127);
  tcase_add_test(tc, test_s21_strerror_128);
  tcase_add_test(tc, test_s21_strerror_129);
  tcase_add_test(tc, test_s21_strerror_130);
  tcase_add_test(tc, test_s21_strerror_131);
  tcase_add_test(tc, test_s21_strerror_132);
  tcase_add_test(tc, test_s21_strerror_133);
  tcase_add_test(tc, test_s21_strerror_134);
  tcase_add_test(tc, test_s21_strerror_135);
  tcase_add_test(tc, test_s21_strerror_136);
  tcase_add_test(tc, test_s21_strerror_137);
  tcase_add_test(tc, test_s21_strerror_138);
  tcase_add_test(tc, test_s21_strerror_139);
  tcase_add_test(tc, test_s21_strerror_140);

  suite_add_tcase(s, tc);
  return s;
}