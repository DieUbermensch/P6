

#include "stdio.h"
#include "ezdsp_setup.h"			// System setup and 

#define MONO 			0
#define STEREO 			1
#define RESOLUTION 		16
#define SAMPLINGRATE 	48
#define startAddr		0x001860
int16 array[20000];

//Band 1 start Address: 0x006680 (20000 + startaddr)
int16 lookUp1[] = {0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7ebc,0x7d7e,0x7c46,0x7b14,0x79e8,0x78c2,0x77a1,0x7685,0x756f,0x745e,0x7351,0x724a,0x7147,0x7048,0x6f4e,0x6e59,0x6d67,0x6c7a,0x6b91,0x6aab,0x69c9,0x68ec,0x6811,0x673a,0x6667,0x6597,0x64ca,0x6400,0x633a,0x6277,0x61b6,0x60f9,0x603e,0x5f86,0x5ed1,0x5e1f,0x5d6f,0x5cc1,0x5c17,0x5b6e,0x5ac8,0x5a25,0x5983,0x58e4,0x5847,0x57ac,0x5714,0x567d,0x55e8,0x5556,0x54c5,0x5436,0x53a9,0x531e,0x5295,0x520e,0x5188,0x5104,0x5081,0x5000,0x4f81,0x4f04,0x4e88,0x4e0d,0x4d94,0x4d1c,0x4ca6,0x4c31,0x4bbe,0x4b4c,0x4adb,0x4a6c,0x49fe,0x4991,0x4925,0x48bb,0x4851,0x47e9,0x4783,0x471d,0x46b8,0x4655,0x45f3,0x4591,0x4531,0x44d2,0x4473,0x4416,0x43ba,0x435f,0x4305,0x42ab,0x4253,0x41fb,0x41a5,0x414f,0x40fa,0x40a6,0x4053,0x4000,0x3faf,0x3f5e,0x3f0e,0x3ebf,0x3e71,0x3e23,0x3dd6,0x3d8a,0x3d3f,0x3cf4,0x3caa,0x3c61,0x3c19,0x3bd1,0x3b89,0x3b43,0x3afd,0x3ab8,0x3a73,0x3a2f,0x39ec,0x39a9,0x3967,0x3925,0x38e4,0x38a4,0x3864,0x3824,0x37e6,0x37a7,0x376a,0x372d,0x36f0,0x36b4,0x3678,0x363d,0x3603,0x35c9,0x358f,0x3556,0x351d,0x34e5,0x34ad,0x3476,0x343f,0x3409,0x33d3,0x339d,0x3368,0x3334,0x32ff,0x32cc,0x3298,0x3265,0x3233,0x3200,0x31cf,0x319d,0x316c,0x313c,0x310b,0x30db,0x30ac,0x307d,0x304e,0x301f,0x2ff1,0x2fc3,0x2f96,0x2f69,0x2f3c,0x2f10,0x2ee3,0x2eb8,0x2e8c,0x2e61,0x2e36,0x2e0c,0x2de1,0x2db7,0x2d8e,0x2d64,0x2d3b,0x2d13,0x2cea,0x2cc2,0x2c9a,0x2c72,0x2c4b,0x2c24,0x2bfd,0x2bd6,0x2bb0,0x2b8a,0x2b64,0x2b3f,0x2b19,0x2af4,0x2ad0,0x2aab,0x2a87,0x2a63,0x2a3f,0x2a1b,0x29f8,0x29d5,0x29b2,0x298f,0x296d,0x294b,0x2929,0x2907,0x28e6,0x28c4,0x28a3,0x2882,0x2861,0x2841,0x2821,0x2800,0x27e1,0x27c1,0x27a1,0x2782,0x2763,0x2744,0x2725,0x2707,0x26e8,0x26ca,0x26ac,0x268e,0x2671,0x2653,0x2636,0x2619,0x25fc,0x25df,0x25c3,0x25a6,0x258a,0x256e,0x2552,0x2536,0x251a,0x24ff,0x24e4,0x24c9,0x24ae,0x2493,0x2478,0x245e,0x2443,0x2429,0x240f,0x23f5,0x23db,0x23c2,0x23a8,0x238f,0x2376,0x235c,0x2343,0x232b,0x2312,0x22fa,0x22e1,0x22c9,0x22b1,0x2299,0x2281,0x2269,0x2251,0x223a,0x2223,0x220b,0x21f4,0x21dd,0x21c6,0x21b0,0x2199,0x2183,0x216c,0x2156,0x2140,0x212a,0x2114,0x20fe,0x20e8,0x20d3,0x20bd,0x20a8,0x2092,0x207d,0x2068,0x2053,0x203e,0x202a,0x2015,0x2000,0x1fec,0x1fd8,0x1fc4,0x1faf,0x1f9b,0x1f87,0x1f74,0x1f60,0x1f4c,0x1f39,0x1f25,0x1f12,0x1eff,0x1eeb,0x1ed8,0x1ec5,0x1eb3,0x1ea0,0x1e8d,0x1e7a,0x1e68,0x1e55,0x1e43,0x1e31,0x1e1f,0x1e0d,0x1dfb,0x1de9,0x1dd7,0x1dc5,0x1db3,0x1da2,0x1d90,0x1d7f,0x1d6d,0x1d5c,0x1d4b,0x1d3a,0x1d29,0x1d18,0x1d07,0x1cf6,0x1ce5,0x1cd5,0x1cc4,0x1cb4,0x1ca3,0x1c93,0x1c82,0x1c72,0x1c62,0x1c52,0x1c42,0x1c32,0x1c22,0x1c12,0x1c03,0x1bf3,0x1be3,0x1bd4,0x1bc5,0x1bb5,0x1ba6,0x1b97,0x1b87,0x1b78,0x1b69,0x1b5a,0x1b4b,0x1b3c,0x1b2e,0x1b1f,0x1b10,0x1b02,0x1af3,0x1ae5,0x1ad6,0x1ac8,0x1ab9,0x1aab,0x1a9d,0x1a8f,0x1a81,0x1a73,0x1a65,0x1a57,0x1a49,0x1a3b,0x1a2e,0x1a20,0x1a12,0x1a05,0x19f7,0x19ea,0x19dc,0x19cf,0x19c2,0x19b4,0x19a7,0x199a,0x198d,0x1980,0x1973,0x1966,0x1959,0x194c,0x1940,0x1933,0x1926,0x191a,0x190d,0x1900,0x18f4,0x18e8,0x18db,0x18cf,0x18c3,0x18b6,0x18aa,0x189e,0x1892,0x1886,0x187a,0x186e,0x1862,0x1856,0x184a,0x183f,0x1833,0x1827,0x181b,0x1810,0x1804,0x17f9,0x17ed,0x17e2,0x17d7,0x17cb,0x17c0,0x17b5,0x17a9,0x179e,0x1793,0x1788,0x177d,0x1772,0x1767,0x175c,0x1751,0x1746,0x173c,0x1731,0x1726,0x171b,0x1711,0x1706,0x16fb,0x16f1,0x16e6,0x16dc,0x16d1,0x16c7,0x16bd,0x16b2,0x16a8,0x169e,0x1694,0x168a,0x167f,0x1675,0x166b,0x1661,0x1657,0x164d,0x1643,0x1639,0x1630,0x1626,0x161c,0x1612,0x1608,0x15ff,0x15f5,0x15eb,0x15e2,0x15d8,0x15cf,0x15c5,0x15bc,0x15b2,0x15a9,0x15a0,0x1596,0x158d,0x1584,0x157a,0x1571,0x1568,0x155f,0x1556,0x154d,0x1544,0x153b,0x1532,0x1529,0x1520,0x1517,0x150e,0x1505,0x14fc,0x14f4,0x14eb,0x14e2,0x14d9,0x14d1,0x14c8,0x14bf,0x14b7,0x14ae,0x14a6,0x149d,0x1495,0x148c,0x1484,0x147b,0x1473,0x146b,0x1462,0x145a,0x1452,0x144a,0x1441,0x1439,0x1431,0x1429,0x1421,0x1419,0x1411,0x1409,0x1400,0x13f9,0x13f1,0x13e9,0x13e1,0x13d9,0x13d1,0x13c9,0x13c1,0x13b9,0x13b2,0x13aa,0x13a2,0x139b,0x1393,0x138b,0x1384,0x137c,0x1374,0x136d,0x1365,0x135e,0x1356,0x134f,0x1347,0x1340,0x1339,0x1331,0x132a,0x1323,0x131b,0x1314,0x130d,0x1305,0x12fe,0x12f7,0x12f0,0x12e9,0x12e2,0x12da,0x12d3,0x12cc,0x12c5,0x12be,0x12b7,0x12b0,0x12a9,0x12a2,0x129b,0x1294,0x128d,0x1287,0x1280,0x1279,0x1272,0x126b,0x1265,0x125e,0x1257,0x1250,0x124a,0x1243,0x123c,0x1236,0x122f,0x1228,0x1222,0x121b,0x1215,0x120e,0x1208,0x1201,0x11fb,0x11f4,0x11ee,0x11e7,0x11e1,0x11db,0x11d4,0x11ce,0x11c8,0x11c1,0x11bb,0x11b5,0x11ae,0x11a8,0x11a2,0x119c,0x1196,0x118f,0x1189,0x1183,0x117d,0x1177,0x1171,0x116b,0x1165,0x115f,0x1159,0x1153,0x114d,0x1147,0x1141,0x113b,0x1135,0x112f,0x1129,0x1123,0x111d,0x1117,0x1112,0x110c,0x1106,0x1100,0x10fa,0x10f5,0x10ef,0x10e9,0x10e3,0x10de,0x10d8,0x10d2,0x10cd,0x10c7,0x10c2,0x10bc,0x10b6,0x10b1,0x10ab,0x10a6,0x10a0,0x109b,0x1095,0x1090,0x108a,0x1085,0x107f,0x107a,0x1074,0x106f,0x106a,0x1064,0x105f,0x1059,0x1054,0x104f,0x1049,0x1044,0x103f,0x103a,0x1034,0x102f,0x102a,0x1025,0x101f,0x101a,0x1015,0x1010,0x100b,0x1006,0x1000,0x0ffb,0x0ff6,0x0ff1,0x0fec,0x0fe7,0x0fe2,0x0fdd,0x0fd8,0x0fd3,0x0fce,0x0fc9,0x0fc4,0x0fbf,0x0fba,0x0fb5,0x0fb0,0x0fab,0x0fa6,0x0fa1,0x0f9d,0x0f98,0x0f93,0x0f8e,0x0f89,0x0f84,0x0f80,0x0f7b,0x0f76,0x0f71,0x0f6c,0x0f68,0x0f63,0x0f5e,0x0f5a,0x0f55,0x0f50,0x0f4b,0x0f47,0x0f42,0x0f3d,0x0f39,0x0f34,0x0f30,0x0f2b,0x0f26,0x0f22,0x0f1d,0x0f19,0x0f14,0x0f10,0x0f0b,0x0f07,0x0f02,0x0efe,0x0ef9,0x0ef5,0x0ef0,0x0eec,0x0ee7,0x0ee3,0x0ede,0x0eda,0x0ed5,0x0ed1,0x0ecd,0x0ec8,0x0ec4,0x0ec0,0x0ebb,0x0eb7,0x0eb3,0x0eae,0x0eaa,0x0ea6,0x0ea1,0x0e9d,0x0e99,0x0e95,0x0e90,0x0e8c,0x0e88,0x0e84,0x0e7f,0x0e7b,0x0e77,0x0e73,0x0e6f,0x0e6b,0x0e66,0x0e62,0x0e5e,0x0e5a,0x0e56,0x0e52,0x0e4e,0x0e4a,0x0e46,0x0e41,0x0e3d,0x0e39,0x0e35,0x0e31,0x0e2d,0x0e29,0x0e25,0x0e21,0x0e1d,0x0e19,0x0e15,0x0e11,0x0e0d,0x0e09,0x0e06,0x0e02,0x0dfe,0x0dfa,0x0df6,0x0df2,0x0dee,0x0dea,0x0de6,0x0de3,0x0ddf,0x0ddb,0x0dd7,0x0dd3,0x0dcf,0x0dcc,0x0dc8,0x0dc4,0x0dc0,0x0dbc,0x0db9,0x0db5,0x0db1,0x0dad,0x0daa,0x0da6,0x0da2,0x0d9e,0x0d9b,0x0d97,0x0d93,0x0d90,0x0d8c,0x0d88,0x0d85,0x0d81,0x0d7d,0x0d7a,0x0d76,0x0d73,0x0d6f,0x0d6b,0x0d68,0x0d64,0x0d61,0x0d5d,0x0d59,0x0d56,0x0d52,0x0d4f,0x0d4b,0x0d48,0x0d44,0x0d41,0x0d3d,0x0d3a,0x0d36,0x0d33,0x0d2f,0x0d2c,0x0d28,0x0d25,0x0d21,0x0d1e,0x0d1a,0x0d17,0x0d14,0x0d10,0x0d0d,0x0d09,0x0d06,0x0d03,0x0cff,0x0cfc,0x0cf8,0x0cf5,0x0cf2,0x0cee,0x0ceb,0x0ce8,0x0ce4,0x0ce1,0x0cde,0x0cda,0x0cd7,0x0cd4,0x0cd1,0x0ccd,0x0cca,0x0cc7,0x0cc3,0x0cc0,0x0cbd,0x0cba,0x0cb7,0x0cb3,0x0cb0,0x0cad,0x0caa,0x0ca6,0x0ca3,0x0ca0,0x0c9d,0x0c9a,0x0c97,0x0c93,0x0c90,0x0c8d,0x0c8a,0x0c87,0x0c84,0x0c80};

