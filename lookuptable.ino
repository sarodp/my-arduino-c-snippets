////////////////////////////////////////////////////////////////////////////////////
// 
// http://embeddedgurus.com/stack-overflow/2010/01/a-tutorial-on-lookup-tables-in-c
//
////////////////////////////////////////////////////////////////////////////////////



static const uint8_t hexlookup[256] =
{
0x00U, 0x07U, 0x0EU, 0x09U, 0x1CU, 0x1BU, 0x12U, 0x15U,
0x38U, 0x3FU, 0x36U, 0x31U, 0x24U, 0x23U, 0x2AU, 0x2DU,
0x70U, 0x77U, 0x7EU, 0x79U, 0x6CU, 0x6BU, 0x62U, 0x65U,
0x48U, 0x4FU, 0x46U, 0x41U, 0x54U, 0x53U, 0x5AU, 0x5DU,
0xE0U, 0xE7U, 0xEEU, 0xE9U, 0xFCU, 0xFBU, 0xF2U, 0xF5U,
0xD8U, 0xDFU, 0xD6U, 0xD1U, 0xC4U, 0xC3U, 0xCAU, 0xCDU,
0x90U, 0x97U, 0x9EU, 0x99U, 0x8CU, 0x8BU, 0x82U, 0x85U,
0xA8U, 0xAFU, 0xA6U, 0xA1U, 0xB4U, 0xB3U, 0xBAU, 0xBDU,
0xC7U, 0xC0U, 0xC9U, 0xCEU, 0xDBU, 0xDCU, 0xD5U, 0xD2U,
0xFFU, 0xF8U, 0xF1U, 0xF6U, 0xE3U, 0xE4U, 0xEDU, 0xEAU,
0xB7U, 0xB0U, 0xB9U, 0xBEU, 0xABU, 0xACU, 0xA5U, 0xA2U,
0x8FU, 0x88U, 0x81U, 0x86U, 0x93U, 0x94U, 0x9DU, 0x9AU,
0x27U, 0x20U, 0x29U, 0x2EU, 0x3BU, 0x3CU, 0x35U, 0x32U,
0x1FU, 0x18U, 0x11U, 0x16U, 0x03U, 0x04U, 0x0DU, 0x0AU,
0x57U, 0x50U, 0x59U, 0x5EU, 0x4BU, 0x4CU, 0x45U, 0x42U,
0x6FU, 0x68U, 0x61U, 0x66U, 0x73U, 0x74U, 0x7DU, 0x7AU,
0x89U, 0x8EU, 0x87U, 0x80U, 0x95U, 0x92U, 0x9BU, 0x9CU,
0xB1U, 0xB6U, 0xBFU, 0xB8U, 0xADU, 0xAAU, 0xA3U, 0xA4U,
0xF9U, 0xFEU, 0xF7U, 0xF0U, 0xE5U, 0xE2U, 0xEBU, 0xECU,
0xC1U, 0xC6U, 0xCFU, 0xC8U, 0xDDU, 0xDAU, 0xD3U, 0xD4U,
0x69U, 0x6EU, 0x67U, 0x60U, 0x75U, 0x72U, 0x7BU, 0x7CU,
0x51U, 0x56U, 0x5FU, 0x58U, 0x4DU, 0x4AU, 0x43U, 0x44U,
0x19U, 0x1EU, 0x17U, 0x10U, 0x05U, 0x02U, 0x0BU, 0x0CU,
0x21U, 0x26U, 0x2FU, 0x28U, 0x3DU, 0x3AU, 0x33U, 0x34U,
0x4EU, 0x49U, 0x40U, 0x47U, 0x52U, 0x55U, 0x5CU, 0x5BU,
0x76U, 0x71U, 0x78U, 0x7FU, 0x6AU, 0x6DU, 0x64U, 0x63U,
0x3EU, 0x39U, 0x30U, 0x37U, 0x22U, 0x25U, 0x2CU, 0x2BU,
0x06U, 0x01U, 0x08U, 0x0FU, 0x1AU, 0x1DU, 0x14U, 0x13U,
0xAEU, 0xA9U, 0xA0U, 0xA7U, 0xB2U, 0xB5U, 0xBCU, 0xBBU,
0x96U, 0x91U, 0x98U, 0x9FU, 0x8AU, 0x8DU, 0x84U, 0x83U,
0xDEU, 0xD9U, 0xD0U, 0xD7U, 0xC2U, 0xC5U, 0xCCU, 0xCBU,
0xE6U, 0xE1U, 0xE8U, 0xEFU, 0xFAU, 0xFDU, 0xF4U, 0xF3U
};


static const uint16_t mvlookup[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup999[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup888[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup777[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup666[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup555[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup444[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup333[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup222[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static const uint16_t mvlookup111[256] =
{ 
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
0101,1111,2222,3333,4444,5555,6666,7777,8888,8999,1010,1111,1212,1313,1414,1515,
};

static uint8_t xhex; 
static float xmv;

void setup() {
  Serial.begin(115200);  
  Serial.println("Ready");    //Test the serial monitor
    
}

void loop() {

 for(int i=0;i<=255;i++)        
 {
   xhex = hexlookup[i];
   xmv = mvlookup[i] * 0.1;
   
   Serial.print("    i=");  
   Serial.print(i);  
   Serial.print("    xhex=");  
   Serial.print(xhex);
   Serial.print("    xmv=");  
   Serial.print(xmv,1);
   Serial.println(" ");
 } 
   Serial.println("================================");
   delay(1000);
}