//Band 2 start Address: 0x006A68 (21024 + startaddr)
int16 lookUp2[] = {0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7ebc,0x7d7e,0x7c46,0x7b14,0x79e8,0x78c2,0x77a1,0x7685,0x756f,0x745e,0x7351,0x724a,0x7147,0x7048,0x6f4e,0x6e59,0x6d67,0x6c7a,0x6b91,0x6aab,0x69c9,0x68ec,0x6811,0x673a,0x6667,0x6597,0x64ca,0x6400,0x633a,0x6277,0x61b6,0x60f9,0x603e,0x5f86,0x5ed1,0x5e1f,0x5d6f,0x5cc1,0x5c17,0x5b6e,0x5ac8,0x5a25,0x5983,0x58e4,0x5847,0x57ac,0x5714,0x567d,0x55e8,0x5556,0x54c5,0x5436,0x53a9,0x531e,0x5295,0x520e,0x5188,0x5104,0x5081,0x5000,0x4f81,0x4f04,0x4e88,0x4e0d,0x4d94,0x4d1c,0x4ca6,0x4c31,0x4bbe,0x4b4c,0x4adb,0x4a6c,0x49fe,0x4991,0x4925,0x48bb,0x4851,0x47e9,0x4783,0x471d,0x46b8,0x4655,0x45f3,0x4591,0x4531,0x44d2,0x4473,0x4416,0x43ba,0x435f,0x4305,0x42ab,0x4253,0x41fb,0x41a5,0x414f,0x40fa,0x40a6,0x4053,0x4000,0x3faf,0x3f5e,0x3f0e,0x3ebf,0x3e71,0x3e23,0x3dd6,0x3d8a,0x3d3f,0x3cf4,0x3caa,0x3c61,0x3c19,0x3bd1,0x3b89,0x3b43,0x3afd,0x3ab8,0x3a73,0x3a2f,0x39ec,0x39a9,0x3967,0x3925,0x38e4,0x38a4,0x3864,0x3824,0x37e6,0x37a7,0x376a,0x372d,0x36f0,0x36b4,0x3678,0x363d,0x3603,0x35c9,0x358f,0x3556,0x351d,0x34e5,0x34ad,0x3476,0x343f,0x3409,0x33d3,0x339d,0x3368,0x3334,0x32ff,0x32cc,0x3298,0x3265,0x3233,0x3200,0x31cf,0x319d,0x316c,0x313c,0x310b,0x30db,0x30ac,0x307d,0x304e,0x301f,0x2ff1,0x2fc3,0x2f96,0x2f69,0x2f3c,0x2f10,0x2ee3,0x2eb8,0x2e8c,0x2e61,0x2e36,0x2e0c,0x2de1,0x2db7,0x2d8e,0x2d64,0x2d3b,0x2d13,0x2cea,0x2cc2,0x2c9a,0x2c72,0x2c4b,0x2c24,0x2bfd,0x2bd6,0x2bb0,0x2b8a,0x2b64,0x2b3f,0x2b19,0x2af4,0x2ad0,0x2aab,0x2a87,0x2a63,0x2a3f,0x2a1b,0x29f8,0x29d5,0x29b2,0x298f,0x296d,0x294b,0x2929,0x2907,0x28e6,0x28c4,0x28a3,0x2882,0x2861,0x2841,0x2821,0x2800,0x27e1,0x27c1,0x27a1,0x2782,0x2763,0x2744,0x2725,0x2707,0x26e8,0x26ca,0x26ac,0x268e,0x2671,0x2653,0x2636,0x2619,0x25fc,0x25df,0x25c3,0x25a6,0x258a,0x256e,0x2552,0x2536,0x251a,0x24ff,0x24e4,0x24c9,0x24ae,0x2493,0x2478,0x245e,0x2443,0x2429,0x240f,0x23f5,0x23db,0x23c2,0x23a8,0x238f,0x2376,0x235c,0x2343,0x232b,0x2312,0x22fa,0x22e1,0x22c9,0x22b1,0x2299,0x2281,0x2269,0x2251,0x223a,0x2223,0x220b,0x21f4,0x21dd,0x21c6,0x21b0,0x2199,0x2183,0x216c,0x2156,0x2140,0x212a,0x2114,0x20fe,0x20e8,0x20d3,0x20bd,0x20a8,0x2092,0x207d,0x2068,0x2053,0x203e,0x202a,0x2015,0x2000,0x1fec,0x1fd8,0x1fc4,0x1faf,0x1f9b,0x1f87,0x1f74,0x1f60,0x1f4c,0x1f39,0x1f25,0x1f12,0x1eff,0x1eeb,0x1ed8,0x1ec5,0x1eb3,0x1ea0,0x1e8d,0x1e7a,0x1e68,0x1e55,0x1e43,0x1e31,0x1e1f,0x1e0d,0x1dfb,0x1de9,0x1dd7,0x1dc5,0x1db3,0x1da2,0x1d90,0x1d7f,0x1d6d,0x1d5c,0x1d4b,0x1d3a,0x1d29,0x1d18,0x1d07,0x1cf6,0x1ce5,0x1cd5,0x1cc4,0x1cb4,0x1ca3,0x1c93,0x1c82,0x1c72,0x1c62,0x1c52,0x1c42,0x1c32,0x1c22,0x1c12,0x1c03,0x1bf3,0x1be3,0x1bd4,0x1bc5,0x1bb5,0x1ba6,0x1b97,0x1b87,0x1b78,0x1b69,0x1b5a,0x1b4b,0x1b3c,0x1b2e,0x1b1f,0x1b10,0x1b02,0x1af3,0x1ae5,0x1ad6,0x1ac8,0x1ab9,0x1aab,0x1a9d,0x1a8f,0x1a81,0x1a73,0x1a65,0x1a57,0x1a49,0x1a3b,0x1a2e,0x1a20,0x1a12,0x1a05,0x19f7,0x19ea,0x19dc,0x19cf,0x19c2,0x19b4,0x19a7,0x199a,0x198d,0x1980,0x1973,0x1966,0x1959,0x194c,0x1940,0x1933,0x1926,0x191a,0x190d,0x1900,0x18f4,0x18e8,0x18db,0x18cf,0x18c3,0x18b6,0x18aa,0x189e,0x1892,0x1886,0x187a,0x186e,0x1862,0x1856,0x184a,0x183f,0x1833,0x1827,0x181b,0x1810,0x1804,0x17f9,0x17ed,0x17e2,0x17d7,0x17cb,0x17c0,0x17b5,0x17a9,0x179e,0x1793,0x1788,0x177d,0x1772,0x1767,0x175c,0x1751,0x1746,0x173c,0x1731,0x1726,0x171b,0x1711,0x1706,0x16fb,0x16f1,0x16e6,0x16dc,0x16d1,0x16c7,0x16bd,0x16b2,0x16a8,0x169e,0x1694,0x168a,0x167f,0x1675,0x166b,0x1661,0x1657,0x164d,0x1643,0x1639,0x1630,0x1626,0x161c,0x1612,0x1608,0x15ff,0x15f5,0x15eb,0x15e2,0x15d8,0x15cf,0x15c5,0x15bc,0x15b2,0x15a9,0x15a0,0x1596,0x158d,0x1584,0x157a,0x1571,0x1568,0x155f,0x1556,0x154d,0x1544,0x153b,0x1532,0x1529,0x1520,0x1517,0x150e,0x1505,0x14fc,0x14f4,0x14eb,0x14e2,0x14d9,0x14d1,0x14c8,0x14bf,0x14b7,0x14ae,0x14a6,0x149d,0x1495,0x148c,0x1484,0x147b,0x1473,0x146b,0x1462,0x145a,0x1452,0x144a,0x1441,0x1439,0x1431,0x1429,0x1421,0x1419,0x1411,0x1409,0x1400,0x13f9,0x13f1,0x13e9,0x13e1,0x13d9,0x13d1,0x13c9,0x13c1,0x13b9,0x13b2,0x13aa,0x13a2,0x139b,0x1393,0x138b,0x1384,0x137c,0x1374,0x136d,0x1365,0x135e,0x1356,0x134f,0x1347,0x1340,0x1339,0x1331,0x132a,0x1323,0x131b,0x1314,0x130d,0x1305,0x12fe,0x12f7,0x12f0,0x12e9,0x12e2,0x12da,0x12d3,0x12cc,0x12c5,0x12be,0x12b7,0x12b0,0x12a9,0x12a2,0x129b,0x1294,0x128d,0x1287,0x1280,0x1279,0x1272,0x126b,0x1265,0x125e,0x1257,0x1250,0x124a,0x1243,0x123c,0x1236,0x122f,0x1228,0x1222,0x121b,0x1215,0x120e,0x1208,0x1201,0x11fb,0x11f4,0x11ee,0x11e7,0x11e1,0x11db,0x11d4,0x11ce,0x11c8,0x11c1,0x11bb,0x11b5,0x11ae,0x11a8,0x11a2,0x119c,0x1196,0x118f,0x1189,0x1183,0x117d,0x1177,0x1171,0x116b,0x1165,0x115f,0x1159,0x1153,0x114d,0x1147,0x1141,0x113b,0x1135,0x112f,0x1129,0x1123,0x111d,0x1117,0x1112,0x110c,0x1106,0x1100,0x10fa,0x10f5,0x10ef,0x10e9,0x10e3,0x10de,0x10d8,0x10d2,0x10cd,0x10c7,0x10c2,0x10bc,0x10b6,0x10b1,0x10ab,0x10a6,0x10a0,0x109b,0x1095,0x1090,0x108a,0x1085,0x107f,0x107a,0x1074,0x106f,0x106a,0x1064,0x105f,0x1059,0x1054,0x104f,0x1049,0x1044,0x103f,0x103a,0x1034,0x102f,0x102a,0x1025,0x101f,0x101a,0x1015,0x1010,0x100b,0x1006,0x1000,0x0ffb,0x0ff6,0x0ff1,0x0fec,0x0fe7,0x0fe2,0x0fdd,0x0fd8,0x0fd3,0x0fce,0x0fc9,0x0fc4,0x0fbf,0x0fba,0x0fb5,0x0fb0,0x0fab,0x0fa6,0x0fa1,0x0f9d,0x0f98,0x0f93,0x0f8e,0x0f89,0x0f84,0x0f80,0x0f7b,0x0f76,0x0f71,0x0f6c,0x0f68,0x0f63,0x0f5e,0x0f5a,0x0f55,0x0f50,0x0f4b,0x0f47,0x0f42,0x0f3d,0x0f39,0x0f34,0x0f30,0x0f2b,0x0f26,0x0f22,0x0f1d,0x0f19,0x0f14,0x0f10,0x0f0b,0x0f07,0x0f02,0x0efe,0x0ef9,0x0ef5,0x0ef0,0x0eec,0x0ee7,0x0ee3,0x0ede,0x0eda,0x0ed5,0x0ed1,0x0ecd,0x0ec8,0x0ec4,0x0ec0,0x0ebb,0x0eb7,0x0eb3,0x0eae,0x0eaa,0x0ea6,0x0ea1,0x0e9d,0x0e99,0x0e95,0x0e90,0x0e8c,0x0e88,0x0e84,0x0e7f,0x0e7b,0x0e77,0x0e73,0x0e6f,0x0e6b,0x0e66,0x0e62,0x0e5e,0x0e5a,0x0e56,0x0e52,0x0e4e,0x0e4a,0x0e46,0x0e41,0x0e3d,0x0e39,0x0e35,0x0e31,0x0e2d,0x0e29,0x0e25,0x0e21,0x0e1d,0x0e19,0x0e15,0x0e11,0x0e0d,0x0e09,0x0e06,0x0e02,0x0dfe,0x0dfa,0x0df6,0x0df2,0x0dee,0x0dea,0x0de6,0x0de3,0x0ddf,0x0ddb,0x0dd7,0x0dd3,0x0dcf,0x0dcc,0x0dc8,0x0dc4,0x0dc0,0x0dbc,0x0db9,0x0db5,0x0db1,0x0dad,0x0daa,0x0da6,0x0da2,0x0d9e,0x0d9b,0x0d97,0x0d93,0x0d90,0x0d8c,0x0d88,0x0d85,0x0d81,0x0d7d,0x0d7a,0x0d76,0x0d73,0x0d6f,0x0d6b,0x0d68,0x0d64,0x0d61,0x0d5d,0x0d59,0x0d56,0x0d52,0x0d4f,0x0d4b,0x0d48,0x0d44,0x0d41,0x0d3d,0x0d3a,0x0d36,0x0d33,0x0d2f,0x0d2c,0x0d28,0x0d25,0x0d21,0x0d1e,0x0d1a,0x0d17,0x0d14,0x0d10,0x0d0d,0x0d09,0x0d06,0x0d03,0x0cff,0x0cfc,0x0cf8,0x0cf5,0x0cf2,0x0cee,0x0ceb,0x0ce8,0x0ce4,0x0ce1,0x0cde,0x0cda,0x0cd7,0x0cd4,0x0cd1,0x0ccd,0x0cca,0x0cc7,0x0cc3,0x0cc0,0x0cbd,0x0cba,0x0cb7,0x0cb3,0x0cb0,0x0cad,0x0caa,0x0ca6,0x0ca3,0x0ca0,0x0c9d,0x0c9a,0x0c97,0x0c93,0x0c90,0x0c8d,0x0c8a,0x0c87,0x0c84,0x0c80};

//Band 3 start Address: 0x006680 (22048 + startaddr)
int16 lookUp3[] = {0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7ebc,0x7d7e,0x7c46,0x7b14,0x79e8,0x78c2,0x77a1,0x7685,0x756f,0x745e,0x7351,0x724a,0x7147,0x7048,0x6f4e,0x6e59,0x6d67,0x6c7a,0x6b91,0x6aab,0x69c9,0x68ec,0x6811,0x673a,0x6667,0x6597,0x64ca,0x6400,0x633a,0x6277,0x61b6,0x60f9,0x603e,0x5f86,0x5ed1,0x5e1f,0x5d6f,0x5cc1,0x5c17,0x5b6e,0x5ac8,0x5a25,0x5983,0x58e4,0x5847,0x57ac,0x5714,0x567d,0x55e8,0x5556,0x54c5,0x5436,0x53a9,0x531e,0x5295,0x520e,0x5188,0x5104,0x5081,0x5000,0x4f81,0x4f04,0x4e88,0x4e0d,0x4d94,0x4d1c,0x4ca6,0x4c31,0x4bbe,0x4b4c,0x4adb,0x4a6c,0x49fe,0x4991,0x4925,0x48bb,0x4851,0x47e9,0x4783,0x471d,0x46b8,0x4655,0x45f3,0x4591,0x4531,0x44d2,0x4473,0x4416,0x43ba,0x435f,0x4305,0x42ab,0x4253,0x41fb,0x41a5,0x414f,0x40fa,0x40a6,0x4053,0x4000,0x3faf,0x3f5e,0x3f0e,0x3ebf,0x3e71,0x3e23,0x3dd6,0x3d8a,0x3d3f,0x3cf4,0x3caa,0x3c61,0x3c19,0x3bd1,0x3b89,0x3b43,0x3afd,0x3ab8,0x3a73,0x3a2f,0x39ec,0x39a9,0x3967,0x3925,0x38e4,0x38a4,0x3864,0x3824,0x37e6,0x37a7,0x376a,0x372d,0x36f0,0x36b4,0x3678,0x363d,0x3603,0x35c9,0x358f,0x3556,0x351d,0x34e5,0x34ad,0x3476,0x343f,0x3409,0x33d3,0x339d,0x3368,0x3334,0x32ff,0x32cc,0x3298,0x3265,0x3233,0x3200,0x31cf,0x319d,0x316c,0x313c,0x310b,0x30db,0x30ac,0x307d,0x304e,0x301f,0x2ff1,0x2fc3,0x2f96,0x2f69,0x2f3c,0x2f10,0x2ee3,0x2eb8,0x2e8c,0x2e61,0x2e36,0x2e0c,0x2de1,0x2db7,0x2d8e,0x2d64,0x2d3b,0x2d13,0x2cea,0x2cc2,0x2c9a,0x2c72,0x2c4b,0x2c24,0x2bfd,0x2bd6,0x2bb0,0x2b8a,0x2b64,0x2b3f,0x2b19,0x2af4,0x2ad0,0x2aab,0x2a87,0x2a63,0x2a3f,0x2a1b,0x29f8,0x29d5,0x29b2,0x298f,0x296d,0x294b,0x2929,0x2907,0x28e6,0x28c4,0x28a3,0x2882,0x2861,0x2841,0x2821,0x2800,0x27e1,0x27c1,0x27a1,0x2782,0x2763,0x2744,0x2725,0x2707,0x26e8,0x26ca,0x26ac,0x268e,0x2671,0x2653,0x2636,0x2619,0x25fc,0x25df,0x25c3,0x25a6,0x258a,0x256e,0x2552,0x2536,0x251a,0x24ff,0x24e4,0x24c9,0x24ae,0x2493,0x2478,0x245e,0x2443,0x2429,0x240f,0x23f5,0x23db,0x23c2,0x23a8,0x238f,0x2376,0x235c,0x2343,0x232b,0x2312,0x22fa,0x22e1,0x22c9,0x22b1,0x2299,0x2281,0x2269,0x2251,0x223a,0x2223,0x220b,0x21f4,0x21dd,0x21c6,0x21b0,0x2199,0x2183,0x216c,0x2156,0x2140,0x212a,0x2114,0x20fe,0x20e8,0x20d3,0x20bd,0x20a8,0x2092,0x207d,0x2068,0x2053,0x203e,0x202a,0x2015,0x2000,0x1fec,0x1fd8,0x1fc4,0x1faf,0x1f9b,0x1f87,0x1f74,0x1f60,0x1f4c,0x1f39,0x1f25,0x1f12,0x1eff,0x1eeb,0x1ed8,0x1ec5,0x1eb3,0x1ea0,0x1e8d,0x1e7a,0x1e68,0x1e55,0x1e43,0x1e31,0x1e1f,0x1e0d,0x1dfb,0x1de9,0x1dd7,0x1dc5,0x1db3,0x1da2,0x1d90,0x1d7f,0x1d6d,0x1d5c,0x1d4b,0x1d3a,0x1d29,0x1d18,0x1d07,0x1cf6,0x1ce5,0x1cd5,0x1cc4,0x1cb4,0x1ca3,0x1c93,0x1c82,0x1c72,0x1c62,0x1c52,0x1c42,0x1c32,0x1c22,0x1c12,0x1c03,0x1bf3,0x1be3,0x1bd4,0x1bc5,0x1bb5,0x1ba6,0x1b97,0x1b87,0x1b78,0x1b69,0x1b5a,0x1b4b,0x1b3c,0x1b2e,0x1b1f,0x1b10,0x1b02,0x1af3,0x1ae5,0x1ad6,0x1ac8,0x1ab9,0x1aab,0x1a9d,0x1a8f,0x1a81,0x1a73,0x1a65,0x1a57,0x1a49,0x1a3b,0x1a2e,0x1a20,0x1a12,0x1a05,0x19f7,0x19ea,0x19dc,0x19cf,0x19c2,0x19b4,0x19a7,0x199a,0x198d,0x1980,0x1973,0x1966,0x1959,0x194c,0x1940,0x1933,0x1926,0x191a,0x190d,0x1900,0x18f4,0x18e8,0x18db,0x18cf,0x18c3,0x18b6,0x18aa,0x189e,0x1892,0x1886,0x187a,0x186e,0x1862,0x1856,0x184a,0x183f,0x1833,0x1827,0x181b,0x1810,0x1804,0x17f9,0x17ed,0x17e2,0x17d7,0x17cb,0x17c0,0x17b5,0x17a9,0x179e,0x1793,0x1788,0x177d,0x1772,0x1767,0x175c,0x1751,0x1746,0x173c,0x1731,0x1726,0x171b,0x1711,0x1706,0x16fb,0x16f1,0x16e6,0x16dc,0x16d1,0x16c7,0x16bd,0x16b2,0x16a8,0x169e,0x1694,0x168a,0x167f,0x1675,0x166b,0x1661,0x1657,0x164d,0x1643,0x1639,0x1630,0x1626,0x161c,0x1612,0x1608,0x15ff,0x15f5,0x15eb,0x15e2,0x15d8,0x15cf,0x15c5,0x15bc,0x15b2,0x15a9,0x15a0,0x1596,0x158d,0x1584,0x157a,0x1571,0x1568,0x155f,0x1556,0x154d,0x1544,0x153b,0x1532,0x1529,0x1520,0x1517,0x150e,0x1505,0x14fc,0x14f4,0x14eb,0x14e2,0x14d9,0x14d1,0x14c8,0x14bf,0x14b7,0x14ae,0x14a6,0x149d,0x1495,0x148c,0x1484,0x147b,0x1473,0x146b,0x1462,0x145a,0x1452,0x144a,0x1441,0x1439,0x1431,0x1429,0x1421,0x1419,0x1411,0x1409,0x1400,0x13f9,0x13f1,0x13e9,0x13e1,0x13d9,0x13d1,0x13c9,0x13c1,0x13b9,0x13b2,0x13aa,0x13a2,0x139b,0x1393,0x138b,0x1384,0x137c,0x1374,0x136d,0x1365,0x135e,0x1356,0x134f,0x1347,0x1340,0x1339,0x1331,0x132a,0x1323,0x131b,0x1314,0x130d,0x1305,0x12fe,0x12f7,0x12f0,0x12e9,0x12e2,0x12da,0x12d3,0x12cc,0x12c5,0x12be,0x12b7,0x12b0,0x12a9,0x12a2,0x129b,0x1294,0x128d,0x1287,0x1280,0x1279,0x1272,0x126b,0x1265,0x125e,0x1257,0x1250,0x124a,0x1243,0x123c,0x1236,0x122f,0x1228,0x1222,0x121b,0x1215,0x120e,0x1208,0x1201,0x11fb,0x11f4,0x11ee,0x11e7,0x11e1,0x11db,0x11d4,0x11ce,0x11c8,0x11c1,0x11bb,0x11b5,0x11ae,0x11a8,0x11a2,0x119c,0x1196,0x118f,0x1189,0x1183,0x117d,0x1177,0x1171,0x116b,0x1165,0x115f,0x1159,0x1153,0x114d,0x1147,0x1141,0x113b,0x1135,0x112f,0x1129,0x1123,0x111d,0x1117,0x1112,0x110c,0x1106,0x1100,0x10fa,0x10f5,0x10ef,0x10e9,0x10e3,0x10de,0x10d8,0x10d2,0x10cd,0x10c7,0x10c2,0x10bc,0x10b6,0x10b1,0x10ab,0x10a6,0x10a0,0x109b,0x1095,0x1090,0x108a,0x1085,0x107f,0x107a,0x1074,0x106f,0x106a,0x1064,0x105f,0x1059,0x1054,0x104f,0x1049,0x1044,0x103f,0x103a,0x1034,0x102f,0x102a,0x1025,0x101f,0x101a,0x1015,0x1010,0x100b,0x1006,0x1000,0x0ffb,0x0ff6,0x0ff1,0x0fec,0x0fe7,0x0fe2,0x0fdd,0x0fd8,0x0fd3,0x0fce,0x0fc9,0x0fc4,0x0fbf,0x0fba,0x0fb5,0x0fb0,0x0fab,0x0fa6,0x0fa1,0x0f9d,0x0f98,0x0f93,0x0f8e,0x0f89,0x0f84,0x0f80,0x0f7b,0x0f76,0x0f71,0x0f6c,0x0f68,0x0f63,0x0f5e,0x0f5a,0x0f55,0x0f50,0x0f4b,0x0f47,0x0f42,0x0f3d,0x0f39,0x0f34,0x0f30,0x0f2b,0x0f26,0x0f22,0x0f1d,0x0f19,0x0f14,0x0f10,0x0f0b,0x0f07,0x0f02,0x0efe,0x0ef9,0x0ef5,0x0ef0,0x0eec,0x0ee7,0x0ee3,0x0ede,0x0eda,0x0ed5,0x0ed1,0x0ecd,0x0ec8,0x0ec4,0x0ec0,0x0ebb,0x0eb7,0x0eb3,0x0eae,0x0eaa,0x0ea6,0x0ea1,0x0e9d,0x0e99,0x0e95,0x0e90,0x0e8c,0x0e88,0x0e84,0x0e7f,0x0e7b,0x0e77,0x0e73,0x0e6f,0x0e6b,0x0e66,0x0e62,0x0e5e,0x0e5a,0x0e56,0x0e52,0x0e4e,0x0e4a,0x0e46,0x0e41,0x0e3d,0x0e39,0x0e35,0x0e31,0x0e2d,0x0e29,0x0e25,0x0e21,0x0e1d,0x0e19,0x0e15,0x0e11,0x0e0d,0x0e09,0x0e06,0x0e02,0x0dfe,0x0dfa,0x0df6,0x0df2,0x0dee,0x0dea,0x0de6,0x0de3,0x0ddf,0x0ddb,0x0dd7,0x0dd3,0x0dcf,0x0dcc,0x0dc8,0x0dc4,0x0dc0,0x0dbc,0x0db9,0x0db5,0x0db1,0x0dad,0x0daa,0x0da6,0x0da2,0x0d9e,0x0d9b,0x0d97,0x0d93,0x0d90,0x0d8c,0x0d88,0x0d85,0x0d81,0x0d7d,0x0d7a,0x0d76,0x0d73,0x0d6f,0x0d6b,0x0d68,0x0d64,0x0d61,0x0d5d,0x0d59,0x0d56,0x0d52,0x0d4f,0x0d4b,0x0d48,0x0d44,0x0d41,0x0d3d,0x0d3a,0x0d36,0x0d33,0x0d2f,0x0d2c,0x0d28,0x0d25,0x0d21,0x0d1e,0x0d1a,0x0d17,0x0d14,0x0d10,0x0d0d,0x0d09,0x0d06,0x0d03,0x0cff,0x0cfc,0x0cf8,0x0cf5,0x0cf2,0x0cee,0x0ceb,0x0ce8,0x0ce4,0x0ce1,0x0cde,0x0cda,0x0cd7,0x0cd4,0x0cd1,0x0ccd,0x0cca,0x0cc7,0x0cc3,0x0cc0,0x0cbd,0x0cba,0x0cb7,0x0cb3,0x0cb0,0x0cad,0x0caa,0x0ca6,0x0ca3,0x0ca0,0x0c9d,0x0c9a,0x0c97,0x0c93,0x0c90,0x0c8d,0x0c8a,0x0c87,0x0c84,0x0c80};

//Band 4 start Address: 0x006680 (23072 + startaddr)
int16 lookUp4[] = {0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7ebc,0x7d7e,0x7c46,0x7b14,0x79e8,0x78c2,0x77a1,0x7685,0x756f,0x745e,0x7351,0x724a,0x7147,0x7048,0x6f4e,0x6e59,0x6d67,0x6c7a,0x6b91,0x6aab,0x69c9,0x68ec,0x6811,0x673a,0x6667,0x6597,0x64ca,0x6400,0x633a,0x6277,0x61b6,0x60f9,0x603e,0x5f86,0x5ed1,0x5e1f,0x5d6f,0x5cc1,0x5c17,0x5b6e,0x5ac8,0x5a25,0x5983,0x58e4,0x5847,0x57ac,0x5714,0x567d,0x55e8,0x5556,0x54c5,0x5436,0x53a9,0x531e,0x5295,0x520e,0x5188,0x5104,0x5081,0x5000,0x4f81,0x4f04,0x4e88,0x4e0d,0x4d94,0x4d1c,0x4ca6,0x4c31,0x4bbe,0x4b4c,0x4adb,0x4a6c,0x49fe,0x4991,0x4925,0x48bb,0x4851,0x47e9,0x4783,0x471d,0x46b8,0x4655,0x45f3,0x4591,0x4531,0x44d2,0x4473,0x4416,0x43ba,0x435f,0x4305,0x42ab,0x4253,0x41fb,0x41a5,0x414f,0x40fa,0x40a6,0x4053,0x4000,0x3faf,0x3f5e,0x3f0e,0x3ebf,0x3e71,0x3e23,0x3dd6,0x3d8a,0x3d3f,0x3cf4,0x3caa,0x3c61,0x3c19,0x3bd1,0x3b89,0x3b43,0x3afd,0x3ab8,0x3a73,0x3a2f,0x39ec,0x39a9,0x3967,0x3925,0x38e4,0x38a4,0x3864,0x3824,0x37e6,0x37a7,0x376a,0x372d,0x36f0,0x36b4,0x3678,0x363d,0x3603,0x35c9,0x358f,0x3556,0x351d,0x34e5,0x34ad,0x3476,0x343f,0x3409,0x33d3,0x339d,0x3368,0x3334,0x32ff,0x32cc,0x3298,0x3265,0x3233,0x3200,0x31cf,0x319d,0x316c,0x313c,0x310b,0x30db,0x30ac,0x307d,0x304e,0x301f,0x2ff1,0x2fc3,0x2f96,0x2f69,0x2f3c,0x2f10,0x2ee3,0x2eb8,0x2e8c,0x2e61,0x2e36,0x2e0c,0x2de1,0x2db7,0x2d8e,0x2d64,0x2d3b,0x2d13,0x2cea,0x2cc2,0x2c9a,0x2c72,0x2c4b,0x2c24,0x2bfd,0x2bd6,0x2bb0,0x2b8a,0x2b64,0x2b3f,0x2b19,0x2af4,0x2ad0,0x2aab,0x2a87,0x2a63,0x2a3f,0x2a1b,0x29f8,0x29d5,0x29b2,0x298f,0x296d,0x294b,0x2929,0x2907,0x28e6,0x28c4,0x28a3,0x2882,0x2861,0x2841,0x2821,0x2800,0x27e1,0x27c1,0x27a1,0x2782,0x2763,0x2744,0x2725,0x2707,0x26e8,0x26ca,0x26ac,0x268e,0x2671,0x2653,0x2636,0x2619,0x25fc,0x25df,0x25c3,0x25a6,0x258a,0x256e,0x2552,0x2536,0x251a,0x24ff,0x24e4,0x24c9,0x24ae,0x2493,0x2478,0x245e,0x2443,0x2429,0x240f,0x23f5,0x23db,0x23c2,0x23a8,0x238f,0x2376,0x235c,0x2343,0x232b,0x2312,0x22fa,0x22e1,0x22c9,0x22b1,0x2299,0x2281,0x2269,0x2251,0x223a,0x2223,0x220b,0x21f4,0x21dd,0x21c6,0x21b0,0x2199,0x2183,0x216c,0x2156,0x2140,0x212a,0x2114,0x20fe,0x20e8,0x20d3,0x20bd,0x20a8,0x2092,0x207d,0x2068,0x2053,0x203e,0x202a,0x2015,0x2000,0x1fec,0x1fd8,0x1fc4,0x1faf,0x1f9b,0x1f87,0x1f74,0x1f60,0x1f4c,0x1f39,0x1f25,0x1f12,0x1eff,0x1eeb,0x1ed8,0x1ec5,0x1eb3,0x1ea0,0x1e8d,0x1e7a,0x1e68,0x1e55,0x1e43,0x1e31,0x1e1f,0x1e0d,0x1dfb,0x1de9,0x1dd7,0x1dc5,0x1db3,0x1da2,0x1d90,0x1d7f,0x1d6d,0x1d5c,0x1d4b,0x1d3a,0x1d29,0x1d18,0x1d07,0x1cf6,0x1ce5,0x1cd5,0x1cc4,0x1cb4,0x1ca3,0x1c93,0x1c82,0x1c72,0x1c62,0x1c52,0x1c42,0x1c32,0x1c22,0x1c12,0x1c03,0x1bf3,0x1be3,0x1bd4,0x1bc5,0x1bb5,0x1ba6,0x1b97,0x1b87,0x1b78,0x1b69,0x1b5a,0x1b4b,0x1b3c,0x1b2e,0x1b1f,0x1b10,0x1b02,0x1af3,0x1ae5,0x1ad6,0x1ac8,0x1ab9,0x1aab,0x1a9d,0x1a8f,0x1a81,0x1a73,0x1a65,0x1a57,0x1a49,0x1a3b,0x1a2e,0x1a20,0x1a12,0x1a05,0x19f7,0x19ea,0x19dc,0x19cf,0x19c2,0x19b4,0x19a7,0x199a,0x198d,0x1980,0x1973,0x1966,0x1959,0x194c,0x1940,0x1933,0x1926,0x191a,0x190d,0x1900,0x18f4,0x18e8,0x18db,0x18cf,0x18c3,0x18b6,0x18aa,0x189e,0x1892,0x1886,0x187a,0x186e,0x1862,0x1856,0x184a,0x183f,0x1833,0x1827,0x181b,0x1810,0x1804,0x17f9,0x17ed,0x17e2,0x17d7,0x17cb,0x17c0,0x17b5,0x17a9,0x179e,0x1793,0x1788,0x177d,0x1772,0x1767,0x175c,0x1751,0x1746,0x173c,0x1731,0x1726,0x171b,0x1711,0x1706,0x16fb,0x16f1,0x16e6,0x16dc,0x16d1,0x16c7,0x16bd,0x16b2,0x16a8,0x169e,0x1694,0x168a,0x167f,0x1675,0x166b,0x1661,0x1657,0x164d,0x1643,0x1639,0x1630,0x1626,0x161c,0x1612,0x1608,0x15ff,0x15f5,0x15eb,0x15e2,0x15d8,0x15cf,0x15c5,0x15bc,0x15b2,0x15a9,0x15a0,0x1596,0x158d,0x1584,0x157a,0x1571,0x1568,0x155f,0x1556,0x154d,0x1544,0x153b,0x1532,0x1529,0x1520,0x1517,0x150e,0x1505,0x14fc,0x14f4,0x14eb,0x14e2,0x14d9,0x14d1,0x14c8,0x14bf,0x14b7,0x14ae,0x14a6,0x149d,0x1495,0x148c,0x1484,0x147b,0x1473,0x146b,0x1462,0x145a,0x1452,0x144a,0x1441,0x1439,0x1431,0x1429,0x1421,0x1419,0x1411,0x1409,0x1400,0x13f9,0x13f1,0x13e9,0x13e1,0x13d9,0x13d1,0x13c9,0x13c1,0x13b9,0x13b2,0x13aa,0x13a2,0x139b,0x1393,0x138b,0x1384,0x137c,0x1374,0x136d,0x1365,0x135e,0x1356,0x134f,0x1347,0x1340,0x1339,0x1331,0x132a,0x1323,0x131b,0x1314,0x130d,0x1305,0x12fe,0x12f7,0x12f0,0x12e9,0x12e2,0x12da,0x12d3,0x12cc,0x12c5,0x12be,0x12b7,0x12b0,0x12a9,0x12a2,0x129b,0x1294,0x128d,0x1287,0x1280,0x1279,0x1272,0x126b,0x1265,0x125e,0x1257,0x1250,0x124a,0x1243,0x123c,0x1236,0x122f,0x1228,0x1222,0x121b,0x1215,0x120e,0x1208,0x1201,0x11fb,0x11f4,0x11ee,0x11e7,0x11e1,0x11db,0x11d4,0x11ce,0x11c8,0x11c1,0x11bb,0x11b5,0x11ae,0x11a8,0x11a2,0x119c,0x1196,0x118f,0x1189,0x1183,0x117d,0x1177,0x1171,0x116b,0x1165,0x115f,0x1159,0x1153,0x114d,0x1147,0x1141,0x113b,0x1135,0x112f,0x1129,0x1123,0x111d,0x1117,0x1112,0x110c,0x1106,0x1100,0x10fa,0x10f5,0x10ef,0x10e9,0x10e3,0x10de,0x10d8,0x10d2,0x10cd,0x10c7,0x10c2,0x10bc,0x10b6,0x10b1,0x10ab,0x10a6,0x10a0,0x109b,0x1095,0x1090,0x108a,0x1085,0x107f,0x107a,0x1074,0x106f,0x106a,0x1064,0x105f,0x1059,0x1054,0x104f,0x1049,0x1044,0x103f,0x103a,0x1034,0x102f,0x102a,0x1025,0x101f,0x101a,0x1015,0x1010,0x100b,0x1006,0x1000,0x0ffb,0x0ff6,0x0ff1,0x0fec,0x0fe7,0x0fe2,0x0fdd,0x0fd8,0x0fd3,0x0fce,0x0fc9,0x0fc4,0x0fbf,0x0fba,0x0fb5,0x0fb0,0x0fab,0x0fa6,0x0fa1,0x0f9d,0x0f98,0x0f93,0x0f8e,0x0f89,0x0f84,0x0f80,0x0f7b,0x0f76,0x0f71,0x0f6c,0x0f68,0x0f63,0x0f5e,0x0f5a,0x0f55,0x0f50,0x0f4b,0x0f47,0x0f42,0x0f3d,0x0f39,0x0f34,0x0f30,0x0f2b,0x0f26,0x0f22,0x0f1d,0x0f19,0x0f14,0x0f10,0x0f0b,0x0f07,0x0f02,0x0efe,0x0ef9,0x0ef5,0x0ef0,0x0eec,0x0ee7,0x0ee3,0x0ede,0x0eda,0x0ed5,0x0ed1,0x0ecd,0x0ec8,0x0ec4,0x0ec0,0x0ebb,0x0eb7,0x0eb3,0x0eae,0x0eaa,0x0ea6,0x0ea1,0x0e9d,0x0e99,0x0e95,0x0e90,0x0e8c,0x0e88,0x0e84,0x0e7f,0x0e7b,0x0e77,0x0e73,0x0e6f,0x0e6b,0x0e66,0x0e62,0x0e5e,0x0e5a,0x0e56,0x0e52,0x0e4e,0x0e4a,0x0e46,0x0e41,0x0e3d,0x0e39,0x0e35,0x0e31,0x0e2d,0x0e29,0x0e25,0x0e21,0x0e1d,0x0e19,0x0e15,0x0e11,0x0e0d,0x0e09,0x0e06,0x0e02,0x0dfe,0x0dfa,0x0df6,0x0df2,0x0dee,0x0dea,0x0de6,0x0de3,0x0ddf,0x0ddb,0x0dd7,0x0dd3,0x0dcf,0x0dcc,0x0dc8,0x0dc4,0x0dc0,0x0dbc,0x0db9,0x0db5,0x0db1,0x0dad,0x0daa,0x0da6,0x0da2,0x0d9e,0x0d9b,0x0d97,0x0d93,0x0d90,0x0d8c,0x0d88,0x0d85,0x0d81,0x0d7d,0x0d7a,0x0d76,0x0d73,0x0d6f,0x0d6b,0x0d68,0x0d64,0x0d61,0x0d5d,0x0d59,0x0d56,0x0d52,0x0d4f,0x0d4b,0x0d48,0x0d44,0x0d41,0x0d3d,0x0d3a,0x0d36,0x0d33,0x0d2f,0x0d2c,0x0d28,0x0d25,0x0d21,0x0d1e,0x0d1a,0x0d17,0x0d14,0x0d10,0x0d0d,0x0d09,0x0d06,0x0d03,0x0cff,0x0cfc,0x0cf8,0x0cf5,0x0cf2,0x0cee,0x0ceb,0x0ce8,0x0ce4,0x0ce1,0x0cde,0x0cda,0x0cd7,0x0cd4,0x0cd1,0x0ccd,0x0cca,0x0cc7,0x0cc3,0x0cc0,0x0cbd,0x0cba,0x0cb7,0x0cb3,0x0cb0,0x0cad,0x0caa,0x0ca6,0x0ca3,0x0ca0,0x0c9d,0x0c9a,0x0c97,0x0c93,0x0c90,0x0c8d,0x0c8a,0x0c87,0x0c84,0x0c80};

// RMS Buffer start Address: 0x007620 (24096 + startaddr)
int16 RMSBUFFER[600];



#define OUTPUT 			up1
#define limThreshUp 	20000
#define limThreshDown 	-20000

uint8 Rcv; // 0x002A49
uint8 Xmit; 
//init
extern void initArray1(void);
extern void initArray2(void);
extern void initArray4(void);
extern void initArray8(void);
extern void initArray16(void);
extern void initArray32(void);
extern void initArray64(void);
extern void initArray128(void);

//Down1
extern void downFunc1(int16 dataIn);
//Down2
extern void downFunc2(int16 dataIn);
//Down4
extern void downFunc4(int16 dataIn);
//Down8
extern void downFunc8(int16 dataIn);
//Down16
extern void downFunc16(int16 dataIn);
//Down32
extern void downFunc32(int16 dataIn);
//Down64
extern void downFunc64(int16 dataIn);
//Down128
extern void downFunc128(int16 dataIn);

//Buffer1
extern int16 delayB1(int16 dataIn);
//Buffer2
extern int16 delayB2(int16 dataIn);
//Buffer4
extern int16 delayB4(int16 dataIn);
//Buffer8
extern int16 delayB8(int16 dataIn);
//Buffer16
extern int16 delayB16(int16 dataIn);
//Buffer32
extern int16 delayB32(int16 dataIn);
//Buffer64
extern int16 delayB64(int16 dataIn);
//Buffer128
extern int16 delayB128(int16 dataIn);


//Up1
extern int16 upFunc1(int16 dataIn,int16 band);
//Up2
extern int16 upFunc2(int16 dataIn,int16 band);
//Up4
extern int16 upFunc4(int16 dataIn,int16 band);
//Up8
extern int16 upFunc8(int16 dataIn,int16 band);
//Up16
extern int16 upFunc16(int16 dataIn,int16 band);
//Up32
extern int16 upFunc32(int16 dataIn,int16 band);
//Up64
extern int16 upFunc64(int16 dataIn,int16 band);
//Up128
extern int16 upFunc128(int16 dataIn,int16 band);

//RMS128
extern int16 RMS128(int16 dataIn);
//RMS128 band 
extern int16 RMS128band(int16 dataIn);
//RMS64 band 
extern int16 RMS64band(int16 dataIn);
//RMS32 band 
extern int16 RMS32band(int16 dataIn);
//RMS32 Up 
extern int16 RMS32up(int16 dataIn);


void initialize(uint8 audioType, uint8 resolution, uint8 fs);

int16 COEFF[25] = {13, 48, -15, -209, -181, 380, 813, -86, 
				   -1881, -1642, 2955, 9702, 12971, 9702, 2955, 
				   -1642, -1881, -86, 813, 380, -181, -209, -15, 48 ,13};

void playback(void){
    int16 audioIn = 0;
    
    long temp;
    
    //1
    int16 band1 = 0; 
    int16 down1 = 0;
    int16 up1	= 0;
    int16 delayVar1 = 0; 
 
    //2
    int16 band2 = 0; 
    int16 down2 = 0;
    int16 up2	= 0;
    int16 delayVar2 = 0;
    
    //4
    int16 band4 = 0; 
    int16 down4 = 0;
    int16 up4	= 0;
    int16 delayVar4 = 0;
    
    //8
    int16 band8 = 0; 
    int16 down8 = 0;
    int16 up8	= 0;
    int16 delayVar8 = 0;

    //16
    int16 band16 = 0; 
    int16 down16 = 0;
    int16 up16	= 0;
    int16 delayVar16 = 0;

    //32
    int16 band32 = 0; 
    int16 down32 = 0;
    int16 up32	= 0;
    int16 delayVar32 = 0;

    //64
    int16 band64 = 0; 
    int16 down64 = 0;
    int16 up64	= 0;
    int16 delayVar64 = 0;

    //128
    int16 band128 = 0; 
    int16 down128 = 0;
    int16 up128	= 0;
    int16 delayVar128 = 0;        
     
    // RMS BUFFER 128 Counter
    int16 cntRMS = 0; 
     
    while(1){
/////// SAMPLE 1 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];							
		// DELAY			
			delayVar1 = delayB1(band1);	
		// UP
			up16 = upFunc16(up32,delayVar16);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 2 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc16(down8); 	
			down16 = array[585];	
			band16 = array[584];		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar16 = delayB16(band16);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 3 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 4 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 5 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 6 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 7 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 8 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 9 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up32 = upFunc32(up64,delayVar32);
			up32 = RMS32up(up32);
			temp = up32;
			if (temp>limThreshUp){
				up32 = limThreshUp;
			}
			if (temp<limThreshDown){
				up32 = limThreshDown;
			}
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 10 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
	    	downFunc32(down16); 			
			band32 = array[684];				
			down32 = array[685];
		// RMS
			band32 = RMS32band(band32);					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar32 = delayB32(band32);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 11 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 12 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 13 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 14 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 15 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 16 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;

/////// SAMPLE 17 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];							
		// DELAY			
			delayVar1 = delayB1(band1);	
		// UP
			up16 = upFunc16(up32,delayVar16);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 18 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc16(down8); 	
			down16 = array[585];	
			band16 = array[584];		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar16 = delayB16(band16);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 19 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 20 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 21 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 22 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 23 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 24 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 25 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up64 = upFunc64(up128,delayVar64);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 26 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];			
	    	downFunc64(down32); 			
			band64 = array[784];				
			down64 = array[785];	
		// RMS
			band64 = RMS64band(band64);
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar64 = delayB64(band64);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 27 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 28 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 29 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 30 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 31 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 32 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];				
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;

/////// SAMPLE 33 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];							
		// DELAY			
			delayVar1 = delayB1(band1);	
		// UP
			up16 = upFunc16(up32,delayVar16);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 34 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc16(down8); 	
			down16 = array[585];	
			band16 = array[584];		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar16 = delayB16(band16);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 35 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 36 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 37 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 38 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 39 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 40 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 41 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up32 = upFunc32(up64,delayVar32);
			up32 = RMS32up(up32);
			temp = up32;
			if (temp>limThreshUp){
				up32 = limThreshUp;
			}
			if (temp<limThreshDown){
				up32 = limThreshDown;
			}
			//up32 = up32 > limThreshUp ? limThreshUp : up32;
			//up32 = up32 < limThreshDown ? limThreshDown : up32;
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 42 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
	    	downFunc32(down16); 			
			band32 = array[684];				
			down32 = array[685];
		// RMS
			band32 = RMS32band(band32);					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar32 = delayB32(band32);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 43 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 44 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 45 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 46 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 47 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 48 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;

/////// SAMPLE 49 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];							
		// DELAY			
			delayVar1 = delayB1(band1);	
		// UP
			up16 = upFunc16(up32,delayVar16);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 50 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc16(down8); 	
			down16 = array[585];	
			band16 = array[584];		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar16 = delayB16(band16);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 51 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 52 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 53 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 54 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 55 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 56 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 57 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up128 = upFunc128(down128,delayVar128);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 58 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];					
			downFunc128(down64); 			
			band128 = array[884];				
			down128 = array[885];
		// RMS	
		if (cntRMS == 0){ 
			down128 = RMS128(down128);
			cntRMS = 1;
		} else{
			cntRMS = 0;
		}
		band128 = RMS128band(band128);
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar128 = delayB128(band128);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 59 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 60 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 61 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 62 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 63 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 64 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;

/////// SAMPLE 65 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];							
		// DELAY			
			delayVar1 = delayB1(band1);	
		// UP
			up16 = upFunc16(up32,delayVar16);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 66 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc16(down8); 	
			down16 = array[585];	
			band16 = array[584];		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar16 = delayB16(band16);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 67 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 68 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 69 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 70 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 71 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 72 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 73 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up32 = upFunc32(up64,delayVar32);
			up32 = RMS32up(up32);
			temp = up32;
			if (temp>limThreshUp){
				up32 = limThreshUp;
			}
			if (temp<limThreshDown){
				up32 = limThreshDown;
			}
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 74 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
	    	downFunc32(down16); 			
			band32 = array[684];				
			down32 = array[685];
		// RMS
			band32 = RMS32band(band32);					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar32 = delayB32(band32);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 75 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 76 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 77 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 78 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 79 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 80 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;

/////// SAMPLE 81 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];							
		// DELAY			
			delayVar1 = delayB1(band1);	
		// UP
			up16 = upFunc16(up32,delayVar16);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 82 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc16(down8); 	
			down16 = array[585];	
			band16 = array[584];		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar16 = delayB16(band16);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 83 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 84 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 85 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 86 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 87 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 88 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 89 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up64 = upFunc64(up128,delayVar64);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 90 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];			
	    	downFunc64(down32); 			
			band64 = array[784];				
			down64 = array[785];
		// RMS
			band64 = RMS64band(band64);		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar64 = delayB64(band64);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 91 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 92 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 93 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 94 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 95 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 96 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;

/////// SAMPLE 97 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];							
		// DELAY			
			delayVar1 = delayB1(band1);	
		// UP
			up16 = upFunc16(up32,delayVar16);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 98 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc16(down8); 	
			down16 = array[585];	
			band16 = array[584];		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar16 = delayB16(band16);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 99 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 100 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 101 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 102 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 103 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 104 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 105 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up32 = upFunc32(up64,delayVar32);
			up32 = RMS32up(up32);
			temp = up32;
			if (limThreshUp<temp){
				up32 = limThreshUp;
			}
			if (temp<limThreshDown){
				up32 = limThreshDown;
			}
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 106 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
	    	downFunc32(down16); 			
			band32 = array[684];				
			down32 = array[685];
		// RMS
			band32 = RMS32band(band32);					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar32 = delayB32(band32);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 107 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 108 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 109 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 110 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 111 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 112 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;

/////// SAMPLE 113 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];							
		// DELAY			
			delayVar1 = delayB1(band1);	
		// UP
			up16 = upFunc16(up32,delayVar16);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 114 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc16(down8); 	
			down16 = array[585];	
			band16 = array[584];		
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar16 = delayB16(band16);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 115 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 116 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE  117 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 118 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 119 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 120 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 121 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 122 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 123 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 124 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT; 


/////// SAMPLE 125 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up8 = upFunc8(up16,delayVar8);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
/////// SAMPLE 126 /////// 
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];	
			downFunc8(down4); 			
			band8 = array[484];				
			down8 = array[485];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);	
			delayVar8 = delayB8(band8);	
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;  		
		 					

/////// SAMPLE 127 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;    
	    // DOWN
		    downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];		
		// DELAY			
			delayVar1 = delayB1(band1);		
		// UP
			up4 = upFunc4(up8,delayVar4);
			up2 = upFunc2(up4,delayVar2);
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;
	
	
/////// SAMPLE 128 ///////
    	while((Rcv & I2S0_IR) == 0); 							
	    audioIn = I2S0_W0_MSW_R;
	    // DOWN
	    	downFunc1(audioIn); 			
			band1 = array[184];				
			down1 = array[185];
			downFunc2(down1); 			
			band2 = array[284];				
			down2 = array[285];		
			downFunc4(down2); 			
			band4 = array[384];				
			down4 = array[385];					
		// DELAY
			delayVar1 = delayB1(band1);	
			delayVar2 = delayB2(band2);
			delayVar4 = delayB4(band4);		
		// UP
			up1 = upFunc1(up2,delayVar1);
	    while((Xmit & I2S0_IR) == 0);  					
		I2S0_W0_MSW_W = OUTPUT;

		
    }
}


void init_array(void){
	int16 cnt;
	// Clear array
	for(cnt=0;cnt<20000;cnt++) array[cnt] = 0;	
	
	// Clear RMS Buffer
	for(cnt=0;cnt<599;cnt++) RMSBUFFER[cnt] = 0;
	
	//Read coefficients into array
	for(cnt=0;cnt<25;cnt++) array[cnt] = COEFF[cnt];
	
	initArray1();
	initArray2();
	initArray4();
	initArray8();
	initArray16();
	initArray32();
	initArray64();
	initArray128();
}

void main(){	
	init_array();
	initialize(STEREO,RESOLUTION,SAMPLINGRATE); // MONO/STEREO, 16/24-bit, sampling rate (48 kHz or 96 kHz)
	playback();
}


void initialize(uint8 audioType, uint8 resolution, uint8 fs){
	printf("\n\nSystem initializing\n");
	switch(audioType){
		case 0:
			Rcv  = 0x04; 				// MONO receive interrupt flag register
			Xmit = 0x10;				// MONO transmit interrupt flag register
			system_init(audioType,resolution,fs); // SETUP - Codec registers and C5515 I2S registers
		case 1:
			Rcv  = 0x08; 				// STEREO receive interrupt flag register
			Xmit = 0x20;				// STEREO transmit interrupt flag register
			system_init(audioType,resolution,fs); // SETUP - Codec registers and C5515 I2S registers
		default:
			Rcv  = 0x04; 				// MONO receive interrupt flag register
			Xmit = 0x10;				// MONO transmit interrupt flag register
			system_init(audioType,resolution,fs); // SETUP - Codec registers and C5515 I2S registers
	}
}

